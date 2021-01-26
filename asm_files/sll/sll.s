.section .text
         .align	4
         .global _start
_start:  
		li x1, 0x001
		li x2, 0x002
		sll x0, x2, x1
		li x3, 0x010
		sll x4, x3, x1
		li x5, 0xFFF
		li x6, 0x12D
		sll x7, x5, x1
		sll x8, x6, x2
		sll x9, x2, x6
		li x14, 0x123
		sll x28, x1, x5
		sll x29, x14, x1
		sll x30, x13, x5
		sll x31, x5, x5
