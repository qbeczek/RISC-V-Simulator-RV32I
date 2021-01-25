#include <stdio.h>

#include "types.h"
#include "mem_abs.h"

void F_ADD(void){
	writeOpcode();
	DataType RS1=(getMEMC(getPC()) & 0xF8000) >> 15;
	DataType RS2=(getMEMC(getPC()) & 0x1F00000) >> 20;
    DataType RD =(getMEMC(getPC()) & 0xF80) >> 7;

	printf("0x%04x: ADD R%d, R%d, R%d\n", getPC(), RD, RS1, RS2);

    setRegister(RD, (getRegister(RS1) + getRegister(RS2)));    //właściwe obliczenie

    incPC();                                                //zwiększenie licznika rozkazów
}