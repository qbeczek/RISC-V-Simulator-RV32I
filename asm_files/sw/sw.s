.section .text
         .align	4
         .global _start
_start:  
		li x1, 0x00000001
		li x2, 0x00000002
		li x3, 0x12DEF001
		li x4, 0xEFFF200F
		sw x0, 0(x2) #test 0
		sw x5, 0(x1)
		sw x6, 0(x2)
		sw x7, 0(x3)
		sw x8, 0(x4)
		sw x9, 1(x1)
		sw x10, 3(x3)
		sw x18, 5(x4)
		sw x29, 2(x4)
		sw x31, 1(x2)