#ifndef PROCESSADOR_H
#define PROCESSADOR_H

#include "memoria.h"

BancoDeInstrucoes bancoI;
BancoDeRegistradores bancoR;
Memoria mem;
Registrador *PC;
Registrador IR;
Registrador aluA, aluB, ALUOut;
Controle controle;
ControleALU controle_alu;
ALUFlags alu_flags;


#endif
