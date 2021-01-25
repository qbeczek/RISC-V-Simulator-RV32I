#include <stdio.h>
#include "types.h"
#include "mem_abs.h"

void F_ADDI(void)
{
	// maska 0xFFF00000 - jedynki na bitach, na których nam zalezy
	// tyle jedynek, jaka jest dl. zmiennej
	// przesuniecie bitowe >>20 bo pierwszy bit na 20-tym miejscu
	writeOpcode();
	// 5-bit
	DataType RS1=(getMEMC(getPC()) & 0xF8000) >>15;
	// 12-bit
	DataType IMM12=(getMEMC(getPC()) & 0xFFF00000) >>20;
	// 5-bit
	DataType RD=(getMEMC(getPC()) & 0xF80) >>7;

	printf("0x%04x: ADD R%d, R%d, R%d\n", getPC(), RD, RS1, IMM12);
	if(getRegister(RS1) + getRegister(IMM12) > MAX_DATA_VAL)
        setFlagsRegister(FLAG_C);
    else
        resetFlagsRegister(FLAG_C);
        
    setRegister(RD, (getRegister(RS1) + getRegister(IMM12)) % MAX_DATA_VAL);

    incPC();
}