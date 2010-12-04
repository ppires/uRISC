#include "controle.h"

Instrucao decodeInstrucao(short int hex){
	bin = int2bin(hex);
	Instrucao instrucao;
	inicializaInstrucao(&instrucao);
	switch(substring(bin, 0, 1)){
	case "00":
		instrucao.type = 0;
		instrucao.op = substring(bin, 2, 3);
		switch(instrucao.op){
		case "00":
			controle_alu.op_code = 11; // jf.cond
			instrucao.cond = substring(bin, 4, 7);
			instrucao.offset8 = substring(bin, 8, 15);
			break;
		case "01":
			controle_alu.op_code = 13; // jt.cond
			instrucao.cond = substring(bin, 4, 7);
			instrucao.offset8 = substring(bin, 8, 15);
			break;
		case "10":
			controle_alu.op_code = 9; // j
			instrucao.offset12 = substring(bin, 4, 15);
			break;
		case "11":
			instrucao.r = substring(bin, 4, 4);
			switch(instrucao.r){
			case "0":
				controle_alu.op_code = 10; // jal
				break;
			case "1":
				controle_alu.op_code = 12; // jr
				break;
			}
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
		switch(instrucao.op){
			case "00000": controle_alu.op_code = 32; break; // zeros
			case "00010": controle_alu.op_code = 3; break; // and
			case "01010": controle_alu.op_code = 4; break; // andnota
			case "01001": controle_alu.op_code = 25; break; // passa
			case "00110": controle_alu.op_code = 31; break; // xor
			case "00100": controle_alu.op_code = 23; break; // or
			case "00101": controle_alu.op_code = 21; break; // nor
			case "00111": controle_alu.op_code = 30; break; // xnor
			case "01000": controle_alu.op_code = 26; break; // passnota
			case "01011": controle_alu.op_code = 24; break; // ornotb
			case "00011": controle_alu.op_code = 20; break; // nand
			case "00001": controle_alu.op_code = 22; break; // ones
			case "11000": controle_alu.op_code = 1; break; // add
			case "11010": controle_alu.op_code = 2; break; // addinc
			case "11100": controle_alu.op_code = 8; break; // inca
			case "11011": controle_alu.op_code = 29; break; // subdec
			case "11001": controle_alu.op_code = 28; break; // sub
			case "11101": controle_alu.op_code = 7; break; // deca
			case "10000": controle_alu.op_code = 18; break; // lsl
			case "10010": controle_alu.op_code = 19; break; // lsr
			case "10011": controle_alu.op_code = 6; break; // asr
			case "10001": controle_alu.op_code = 5; break; // asl
			case "10100": controle_alu.op_code = 16; break; // load
			case "10110": controle_alu.op_code = 27; break; // store
		}
		break;
	case "10":
		controle_alu.op_code = 17; // loadlit
		instrucao.type = 2;
		instrucao.rc = substring(bin, 2, 4);
		instrucao.offset11 = substring(bin, 5, 15);
		break;
	case "11":
		instrucao.type = 3;
		instrucao.rc = substring(bin, 2, 4);
		instrucao.offset8 = substring(bin, 8, 15);
		instrucao.r = substring(bin, 5, 5);
		switch(instrucao.r){
			case "0": controle_alu.op_code = 15; break; // lcl
			case "1": controle_alu.op_code = 14; break; // lch
		}
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

void inicializaControleALU(ControleALU *alucontrol){
	alucontrol->op_code = 0;
	alucontrol->cond = FALSE;
}

void inicializaALUFlags(ALUFlags *flags){
	flags->carry = FALSE;
	flags->neg = FALSE;
	flags->negzero = FALSE;
	flags->overflow = FALSE;
	flags->true = FALSE;
	flags->zero = FALSE;
}
