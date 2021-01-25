#include <stdio.h>

#include "types.h"
#include "mem_abs.h"

void F_ADDI(void)
{
	// maska 0xFFF00000 - jedynki na bitach, na których nam zalezy
	// tyle jedynek, jaka jest dl. zmiennej
	// przesuniecie bitowe >>20 bo pierwszy bit na 20-tym miejscu
	writeOpcode();
	DataType RS1=(getMEMC(getPC()) & 0xF8000) >>15;
	DataType IMM12=(getMEMC(getPC()) & 0xFFF00000) >>20;
	DataType RD=(getMEMC(getPC()) & 0xF80) >>7;

}