#include "processador.h"

void proc(int argc, char *argv[]){
	inicializaControle(&controle);
	inicializaALUFlags(&alu_flags);
	carregaInstrucoes(&bancoI, argc, argv);
	PC = &bancoI->instrucopces[0];
}

void IF(){
	IR = *PC;
	PC++;
}

void ID(){
	Instrucao instrucao = decodeInstrucao(*IR);
	carregaRegistradores(instrucao);
}

void EX_MEM(){
	execALU();
}

void WB(){

}
