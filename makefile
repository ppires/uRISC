COMPILER = gcc
OPTIONS = -c -Wall -Wextra -Werror -g

all: uRISC

uRISC: main.o io.o banco_de_registradores.o
	$(COMPILER) main.o io.o banco_de_registradores.o -o uRISC

main.o: io.o banco_de_registradores.o main.c
	$(COMPILER) $(OPTIONS) main.c

banco_de_registradores.o: banco_de_registradores.c
	$(COMPILER) $(OPTIONS) banco_de_registradores.c	

io.o: io.c
	$(COMPILER) $(OPTIONS) io.c	

clean:
	rm -f *.o uRISC
