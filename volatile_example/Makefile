
CC=gcc
STD=-std=c11
OPTIMIZATION=-O2

C_DEF=-DIS_SIG=1 -DDEF_VALUE=4
CFLAGS=${STD} -g -Wall -Werror ${OPTIMIZATION} ${C_DEF}

all: main.c
	${CC} ${CFLAGS} -o main main.c


clean:
	rm -rf main main.o main.dSYM