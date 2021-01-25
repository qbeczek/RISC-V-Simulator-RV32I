#include <stdio.h>

#include "types.h"
#include "mem_abs.h"

void F_AUIPC(void){
	writeOpcode();
	DataType RD =(getMEMC(getPC()) & 0xF80) >> 7;
	
}