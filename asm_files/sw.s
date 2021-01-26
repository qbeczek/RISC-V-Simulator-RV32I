.section .text
         .align	4
         .global _start
_start:  
		sw x1, 0(x5) # mem[x5 + offset] ←− x1