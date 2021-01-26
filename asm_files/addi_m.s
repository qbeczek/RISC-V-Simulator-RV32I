# ADDI adds 12 bit signed immediate to value in register
# For 12 bit signed immediate possible values are [0x7FF(2047) - 0x800(-2048)]

.data
	.align	4

.text
     .align	4
     .global _start

_start:
	# We expect 0 as result of every operation on x0
	addi x0, x0, 0x7FF
	# Max positive value
	addi x1, x1, 0x7FF
	# Min negative value (x2 = 0xFFFFF800 expected)
	addi x2, x2, -0x800
	# Positive value
	addi x3, x3, 0x0A5
	# Negative value (x4 = 0xFFFFFF5B expected)
	addi x4, x4, -0x0A5
	# Add two registers (x5 = 0x00000010, x6 = 0x09 expected)
	addi x5, x5, 0
	addi x6, x6, 0x09
	addi x5, x6, 0x07
	# Add max value to max value
	addi x7, x7, 0x7FF
	addi x7, x7, 0x7FF
		# and add 0x002 to overflow 12bits (x7 = 0x00001000 expected)
	addi x7, x7, 0x002
	# Add max positive and min negative values (x9 = 0 expected)
	addi x8, x1, 0
	addi x9, x8, -0x800
		# and overflow to downside (x10 = 0xFFFFF000 expected)
	addi x10, x9, 0
	addi x10, x10, -0x800
	addi x10, x10, -0x800
	addi x10, x10, 0x001
	# Whole word overflow (x11 = 0xFFFFFFFF)
	lui x11, 0xFFFFF
	addi x11, x11, 0x7FF
	addi x11, x11, 0x7FF
		# To the upside (x12 = 0, x13 = 0x00000001)
	addi x11, x11, 0x001
	addi x12, x11, 0
	addi x12, x12, 0x001
	addi x13, x11, 0
	addi x13, x13, 0x002
		# And to the downside (x14 = 0xFFFFFFFF)
	addi x14, x0, 0
	addi x14, x14, -1

