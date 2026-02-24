#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tv/tv.h"
#include "irq/interrupts.h"
#include "hyperscan/hs_controller/hs_controller.h"

unsigned short *fb = (unsigned short *) 0xA0400000;

volatile unsigned int count = 0;
volatile unsigned int vblank_count = 0;
void count_vblank(void) {
	*P_IRQ_STATUS = 1;
	hs_controller_read();
	if(vblank_count++ % 15 == 0) count++;
}

int main(){
	
	int nExitCode = 0;
	
	hs_controller_init();
	
	tv_init(RESOLUTION_640_480, COLOR_RGB565, 0xA0400000, 0xA0400000, 0xA0400000);

    attach_isr(INT_PPU_VBLANK_START, count_vblank);
    enable_isr(INT_PPU_VBLANK_START);
    
    char *msgs = "HyperScan Basic Example";

	char *start_msg = "START button pressed";
    char *select_msg = "SELECT button pressed";
    char *right_t_msg = "RIGHT TRIGGER pressed";
    char *left_t_msg = "LEFT TRIGGER pressed";
    char *right_s_msg = "RIGHT SHOULDER pressed";
    char *left_s_msg = "LEFT SHOULDER pressed";
    char *green_msg = "GREEN button pressed";
    char *yellow_msg = "YELLOW button pressed";
    char *red_msg = "RED button pressed";
    char *blue_msg = "BLUE button pressed";
    char *up_msg = "UP";
    char *down_msg = "DOWN";
    char *left_msg = "LEFT";
    char *right_msg = "RIGHT";
    
	while(1){
						
		// Print text on TV
		tv_print(fb, 28, 2, msgs);

		if(controller[hs_controller_1].input.start) tv_print(fb, ((640/8)-strlen(start_msg)-1)/2, 4, start_msg); else tv_print(fb, ((640/8)-strlen(start_msg)-1)/2, 4, "                    ");
		if(controller[hs_controller_1].input.select) tv_print(fb, ((640/8)-strlen(select_msg)-1)/2, 5, select_msg); else tv_print(fb, ((640/8)-strlen(select_msg)-1)/2, 5, "                     ");		
		if(controller[hs_controller_1].input.rt) tv_print(fb, ((640/8)-strlen(right_t_msg)-1)/2, 6, right_t_msg); else tv_print(fb, ((640/8)-strlen(right_t_msg)-1)/2, 6, "                     ");
		if(controller[hs_controller_1].input.lt) tv_print(fb, ((640/8)-strlen(left_t_msg)-1)/2, 7, left_t_msg); else tv_print(fb, ((640/8)-strlen(left_t_msg)-1)/2, 7, "                    ");
		if(controller[hs_controller_1].input.rs) tv_print(fb, ((640/8)-strlen(right_s_msg)-1)/2, 8, right_s_msg); else tv_print(fb, ((640/8)-strlen(right_s_msg)-1)/2, 8, "                      ");
		if(controller[hs_controller_1].input.ls) tv_print(fb, ((640/8)-strlen(left_s_msg)-1)/2, 9, left_s_msg); else tv_print(fb, ((640/8)-strlen(left_s_msg)-1)/2, 9, "                     ");
		if(controller[hs_controller_1].input.g) tv_print(fb, ((640/8)-strlen(green_msg)-1)/2, 10, green_msg); else tv_print(fb, ((640/8)-strlen(green_msg)-1)/2, 10, "                    ");
		if(controller[hs_controller_1].input.y) tv_print(fb, ((640/8)-strlen(yellow_msg)-1)/2, 11, yellow_msg); else tv_print(fb, ((640/8)-strlen(yellow_msg)-1)/2, 11, "                     ");
		if(controller[hs_controller_1].input.r) tv_print(fb, ((640/8)-strlen(red_msg)-1)/2, 12, red_msg); else tv_print(fb, ((640/8)-strlen(red_msg)-1)/2, 12, "                    ");
		if(controller[hs_controller_1].input.b) tv_print(fb, ((640/8)-strlen(blue_msg)-1)/2, 13, blue_msg); else tv_print(fb, ((640/8)-strlen(blue_msg)-1)/2, 13, "                    ");

		if(controller[hs_controller_1].input.joystick_y <= 0x60) tv_print(fb, ((640/8)-strlen(down_msg)-1)/2, 15, down_msg); else tv_print(fb, ((640/8)-strlen(down_msg)-1)/2, 15, "    ");
		if(controller[hs_controller_1].input.joystick_y >= 0xB0) tv_print(fb, ((640/8)-strlen(up_msg)-1)/2, 14, up_msg); else tv_print(fb, ((640/8)-strlen(up_msg)-1)/2, 14, "    ");
		if(controller[hs_controller_1].input.joystick_x <= 0x60) tv_print(fb, ((640/8)-strlen(right_msg)-1)/2, 17, right_msg); else tv_print(fb, ((640/8)-strlen(right_msg)-1)/2, 17, "     ");
		if(controller[hs_controller_1].input.joystick_x >= 0xB0) tv_print(fb, ((640/8)-strlen(left_msg)-1)/2, 16, left_msg); else tv_print(fb, ((640/8)-strlen(left_msg)-1)/2, 16, "    ");		
	}
		
	return nExitCode;
}
