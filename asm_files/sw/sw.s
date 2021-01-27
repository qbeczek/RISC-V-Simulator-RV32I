.section .text
         .align	4
         .global _start
_start:  
		li x1, 0x001
		li x2, 0x002
		li x3, 0x003
		li x4, 0x004
		sw x1, 0(x0) #test Zero
		sw x0, 0(x2) 
		sw x1, 4(x3)
		sw x2, 1(x5)
		sw x4, 28(x2)
		li x5, 0XFFFFFFF
		sw x5, 10(x5)
		sw x3, 31(x3)
