#include <stdio.h>

#include "types.h"
#include "mem_abs.h"

void F_SW(void){
	writeOpcode();
    
    DataType RS1=(getMEMC(getPC()) & 0xF8000) >> 15;
    DataType RS2=(getMEMC(getPC()) & 0x1F00000) >> 20;
    DataType imm =((getMEMC(getPC()) & 0xF80) >> 7) + ((getMEMC(getPC()) & 0xFE000000) >> 20);
    
}

