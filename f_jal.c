#include <stdio.h>

#include "types.h"
#include "mem_abs.h"

void F_JAL(void){
	writeOpcode();
    
    DataType RD=(getMEMC(getPC()) & 0xF80) >>7;
    //tu robie dalej MG
}
