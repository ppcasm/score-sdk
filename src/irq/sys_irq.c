#include <stdio.h>
#include "cpu/cache.h"
#include "score7_registers.h"
#include "score7_constants.h"

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
static void handler_placeholder(void) { return; }

// Hook IRQ ISR
void attach_isr(unsigned int irq, isr_handler handler) {

    volatile unsigned int flush_wait = 0;
    
	// Only attach handler if our irq is within the appropriate IRQ firing range
    if (irq >= MIN_IRQ && irq <= MAX_IRQ) {
    	
    	// Disable interrupts
		asm("li r4, 0x0");
		asm("mtcr r4, cr0");
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");
		
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
		
		COMPILER_BARRIER();
		cache_sync(&fixed_irq_dispatch[irq], 4);
		cache_flush_all();
		COMPILER_BARRIER();
		
		for (flush_wait = 0; flush_wait < 5000; flush_wait++) {
			__asm__ volatile("nop" ::: "memory");
		}
		
		COMPILER_BARRIER();
		
		//printf("Installing handler for IRQ%d @ 0x%08x\n", irq, (unsigned int)&fixed_irq_dispatch[irq_offset]);
		
		// Enable interrupts
		asm("li r4, 0x1");
		asm("mtcr r4, cr0");
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");
    }
}

// Get cause and handle IRQ
void irq_dispatch(unsigned int cp0_cause) {
    // Bits [23:18] of cause register gives the IRQ number
    unsigned int intvec = (cp0_cause & 0x00FC0000u) >> 18;

    //printf("CAUSE: %x\n", intvec);
 
	// Only hook between MIN_IRQ and MAX_IRQ (24~63) for now, until we add custom CPU exception handling
	if (intvec >= MIN_IRQ && intvec <= MAX_IRQ) {
    	// Look it up in the table
    	isr_handler h = isr_table[intvec];
    	if (h) h(); else handler_placeholder();
	}
}

/********************************************************************
* Enable/Disable IRQ ISR                                                    *
*                                                                   *
* The module interrupts are enabled from a bit masking via their    *
* interrupt source number. Because the vector address ends at 63    *
* it can be reasoned that we could just subtract 63 from the vector *
* address to base the source number to 0 so that we can just pass   *
* this function the appropriate "vector address" through the        *
* interrupt defines in interrupts.h                                 *
*                                                                   *
* This means that we could do like this:                            *
*                                                                   *
* attach_isr(INT_PPU_VBLANK_START, handler);                        *
*                                                                   *
* and then:                                                         *
* enable_isr(INT_PPU_VBLANK_START);                                 *
*                                                                   *
* or:                                                               *
* disable_isr(INT_PPU_VBLANK_START);                                *
*                                                                   *
* Because the masking spans across more than 32 bits, there are 2   *
* actual interrupt masking registers (CTRL1/CTRL2) and so we need   *
* to just automatically account for this in the enable/disable ISR  *
* functions so that it's seamless.                                  *
*********************************************************************/

static inline unsigned int vector_to_source(unsigned int vector)
{
    return 63u - vector;
}

void enable_isr(unsigned int vector)
{
	// Disable interrupts
	asm("li r4, 0x0");
	asm("mtcr r4, cr0");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
    asm("nop");
		    
    unsigned int intr_src = vector_to_source(vector);

    // Unmask/Enable
    if (intr_src < 32) {
        *P_INT_MASK_CTRL1 &= ~(1u << intr_src);
    } else {
        *P_INT_MASK_CTRL2 &= ~(1u << (intr_src - 32u));
    }
    
    // Enable interrupts
	asm("li r4, 0x1");
	asm("mtcr r4, cr0");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
}

void disable_isr(unsigned int vector)
{
	// Disable interrupts
	asm("li r4, 0x0");
	asm("mtcr r4, cr0");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
    asm("nop");
		    
    unsigned int intr_src = vector_to_source(vector);

    // Mask/Disable
    if (intr_src < 32) {
        *P_INT_MASK_CTRL1 |= (1u << intr_src);
    } else {
        *P_INT_MASK_CTRL2 |= (1u << (intr_src - 32u));
    }
    
    // Enable interrupts
	asm("li r4, 0x1");
	asm("mtcr r4, cr0");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
}





