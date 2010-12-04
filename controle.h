#ifndef CONTROLE_H
#define CONTROLE_H

#include "aux.h"
#include "memoria.h"
#include "banco_de_registradores.h"

typedef struct{
	short int zero;
	short int neg;
	short int negzero;
	short int overflow;
	short int carry;
	short int true;
}ALUFlags;

typedef struct {
	short int op_code;
	short int cond;
}ControleALU;

typedef struct {
	int type; // 0, 1, 2 ou 3

	// Formato 01
	short int *wc;
	char *op;
	char *ra;
	char *rb;

	// Formato 10
	char *rc;
	char *offset11;

	//Formato 11
	char *r;
	char *offset8;

	//Formato 00
	char *offset12;
	char *cond;
}Instrucao;

typedef struct {
	char *ALUop;
	short int RegDST;
	short int RegWrite;
	short int MemWrite;
	short int MemRead;
	short int IRWrite;
	short int PCWriteCond;
	short int Jump;
	short int OpOn;
	short int PCCond;
}Controle;

extern BancoDeInstrucoes bancoI;
extern BancoDeRegistradores bancoR;
extern Memoria mem;
extern Registrador *PC;
extern Registrador IR;
extern Registrador aluA, aluB, ALUOut;
extern Controle controle;
extern ControleALU controle_alu;
extern ALUFlags alu_flags;

Instrucao decodeInstrucao(short int hex);

void inicializaInstrucao(Instrucao *i);

void inicializaControle(Controle *controle);

void inicializaALUFlags(ALUFlags *flags);

#endif /* CONTROLE_H_ */
