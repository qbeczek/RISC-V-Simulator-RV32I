#include <stdio.h>

#include "types.h"
#include "mem_abs.h"

void F_SLL(void){
	writeOpcode();
	DataType RS1=(getMEMC(getPC()) & 0xF8000) >>15;
	DataType RS2=(getMEMC(getPC()) & 0x1F00000) >>20;

	printf("0x%04x: SLL R%d, R%d\n", getPC(), RS1, RS2);

	 setRegister(RS1, (getRegister(RS1) + getRegister(RS2)) % MAX_DATA_VAL);    //właściwe obliczenie

    incPC();                                                //zwiększenie licznika rozkazów
}