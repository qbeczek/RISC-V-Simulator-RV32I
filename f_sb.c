#include <stdio.h>

#include "types.h"
#include "mem_abs.h"

void F_SB(void)
{
//	writeOpcode();
	// 5-bit; 15-19
	DataType RS1 = getRS1(); //stary zapis JonczykPRO (getMEMC(getPC()) & 0x7C000) >>15;
	// 5-bit; 20-24
	DataType RS2 = getRS2(); //stary zapis JonczykPRO (getMEMC(getPC()) & 0xF80000) >>20;
	// 5-bit IMM5 + 7-bit IMM7
	DataType IMM12 = ((getMEMC(getPC()) & 0x7C0) >> 7) + ((getMEMC(getPC()) & 0xFE000000) >> 25);
	printf("0x%04x: SB R%d, IMM12%d(R%d)\n", getPC(), RS1, IMM12, RS2);
	

	setRegister(RS1, getRegister((int8_t)IMM12 + (RS2)));
	// IMM12 jako offset - adres RS2+IMM
	checkR0(RS1);
    incPC();
}
