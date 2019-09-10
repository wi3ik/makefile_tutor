#include <stdio.h>

int main(int argc, char **argv) {
  FILE *f = fopen("binary", "r+b");
  unsigned int opcode = 0x118c0f; // order should need reverted, 8d (jge) => 8c (jl) [ on Mac ]

// http://www.unixwiz.net/techtips/x86-jumps.html

/*
100000f51:	0f 8d 11 00 00 00 	jge	17 <_main+0x38>
                V
100000f51:	0f 8c 11 00 00 00 	jl	17 <_main+0x38>
*/

  fseek(f, 0xf51, SEEK_SET);

  fwrite(&opcode, sizeof(opcode), 1, f);

  fclose(f);

  return 0;
}
