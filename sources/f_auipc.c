#include <stdio.h>

#include "types.h"
#include "mem_abs.h"

void F_AUIPC(void){
	//writeOpcode();
	DataType RD = getRD();
	DataType IMM20=(getMEMC(getPC()) & 0xFFFFF000) >>12;

	printf("0x%04x: AUIPC R%d, R%d\n", getPC(), RD, IMM20);
        
    setRegister(RD, (getPC() + (IMM20 << 12)));
    checkR0(RD);
    incPC();
}