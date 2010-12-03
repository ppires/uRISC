#include "controle.h"

Instrucao decodeInstruction(short int hex){
	bin = int2bin(hex);
	Instrucao instrucao;
	inicializaInstrucao(&instrucao);
	switch(substring(bin, 0, 1)){
	case "00":
		instrucao.type = 0;
		instrucao.op = substring(bin, 2, 3);
		switch(instrucao.op){
		case "00":
			instrucao.cond = substring(bin, 4, 7);
			instrucao.offset8 = substring(bin, 8, 15);
			break;
		case "01":
			instrucao.cond = substring(bin, 4, 7);
			instrucao.offset8 = substring(bin, 8, 15);
			break;
		case "10":
			instrucao.offset12 = substring(bin, 4, 15);
			break;
		case "11":
			instrucao.r = substring(bin, 4, 4);
			instrucao.rb = substring(bin, 13, 15);
			break;
		}
		break;
	case "01":
		instrucao.type = 1;
		instrucao.wc = substring(bin, 2, 4);
		instrucao.op = substring(bin, 5, 9);
		instrucao.ra = substring(bin, 10, 12);
		instrucao.rb = substring(bin, 13, 15);
		break;
	case "10":
		instrucao.type = 2;
		instrucao.rc = substring(bin, 2, 4);
		instrucao.offset11 = substring(bin, 5, 15);
		break;
	case "11":
		instrucao.type = 3;
		instrucao.rc = substring(bin, 2, 4);
		instrucao.r = substring(bin, 5, 5);
		instrucao.offset8 = substring(bin, 8, 15);
		break;
	}
	return instrucao;
}

void inicializaInstrucao(Instrucao *i){
	i->cond = NULL;
	i->offset11 = NULL;
	i->offset8 = NULL;
	i->offset12 = NULL;
	i->op = NULL;
	i->r = NULL;
	i->ra = NULL;
	i->rb = NULL;
	i->rb = NULL;
	i->rc = NULL;
	i->wc = NULL;
}

void inicializaControle(Controle *controle){
	controle->ALUop = NULL;
	controle->RegDST = FALSE;
	controle->RegWrite = FALSE;
	controle->MemWrite = FALSE;
	controle->MemRead = FALSE;
	controle->IRWrite = FALSE;
	controle->PCWriteCond = FALSE;
	controle->OpOn = FALSE;
	controle->PCCond = FALSE;
}

void inicializaALUFlags(ALUFlags *flags){
	flags->carry = FALSE;
	flags->neg = FALSE;
	flags->negzero = FALSE;
	flags->overflow = FALSE;
	flags->true = FALSE;
	flags->zero = FALSE;
}
