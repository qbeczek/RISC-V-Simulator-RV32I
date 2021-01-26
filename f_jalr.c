#include <stdio.h>

#include "types.h"
#include "mem_abs.h"

void F_JALR(void)
{
	writeOpcode();

	// 5-bit; 7-11
	DataType RD = getRD();
	// 5-bit; 15-19
	DataType RS1 = getRS1();
	// 12-bit; 20-31
	DataType IMM12=(getMEMC(getPC()) & 0xFFF00000) >>20;
    
    setRegister(RD, getPC() + 4);
    checkR0(RD);
    setPC(IMM_WORD_ALIGNMENT(IMM20) + getRegister(RS1));

	printf("0x%04x: JALR R%d, IMM12%d(R%d)\n", getPC(), RD, IMM12, RS1);
}
