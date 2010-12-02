#include "memoria.h"

void inicializaMemoria(Memoria *memoria){
	int i;
	for(i = 0; i < 65536; i++){
		memoria->endereco[i] = 0;
	}
}

short int getWord(Memoria *memoria, int address){
	return memoria->endereco[address];
}

void setWord(Memoria *memoria, int address, short int word){
	memoria->endereco[addresss] = word;
}
