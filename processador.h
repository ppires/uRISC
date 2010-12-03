#ifndef PROCESSADOR_H
#define PROCESSADOR_H

#include "memoria.h"

BancoDeInstrucoes bancoI;
BancoDeRegistradores bancoR;
Memoria mem;
Registrador *PC;
Registrador IR;
Registrador aluA, aluB;
Controle controle;
ALUFlags alu_flags;


#endif
