#ifndef BANCO_DE_REGISTRADORES_H
#define BANCO_DE_REGISTRADORES_H

#include <unistd.h>
#include <stdio.h>
#include "controle.h"
#include "memoria.h"

typedef short int Registrador;

typedef struct{
	Registrador regs[5];
	Registrador *ra, *fp, *sp;
} BancoDeRegistradores;

extern BancoDeInstrucoes bancoI;
extern BancoDeRegistradores bancoR;
extern Memoria mem;
extern Registrador *PC;
extern Registrador IR;
extern Registrador aluA, aluB, ALUOut;
extern Controle controle;
extern ControleALU controle_alu;
extern ALUFlags alu_flags;

void carregaRegistradores(Instrucao instrucao);

void InicializaBanco(BancoDeRegistradores *banco);

void StoreReg(Registrador *destino, int valor);

Registrador LoadReg(Registrador *reg);

void PrintBanco(BancoDeRegistradores banco);

#endif
