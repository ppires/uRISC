#ifndef MEMORIA_H
#define MEMORIA_H

typedef struct {
	short int endereco[65536];
}Memoria;

void inicializaMemoria(Memoria *memoria);

short int getWord(Memoria *memoria, int address);

void setWord(Memoria *memoria, int address, short int word);

#endif
