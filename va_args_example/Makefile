CC=gcc
CFLAGS=-Wall -Werror -g -O2
EXE=example

##$(CC) $(CFLAGS) $< -o $@ $(LFLAGS)


all: $(EXE)

%: %.c
	$(CC) -g -std=c11 $(CFLAGS) -o ${EXE} ${EXE}.c
	

clean:
	rm -rf *.dSYM *.o $(EXE)


