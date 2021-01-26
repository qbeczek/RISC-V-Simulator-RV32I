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
	
    // 5-bit; 7-11
	DataType IMM5=(getMEMC(getPC()) & 0x7C0) >>7;
	// 7-bit; 25-31
	DataType IMM7=(getMEMC(getPC()) & 0xFE000000) >> 25;

	DataType IMM12 = (IMM5 + IMM7);

	// IMM12 jako offset
	printf("0x%04x: SB R%d, R%d(R%d)\n", getPC(), RS1, IMM12, RS2);

    setRegister(RS1, (getRegister(RS2 + IMM12)));
    checkR0(RS1);
    incPC();
}
