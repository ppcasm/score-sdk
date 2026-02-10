////////////////////////////////////////////////////
// Definition of registers
#define    SP        r0
#define    AT        r1
#define    BP        r2
#define    LR        r3
#define    A0        r4
#define    A1        r5
#define    A2        r6
#define    A3        r7
#define    T0        r8
#define    T1        r9
#define    T2        r10
#define    T3        r11
#define    S0        r12
#define    S1        r13
#define    S2        r14
#define    S3        r15
#define    S4        r16
#define    S5        r17
#define    S6        r18
#define    S7        r19
#define    S8        r20
#define    S9        r21
#define    T4        r22
#define    T5        r23
#define    T6        r24
#define    T7        r25
#define    T8        r26
#define    T9        r27
#define    R28       r28
#define    JP        r29
#define    K0        r30
#define    K1        r31

// CP0 register define
#define CP0_STATUS   cr0
#define CP0_COND     cr1
#define CP0_CAUSE    cr2
#define CP0_EPC      cr5
#define CP0_EXCPVEC  cr3
#define CP0_CCR      cr4
#define CP0_BADVA    cr6
#define CP0_WIRE     cr7
#define CP0_INDEX    cr8
#define CP0_CONTEXT  cr9
#define CP0_RANDOM   cr10
#define CP0_ENTRYHI  cr11
#define CP0_ENTRYLO  cr12
#define CP0_FMARLO   cr13
#define CP0_FMARHI   cr14
#define CP0_FMCR     cr15
#define CP0_FFMR     cr16
#define CP0_LLADDR   cr17
#define CP0_PREV     cr18
#define CP0_DREG     cr29
#define CP0_DEPC     cr30
#define CP0_DSAVE    cr31
#define SPR_HI       sr1
#define SPR_LO       sr2
#define SR_CNT       sr0
#define SR_LCR       sr1
#define SR_SCR       sr2

//=========================================================
// startup code for standard project
//=========================================================
.extern main
.section .hardware_init,"ax",@progbits
.global _hardware_init
.ent _hardware_init
_hardware_init:
		
		// Set up gp
		la      r28, _gp
		
		// Init/Clear BSS segment
		la      r8, __bss_start
		la      r9, _bss_end__
		ldi     r10, 0
clear_bss_loop:
		sb		r10, [r8]+, 1
		cmp!	r8, r9
		ble!	clear_bss_loop
		nop
		
		// Disable write back data cache
		mfcr r5, cr4
		nop
		li r7, 0x80
		andri r6, r5, 0x80
		
		// Check under WB mode
		cmp.c r7, r6
		bne under_wt
		nop
under_wb:
		la r7, tgl_wb
		cache 0x1f, [r7, 0]			//	force write out dirty entry and set invalid
		nop
		nop
		nop
tgl_wb:
		cache 0x1d, [r7, 0]			//	toggle write-back function
		nop
under_wt:							//	Processor is under write-through mode

		// Enable BIU Write buffer
		la r4, biu_wben
biu_wben:
		cache 0x1b, [r4, 0]
		
		// Setup SDRAM
		//la	r9, 0x88070060
		//la r10, 0x95404b04
		//sw r10, [r9, 0]
		
		// Setup stack pointer
		la r0,_stack
		
		// void main();
		jl main
		nop
		
		// Hang if we return from main, but later we will have it
		// go back to the firmware
loop_to_self:
		j loop_to_self
		nop
		 
.end _hardware_init

