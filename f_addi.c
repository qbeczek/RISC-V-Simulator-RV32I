#include <stdio.h>
#include "types.h"
#include "mem_abs.h"

void F_ADDI(void)
{
	//writeOpcode();
	DataType RD = getRD();
	DataType RS1 = getRS1();
	DataType IMM12=(getMEMC(getPC()) & 0xFFF00000) >>20;
	
	printf("0x%04x: ADDI R%d, R%d, R%d\n", getPC(), RD, RS1, IMM12);

    setRegister(RD, (getRegister(RS1) + IMM12));
    checkR0(RD);
    incPC();
}
