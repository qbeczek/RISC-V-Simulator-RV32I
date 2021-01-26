#include <stdio.h>
#include <stdlib.h>

#include "merror.h"
#include "types.h"

CodeType    MEMC[MAX_ADDRESS+1];    //obszar pamiêci kodu 
DataType    MEMD[MAX_ADDRESS+1];    //obszar pamiêci danych
DataType    REG[MAX_REGISTER+1];    //deklaracja przechowywania rejestrów

AddressType   PC;                   //licznik rozkazów
DataType    FLAGS;                  //flagi procesora

void loadMEMC(char *file){          //£adowanie pamiêci kodu z pliku 
    FILE *file_ptr;
    file_ptr=fopen(file, "rb");
    if(!file_ptr){
        printf("MEMC file not found (%s)!\n", file);
        exit(-2);
    }
    fseek(file_ptr, 0, SEEK_SET);
    fread(MEMC, MAX_ADDRESS+1, 1, file_ptr);
    fclose(file_ptr);
}

void loadMEMD(char *file){        //£adowanie pamiêci danych z pliku
    FILE *file_ptr;
    file_ptr=fopen(file, "rb");
    if(!file_ptr){
        printf("MEMD file not found (%s)!\n", file);
        exit(-3);
    }    
    fseek(file_ptr, 0, SEEK_SET);
    fread(MEMD, MAX_ADDRESS+1, 1, file_ptr);
    fclose(file_ptr);
}

void loadREGS(char *file){        //£adowanie stanu rejestrów i PC z pliku
    FILE *file_ptr;
    file_ptr=fopen(file, "rb");
    if(!file_ptr){
        printf("MEMD file not found (%s)!\n", file);
        exit(-3);
    }    
    fseek(file_ptr, 0, SEEK_SET);
    fread(REG, MAX_REGISTER+1, 1, file_ptr);        //Ladowanie stanu rejestrów
    fread(&PC, sizeof(AddressType), 1, file_ptr);   //Ladowanie stanu PC (w pliku jest za kopia rejestrów)
    fread(&FLAGS, sizeof(DataType), 1, file_ptr);   //Ladowanie stanu rejestru floagowe (w pliku jest za kopia PC)
    fclose(file_ptr);
}

void saveMEMD(char *file){        //zapisz zawartoœæ pamiêci danych do pliku 
    FILE *file_ptr;
    file_ptr=fopen(file, "wb");
    if(!file_ptr){
        printf("MEMD cannot open to write (%s)!\n", file);
        exit(-3);
    }    
    fseek(file_ptr, 0, SEEK_SET);
    fwrite(MEMD, MAX_ADDRESS+1, 1, file_ptr);
    fclose(file_ptr);
}

void saveREGS(char *file){        //zapisz zawartoœæ rejestrów i PC do pliku 
    FILE *file_ptr;
    file_ptr=fopen(file, "wb");
    if(!file_ptr){
        printf("MEMD cannot open to write (%s)!\n", file);
        exit(-3);
    }    
    fseek(file_ptr, 0, SEEK_SET);
    fwrite(REG, sizeof(DataType), MAX_REGISTER+1, file_ptr);
    fwrite(&PC, sizeof(AddressType), 1, file_ptr);
//  fwrite(&FLAGS, sizeof(DataType), 1, file_ptr);
    fclose(file_ptr);
}

CodeType getMEMC(AddressType p){
    if(p/4>MAX_ADDRESS)               //Czy odwolanie nie siega poza pamiec kodu
        merror(OUT_OF_CODE_MEMORY_SPACE_ERROR, p);
    return MEMC[p/4];
}

DataType getMEMD(AddressType p){
    if(p>MAX_ADDRESS)               //Czy odwolanie nie siega poza pamiec danych
        merror(OUT_OF_DATA_MEMORY_SPACE_ERROR, p);
    return MEMD[p];
}

void setPC(AddressType v){
    PC=v;
}

AddressType getPC(void){
    return PC;
}

void incPC(void){
    PC+=4;
}

DataType getRegister(DataType n){
    if(n>MAX_REGISTER)               //Czy odwolanie nie siega poza zdefiniowany zestaw rejestrow
        merror(INVALID_REGISTER_GET, n);
    return REG[n];
}

void setRegister(DataType n, DataType v){
    if(n>MAX_REGISTER)               //Czy odwolanie nie siega poza zdefiniowany zestaw rejestrow
        merror(INVALID_REGISTER_SET, n);
    REG[n]=v;
}

void setFlagsRegister(int b){
    if(b>sizeof(DataType))               //Czy odwolanie nie siega poza zdefiniowana szrekosc rejestru flagowego
        merror(INVALID_SET_OF_FLAGS_BIT, b);
    FLAGS = FLAGS | (1<<b);
}

void resetFlagsRegister(int b){
    if(b>sizeof(DataType))               //Czy odwolanie nie siega poza zdefiniowana szrekosc rejestru flagowego
        merror(INVALID_RESET_OF_FLAGS_BIT, b);
    FLAGS = FLAGS & (~(1<<b));
}

int getFlagsRegister(int b){
    if(b>sizeof(DataType))               //Czy odwolanie nie siega poza zdefiniowana szrekosc rejestru flagowego
        merror(INVALID_GET_OF_FLAGS_BIT, b);
    return FLAGS & (1<<b);
}


DataType getRD(void){
   return (getMEMC(getPC()) & 0xF80) >> 7;
}

DataType getRS1(void){
    return (getMEMC(getPC()) & 0xF8000) >>15;
}

DataType getRS2(void){
    return (getMEMC(getPC()) & 0x1F00000) >> 20;
}

void checkR0(DataType RD){
	if(RD == 0){
		setRegister(RD, 0);
    } 
}

void writeOpcode(void){
	CodeType T; 
	T=getMEMC(getPC());
    T = (T & 0x0000007F) + ((T & 0x000007000)>>4);
    printf("0x%04x\n", T);
   
}
