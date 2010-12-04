#include "aux.h"

char *int2bin(short int n){
    unsigned int i;
    int k;
    char *binary = (char *) malloc(sizeof(char) * 16);
    i = 1<<(sizeof(n) * 8 - 1);
    for(k = 0; k < 16; k++){
        if (n & i)
            binary[k] = '1';
        else
        	binary[k] = '0';
        i >>= 1;
    }
    //printf("%s\n", binary);
    return binary;
}

short int bin2int(char *bin){
	short int integer = 0;
	int i, j = 0;
	for(i = strlen(bin) - 1; i >= 0 ; i--){
	    printf("2 elevado a %d = %d\n", j, (short int) pow(2, j));
		if(bin[i] == '1'){
			integer += (short int) pow(2, j);
		}
		j++;
	}
	return integer;
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

char *extendSignal(char *signal){
	char *extended = malloc(sizeof(char) * 17);
	int i, j = 0;
	for(i = 0; i < 16; i++){
		if(i < 16 - strlen(signal)){
			extended[i] = signal[0];
		}
		else{
			extended[i] = signal[j];
			j++;
		}
	}
	extended[17] = '\0';
	return extended;
}
