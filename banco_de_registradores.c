#include "banco_de_registradores.h"

void InicializaBanco(BancoDeRegistradores *banco){
	int i;
	for(i = 0; i < 5; i++) banco->regs[i] = 0;
	banco->sp = NULL;
	banco->ra = NULL;
	banco->fp = NULL;
}

void StoreReg(Registrador *destino, int valor){
	*destino = valor;
}

Registrador LoadReg(Registrador *reg){
	return *reg;
}

void carregaRegistradores(Instrucao instrucao){
	switch(instrucao.type){
	case 0:
		// JUMPS
		if(instrucao.cond){ // jump condicional
			aluB = bin2int(extendSignal(instrucao.offset8));
			switch(instrucao.cond){
			case "0100":
				controle->PCCond = alu_flags.neg;
				break;
			case "0101":
				controle->PCCond = alu_flags.zero;
				break;
			case "0110":
				controle->PCCond = alu_flags.carry;
				break;
			case "0111":
				controle->PCCond = alu_flags.negzero;
				break;
			case "0000":
				controle->PCCond = alu_flags.true;
				break;
			case "0011":
				controle->PCCond = alu_flags.overflow;
				break;
			}
		}
		else if(instrucao.r){ // jal, jr
			aluB = bin2int(instrucao.rb);
		}
		else { // jump incondicional
			aluB = bin2int(extendSignal(instrucao.offset12));
		}

		controle->ALUop = instrucao.op;
		controle->OpOn = TRUE;
		controle->RegWrite = FALSE;
		controle->MemWrite = FALSE;
		controle->MemRead = FALSE;
		controle->IRWrite = FALSE;
		controle->PCWriteCond = TRUE;
		controle->RegDST = NULL;

		break;
	case 1:
		aluA = bancoR.regs[bin2int(instrucao.ra)];
		aluB = bancoR.regs[bin2int(instrucao.rb)];
		controle->regDST = bin2int(instrucao.wc);
		controle->ALUop = instrucao.op;
		controle->RegWrite = FALSE;
		controle->MemWrite = FALSE;
		controle->MemRead = TRUE;
		controle->IRWrite = FALSE;
		controle->PCWriteCond = FALSE;
		controle->OpOn = TRUE;
		break;
	case 2:
		aluA = bancoR.regs[bin2int(instrucao.rc)];
		aluB = bin2int(extendSignal(instrucao.offset12));
		controle->regDST = bin2int(instrucao.wc);
		controle->ALUop = instrucao.op;
		controle->RegWrite = TRUE;
		controle->MemWrite = FALSE;
		controle->MemRead = FALSE;
		controle->IRWrite = FALSE;
		controle->PCWriteCond = FALSE;
		controle->OpOn = FALSE;
		break;
	case 3:
		aluA = bancoR.regs[bin2int(instrucao.rc)];
		aluB = bin2int(extendSignal(instrucao.offset8));
		controle->regDST = bin2int(instrucao.wc);
		controle->ALUop = instrucao.op;
		controle->RegWrite = TRUE;
		controle->MemWrite = FALSE;
		controle->MemRead = FALSE;
		controle->IRWrite = FALSE;
		controle->PCWriteCond = FALSE;
		controle->OpOn = FALSE;
		break;
	}
}

void PrintBanco(BancoDeRegistradores banco){
	printf(" r0: %x\n", banco.r0);
	printf(" r1: %x\n", banco.r1);
	printf(" r2: %x\n", banco.r2);
	printf(" r3: %x\n", banco.r3);
	printf(" r4: %x\n", banco.r4);
	printf(" sp: %p\n", banco.sp);
	printf(" ra: %p\n", banco.ra);
	printf(" fp: %p\n", banco.fp);
}
