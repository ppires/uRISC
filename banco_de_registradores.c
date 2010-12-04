#include "banco_de_registradores.h"

void carregaRegistradores(Instrucao instrucao){
	switch(instrucao.type){
	case 0: // JUMPS
		switch(bin2int(instrucao.op)){
		case 0: // jf
			aluB = bin2int(extendSignal(instrucao.offset8));
			switch(bin2int(instrucao.cond)){
			case 4: //0100
				controle_alu.cond = alu_flags.neg;
				break;
			case 5: //0101
				controle_alu.cond = alu_flags.zero;
				break;
			case 6: //0110
				controle_alu.cond = alu_flags.carry;
				break;
			case 7: //0111
				controle_alu.cond = alu_flags.negzero;
				break;
			case 0: //0000
				controle_alu.cond = alu_flags.true;
				break;
			case 3: //0011
				controle_alu.cond = alu_flags.overflow;
				break;
			}
			break;
		case 1: // jt
			aluB = bin2int(extendSignal(instrucao.offset8));
			switch(bin2int(instrucao.cond)){
			case 4: //0100
				controle_alu.cond = alu_flags.neg;
				break;
			case 5: //0101
				controle_alu.cond = alu_flags.zero;
				break;
			case 6: //0110
				controle_alu.cond = alu_flags.carry;
				break;
			case 7: //0111
				controle_alu.cond = alu_flags.negzero;
				break;
			case 0: //0000
				controle_alu.cond = alu_flags.true;
				break;
			case 3: //0011
				controle_alu.cond = alu_flags.overflow;
				break;
			}
			break;
		case 2: // j
			aluB = bin2int(extendSignal(instrucao.offset12));
			break;
		case 3: // jal / jr
			aluB = bin2int(instrucao.rb);
			break;
		}
		controle.ALUop = instrucao.op;
		controle.OpOn = TRUE;
		controle.RegWrite = FALSE;
		controle.MemWrite = FALSE;
		controle.MemRead = FALSE;
		controle.IRWrite = FALSE;
		controle.PCWriteCond = TRUE;
		controle.RegDST = NULL;
		break;
	case 1:
		aluA = bancoR.regs[bin2int(instrucao.ra)];
		aluB = bancoR.regs[bin2int(instrucao.rb)];
		controle.RegDST = bin2int(instrucao.wc);
		controle.ALUop = instrucao.op;
		controle.RegWrite = FALSE;
		controle.MemWrite = FALSE;
		controle.MemRead = TRUE;
		controle.IRWrite = FALSE;
		controle.PCWriteCond = FALSE;
		break;
	case 2:
		aluA = bancoR.regs[bin2int(instrucao.rc)];
		aluB = bin2int(extendSignal(instrucao.offset12));
		controle.RegDST = bin2int(instrucao.wc);
		controle.ALUop = instrucao.op;
		controle.RegWrite = TRUE;
		controle.MemWrite = FALSE;
		controle.MemRead = FALSE;
		controle.IRWrite = FALSE;
		controle.PCWriteCond = FALSE;
		break;
	case 3:
		aluA = bancoR.regs[bin2int(instrucao.rc)];
		aluB = bin2int(extendSignal(instrucao.offset8));
		controle.RegDST = bin2int(instrucao.wc);
		controle.ALUop = instrucao.op;
		controle.RegWrite = TRUE;
		controle.MemWrite = FALSE;
		controle.MemRead = FALSE;
		controle.IRWrite = FALSE;
		controle.PCWriteCond = FALSE;
		break;
	}
}

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

void PrintBanco(BancoDeRegistradores banco){
	int i;
	for(i = 0; i < 5; i++){
		printf(" r%d: %x\n", i, banco.regs[i]);
	}
	printf(" ra: %p\n", banco.ra);
	printf(" fp: %p\n", banco.fp);
	printf(" sp: %p\n", banco.sp);
}
