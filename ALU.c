#include "ALU.h"

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
