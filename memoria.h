#ifndef MEMORIA_H
#define MEMORIA_H

typedef struct {
	short int endereco[65536];
}Memoria;

typedef struct {
	short int *intrucoes;
}BancoDeInstrucoes;

void inicializaMemoria(Memoria *memoria);

short int getWord(Memoria *memoria, int address);

void setWord(Memoria *memoria, int address, short int word);

void carregaInstrucoes(BancoDeInstrucoes *banco, char *filename, int argc, char *argv[]);

#endif
