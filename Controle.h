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
}Flags;

typedef struct {
	int type; // 0, 1, 2 ou 3

	// Formato 01
	char *wc;
	char *op;
	char *ra;
	char *rb;

	// Formato 10
	char *rc;
	char *offset11;

	//Formato 11
	char *rc;
	char *r;
	char *offset8;

	//Formato 00
	char *op;
	char *ofset12;
	char *cond;
}Instrucao;

#endif /* CONTROLE_H_ */
