.section .text
         .align	4
         .global _start
_start:  
		li x1, 0x01
		li x2, 0x02
		li x3, 0x03
		li x4, 0x04
		sb x0, 1(x1)	
		sb x5, 0(x2)
		sb x6, 1(x2)
		sb x7, 1(x4)
