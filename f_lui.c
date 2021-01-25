#include <stdio.h>

#include "types.h"
#include "mem_abs.h"

void F_LUI(void){
	 writeOpcode();
    
    DataType IMM12=(getMEMC(getPC()) & 0xFFFFF000) >>12;
    DataType RD=(getMEMC(getPC()) & 0xF80) >>7;
}
