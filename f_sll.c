#include <stdio.h>

#include "types.h"
#include "mem_abs.h"

void F_SLL(void){
	writeOpcode();
	DataType RS1 = getRS1();
	DataType RS2 = getRS2();
    DataType RD = getRD();

	printf("0x%04x: SLL R%d, R%d, R%d\n", getPC(), RD, RS1, RS2);

	setRegister(RD, (getRegister(RS1) << getRegister(RS2)));    //właściwe obliczenie
	checkR0(RD);
    incPC();                                                //zwiększenie licznika rozkazów
}
