#include <stdio.h>

#include "types.h"
#include "mem_abs.h"

void F_SW(void){
	writeOpcode();
    
    DataType RS1 = getRS1();
    DataType RS2 = getRS2();
    DataType IMM17 =((getMEMC(getPC()) & 0xF80) >> 7) + ((getMEMC(getPC()) & 0xFE000000) >> 20);
    
    printf("0x%04x: SW R%d, R%d, R%d\n", getPC(), RS1, RS2, IMM17);
    
    // tu robie dalej MG!!!!
    
    incPC();                                                //zwiększenie licznika rozkazów
    
}

