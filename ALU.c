#include "ALU.h"

void add(Registrador *c, Registrador a, Registrador b){
	*c = a + b;
}

void addinc(Registrador *c, Registrador a, Registrador b){
	*c =  a + b + 1;
}

void and(Registrador *c, Registrador a, Registrador b){
	*c = a & b;
}

void andnota(Registrador *c, Registrador a, Registrador b){
	*c =  ~a & b;
}

void asl(Registrador *c, Registrador a){
	*c = a << 1;
}

void asr(Registrador *c, Registrador a){
	*c = a >> 1;
}

void deca(Registrador *c, Registrador a){
	*c = a - 1;
}

void inca(Registrador *c, Registrador a){
	*c = a + 1;
}

void j(Registrador destino_extended){
	pc += 1;
	pc += destino_extended;
}

void jal(Registrador destino){
	banco.ra = pc + 1;
	pc = destino;
}

void jf(int flag, Registrador destino_extended){
	if(!flag){
		pc += 1;
		pc += destino_extended;
	}
}

void jt(int flag, Registrador destino_extended){
	if(flag){
		pc += 1;
		pc += destino_extended;
	}
}

void jr(Registrador destino){
	pc = destino;
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

void lsl(Registrador *c, Registrador a){
	*c = a << 1;
}

void lsr(Registrador *c, Registrador a){
	*c = a >> 1;
}

void nand(Registrador *c, Registrador a, Registrador b){
	*c = ~(a & b);
}

void nor(Registrador *c, Registrador a, Registrador b){
	*c = ~(a | b);
}

void ones(Registrador *reg){
	*reg = 1;
}

void or(Registrador *c, Registrador a, Registrador b){
	*c = a | b;
}

void ornotb(Registrador *c, Registrador a, Registrador b){
	*c = a | ~b;
}

void passa(Registrador *c, Registrador a){
	*c = a;
}

void passnota(Registrador *c, Registrador a){
	*c = ~a;
}

void store(Registrador a, Registrador b){
	/******/
}

void sub(Registrador *c, Registrador a, Registrador b){
	*c = a - b;
}

void subdec(Registrador *c, Registrador a, Registrador b){
	*c = a - b - 1;
}

void xnor(Registrador *c, Registrador a, Registrador b){
	*c = ~(a ^ b);
}

void xor(Registrador *c, Registrador a, Registrador b){
	*c = a ^ b;
}

void zeros(Registrador *reg){
	*reg = 0;
}
