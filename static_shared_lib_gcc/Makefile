
# https://www.thegeekstuff.com/2012/06/linux-shared-libraries/

FNAME=logic
SHARED_NAME=shared
STATIC_NAME=static

OS_NAME:=$(shell sw_vers -productName)
#ifneq (,$(findstring Mac,$(OS_NAME)))
#	@echo "MAC"
#endif

help:
	@echo "make static - compile example using static library flow"
	@echo "make shared - the same but with shared library"
	@echo "make clean - remove all garbage"
	@echo $(OS_NAME)

static:
	@echo "won't work on Mac OSes"
	gcc -c $(FNAME).c -o calc_$(STATIC_NAME).o -I.$(FNAME).h
	ar rcs lib$(STATIC_NAME).a calc_$(STATIC_NAME).o 
	gcc -static main.c -L. -l$(STATIC_NAME) -o $(STATIC_NAME)_result -I.$(FNAME).h

shared:
	gcc -c -Wall -Werror -fPIC $(FNAME).c
	@echo "Now let's create Shared Library 'lib$(SHARED_NAME).so'"
	gcc -shared -o lib$(SHARED_NAME).so $(FNAME).o 
	@echo "Compile resulting file using shared library"
	@echo "Note that shared library may be stored at /lib or /usr/lib or /usr/local/lib folders"
	@echo "and you need to run 'ldconfig'"
	gcc -L. -Wall main.c -o $(SHARED_NAME)_result -l$(SHARED_NAME)

clear clean:
	rm -rf *result
	rm -rf *.a
	rm -rf *.o
	rm -rf *.so*

# shared libs may be stored at one of the following directories:
# /lib
# /usr/lib
# /usr/local/lib - third party libraries - may be baggy (not included to standart distributor)

# copy library to one of this folders and execute 'ldconfig'
