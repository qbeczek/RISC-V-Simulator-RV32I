.section .text
         .align	4
         .global _start
_start: 
		slti x0, x1, 1
		slti x1, x0, 1
		slti x2, x3, 0x111
		slti x3, x1, 0
		slti x4, x1, 2 # x5 ←− x1 < 2
		slti x5, x1, 0
		slti x6, x2, 0x111
		slti x7, x7, 0xF