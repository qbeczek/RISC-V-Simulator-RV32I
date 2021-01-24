#include <stdio.h>

#include "types.h"
#include "mem_abs.h"

void F_ADD(void){
	writeOpcode();
	DataType RS1=(getMEMC(getPC()) & 0xF8000) >>15;
	DataType RS2=(getMEMC(getPC()) & 0x1F00000) >>20;

	printf("0x%04x: ADD R%d, R%d\n", getPC(), RS1, RS2);

    if((getRegister(RS1) + getRegister(RS2)) > MAX_DATA_VAL)
        setFlagsRegister(FLAG_C);                           //ustawienie flagi przeniesienia
    else
        resetFlagsRegister(FLAG_C);                         //wykasowanie flagi przeniesienia
        
    setRegister(RS1, (getRegister(RS1) + getRegister(RS2)) % MAX_DATA_VAL);    //właściwe obliczenie

    incPC();                                                //zwiększenie licznika rozkazów
}	