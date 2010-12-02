#include "aux.h"

char *int2bin(short int n){
    unsigned int i;
    int k;
    char * binary = (char *) malloc(sizeof(char) * 16);
    i = 1<<(sizeof(n) * 8 - 1);
    for(k = 0; k < 16; k++){
        if (n & i)
            binary[k] = '1';
        else
        	binary[k] = '0';
        i >>= 1;
    }
    printf("%s\n", binary);
    return binary;
}

int verifyCarry(short int a, short int b){
	char *st_a = int2bin(a);
	char *st_b = int2bin(b);
	int i;
	for(i = 0; i < 16; i++){
		if((st_a[i] == '1') && (st_b[i] == '1')) return TRUE;
	}
	return FALSE;
}

char *substring(char *string, int num1, int num2){
	int num_chars = num2 - num1;
	char *ans = (char *)malloc(sizeof(char) * (num_chars + 1));
	int i;
	for(i = num1; i <= num2; i++){
		ans[i - num1] = string[i];
	}
	ans[strlen(string) - 1] = '\0';
	return ans;
}
