
#include <stdio.h>
#include <stdlib.h>
#include "tv/tv.h"
#include "cpu/cache.h"
#include "irq/interrupts.h"
#include "score7_registers.h"
#include "score7_constants.h"
#include "hyperscan/hyperscan.h"

// Stupid Framebuffer
unsigned short *fb = (unsigned short *) 0xA0400000;

volatile unsigned int secondz = 0;
volatile uint32_t last_sec_ms = 0;
volatile uint32_t ms_ticks = 0;

void timer5_isr(void)
{
    if ((*P_TIMER5_MODE_CTRL >> 26) & 1) {
        *P_TIMER5_MODE_CTRL = 0x8C000000u;
        if (ms_ticks - last_sec_ms >= 1000) {
            last_sec_ms += 1000;
            secondz++;
        }
        ms_ticks++;
    }
}

int main()
{	

    disable_isr(INT_TIMER);
	attach_isr(INT_TIMER, timer5_isr);
	
    *P_TIMER5_CLK_CONF = 0;
    *P_TIMER5_CLK_CONF = C_TIMER_CLK_EN | C_TIMER_RST_DIS;
    
    *P_TIMER_CLK_SEL = C_TIMER5_CLK_27M | 26;
    
    *P_TIMER5_CCP_CTRL = C_TIMER_NOR_MODE;
    
    *P_TIMER5_PRELOAD_DATA = 0xFC18;
    
    *P_TIMER5_MODE_CTRL = C_TIMER_CTRL_EN | C_TIMER_INT_EN | C_TIMER_INT_FLAG;

    enable_isr(INT_TIMER);    
    
	tv_init(RESOLUTION_640_480, COLOR_RGB565, 0xA0400000, 0xA0400000, 0xA0400000);
	
	//*P_TIMER5_MODE_CTRL = 0x88000000u;
    
	while(1){

		tv_printhex(fb, 1, 1, *P_TIMER5_COUNT_DATA);
		tv_printhex(fb, 4, 4, secondz);
	}
}

