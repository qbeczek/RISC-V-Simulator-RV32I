#ifndef __OPCODES_H__
#define __OPCODES_H__

//wzorce opcodow 
#define OP_LUI					0x37
#define OP_JAL					0x6F
#define OP_AUIPC				0x17
#define OP_JALR					0x67
#define OP_BNE					0x63

//type S
#define OP_SW					0x23 
#define OP_SB					0x23

//type R
#define OP_SLL					0x33
#define OP_ADD 					0x33

//type I
#define OP_SLTI					0x13
#define OP_ADDI					0x13

//wzorce OP + FUNCT3
#define F3_SW					0x0223
#define F3_SLL					0x0133
#define F3_ADD 					0x0033
#define F3_SLTI					0x0213
#define F3_SB					0x0023
#define F3_ADDI					0x0013

//wzorce OP + FUNCT3 + FUNCT7
#define F7_SLL					0x000133
#define F7_ADD					0x000033
//...

//naglowki funkcji dla poszczegolnych opcodow 
void F_SW(void);
void F_SLL(void);
void F_LUI(void);
void F_JAL(void);
void F_AUIPC(void);
void F_ADD(void);
void F_SLTI(void);
void F_SB(void);
void F_JALR(void);
void F_BNE(void);
void F_ADDI(void);
//...

#endif //__OPCODES_H__