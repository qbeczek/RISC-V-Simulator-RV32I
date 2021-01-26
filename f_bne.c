#include <stdio.h>

#include "types.h"
#include "mem_abs.h"


DataType IMM_WORD_ALIGNMENT(DataType BEFORE_WA){  //funkcja do rozszerzenia ze znakiem

 if(((BEFORE_WA & 0x1000) >> 12) == 1) //jeli najstarszy bit z 13 bitowego wyrazenia IMM jest jedynka to powiela jedynke, jesli jest zerem to powiela zero od 13 do 31 bitu
     return 0xFFFFE000 + BEFORE_WA; // 0xFFFFE000 to 19 jedynek i 13 zer + BEFORE_WA - to wartosci pierwszych 13 bitow
 else return BEFORE_WA;

    
void F_BNE(void){
	writeOpcode();
    
    DataType RS1 = getRS1();
    DataType RS2 = getRS2();
    DataType IMM_B_type = ((getMEMC(getPC()) & 0xF00) >> 7) + ((getMEMC(getPC()) & 0x7E000000) >> 20 ) + ((getMEMC(getPC()) & 0x80) << 4 ) + ((getMEMC(getPC()) & 0x80000000) >> 19 );
    
    //pojedyncze przesuniecia
    //imm[0]=0 domyslnie bit zerowy jest zerem - zatem imm ma 13 bitow
    //DataType IMM_B_type_4_1 = ((getMEMC(getPC()) & 0xF00) >> 7) ;
    //DataType IMM_B_type_10_5 =((getMEMC(getPC()) & 0x7E000000) >> 20 );
    //DataType IMM_B_type_11 =((getMEMC(getPC()) & 0x80) << 4 );
    //DataType IMM_B_type_12 =((getMEMC(getPC()) & 0x80000000) >> 19 );
    
    if (getRegister(RS1) != getRegister(RS2)){
        setPC(IMM_WORD_ALIGNMENT(IMM_B_type) + getPC());
    }
    else {
        incPC();                                                //zwiększenie licznika rozkazów
    }

}
