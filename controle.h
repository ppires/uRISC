#ifndef CONTROLE_H
#define CONTROLE_H

#include "aux.h"

typedef struct{
	short int zero;
	short int neg;
	short int negzero;
	short int overflow;
	short int carry;
	short int true;
}ALUFlags;

typedef struct {
	int type; // 0, 1, 2 ou 3

	// Formato 01
	Registrador *wc;
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

#endif /* CONTROLE_H_ */