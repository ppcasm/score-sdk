.extern main
.section .hardware_init,"ax",@progbits

.global _hardware_init
.ent _hardware_init
_hardware_init:
	
		

		la      r28, _gp
		
		la      r8, __bss_start
		la      r9, _bss_end__
		ldi     r10, 0
clear_bss_loop:
		sb		r10, [r8]+, 1
		cmp!	r8, r9
		ble!	clear_bss_loop
		nop
		
			mfcr r5, cr4
		nop
		li r7, 0x80
		andri r6, r5, 0x80
	
		cmp.c r7, r6
		bne under_wt
		nop
under_wb:
		la r7, tgl_wb
		cache 0x1f, [r7, 0]		
		nop
		nop
		nop
tgl_wb:
		cache 0x1d, [r7, 0]			
		nop
under_wt:							
                la r4, biu_wben
biu_wben:
		cache 0x1b, [r4, 0]
		
              
		la	r9, 0x88070060
		la r10, 0x95404b04
		sw r10, [r9, 0]
		
               
		la r0,_stack
		
              
		jl main
		nop
		
    
loop_to_self:
		j loop_to_self
		nop
		 
.end _hardware_init
