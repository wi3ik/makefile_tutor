#include <stdio.h>

int main(int argc, char **argv) {
  int a = 10;

  if (a < 11) {
    printf("We see excpected log message.\n");
  }
 
  return 0;
}

// objdump -S --section=.text binary
// objdump -S binary
