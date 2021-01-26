#include <stdio.h>

#include "types.h"
#include "mem_abs.h"

void F_AUIPC(void){
	writeOpcode();
	DataType RD = getRD();
	DataType IMM12=(getMEMC(getPC()) & 0xFFFFF000) >>12;

	printf("0x%04x: AUIPC R%d, R%d\n", getPC(), RD, IMM12);
        
    setRegister(RD, (getPC() + (IMM12 << 12)));
    checkR0(RD);
    incPC();
}
