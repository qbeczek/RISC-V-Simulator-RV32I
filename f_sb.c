#include <stdio.h>

#include "types.h"
#include "mem_abs.h"

void F_SB(void)
{
	// 5-bit; 15-19
	DataType RS1=(getMEMC(getPC()) & 0x7C000) >>15;
	// 5-bit; 20-24
	DataType RS2=(getMEMC(getPC()) & 0xF80000) >>20;
	// 5-bit; 7-11
	DataType IMM5=(getMEMC(getPC()) & 0x7C0) >>7;
	// 7-bit; 25-31
	DataType IMM7=(getMEMC(getPC()) & 0xFE000000) >>7;

	printf("0x%04x: SB R%d, R%d\n", getPC(), RS1, RS2);

	// zapisz w pamięci pod efektywny adres wartość 8 bitową – używaj młodszych bitów z rs2
	// tu pewnie musze jeszcze przesunac o ten offset IMM12: IMM5 i IMM7 - moze getRegister(RS2 + IMM12)?
    setRegister(RS1, (getRegister(RS2)));

    incPC();
}