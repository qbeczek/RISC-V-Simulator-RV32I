#include <stdio.h>

#include "types.h"
#include "mem_abs.h"

void F_LUI(void){
	 writeOpcode();
    
    DataType IMM12=(getMEMC(getPC()) & 0xFFFFF000) >>12;
    DataType RD = getRD();
    
    printf("0x%04x: LUI R%d, R%d\n", getPC(), RD, IMM12);
    
    setRegister(RD, IMM12 << 12);
    checkR0(RD);
    incPC();                                                //zwiększenie licznika rozkazów
    // jest git MG
    
}
