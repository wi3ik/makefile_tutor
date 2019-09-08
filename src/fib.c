#include <fib.h>

int fibonacci_get(int n) {

  if (n <= 1) {
    return n;
  }
  return fibonacci_get(n-1) + fibonacci_get(n-2);
}
