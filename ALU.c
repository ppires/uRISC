#include "ALU.h"

void execALU(){
	switch(controle_alu.op_code){
		case  1: add();      break;
		case  2: addinc();   break;
		case  3: and();      break;
		case  4: andnota();  break;
		case  5: asl();      break;
		case  6: asr();      break;
		case  7: deca();     break;
		case  8: inca();     break;
		case  9: j();        break;
		case 10: jal(); 	 break;
		case 11: jf(); 	  	 break;
		case 12: jr(); 		 break;
		case 13: jt(); 		 break;
		case 14: lch(); 	 break;
		case 15: lcl(); 	 break;
		case 16: load();	 break;
		case 17: loadlit();	 break;
		case 18: lsl();		 break;
		case 19: lsr();		 break;
		case 20: nand();	 break;
		case 21: nor();		 break;
		case 22: ones();	 break;
		case 23: or();		 break;
		case 24: ornotb();	 break;
		case 25: passa();	 break;
		case 26: passnota(); break;
		case 27: store();	 break;
		case 28: sub();		 break;
		case 29: subdec();	 break;
		case 30: xnor();	 break;
		case 31: xor();		 break;
		case 32: zeros();	 break;
	}
}

void add(){
	ALUOut = aluA + aluB; // execução
	alu_flags.zero = ALUOut == 0;
	alu_flags.neg = ALUOut < 0;
	alu_flags.negzero = alu_flags.zero || alu_flags.neg;
	alu_flags.overflow = aluB > 0 ? (32767 - aluB) < aluA : (-32768 - aluB) > aluA;
	alu_flags.carry = verifyCarry(aluA, aluB);
}

void addinc(){
	ALUOut =  aluA + aluB + 1; // execução
	alu_flags.zero = ALUOut == 0;
	alu_flags.neg = ALUOut < 0;
	alu_flags.negzero = (alu_flags.zero || alu_flags.neg);
	alu_flags.overflow = aluB > 0 ? (32767 - aluB) < aluA : (-32768 - aluB) > aluA;
	alu_flags.carry = verifyCarry(aluA, aluB);
}

void and(){
	ALUOut = aluA & aluB; // execução
	//alu_flags.zero = ALUOut == 0 ? TRUE : FALSE; TODO
	//alu_flags.neg = ALUOut < 0 ? TRUE : FALSE;
	alu_flags.negzero = alu_flags.zero || alu_flags.neg;
	alu_flags.carry = FALSE;
	alu_flags.overflow = FALSE;
}

void andnota(){
	ALUOut = (~aluA) & aluB; // execução
	//alu_flags.zero = ALUOut == 0 ? TRUE : FALSE; TODO
	//alu_flags.neg = ALUOut < 0 ? TRUE : FALSE;
	alu_flags.negzero = alu_flags.zero || alu_flags.neg;
	alu_flags.carry = FALSE;
	alu_flags.overflow = FALSE;
}

void asl(){
	ALUOut = aluA << 1; // execução
	alu_flags.zero = ALUOut == 0 ? TRUE : FALSE;
	alu_flags.neg = ALUOut < 0 ? TRUE : FALSE;
	alu_flags.negzero = alu_flags.zero || alu_flags.neg;
	alu_flags.overflow = aluB > 0 ? (32767 - aluB) < aluA : (-32768 - aluB) > aluA;
	alu_flags.carry = int2bin(aluA)[15];
}

void asr(){
	ALUOut = aluA >> 1; // execução
	alu_flags.zero = ALUOut == 0 ? TRUE : FALSE;
	alu_flags.neg = ALUOut < 0 ? TRUE : FALSE;
	alu_flags.negzero = alu_flags.zero || alu_flags.neg;
	alu_flags.carry = FALSE;
	alu_flags.overflow = FALSE;
}

void deca(){
	ALUOut = aluA - 1; // execução
	alu_flags.zero = ALUOut == 0 ? TRUE : FALSE;
	alu_flags.neg = ALUOut < 0 ? TRUE : FALSE;
	alu_flags.negzero = alu_flags.zero || alu_flags.neg;
	alu_flags.overflow = aluB > 0 ? (32767 - aluB) < aluA : (-32768 - aluB) > aluA;
	alu_flags.carry = verifyCarry(aluA, -1);
}

void inca(){
	ALUOut = aluA + 1; // execução
	alu_flags.zero = ALUOut == 0 ? TRUE : FALSE;
	alu_flags.neg = ALUOut < 0 ? TRUE : FALSE;
	alu_flags.negzero = alu_flags.zero || alu_flags.neg;
	alu_flags.overflow = aluB > 0 ? (32767 - aluB) < aluA : (-32768 - aluB) > aluA;
	alu_flags.carry = verifyCarry(aluA, 1);
}

void j(){
	ALUOut = aluB; // cálculo do endereço
}

void jal(){
	ALUOut = aluB; // cálculo do endereço
}

void jf(){
	ALUOut = aluB; // cálculo do endereço
}

void jt(){
	ALUOut = aluB; // cálculo do endereço
}

void jr(){
	ALUOut = aluB; // cálculo do endereço
}

void lch(){
	ALUOut = (aluB << 8) | (ALUOut & 0x00ff); // execução
}

