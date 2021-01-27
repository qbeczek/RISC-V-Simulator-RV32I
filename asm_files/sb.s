.section .text
         .align	4
         .global _start
_start:  
		li x1, 0x001
		li x2, 0x00000002
		li x3, 0x12DEF001
		li x4, 0xEFFF200F
		sb x0, 1(x4)	
		sb x5, 2(x2)
		sb x6, 3(x2)
