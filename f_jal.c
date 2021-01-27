#include <stdio.h>

#include "types.h"
#include "mem_abs.h"

DataType IMM_WORD_ALIGNMENT_jal(DataType BEFORE_WA){  //funkcja do rozszerzenia ze znakiem 
    
     if(((BEFORE_WA & 0x100000) >> 20) == 1) //jeli najstarszy bit z 21 bitowego wyrazenia IMM jest jedynka to powiela jedynke, jesli jest zerem to powiela zero od 20 do 32 bitu
         return 0xFFE00000 + BEFORE_WA; // 0xFFF00000 to 12 jedynek i 20 zer + BEFORE_WA - to wartosci pierwszych 20 bitow
     else return BEFORE_WA;
}

void F_JAL(void){
	writeOpcode();
    
    DataType RD = getRD();
    
    //składowe IMM - bit zerowy IMM jest domniemany i zostawiamy tam wartosc 0
    //DataType IMM_10_1 =  (getMEMC(getPC()) & 0x7FE00000) >> 20;
    //DataType IMM_11_ =  (getMEMC(getPC()) & 0x100000) >> 9;
    //DataType IMM_19_12 =  (getMEMC(getPC()) & 0xFF000);
    //DataType IMM_20_ =  (getMEMC(getPC()) & 0x80000000) >> 11;
    
    DataType IMM20 = ((getMEMC(getPC()) & 0x7FE00000) >> 20) + ((getMEMC(getPC()) & 0x100000) >> 9) + (getMEMC(getPC()) & 0xFF000) + ((getMEMC(getPC()) & 0x80000000) >> 11);
    
    setRegister(RD, getPC() + 4);
    checkR0(RD);
    setPC(IMM_WORD_ALIGNMENT_jal(IMM20) + getPC());
    printf("wynik JAL   RD%d    IMM20%d",RD ,IMM20 );
}
