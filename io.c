#include "io.h"

char *GetOpt(int argc, char *argv[]){
    int c;
    extern int optopt;
    char *filename = argv[1];
    extern int s, p;
    while ((c = getopt(argc, argv, "s::d:p::")) != -1) {
        switch (c) {
        case 'd':
        	printf("Parâmetro '-d' = %s\n", optarg);
            break;
        case 's':
        	printf("Parâmetro '-s'\n");
        	s = TRUE;
            break;
        case 'p':
        	printf("Parâmetro '-p'\n");
        	p = TRUE;
            break;
        case ':':
            printf("O parâmetro '-%c' necessita de um argumento!\n", optopt);
            exit(EXIT_FAILURE);
            break;
        case '?':
            printf("Parametro '-%c' desconhecido.\n",optopt);
            break;
        }
    }
    printf("filename: %s\n", filename);
    printf("%d %d\n", s, p);
    return filename;
}

