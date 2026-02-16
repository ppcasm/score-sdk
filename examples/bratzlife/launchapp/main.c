/*

This is part of the MGA BratzLife examples from the Sunplus S+Core SDK by ppcasm (ppcasm@gmail.com)

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tv/tv.h"
#include "irq/interrupts.h"
#include "score7_registers.h"
#include "score7_constants.h"

#define TESTFB 0xA0400000

unsigned int *fb = (unsigned int *)TESTFB;

volatile unsigned int vblank = 0;
void inc_vblank(void) {
	vblank++;
}

unsigned int alive = 0;

int main(){
    
    tv_init(RESOLUTION_640_480, COLOR_RGB565, TESTFB, TESTFB, TESTFB);
    
    attach_isr(INT_PPU_VBLANK_START, inc_vblank);
    enable_isr(INT_PPU_VBLANK_START);
    
    while(1) {
        tv_printhex((unsigned short *)TESTFB, 4, 4, alive++);
        if(alive == 0x1500) {
        	enable_isr(INT_PPU_VBLANK_START);
        }
        if(alive == 0x3000) {
        	disable_isr(INT_PPU_VBLANK_START);
        	alive = 0;
        }
        tv_printhex((unsigned short *)TESTFB, 8, 8, vblank);
    }
    
    return 0;
}
