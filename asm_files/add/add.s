.data 
	.align 4
.text 
	.align	4
	.global _start
_start: 
	li x1, 0x111
	li x2, 0x7FF
	add x0, x1, x2 #expect 0
	li x3, 0x001
	li x4, 0x001
	add x5, x3, x4 #expect 2
	li x6, 0x7FF
	li x7, 0x7FF
	add x8, x6, x7 #expect 0xFFE
	li x9, -0x800
	li x10, -0x800
	add x11, x9, x3 
	add x12, x10, x9
	add x13, x7, x0
	add x14, x7, x3
	li x28, 0x002 
	li x29, 0x13D
	add x30, x29, x28
	add x31, x29, x10
