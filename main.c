#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "mem_abs.h"
#include "merror.h"
#include "opcodes.h" //wzorce i naglowki opcodow

void merror(int i, int j){
    printf("ERROR code: 0x%08lx with arg. 0x%08lx at PC=0x%08lx\r\n", i, j, getPC());
    saveMEMD("test\\file_data_out.bin");      //zapisz zawartość pamięci danych do pliku
    saveREGS("test\\file_reg_out.bin");       //zapisz zawartość rejestrów i PC do pliku
    exit(-1);
}

int main(void){
    CodeType T;                         //zmienna pomocnicza
    loadMEMC("test\\file_code.bin");          //ładowanie pamięci kodu z pliku 
    loadMEMD("test\\file_data_in.bin");       //ładowanie pamięci danych z pliku
    loadREGS("test\\file_reg_in.bin");        //ładowanie stanu rejestrów z pliku
    setPC(0x00000000);                      //Warunki początkowe PC (RESET)
    for(;;){
        T=getMEMC(getPC());            //T=ID operacji i arg. wbudowanych
        switch(T & 0x0000007F){      //wyłuskanie właściwego kodu operacji OPCODE
            case OP_LUI:      
                F_LUI();
                break;
            case OP_JAL:      
                F_JAL();
                break;
            case OP_AUIPC:				
            	F_AUIPC();
            	break;
            case OP_JALR:
            	F_JALR();
            	break;
            case OP_BNE:
            	F_BNE();
            	break;
            default:
            	switch((T & 0x0000007F) + ((T & 0x000007000)>>4)){ //wyłuskanie właściwego kodu operacji OPCODE + FUNCT3
            		case F3_SW:
            			F_SW();
            			break;
            		case F3_SLL:
            			F_SLL();
            			break;
            		case F3_ADD:
            			F_ADD();
            			break;
            		case F3_SLTI:
            			F_SLTI();
            			break;
            		case F3_SB:
            			F_SB();
            			break;
            		case F3_ADDI:
            			F_ADDI();
            			break;
            		default:
            			printf("Wykryto nieznana instrukcje (PC=0x%08lx, T=0x%08lx)\r\n", getPC(), T);
                		saveMEMD("test\\file_data.bin");      //zapisz zawartość pamieci danych do pliku
                		saveREGS("test\\file_reg_out.bin");   //zapisz zawartość rejestrów i PC do pliku 
                		return -1;
            		}
            	}
    }
    saveMEMD("test\\file_data_out.bin");      //zapisz zawartość pamięci danych do pliku
    saveREGS("test\\file_reg_out.bin");       //zapisz zawartość rejestrów i PC do pliku
    return 0;
}
