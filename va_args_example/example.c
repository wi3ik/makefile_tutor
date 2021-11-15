#include<stdio.h>



#define NARGS_SEQ(_1, _2, _3, _4, _5, _6, _7, _8, N, ...) N
#define NARGS(...) NARGS_SEQ(__VA_ARGS__, 7, 6, 5, 4, 3, 2, 1, 0)
#define PRIMITIVE_CAT(x, y) x ## y
#define CAT(x, y) PRIMITIVE_CAT(x, y)

char *prt_fnc_3(char *s, int a, int b, int c) {
    char aa[100];
    sprintf(aa, "#3 string: %s\n int1: %d, int2: %d int3: %d\n", s, a, b, c);
    printf("%s", aa);
    return "fnc_3";
}

char *prt_fnc_2(char *s, int a, int b) {
    char aa[100];
    sprintf(aa, "#2 string: %s\n int1: %d, int2: %d\n", s, a, b);
    printf("%s", aa);
    return "fnc_2";
}

#define foo(...) CAT(prt_fnc_, NARGS(__VA_ARGS__)(__VA_ARGS__))


int main() {

  printf("%s\n", foo("fnc_with_3_args", 4, 2, 3) );
  printf("%s\n", foo("fnc_with_2_args", 4, 3) );

  return 0;
}



