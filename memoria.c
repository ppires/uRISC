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

void carregaInstrucoes(BancoDeInstrucoes *banco, int argc, char *argv[]){
	FILE *fp = NULL;
	banco->intrucoes = NULL;
	char *filename = GetOpt(argc, argv);
	fp = fopen(filename);
	char *line = malloc(sizeof(char) * 16);
	int i = 0;
	while(!feof(fp)){
		if(fgets(line, 15, fp) != NULL){
			banco->intrucoes = (short int*) realloc(banco->instrucoes, sizeof(short int) * (i+1));
			banco->intrucoes[i] = (short int) atol(line);
		}
	}
	free(line);
}
