#include <stdio.h>

#include "types.h"
#include "mem_abs.h"

void F_SLTI(void){
	writeOpcode();
	// 5-bit
	DataType RS1=(getMEMC(getPC()) & 0xF8000) >>15;
	// 12-bit
	DataType IMM12=(getMEMC(getPC()) & 0xFFF00000) >>20;
	// 5-bit
	DataType RD=(getMEMC(getPC()) & 0xF80) >>7;

	printf("0x%04x: ADD R%d, R%d, R%d\n", getPC(), RD, RS1, IMM12);
	if(RS1 > IMM12){
		 setRegister(RD, 0x00000001);
	}	else{
		 setRegister(RD, 0x00000000);
	}
	incPC();
}