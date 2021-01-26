#include <stdio.h>

#include "types.h"
#include "mem_abs.h"

DataType IMM_WORD_ALIGNMENT(DataType BEFORE_WA){  //funkcja do rozszerzenia ze znakiem 
    
     if(((BEFORE_WA & 0x80000) >> 19) == 1) //jeli najstarszy bit z 20 bitowego wyrazenia IMM jest jedynka to powiela jedynke, jesli jest zerem to powiela zero od 20 do 32 bitu
         return 0xFFF00000 + BEFORE_WA; // 0xFFF00000 to 12 jedynek i 20 zer + BEFORE_WA - to wartosci pierwszych 20 bitow
     else return BEFORE_WA;
        
}

void F_JAL(void){
	writeOpcode();
    
    DataType RD = getRD();
    
    //składowe IMM - juz przesuniete, jeszcze nie dodane
    //DataType IMM_10_1 =  (getMEMC(getPC()) & 0x7FE00000) >> 21;
    //DataType IMM_11_ =  (getMEMC(getPC()) & 0x100000) >> 10;
    //DataType IMM_19_12 =  (getMEMC(getPC()) & 0xFF000) >> 1;
    //DataType IMM_20_ =  (getMEMC(getPC()) & 0x80000000) >> 12;
    
    DataType IMM20 = ((getMEMC(getPC()) & 0x7FE00000) >> 21) + ((getMEMC(getPC()) & 0x100000) >> 10) + ((getMEMC(getPC()) & 0xFF000) >> 1) + ((getMEMC(getPC()) & 0x80000000) >> 12);
    
    setRegister(RD, getPC() + 4);
    checkR0(RD);
    setPC(IMM_WORD_ALIGNMENT(IMM20) + getPC());
    printf("wynik JAL   RD%d    IMM20%d",RD ,IMM20 );
    
    
    
    //tu robie dalej MG
}
