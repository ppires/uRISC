#ifndef BANCO_DE_REGISTRADORES_H
#define BANCO_DE_REGISTRADORES_H

#include <unistd.h>
#include <stdio.h>

typedef int Registrador;

typedef struct{
	Registrador r0, r1, r2, r3, r4;
	Registrador *ra, *fp, *sp;
} BancoDeRegistradores;

void InicializaBanco(BancoDeRegistradores *banco);

void Store(Registrador *destino, int valor);

void PrintBanco(BancoDeRegistradores banco);

#endif
