#ifndef AUX_H
#define AUX_H

#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

char *int2bin(short int n);

short int bin2int(char *bin);

int verifyCarry(short int a, short int b);

char *substring(char *string, int num1, int num2);

char *extendSignal(char *signal);

#endif
