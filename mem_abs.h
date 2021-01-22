#ifndef __MEM_ABS_H__
#define __MEM_ABS_H__

void loadMEMC(char *file);
void loadMEMD(char *file);
void loadREGS(char *file);
void saveMEMD(char *file);
void saveREGS(char *file);

CodeType getMEMC(AddressType p);
DataType getMEMD(AddressType p);

void setPC(AddressType v);
AddressType getPC(void);
void incPC(void);

DataType getRegister(int n);
void setRegister(int n, DataType v);

void setFlagsRegister(int b);
void resetFlagsRegister(int b);
int getFlagsRegister(int b);

#endif //__MEM_ABS_H__
