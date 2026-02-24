.extern _start
.section .hardware_init,"ax",@progbits

.global _hardware_init
.ent _hardware_init
_hardware_init:
		
		// Setup SDRAM
		la	r9, 0x88070060
		la r10, 0x95404b04
		sw r10, [r9, 0]
		
		la r0,_stack

		j _start

.end _hardware_init

