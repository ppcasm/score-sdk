.extern main
.section .hardware_init,"ax",@progbits

.global _hardware_init
.ent _hardware_init
_hardware_init:
	////////////////////////////////////////////////////
	
	// Change exception vector base to 0xA0090000
	//	la    	r4, 0xa0090000
	//	mtcr    r4, cr3
	//	nop
	//	nop
	//	nop
	//	nop
	//	nop
		
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
		la	r9, 0x88070060
		la r10, 0x95404b04
		sw r10, [r9, 0]
		
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
