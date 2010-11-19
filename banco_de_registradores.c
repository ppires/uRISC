#include "banco_de_registradores.h"

void InicializaBanco(BancoDeRegistradores *banco){
	banco->r0 = 0;
	banco->r1 = 0;
	banco->r2 = 0;
	banco->r3 = 0;
	banco->r4 = 0;
	banco->sp = NULL;
	banco->ra = NULL;
	banco->fp = NULL;
}

void Store(Registrador *destino, int valor){
	*destino = valor;
}

Registrador Load(Registrador *reg){
	return *reg;
}

void PrintBanco(BancoDeRegistradores banco){
	printf(" r0: %d\n", banco.r0);
	printf(" r1: %d\n", banco.r1);
	printf(" r2: %d\n", banco.r2);
	printf(" r3: %d\n", banco.r3);
	printf(" r4: %d\n", banco.r4);
	printf(" sp: %p\n", banco.sp);
	printf(" ra: %p\n", banco.ra);
	printf(" fp: %p\n", banco.fp);
}
