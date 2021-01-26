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
