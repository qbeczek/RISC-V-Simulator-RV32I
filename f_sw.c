#include <stdio.h>

#include "types.h"
#include "mem_abs.h"

void F_SW(void){
	//writeOpcode();
    
    DataType RS1 = getRS1();
    DataType RS2 = getRS2();
    DataType IMM17 =((getMEMC(getPC()) & 0xF80) >> 7) + ((getMEMC(getPC()) & 0xFE000000) >> 20);
    
    // store value from RS1 to (R2 + IMM)
    setRegister((RS2) + (int32_t)IMM17, getRegister(RS1));

    printf("0x%04x: SW R%d, R%d, R%d\n", getPC(), RS1, RS2, IMM17);
    checkR0((RS2) + (int32_t)IMM17);
    // Increment Program Counter
    incPC();
}

