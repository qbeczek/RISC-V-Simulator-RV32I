.section .text
         .align	4
         .global _start
_start:  
		 addi x0, x0, 0x001 #przewidywanie w x0 0
		 addi x1, x0, 0x001 #przewidywanie w x1 1
		 addi x2, x0, 0x002 #przewidywanie w x2 2
		 addi x3, x1, -0x001 #przewidywanie w x3 0
		 addi x4, x1, -0x005 #przewidywanie w x4 -5
		 addi x5, x4, 0x005 #przewidydywanie w x5 0 
		 addi x6, x0, 0x7FF #przewidydywanie w x6 MAX_WARTOSC 
		 addi x7, x0, -0x800 #przewidydywanie w x7 MIN_WARTOSC
	     addi x8, x6, 0x7FF #0 MAX MAX
	     addi x9, x8, 0x001
	     addi x10, x7, -0x800 #0 MIN MIN
	     addi x11, x10, 0x001
	     addi x25, x0, 0x001
	     addi x26, x25, 0x001
	     addi x27, x26, 0x001
	     addi x28, x27, 0x001
	     addi x29, x28, 0x001 
	     addi x30, x29, 0x001
 		 addi x31, x0, 0x7FF
 		 
