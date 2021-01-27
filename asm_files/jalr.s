.section .text
         .align	4
         .global _start
_start:
		li x1, 0x01
		jalr x11, 0(x1)
_funct1:
_end:
		nop