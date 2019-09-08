#include <stdio.h>
#include <stdlib.h> /* required becasue strtol  */
#include <fib.h>

#define REQUIRED_ARGS_NUM (2)


int main(int argc, char **argv) {

#ifdef DEBUG
  printf("\nDEBUG: %s[%u] argv[0]: %s\n", __FILE__, __LINE__, argv[0]);
#endif

  if (argc < REQUIRED_ARGS_NUM) {
    printf("\n You must specify possition value for which Fibonacci value will be calculated.\n");
    return -1;
  }

  int n = strtol(argv[1], NULL, 10);
  int value = fibonacci_get(n);

  printf("Fibonacci value for %d is %d.\n", n, value);

  return 0;
}
