
#include <stdio.h>
#include <stdlib.h>
#include "tv/tv.h"
#include "cpu/cache.h"
#include "irq/interrupts.h"
#include "score7_registers.h"
#include "score7_constants.h"

// Stupid Framebuffer
unsigned short *fb = (unsigned short *) 0xA0400000;

static inline unsigned int read_cp0_dreg(void)
{
    unsigned int v;
    __asm__ volatile (
        "mfcr %0, cr29"
        : "=r"(v)
    );
    return v;
}

static inline unsigned int read_cr0_reg(void)
{
    unsigned int v;
    __asm__ volatile (
        "mfcr %0, cr0"
        : "=r"(v)
    );
    return v;
}

static inline void write_cp0_dreg(unsigned int v)
{
    __asm__ volatile (
        "mtcr %0, cr29"
        :
        : "r"(v)
    );
}


static inline void sdbbp(void) {
  __asm__ volatile ("sdbbp");
}

static inline void drte(void) {
  __asm__ volatile ("drte");
}

volatile unsigned int vblank = 0;

void inc_vblank(void) {
	*P_IRQ_STATUS = 0x00000001u;
	vblank++;
}

typedef volatile unsigned int U32;

int main()
{	
	*P_INT_MASK_CTRL1 = 0xFFFFFFFFu;
	cache_flush_all();
	/*
	*(volatile uint32_t *)0x88010090 = 0x5A;
	*(volatile uint32_t *)0x88010080 = 1;
	*(volatile uint32_t *)0x88090004 = 0;
	*(volatile uint32_t *)0x8809003C = 0;
	*(volatile uint32_t *)0x88090058 = 0;
	*(volatile uint32_t *)0x880100C4 = 0xA0400000u;
	*(volatile uint32_t *)0x880100C8 = 0xA0400000u;
	*(volatile uint32_t *)0x880100CC = 0xA0400000u;
	*(volatile uint32_t *)0x88070044 = 0xA0400000u;
	*(volatile uint32_t *)0x88070048 = 0xA0400000u;
	*(volatile uint32_t *)0x88070064 = 0xA0400000u;
	*(volatile uint32_t *)0x88030000 = 0x1118;
	*(volatile uint32_t *)0x88010000 = 0x1002;
	
	*(volatile uint32_t *)0x88070044 = 0xA0400000;
	*(volatile uint32_t *)0x88070048 = 0xA0400000;
	*(volatile uint32_t *)0x88070064 = 0xA0400000;
	
	*P_PTR_SETTING = 0xF0;
	*P_P2T_SETTING = 1;
	*P_HW4_SETTING = 1;
	
	*(volatile uint32_t *)0x880100C4 = 0xA0400000;
	*(volatile uint32_t *)0x880100C8 = 0xA0400000;
	*(volatile uint32_t *)0x880100CC = 0xA0400000;
	
	*P_TV_MODE_CTRL = 0x1114;
	*P_PPU_CONTROL = 0x1001;
	
	*P_VBLK_TIME = 100;
	*P_IRQ_CONTROL = 1;
    cache_flush_all();
    */
	tv_init(RESOLUTION_640_480, COLOR_RGB565, 0xA0400000, 0xA0400000, 0xA0400000);
	
	attach_isr(INT_PPU_VBLANK_START, inc_vblank);
	attach_isr(INT_TV_VBLANK_START, inc_vblank);
    enable_isr(INT_PPU_VBLANK_START);
    enable_isr(INT_PPU_VBLANK_START);
    
    
	while(1){
		cache_flush_all();
		if(vblank) printf("Vblank: %x\n", vblank);
		//printf("INT: %x\n", read_cr0_reg());
		//a = 5 / 0;
		//sdbbp();g
	}
}

