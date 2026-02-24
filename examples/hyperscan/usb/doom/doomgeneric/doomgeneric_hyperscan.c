//doomgeneric for Mattel HyperScan

#include "doomkeys.h"
#include "m_argv.h"
#include "doomgeneric.h"

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "tv/tv.h"
#include "score7_registers.h"
#include "score7_constants.h"
#include "irq/interrupts.h"
#include "hyperscan/hyperscan.h"
#include "hyperscan/fatfs/ff.h"
#include "hyperscan/hs_controller/hs_controller.h"

#define SRC_W 320
#define SRC_H 200

#define DST_W 320
#define DST_H 240

#define KEYQUEUE_SIZE 32

static unsigned short s_KeyQueue[KEYQUEUE_SIZE];
static unsigned int s_KeyQueueWriteIndex = 0;
static unsigned int s_KeyQueueReadIndex = 0;

#define FBADDR 0xA0F69000

void _unlink_r(){
	printf("_unlink_r called\n");
}

void _link_r(){
	printf("_link_r called\n");
}

static unsigned char convertToDoomKey(unsigned int key)
{
	return key;
}

static void addKeyToQueue(int pressed, unsigned int keyCode)
{
    unsigned char key = convertToDoomKey(keyCode);
    unsigned short keyData = ((pressed & 1) << 8) | key;

    unsigned int next = (s_KeyQueueWriteIndex + 1) % KEYQUEUE_SIZE;
    if (next == s_KeyQueueReadIndex) {
        // queue full, drop event
        return;
    }

    s_KeyQueue[s_KeyQueueWriteIndex] = keyData;
    s_KeyQueueWriteIndex = next;
}

static inline int joy_left(uint8_t x)  { return x >= 0xB0; }
static inline int joy_right(uint8_t x) { return x <= 0x60; }
static inline int joy_up(uint8_t y)    { return y >= 0xB0; }
static inline int joy_down(uint8_t y)  { return y <= 0x60; }

static void handleKeyInput_from_hyperscan(void)
{
    // --- current state ---
    int start  = controller[hs_controller_1].input.start;
    int select = controller[hs_controller_1].input.select;

    int g = controller[hs_controller_1].input.g;
    int y = controller[hs_controller_1].input.y;
    int r = controller[hs_controller_1].input.r;
    int b = controller[hs_controller_1].input.b;

    // int rt = controller[hs_controller_1].input.rt;
    // int lt = controller[hs_controller_1].input.lt;
    int rs = controller[hs_controller_1].input.rs;
    int ls = controller[hs_controller_1].input.ls;

    uint8_t jx = controller[hs_controller_1].input.joystick_x;
    uint8_t jy = controller[hs_controller_1].input.joystick_y;

    int left  = joy_left(jx);
    int right = joy_right(jx);
    int up    = joy_up(jy);
    int down  = joy_down(jy);

    // --- previous state ---
    static int p_start=0, p_select=0;
    static int p_g=0, p_y=0, p_r=0, p_b=0;
    static int p_rs=0, p_ls=0; // p_rt=0, p_lt=0;
    static int p_left=0, p_right=0, p_up=0, p_down=0;

    // Emit a key event only when state changes
    #define EMIT(now, prev, doomkey) \
        do { \
            if ((now) != (prev)) { \
                addKeyToQueue((now) ? 1 : 0, (doomkey)); \
                (prev) = (now); \
            } \
        } while (0)

    // Start -> MENU
    EMIT(start,  p_start,  KEY_ESCAPE);

    // Select -> ENTER
    EMIT(select, p_select, KEY_ENTER);

    // Face buttons
    EMIT(g, p_g, KEY_FIRE);       // Fire
    EMIT(r, p_r, KEY_USE);        // Use/Open
    EMIT(y, p_y, KEY_STRAFE_L);   // Strafe (or KEY_STRAFE_R)
    EMIT(b, p_b, KEY_RSHIFT);     // Run (speed) - keep shift

    // Shoulder/trigger: weapon cycle
    EMIT(ls, p_ls, ',');       // Prev weapon
    EMIT(rs, p_rs, '.');       // Next weapon
  
    // Movement
    EMIT(left,  p_left,  KEY_LEFTARROW);
    EMIT(right, p_right, KEY_RIGHTARROW);
    EMIT(up,    p_up,    KEY_UPARROW);
    EMIT(down,  p_down,  KEY_DOWNARROW);

    #undef EMIT
}

void DG_Init()
{
	hs_controller_init();

    tv_init(RESOLUTION_320_240,
            COLOR_RGB565,
            (uint32_t)FBADDR,
            (uint32_t)FBADDR,
            (uint32_t)FBADDR);
            
	ticks = 0;
}

void DG_SleepMs(uint32_t ms)
{
}

volatile uint32_t ticks = 0;

uint32_t DG_GetTicksMs()
{
    return ticks+=8; //get_uptime_ms();
}

int DG_GetKey(int* pressed, unsigned char* doomKey)
{
    if (s_KeyQueueReadIndex == s_KeyQueueWriteIndex)
    {
        //key queue is empty

        return 0;
    }
    else
    {
        unsigned short keyData = s_KeyQueue[s_KeyQueueReadIndex];
        s_KeyQueueReadIndex++;
        s_KeyQueueReadIndex %= KEYQUEUE_SIZE;

        *pressed = keyData >> 8;
        *doomKey = keyData & 0xFF;

        return 1;
    }
}

void DG_SetWindowTitle(const char * title)
{
}

int main(int argc, char **argv) 
{	
    //*(volatile unsigned int *)0xA00416D0 = (volatile unsigned int *)inc_ticks;

	FATFS fs0;
	f_mount(&fs0, "0:", 1);
    
	char *fake_argv[] = {"HYPER.EXE", "-merge", "batman.wad", "-iwad", "doom2.wad", "-nomouse", "-nosound", "-scaling", "0", NULL};
	//char *fake_argv[] = {
    //    "HYPER.EXE",
    //    //"-iwad", "doom2.wad",
    //    "-merge", "batman.wad",
    //    "doom2.wad",
        //"-file", "batman.wad",
    //    "-nomouse",
    //    "-nosound",
    //    "-scaling", "0",
    //    NULL
    //};
    
	int fake_argc = sizeof(fake_argv) / sizeof(fake_argv[0]) - 1;
	
	doomgeneric_Create(fake_argc, fake_argv);
	
	while(1) {
	    hs_controller_read();
	    handleKeyInput_from_hyperscan();
        doomgeneric_Tick();
    }
    
    return 0;
}