void lcl(){
	ALUOut = aluB | (ALUOut & 0xff00); // execução
}

void load(){
	/************/
}

void loadlit(){
	/************/
}

void lsl(){
	ALUOut = aluA << 1; // execução
	alu_flags.zero = ALUOut == 0 ? TRUE : FALSE;
	alu_flags.neg = ALUOut < 0 ? TRUE : FALSE;
	alu_flags.negzero = alu_flags.zero || alu_flags.neg;
	alu_flags.overflow = FALSE;
	alu_flags.carry = int2bin(aluA)[15];
}

void lsr(){
	ALUOut = aluA >> 1; // execução
	alu_flags.zero = ALUOut == 0 ? TRUE : FALSE;
	alu_flags.neg = ALUOut < 0 ? TRUE : FALSE;
	alu_flags.negzero = alu_flags.zero || alu_flags.neg;
	alu_flags.overflow = FALSE;
	alu_flags.carry = FALSE;
}

void nand(){
	ALUOut = ~(aluA & aluB); // execução
	alu_flags.zero = ALUOut == 0 ? TRUE : FALSE;
	alu_flags.neg = ALUOut < 0 ? TRUE : FALSE;
	alu_flags.negzero = alu_flags.zero || alu_flags.neg;
	alu_flags.overflow = FALSE;
	alu_flags.carry = FALSE;
}

void nor(){
	ALUOut = ~(aluA | aluB); // execução
	alu_flags.zero = ALUOut == 0 ? TRUE : FALSE;
	alu_flags.neg = ALUOut < 0 ? TRUE : FALSE;
	alu_flags.negzero = alu_flags.zero || alu_flags.neg;
	alu_flags.overflow = FALSE;
	alu_flags.carry = FALSE;
}

void ones(){
	ALUOut = 1; // execução
	alu_flags.zero = FALSE;
	alu_flags.neg = FALSE;
	alu_flags.negzero = FALSE;
	alu_flags.overflow = FALSE;
	alu_flags.carry = FALSE;
}

void or(){
	ALUOut = aluA | aluB; // execução
	alu_flags.zero = ALUOut == 0;
	alu_flags.neg = ALUOut < 0;
	alu_flags.negzero = alu_flags.zero || alu_flags.neg;
	alu_flags.overflow = FALSE;
	alu_flags.carry = FALSE;
}

void ornotb(){
	ALUOut = aluA | ~aluB; // execução
	alu_flags.zero = ALUOut == 0;
	alu_flags.neg = ALUOut < 0;
	alu_flags.negzero = alu_flags.zero || alu_flags.neg;
	alu_flags.overflow = FALSE;
	alu_flags.carry = FALSE;
}

void passa(){
	ALUOut = aluA; // execução
	alu_flags.zero = ALUOut == 0;
	alu_flags.neg = ALUOut < 0;
	alu_flags.negzero = alu_flags.zero || alu_flags.neg;
	alu_flags.overflow = FALSE;
	alu_flags.carry = FALSE;
}

void passnota(){
	ALUOut = ~aluA; // execução
	alu_flags.zero = ALUOut == 0;
	alu_flags.neg = ALUOut < 0;
	alu_flags.negzero = alu_flags.zero || alu_flags.neg;
	alu_flags.overflow = FALSE;
	alu_flags.carry = FALSE;
}

void store(){
	/******/
}

void sub(){
	ALUOut = aluA - aluB; // execução
	alu_flags.zero = ALUOut == 0;
	alu_flags.neg = ALUOut < 0;
	alu_flags.negzero = alu_flags.zero || alu_flags.neg;
	alu_flags.overflow = aluB > 0 ? (32767 - aluB) < aluA : (-32768 - aluB) > aluA;
	alu_flags.carry = verifyCarry(aluA, aluB);
}

void subdec(){
	ALUOut = aluA - aluB - 1; // execução
	alu_flags.zero = ALUOut == 0;
	alu_flags.neg = ALUOut < 0;
	alu_flags.negzero = alu_flags.zero || alu_flags.neg;
	alu_flags.overflow = aluB > 0 ? (32767 - aluB) < aluA : (-32768 - aluB) > aluA;
	alu_flags.carry = verifyCarry(aluA, -aluB);
}

void xnor(){
	ALUOut = ~(aluA ^ aluB); // execução
	alu_flags.zero = ALUOut == 0;
	alu_flags.neg = ALUOut < 0;
	alu_flags.negzero = alu_flags.zero || alu_flags.neg;
	alu_flags.overflow = FALSE;
	alu_flags.carry = FALSE;
}

void xor(){
	ALUOut = aluA ^ aluB; // execução
	alu_flags.zero = ALUOut == 0;
	alu_flags.neg = ALUOut < 0;
	alu_flags.negzero = alu_flags.zero || alu_flags.neg;
	alu_flags.overflow = FALSE;
	alu_flags.carry = FALSE;
}

void zeros(){
	ALUOut = 0; // execução
	alu_flags.zero = TRUE;
	alu_flags.neg = FALSE;
	alu_flags.negzero = TRUE;
	alu_flags.overflow = FALSE;
	alu_flags.carry = FALSE;
}
