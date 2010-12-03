#include "ALU.h"

void execALU(){
	if(controle.PCWriteCond){ // JUMP

	}
	else if(controle.OpOn){ // ALU
		switch(controle.op){
		case "00000": //zeros
			zeros(&controle.RegDST);
			break;
		case "00010": //and
			and(&controle.RegDST, aluA, aluB);
			break;
		case "01010": // andnota
			andnota(&controle.RegDST, aluA, aluB);
			break;
		case "01001": // passa
			passa(&controle.RegDST, aluA);
			break;
		case "00110": // xor
			xor(&controle.RegDST, aluA, aluB);
			break;
		case "00100": // or
			or(&controle.RegDST, aluA, aluB);
			break;
		case "00101": // nor
			nor(&controle.RegDST, aluA, aluB);
			break;
		case "00111": // xnor
			xnor(&controle.RegDST, aluA, aluB);
			break;
		case "01000": // passnota
			pasnota(&controle.RegDST, aluA);
			break;
		case "01011": // ornotb
			ornotb(&controle.RegDST, aluA, aluB);
			break;
		case "00011": // nand
			nand(&controle.RegDST, aluA, aluB);
			break;
		case "00001": // ones
			ones(&controle.RegDST);
			break;
		case "11000": // add
			add(&controle.RegDST, aluA, aluB);
			break;
		case "11010": // addinc
			addinc(&controle.RegDST, aluA, aluB);
			break;
		case "11100": // inca
			inca(&controle.RegDST, aluA);
			break;
		case "11011": // subdec
			subdec(&controle.RegDST, aluA, aluB);
			break;
		case "11001": //sub
			sub(&controle.RegDST, aluA, aluB);
			break;
		case "11101": // deca
			deca(&controle.RegDST, aluA);
			break;
		case "10000": // lsl
			lsl(&controle.RegDST, aluA);
			break;
		case "10010": // lsr
			lsr(&controle.RegDST, aluA);
			break;
		case "10011": // asr
			asr(&controle.RegDST, aluA);
			break;
		case "10001": // asl
			asl(&controle.RegDST, aluA);
			break;
		}
	}
	else { // load constant lcl lcr loadlit...
		switch(controle.op){
		case "00": // jump false
			jf(controle.PCCond, aluB);
			break;
		case "01": // jump true
			jt(controle.PCCond, aluB);
			break;
		case "10": // jump incondicional
			j(aluB);
			break;
		case "11": // jump and link / jump regiter
			//switch()
			//jal(aluB);
			break;
		}
	}
}

void add(Flags *flags, Registrador *c, Registrador a, Registrador b){
	*c = a + b;
	flags->zero = *c == 0;
	flags->neg = *c < 0;
	flags->negzero = flags->zero || flags->neg;
	flags->overflow = b > 0 ? (32767 - b) < a : (-32768 - b) > a;
	flags->carry = verifyCarry(a, b);
}

void addinc(Flags *flags, Registrador *c, Registrador a, Registrador b){
	*c =  a + b + 1;
	flags->zero = *c == 0;
	flags->neg = *c < 0;
	flags->negzero = flags->zero || flags->neg;
	flags->overflow = b > 0 ? (32767 - b) < a : (-32768 - b) > a;
	flags->carry = verifyCarry(a, b);
}

void and(Flags *flags, Registrador *c, Registrador a, Registrador b){
	*c = a & b;
	//flags->zero = *c == 0 ? TRUE : FALSE; TODO
	//flags->neg = *c < 0 ? TRUE : FALSE;
	flags->negzero = flags->zero || flags->neg;
	flags->carry = FALSE;
	flags->overflow = FALSE;
}

void andnota(Flags *flags, Registrador *c, Registrador a, Registrador b){
	*c =  ~a & b;
	*c = a & b;
	//flags->zero = *c == 0 ? TRUE : FALSE; TODO
	//flags->neg = *c < 0 ? TRUE : FALSE;
	flags->negzero = flags->zero || flags->neg;
	flags->carry = FALSE;
	flags->overflow = FALSE;
}

void asl(Flags *flags, Registrador *c, Registrador a){
	*c = a << 1;
	flags->zero = *c == 0 ? TRUE : FALSE;
	flags->neg = *c < 0 ? TRUE : FALSE;
	flags->negzero = flags->zero || flags->neg;
	flags->overflow = b > 0 ? (32767 - b) < a : (-32768 - b) > a;
	flags->carry = int2bin(a)[15];
}

void asr(Flags *flags, Registrador *c, Registrador a){
	*c = a >> 1;
	flags->zero = *c == 0 ? TRUE : FALSE;
	flags->neg = *c < 0 ? TRUE : FALSE;
	flags->negzero = flags->zero || flags->neg;
	flags->carry = FALSE;
	flags->overflow = FALSE;
}

void deca(Flags *flags, Registrador *c, Registrador a){
	*c = a - 1;
	flags->zero = *c == 0 ? TRUE : FALSE;
	flags->neg = *c < 0 ? TRUE : FALSE;
	flags->negzero = flags->zero || flags->neg;
	flags->overflow = b > 0 ? (32767 - b) < a : (-32768 - b) > a;
	flags->carry = verifyCarry(a, -1);
}

void inca(Flags *flags, Registrador *c, Registrador a){
	*c = a + 1;
	flags->zero = *c == 0 ? TRUE : FALSE;
	flags->neg = *c < 0 ? TRUE : FALSE;
	flags->negzero = flags->zero || flags->neg;
	flags->overflow = b > 0 ? (32767 - b) < a : (-32768 - b) > a;
	flags->carry = verifyCarry(a, 1);
}

