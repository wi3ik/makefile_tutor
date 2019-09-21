all:
	gcc -c boo.c -o calc_boo.o -I.boo.h
	ar rcs libboo.a calc_boo.o 
	gcc -static main.c -L. -lboo -o result -I.boo.h

clear clean:
	rm -rf result
