#include <stdio.h>
#include "uart/uart.h"
#define P_CSI_GPIO_SETUP (volatile unsigned int*)0x88200024
#define HS_LEDS(value) (*P_CSI_GPIO_SETUP = (0x1FFE0000+(value<<5)))

static inline unsigned int asm_j_insn(unsigned int address, unsigned int link) {
    // low half: bits [14:0] of address, plus the p-bit at bit 15
    unsigned int insn_l = (address & 0x7FFFU)    // mask low 15 bits
                    | (1U << 15);            // set p-bit
    // high half: bits [28:16] of (address<<1), plus bits 31 and 27
    unsigned int insn_h = ((address << 1) & 0x1FFF0000U)  // mask bits [28:16]
                    | (1U << 31)                   // set bit 31
                    | (1U << 27);                  // set bit 27
    // combine halves and add the link field
    unsigned int assembled = (insn_h & 0xFFFF0000U)    // upper 16 bits
                       | (insn_l & 0x0000FFFFU);  // lower 16 bits
    assembled += link;
    return assembled;
}

void iso_init_callback() {
//	HS_LEDS(0x01);
//	while(1) {
//		uart_print_string("iso_init_callback\n");
//	}
}

void iso_open_callback() {
	uart_enable_interface();
	HS_LEDS(0x0f);

	asm("la r28, 0xa0045140");
	asm("ldis r10, 0xa002");
	asm("ori r10, 0x5f44");
	asm("br! r10");
	asm("nop!");
}

int iso_read_callback(int filedes, void *buffer, unsigned int size) {
	uart_enable_interface();
	
	HS_LEDS(0x0f);

	// invalidate D-Cache
	asm("cache 0x18, [r15, 0]");
	asm("nop");
	asm("nop!");
	asm("nop!");
	asm("nop!");
	asm("nop!");
	asm("nop");
	
	//	invalidate I-Cache
	asm("cache 0x10, [r15, 0]");
	asm("nop");
	asm("nop!");
	asm("nop!");
	asm("nop!");
	asm("nop!");
	asm("nop");
	
	// Drain write buffer
	asm("cache 0x1A, [r15, 0]");
	asm("nop");
	asm("nop!");
	asm("nop!");
	asm("nop!");
	asm("nop!");
	asm("nop");
	

	printf("iso_read: filedes(%d) | buf(%p) | size(%d)\n", filedes, buffer, size);
	while(1){}
}
int iso_lseek_callback(int fd, int offset, int whence) {
	uart_enable_interface();
	HS_LEDS(0x08);
	while(1){} 
return 0;
}

void iso_close_callback(int filedes) {
	uart_enable_interface();
	HS_LEDS(0x08);
	while(1){} 
}

int main(){
	
	while(1) {
	    uart_print_string("TESTING\n");
	}
	
	/*
	int i = 0;	
		
	//uart_print_string("STARTED\n");
		
	volatile unsigned int *src = (volatile unsigned int *)0x9F001000;
	volatile unsigned int *dst = (volatile unsigned int *)0x800001FC;
	unsigned int n = (0xFF000 / 4);
	
	// invalidate D-Cache
	asm("cache 0x18, [r15, 0]");
	asm("nop");
	asm("nop!");
	asm("nop!");
	asm("nop!");
	asm("nop!");
	asm("nop");
	
	//	invalidate I-Cache
	asm("cache 0x10, [r15, 0]");
	asm("nop");
	asm("nop!");
	asm("nop!");
	asm("nop!");
	asm("nop!");
	asm("nop");
	// Drain write buffer
	asm("cache 0x1A, [r15, 0]");
	asm("nop");
	asm("nop!");
	asm("nop!");
	asm("nop!");
	asm("nop!");
	asm("nop");
	
	for(i = 0; i < n; i++) {
		dst[i] = src[i];
	}
	
	// invalidate D-Cache
	asm("cache 0x18, [r15, 0]");
	asm("nop");
	asm("nop!");
	asm("nop!");
	asm("nop!");
	asm("nop!");
	asm("nop");
	
	//	invalidate I-Cache
	asm("cache 0x10, [r15, 0]");
	asm("nop");
	asm("nop!");
	asm("nop!");
	asm("nop!");
	asm("nop!");
	asm("nop");
	// Drain write buffer
	asm("cache 0x1A, [r15, 0]");
	asm("nop");
	asm("nop!");
	asm("nop!");
	asm("nop!");
	asm("nop!");
	asm("nop");

	// Patch checksum
	//*(volatile unsigned int*) 0xa000f740 = 0x84b88018;

	// You could place firmware patches here that would get applied before booting HyperScanOS
	// Patch iso_init callback
	//*(volatile unsigned int *)0xa0000890 = 0x00000000; 
	//*(volatile unsigned int *)0xa0000894 = 0x00000000;
	//*(volatile unsigned int *)0xa0000898 = asm_j_insn((unsigned int)iso_init_callback, 0);

	// Patch iso_open callback
	//asm("la r0, 0xa0c00000");
	*(volatile unsigned int *)0xa000089C = 0x00000000;
	*(volatile unsigned int *)0xa00008A0 = 0x00000000;
	*(volatile unsigned int *)0xa00008A4 = asm_j_insn((unsigned int)iso_open_callback, 0);

	// Patch iso_read callback
	//*(volatile unsigned int *)0xa00008A8 = 0x00000000;
	//*(volatile unsigned int *)0xa00008AC = 0x00000000;
	//*(volatile unsigned int *)0xa00008B0 = asm_j_insn((unsigned int)iso_read_callback, 0);

	// Patch iso_lseek callback
//	*(volatile unsigned int *)0xa00008B4 = 0x00000000;
//	*(volatile unsigned int *)0xa00008B8 = 0x00000000;
//	*(volatile unsigned int *)0xa00008BC = asm_j_insn((unsigned int)iso_lseek_callback, 0);

	// Patch iso_close callback
//	*(volatile unsigned int *)0xa00008C0 = 0x00000000;
//	*(volatile unsigned int *)0xa00008C4 = 0x00000000;
//	*(volatile unsigned int *)0xa00008C8 = asm_j_insn((unsigned int)iso_close_callback, 0);
		
		
	// invalidate D-Cache
	asm("cache 0x18, [r15, 0]");
	asm("nop");
	asm("nop!");
	asm("nop!");
	asm("nop!");
	asm("nop!");
	asm("nop");
	
	//	invalidate I-Cache
	asm("cache 0x10, [r15, 0]");
	asm("nop");
	asm("nop!");
	asm("nop!");
	asm("nop!");
	asm("nop!");
	asm("nop");
	// Drain write buffer
	asm("cache 0x1A, [r15, 0]");
	asm("nop");
	asm("nop!");
	asm("nop!");
	asm("nop!");
	asm("nop!");
	asm("nop");
		
	void (*entry_start)(void) = (void *)0xA0001000;
	entry_start();
    */
return 0;
}