void j(Registrador destino_extended){
	PC += 1;
	PC += destino_extended;
}

void jal(Registrador destino){
	bancoR.ra = PC + 1;
	PC = destino;
}

void jf(int flag, Registrador destino_extended){
	if(flag){
		PC += 1;
		PC += destino_extended;
	}
}

void jt(int flag, Registrador destino_extended){
	if(flag){
		PC += 1;
		PC += destino_extended;
	}
}

void jr(Registrador destino){
	PC = destino;
}

void lch(Registrador *c, int offset){
	*c = (offset << 8) | (*c & 0x00ff);
}

void lcl(Registrador *c, int offset){
	*c = offset | (*c & 0xff00);
}

Registrador load(Registrador address){
	/************/
}

Registrador loadlit(){
	/************/
}

void lsl(Flags *flags, Registrador *c, Registrador a){
	*c = a << 1;
	flags->zero = *c == 0 ? TRUE : FALSE;
	flags->neg = *c < 0 ? TRUE : FALSE;
	flags->negzero = flags->zero || flags->neg;
	flags->overflow = FALSE;
	flags->carry = int2bin(a)[15];
}

void lsr(Flags *flags, Registrador *c, Registrador a){
	*c = a >> 1;
	flags->zero = *c == 0 ? TRUE : FALSE;
	flags->neg = *c < 0 ? TRUE : FALSE;
	flags->negzero = flags->zero || flags->neg;
	flags->overflow = FALSE;
	flags->carry = FALSE;
}

void nand(Flags *flags, Registrador *c, Registrador a, Registrador b){
	*c = ~(a & b);
	flags->zero = *c == 0 ? TRUE : FALSE;
	flags->neg = *c < 0 ? TRUE : FALSE;
	flags->negzero = flags->zero || flags->neg;
	flags->overflow = FALSE;
	flags->carry = FALSE;
}

void nor(Flags *flags, Registrador *c, Registrador a, Registrador b){
	*c = ~(a | b);
	flags->zero = *c == 0 ? TRUE : FALSE;
	flags->neg = *c < 0 ? TRUE : FALSE;
	flags->negzero = flags->zero || flags->neg;
	flags->overflow = FALSE;
	flags->carry = FALSE;
}

void ones(Flags *flags, Registrador *reg){
	*reg = 1;
	flags->zero = *c == 0 ? TRUE : FALSE;
	flags->neg = *c < 0 ? TRUE : FALSE;
	flags->negzero = flags->zero || flags->neg;
	flags->overflow = FALSE;
	flags->carry = FALSE;
}

void or(Flags *flags, Registrador *c, Registrador a, Registrador b){
	*c = a | b;
	flags->zero = *c == 0;
	flags->neg = *c < 0;
	flags->negzero = flags->zero || flags->neg;
	flags->overflow = FALSE;
	flags->carry = FALSE;
}

void ornotb(Flags *flags, Registrador *c, Registrador a, Registrador b){
	*c = a | ~b;
	flags->zero = *c == 0;
	flags->neg = *c < 0;
	flags->negzero = flags->zero || flags->neg;
	flags->overflow = FALSE;
	flags->carry = FALSE;
}

void passa(Flags *flags, Registrador *c, Registrador a){
	*c = a;
	flags->zero = *c == 0;
	flags->neg = *c < 0;
	flags->negzero = flags->zero || flags->neg;
	flags->overflow = FALSE;
	flags->carry = FALSE;
}

void passnota(Flags *flags, Registrador *c, Registrador a){
	*c = ~a;
	flags->zero = *c == 0;
	flags->neg = *c < 0;
	flags->negzero = flags->zero || flags->neg;
	flags->overflow = FALSE;
	flags->carry = FALSE;
}

void store(Registrador a, Registrador b){
	/******/
}

void sub(Flags *flags, Registrador *c, Registrador a, Registrador b){
	*c = a - b;
	flags->zero = *c == 0;
	flags->neg = *c < 0;
	flags->negzero = flags->zero || flags->neg;
	flags->overflow = b > 0 ? (32767 - b) < a : (-32768 - b) > a;
	flags->carry = verifyCarry(a, b);
}

void subdec(Flags *flags, Registrador *c, Registrador a, Registrador b){
	*c = a - b - 1;
	flags->zero = *c == 0;
	flags->neg = *c < 0;
	flags->negzero = flags->zero || flags->neg;
	flags->overflow = b > 0 ? (32767 - b) < a : (-32768 - b) > a;
	flags->carry = verifyCarry(a, -b);
}

void xnor(Flags *flags, Registrador *c, Registrador a, Registrador b){
	*c = ~(a ^ b);
	flags->zero = *c == 0;
	flags->neg = *c < 0;
	flags->negzero = flags->zero || flags->neg;
	flags->overflow = FALSE;
	flags->carry = FALSE;
}

void xor(Flags *flags, Registrador *c, Registrador a, Registrador b){
	*c = a ^ b;
	flags->zero = *c == 0;
	flags->neg = *c < 0;
	flags->negzero = flags->zero || flags->neg;
	flags->overflow = FALSE;
	flags->carry = FALSE;
}

void zeros(Flags *flags, Registrador *reg){
	*reg = 0;
	flags->zero = TRUE;
	flags->neg = FALSE;
	flags->negzero = flags->zero || flags->neg;
	flags->overflow = FALSE;
	flags->carry = FALSE;
}
