#ifndef ALU_H
#define ALU_H

#include "banco_de_registradores.h"
#include "aux.h"
#include "controle.h"
#include "banco_de_registradores.h"
#include "memoria.h"

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif


extern BancoDeInstrucoes bancoI;
extern BancoDeRegistradores bancoR;
extern Memoria mem;
extern Registrador *PC;
extern Registrador IR;
extern Registrador aluA, aluB, ALUOut;
extern Controle controle;
extern ControleALU controle_alu;
extern ALUFlags alu_flags;



/* ALU functions */

void execALU();

void add();

void addinc();

void and();

void andnota();

void asl();

void asr();

void deca();

void inca();

void j();

void jal();

void jf();

void jt();

void jr();

void lch();

void lcl();

void load();

void loadlit();

void lsl();

void lsr();

void nand();

void nor();

void ones();

void or();

void ornotb();

void passa();

void passnota();

void store();

void sub();

void subdec();

void xnor();

void xor();

void zeros();


#endif
