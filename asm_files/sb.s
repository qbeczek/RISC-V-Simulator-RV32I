.section .text
         .align	4
         .global _start
_start:  
		li x1, 0x111
		li x2, 0x222
		li x3, 0x333
		li x4, 0x444
		sb x0, 1(x2) # test0
		sb x5, 1(x1)
		li x10, 0x3DAB
		sb x11, 0(x10)
		sb x10, 0(x0)
		sb x30, 3(x1)
		sb x31, 10(x1)
