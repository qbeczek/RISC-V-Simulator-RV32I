#include <stdio.h>

#include "types.h"
#include "mem_abs.h"

void F_BNE(void){
	writeOpcode();
    
    DataType RS1 = getRS1();
    DataType RS2 = getRS2();
    //DataType IMM_B_type = ;
    
    
    //DataType
    //składowe IMM - juz przesuniete, jeszcze nie dodane
    //DataType IMM_10_1 =  (getMEMC(getPC()) & 0x7FE00000) >> 21;
    //DataType IMM_11_ =  (getMEMC(getPC()) & 0x100000) >> 10;
    //DataType IMM_19_12 =  (getMEMC(getPC()) & 0xFF000) >> 1;
    DataType IMM_20_ =  (getMEMC(getPC()) & 0x80000000) >> 12;
    
    
    incPC();                                                //zwiększenie licznika rozkazów
}
