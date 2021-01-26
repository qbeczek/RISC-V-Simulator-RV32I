#include <stdio.h>

#include "types.h"
#include "mem_abs.h"

void F_SB(void)
{
	writeOpcode();
	// 5-bit; 15-19
	DataType RS1 = getRS1(); //stary zapis JonczykPRO (getMEMC(getPC()) & 0x7C000) >>15;
	// 5-bit; 20-24
	DataType RS2 = getRS2(); //stary zapis JonczykPRO (getMEMC(getPC()) & 0xF80000) >>20;
	
	// 5-bit IMM5 + 7-bit IMM7
	DataType IMM12 = ((getMEMC(getPC()) & 0x7C0) >> 7) + ((getMEMC(getPC()) & 0xFE000000) >> 25);

	// setRegister(RS1, (getRegister(RS2 + (int8_t)IMM12)));
	// checkR0(RS1);

	setMEMD(getRegister(RS1), getRegister((int8_t)IMM12 + (RS2)));
	// IMM12 jako offset - adres RS2+IMM
	printf("0x%04x: SB R%d, IMM12%d(R%d)\n", getMEMD(), RS1, IMM12, RS2);
    incPC();
}
