.section .text
         .align	4
         .global _start
_start:  
		sb x0, 1(x5)	
		sb x1, 2(x0)
		sb x2, 3(x1)