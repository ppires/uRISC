#include "processador.h"

void proc(int argc, char *argv[]){
	inicializaControle(&controle);
	inicializaALUFlags(&alu_flags);
	inicializaMemoria(&mem);
	inicializaALUFlags(&alu_flags);
	inicializaControleALU(&controle_alu);
	carregaInstrucoes(&bancoI, argc, argv); // carrega as instruções do arquivo para a memória de instruções
	PC = &bancoI->instrucoces[0]; // aponta PC para a primeira instrução

	while(PC != 0x2fff){ // 0x2fff é a instrução de término de processamento
		IF();
		ID();
		EX_MEM();
		WB();
	}
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
