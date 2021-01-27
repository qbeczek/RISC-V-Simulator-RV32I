.section .text
         .align	4
         .global _start
_start: 
		slti x0, x1, 1
		li x1, 0x02
		slti x2, x1, 0x01
		slti x3, x1, 0x03
		li x4, 0x1F
		li x5, 0x00
		slti x6, x4, 0x1F
		slti x7, x4, 0x00
		slti x8, x5, 0x1F
		slti x9, x5, 0x00
		li x25, 0xEFFFFFFF
		li x26, 0xFFFFFFFF
		slti x27, x25, 0xFFFFFFFF
		slti x28, x25, 0x00
		slti x29, x26, 0x011
		slti x30, x26, 0x00
		slti x31, x26, 0xFFFFFFFF
