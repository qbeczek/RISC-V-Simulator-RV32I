#include <stdio.h>

#include "types.h"
#include "mem_abs.h"

void F_SLTI(void){
	//writeOpcode();
	DataType RS1 = getRS1();
	DataType IMM12=(getMEMC(getPC()) & 0xFFF00000) >>20;
	DataType RD = getRD();

	printf("0x%04x: SLTI R%d, R%d, R%d\n", getPC(), RD, RS1, IMM12);
	
	if(getRegister(RS1) > IMM12){
		 setRegister(RD, 0x00000001);
	}	else{
		 setRegister(RD, 0x00000000);
	}
	checkR0(RD);
	incPC();
}
