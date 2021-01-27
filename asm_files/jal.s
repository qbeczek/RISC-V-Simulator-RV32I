.section .text
         .align	4
         .global _start
 _start:
 		li x1, 0x0
 		jal x11, _funct2
 _funct1:
 		li x2, 0x1
 		jal x12, _funct5
 _funct2:
 		li x3, 0x2
 		jal x13, _funct4
 _funct3:
 		li x4, 0x3
 		jal x14, _funct1
 _funct4:
 		li x5, 0x4
 		jal x15, _funct3
 _funct5:
 		nop
