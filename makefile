COMPILER = gcc
OPTIONS = -c -Wall -Wextra -Werror -g

all: uRISC

uRISC: main.o io.o
	$(COMPILER) main.o io.o -o uRISC

main.o: io.o main.c
	$(COMPILER) $(OPTIONS) main.c

io.o: io.c
	$(COMPILER) $(OPTIONS) io.c	

clean:
	rm -f *.o uRISC
