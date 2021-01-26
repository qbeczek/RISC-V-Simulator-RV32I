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
	DataType RD = getRD();
	DataType RS1 = getRS1();
	// 12-bit
	DataType IMM12=(getMEMC(getPC()) & 0xFFF00000) >>20;
	// 5-bit
	
	printf("0x%04x: ADDI R%d, R%d, R%d\n", getPC(), RD, RS1, IMM12);
	
    if(RD == 0){
    	setRegister(RD, 0);
    } else {
    	setRegister(RD, (getRegister(RS1) + IMM12));
	}
    
    incPC();
}
