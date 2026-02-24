.extern main
.section .hardware_init,"ax",@progbits

.global _hardware_init
.ent _hardware_init
_hardware_init:

		j main
		nop
		
.end _hardware_init
