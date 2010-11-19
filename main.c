#include "io.h"

int s = FALSE;
int p = FALSE;


int main(int argc, char *argv[]){

	GetOpt(argc, argv);

	printf("%d %d\n", s, p);

	return EXIT_SUCCESS;
}
