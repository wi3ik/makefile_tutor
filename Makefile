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
	@echo "  asm - stop after assembler file is ready."
	@echo "  lnk - stop after linker file is ready."	
	@echo "  lib - compile all (but using static library)"
	@echo ""

	
all: main.c
	
	$(GCC) $(IFDEF) $(LIB) $(SRC) -o $(RESULT) $(INC)

preproc:
	echo "Stop process after preprocessing."
	$(GCC) -E $(LIB) main.c -o $(RESULT).i $(INC)

asm:
	$(GCC) -S $(LIB) main.c -o $(RESULT).s $(INC)

lnk:
	$(GCC) $(IFDEF) $(LIB) $(SRC) -e $(RESULT) $(INC)
	
lib: main.c libfib.a
	@echo "  This won't work for MAC OS  "
	@echo " https://stackoverflow.com/questions/3801011/ld-library-not-found-for-lcrt0-o-on-osx-10-6-with-gcc-clang-static-flag  "
	$(GCC) -static main.c -L.  -lfib -o $(RESULT) $(INC)

libfib.a:
	$(GCC) -c src/fib.c -o calc_fib.o $(INC)
	ar rcs libfib.a calc_fib.o


.PHONY: clean
clean:
	@echo "Clean-up dorectory - remove all remporary files." 
	@rm -rf $(RESULT)
	@rm -rf *.o
	@rm -rf *.i
	@rm -rf *.s
	@rm -rf *.a
