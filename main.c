#include "io.h"
#include "banco_de_registradores.h"

int s = FALSE;
int p = FALSE;


int main(int argc, char *argv[]){

	GetOpt(argc, argv);

	BancoDeRegistradores banco;
	InicializaBanco(&banco);
	PrintBanco(banco);

	return EXIT_SUCCESS;
}
