/*

This is part of the Mattel HyperScan SDK by ppcasm (ppcasm@gmail.com)

This example is to show how it's possible to write a custom firmware installer for the HyperScan. By default this
doesn't run as a normal HYPER.EXE app, and it's meant to be run from recovery mode, and uploaded through the UART
interface. Please run the HYPER.EXE from the FlashRecovery example project first before attemping to run this.

This requires that you have a UART serial cable installed as well. Instructions on how to install a 
UART cable are found in the documentation section of this repo.

*/

#include <stdio.h>
#include <stdlib.h>

#include "tv/tv.h"
#include "irq/interrupts.h"
#include "score7_registers.h"
#include "score7_constants.h"
#include "norflash/norflash.h"
#include "hyperscan/hs_controller/hs_controller.h"

#define UPLOAD_ADDRESS 0x80600000

// Macro for controlling the HyperScan LEDs
#define HS_LEDS(value) (*P_CSI_GPIO_SETUP = (0x1FFE0000+(value<<5)))

#define SECTOR_SIZE 0x1000

// Stupid Framebuffer
unsigned short *fb = (unsigned short *) 0xA0400000;

#define BIT(n)	(1 << n)

#define SW_UART_UART	BIT(24)

#define UART_BUSY	BIT(3)
#define UART_TRANSMIT_EMPTY	BIT(7)
#define UART_TRANSMIT_FULL	BIT(5)
#define UART_RECEIVE_EMPTY	BIT(4)
#define UART_RECEIVE_FULL	BIT(6)

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef volatile u32 vu32;

static void uart_enable_interface() {
	*P_UART_INTERFACE_SEL |= SW_UART_UART;
}

static void uart_wait_nonbusy() {
	u32 status = *P_UART_TXRX_STATUS;
	while (status & UART_BUSY || status & UART_TRANSMIT_FULL || !(status & UART_TRANSMIT_EMPTY)) {
		status = *P_UART_TXRX_STATUS;
	}
}

static void uart_write_byte(u32 c) {
	*P_UART_TXRX_DATA = c;
	uart_wait_nonbusy();
}

static void print_string(const char *str) {
	while (*str) {
		uart_write_byte(*str++);
	}
}

static u8 uart_read_byte() {
	while (*P_UART_TXRX_STATUS & UART_RECEIVE_EMPTY);
	return *P_UART_TXRX_DATA;
}

static inline unsigned int read_cp0_dreg(void)
{
    unsigned int v;
    __asm__ volatile (
        "mfcr %0, cr29"
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

unsigned int test = 0;
void truesay(void) {
	//if (( *(volatile unsigned int *)0x88161000 >> 0x1a & 1) !=0) {
	//	*(volatile unsigned int *)0x88161000 = 0x8c000000;
	//	test++;
	//}
	test++;
	return;
}

unsigned int test1 = 0;

#define TIMER_ON		0x80000000
#define TIMER_OFF		0x00000000
#define TIMER_IRQ_ON	0x08000000
#define TIMER_IRQ_OFF	0x00000000
#define TIMER_IRQ_CLR	0x04000000
#define TIMER_CPPNOR	0x00000000
#define TIMER_CCPCAP	0x40000000
#define TIMER_CCPCMP	0x80000000
#define TIMER_CCPPWM	0xc0000000
#define TIMER_CAPCS0	0x00000000
#define TIMER_CAPCS1	0x08000000
#define TIMER_CMPCS0	0x00000000
#define TIMER_CMPCS1	0x04000000
#define TIMER_PWMCS0	0x00000000
#define TIMER_PWMCS1	0x02000000

void InitTimer(void)
{
	TIMER_INT_UNMASK();
	*P_CKG_CFG_TIMER0 = 0x00000000;
	*P_CKG_CFG_TIMER0 = 0x00000003;
	*P_CKG_SEL_TIMER = 0x00000003;
	
	*P_TM0_PRELOAD = 0x6fff; // set timer cycle
	*P_TM0_CCP_CTRL = TIMER_CPPNOR; // normal mode
	*P_TM0_CTRL = TIMER_ON | TIMER_IRQ_ON | TIMER_IRQ_CLR;
}

void FadeIn(void)     
{
    unsigned int i, j;
	for(i=0; i<1024; i++)
	{
		*P_TV_FADE_SETUP = 255-i;
		for(j=0; j<1024*8; j++);
	}
}

int main()
{	

	int nExitCode = 0;
	/************************************************************************/
	/*   TODO: add your code here                                           */
	/************************************************************************/

	int i = 0;
	
	/* Initialize NOR flash GPIO for R/W */
	//norflash_init();
	
	/* Initalize Mattel HyperScan controller interface */
	//hs_controller_init();
	
	/*
	Set TV output up with RGB565 color scheme and make set all framebuffers
	to stupid framebuffer address, tv_init will select the first framebuffer
	as default.
	*/
	tv_init(RESOLUTION_640_480, COLOR_RGB565, 0xA0400000, 0xA0400000, 0xA0400000);
    
    attach_isr(INT_TV_VBLANK_START, truesay);
    attach_isr(INT_PPU_VBLANK_START, truesay);
    attach_isr(INT_TV_VBLANK_END, truesay);
    *(volatile unsigned int *)0x8809003C = 0x00000001;
    *P_VBLK_TIME 	= 0x5a;
	*P_IRQ_CONTROL 	= 0xffffffff;
	
	INT_UNMASK_SETUP1(0u);
    //InitTimer();
    unsigned int v = 0;
    unsigned int v1 = 0;
	while(1){
		tv_printhex(fb, 2, 2, test);
		tv_printhex(fb, 8, 8, test1++);
		v = read_cp0_dreg();
        v = (v & ~(1u << 29)) | (1u << 28);
        write_cp0_dreg(v);
        v = read_cp0_dreg();
		tv_printhex(fb, 10, 10, v);
		//tv_printhex(fb, 20, 20, *(unsigned int*)0x88200004);
	}
		
	return nExitCode;
}
