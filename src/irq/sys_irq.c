#include <stdio.h>
#include "score7_registers.h"

/************************************************************************************
* S+Core uses vectored interrupts, and here's how that works                        *
*                                                                                   *
* You basically have your DEBUG, GENERAL, and INT vectors                           *
* and DEBUG is for when doing debugging operations (SJProbe, etc)                   *
* and GENERAL is for mostly software based handling (think CPU exceptions)          *
* and INTERRUPT is for handling hardware (think GPIO, etc)                          *
*                                                                                   *
* When a hardware interrupt is called it immediately jumps to an offset (vector)    *
* at which point a handler will derive the cause from the CP0_CAUSE register        *
* and then begin processing based on the number derived                             *
*                                                                                   *
* In our handler we will handle the external hardware interrupts by building a      *
* table that fills in callback handlers ONLY for interrupts we choose to handle.    *
* This is because on HyperScan the OS already loads some necessary functionality    *
* in the vector for dealing with hardware as it relates to their system.            *
*                                                                                   *
* What this also means is that if someone chooses to use this for another S+Core    *
* system, then it might be adventageous to simply fill ALL of the slots with a      *
* NULL handler just in case.                                                        *
*                                                                                   *
*                                                                                   *
************************************************************************************/
#define DEBUG_VEC   0xA00001FC
#define GENERAL_VEC 0xA0000200
#define INT_VEC     0xA0000204

// Used to reference start of current exception vector
extern void int1_vec(void);

// Max/Min number of IRQs
// For now we will only attach handlers for 24~63 (src 0~39) but
// will later add support for the CPU exceptions and 
// custom handling of those (for now those just freeze
// with a jump to self at intmsg)
#define MIN_IRQ 24
#define MAX_IRQ 63

// Type for an ISR callback
typedef void (*isr_handler)(void);

// Dispatch table, all entries == NULL
static isr_handler isr_table[MAX_IRQ] = { 0 };

// Fallback when no handler is attached
static void handler_placeholder(void) { }

// Hook IRQ ISR
void attach_isr(unsigned int irq, isr_handler handler) {

	// Only attach handler if our irq is within the appropriate IRQ firing range
    if (irq >= MIN_IRQ && irq <= MAX_IRQ) {
    	
    	// Disable interrupts
		//asm("li r4, 0x0");
		//asm("mtcr r4, cr0");
		//asm("nop");
		//asm("nop");
		//asm("nop");
		//asm("nop");
		//asm("nop");
		
		// Install handler to isr_table
    	isr_table[irq] = handler;
    
		// There seems to possibly be a bug in SPG290 (maybe other score7 based SoC?) where it seems
		// like the vector table won't properly relocate (I could be wrong) but this is fine
		// as we can just copy only the vectors that we expect to use over the fixed default vector
		// address space (0xA00001FC area) and use the attach_isr to hook into the vector table with
		// our handler
		
		// Patch the irq_dispatch vector from our current one, to the fixed address (0xA00001FC area)
		// to use our custom isr dispatch for specified isr. This could possibly only work on Hyperscan
		// since I haven't seen any examples of other score7 based systems and their memory map, but if so
		// this could easily be fixed to accomodate those systems as well with our -D(platform) configuration switch
		volatile unsigned int *current_irq_dispatch = (volatile unsigned int *)int1_vec;
		
		// This might seem hacky here, but because we source from 1 (0xA0000204 is int1) it seems best to align
		// our table by 0xA0000200 + (irq * 4) 
		volatile unsigned int *fixed_irq_dispatch = (volatile unsigned int *)GENERAL_VEC;
		
		unsigned int irq_offset = irq;
		
		// Swap handler at fixed vector with the one from our (unused) current vector
		fixed_irq_dispatch[irq_offset] = current_irq_dispatch[irq_offset];

		printf("Installing handler for IRQ%d @ 0x%08x\n", irq, (unsigned int)&fixed_irq_dispatch[irq_offset]);
		/*
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
		*/
		// Enable interrupts
		//asm("li r4, 0x1");
		//asm("mtcr r4, cr0");
		//asm("nop");
		//asm("nop");
		//asm("nop");
		//asm("nop");
		//asm("nop");
    }
}

// Get cause and handle IRQ
void irq_dispatch(unsigned int cp0_cause) {
    // bits [23:18] of cause register gives the IRQ number
    unsigned int intvec = (cp0_cause & 0x00FC0000u) >> 18;
    printf("CAUSE: %x\n", intvec);
	// Only hook between MIN_IRQ and MAX_IRQ (24~63) for now, until we add custom CPU exception handling
	if (intvec >= MIN_IRQ && intvec <= MAX_IRQ) {
    	// Look it up in the table
    	isr_handler h = isr_table[intvec];
    	if (h) h(); else handler_placeholder();
	}
}



