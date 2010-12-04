#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

char *GetOpt(int argc, char *argv[]);

#endif
