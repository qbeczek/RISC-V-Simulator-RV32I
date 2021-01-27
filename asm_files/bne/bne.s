.section .text
         .align	4
         .global _start
_start: 
		li x1, 0x01
		li x2, 0x02
		li x3, 0xFF
		li x4, 0xFF
		bne x1, x2, _funct1
		nop 
_funct1:
		nop
		addi x1, x1, 0x02
		nop
		bne x3, x4, _funct2
		bne x1, x3, _funct3
_funct2:
		li x5, 0x2
_funct3:
		li x5, 0x1
		li x29, -0x800
		li x30, 0xFFF
		nop
		bne x30, x29, _funct4
_funct4:
		li x31, 0x01
		