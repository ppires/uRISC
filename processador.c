#include "processador.h"

void proc(int argc, char *argv[]){
	inicializaControle(&controle);
	inicializaALUFlags(&alu_flags);
	inicializaMemoria(&mem);
	inicializaALUFlags(&alu_flags);
	inicializaControleALU(&controle_alu);
	carregaInstrucoes(&bancoI, argc, argv);
	PC = &bancoI->instrucoces[0]; // aponta PC para a primeira instrução
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
