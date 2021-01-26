#include <stdio.h>

#include "types.h"
#include "mem_abs.h"

void F_SB(void)
{
	// 5-bit; 15-19
	DataType RS1=(getMEMC(getPC()) & 0x7C000) >>15;
	// 5-bit; 20-24
	DataType RS2=(getMEMC(getPC()) & 0xF80000) >>20;

	// zapisz w pamięci pod efektywny adres wartość 8 bitową – używaj młodszych bitów z rs2
	// nie wiem czy to jest ok
    setRegister(RS1, (getRegister(RS2)));

    incPC();
}