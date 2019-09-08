GCC=gcc
RESULT=main

IFDEF=
#IFDEF+=-DDEBUG



# -Wall — enables all major warnings.
#  # -Wextra — enables other important warnings.
# -Werror — make all warnings into errors, causing compilations to fail if any warnings are reported.
#
LIB=$(C11) -Wall -Wextra #-Werror

# if we need to know actual pwd
CPWD:=$(shell pwd)

INC=-I./include
SRC=main.c \
	src/fib.c




# @ - allow to hide printing command code which will be called, so only expected output will be printed 
help:
	@echo ""
	@echo "  all - normal full compilation to prepare resulting binary file."
	@echo "  preproc - stop after preprocessing."
	@echo ""

	
all: main.c
	
	$(GCC) $(IFDEF) $(LIB) $(SRC) -o $(RESULT) $(INC)

preproc:
	echo "Stop process after preprocessing."
	$(GCC) -E $(LIB) main.c -o $(RESULT).i $(INC)

.PHONY: clean
clean:
	rm -rf $(RESULT)
	rm -rf *.o
	rm -rf *.i
