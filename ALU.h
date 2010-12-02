#ifndef ALU_H
#define ALU_H

#include "banco_de_registradores.h"
#include "aux.h"
#include "Controle.h"

extern BancoDeRegistradores banco;



/* ALU functions */

void add(Registrador *c, Registrador a, Registrador b);

void addinc(Registrador *c, Registrador a, Registrador b);

void and(Registrador *c, Registrador a, Registrador b);

void andnota(Registrador *c, Registrador a, Registrador b);

void asl(Registrador *c, Registrador a);

void asr(Registrador *c, Registrador a);

void deca(Registrador *c, Registrador a);

void inca(Registrador *c, Registrador a);

void j(Registrador destino_extended);

void jal(Registrador destino);

void jf(int flag, Registrador destino_extended);

void jt(int flag, Registrador destino_extended);

void jr(Registrador destino);

void lch(Registrador *c, int offset);

void lcl(Registrador *c, int offset);

Registrador load(Registrador address);

Registrador loadlit();

void lsl(Registrador *c, Registrador a);

void lsr(Registrador *c, Registrador a);

void nand(Registrador *c, Registrador a, Registrador b);

void nor(Registrador *c, Registrador a, Registrador b);

void ones(Registrador *reg);

void or(Registrador *c, Registrador a, Registrador b);

void ornotb(Registrador *c, Registrador a, Registrador b);

void passa(Registrador *c, Registrador a);

void passnota(Registrador *c, Registrador a);

void store(Registrador a, Registrador b);

void sub(Registrador *c, Registrador a, Registrador b);

void subdec(Registrador *c, Registrador a, Registrador b);

void xnor(Registrador *c, Registrador a, Registrador b);

void xor(Registrador *c, Registrador a, Registrador b);

void zeros(Registrador *reg);

/*****************/









#endif ALU_H
