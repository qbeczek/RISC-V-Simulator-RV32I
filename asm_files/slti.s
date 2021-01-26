.section .text
         .align	4
         .global _start
_start: 
		slti x0, x1, 1
		li x1, 0x02
		slti x2, x1, 0x01
		slti x3, x1, 0x03
		slti x4, x1, 0x02 # x5 ←− x1 < 2
		slti x5, x1, 0x00
		slti x6, x2, 0x111
		slti x7, x7, 0xF
		