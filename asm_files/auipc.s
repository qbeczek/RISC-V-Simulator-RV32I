.section .text
         .align	4
         .global _start
_start:  
		# We expect 0 as result of every operation on x0
		auipc x0, 0xFFFFF
	# Max positive value
		auipc x1, 0xFFFFF
	# Positive value
		auipc x2, 0xF1D6C
		auipc x3, 0x00200
		auipc x4, 0x0125D
