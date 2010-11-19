#include "io.h"
#include "banco_de_registradores.h"

int s = FALSE;
int p = FALSE;
Registrador pc;
BancoDeRegistradores banco;

#define INT_MAX 32,767
#define INT_MIN -32,768

int main(int argc, char *argv[]){
	InicializaBanco(*banco);

	GetOpt(argc, argv);

	BancoDeRegistradores banco;
	InicializaBanco(&banco);
	PrintBanco(banco);

	return EXIT_SUCCESS;
}
