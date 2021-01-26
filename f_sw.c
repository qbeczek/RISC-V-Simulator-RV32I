#include <stdio.h>

#include "types.h"
#include "mem_abs.h"

void F_SW(void){
	writeOpcode();
    
    DataType RS1 = getRS1();
    DataType RS2 = getRS2();
    DataType IMM17 =((getMEMC(getPC()) & 0xF80) >> 7) + ((getMEMC(getPC()) & 0xFE000000) >> 20);
    
    setMEMD(getRegister(RS1), getRegister((int32_t)IMM17 + RS2));

    printf("0x%04x: SW R%d, R%d, R%d\n", getMEMD(), RS1, RS2, IMM17);
    // inkrementacja licznika rozkazow
    incPC();
}

