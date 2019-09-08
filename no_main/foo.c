#include <stdio.h>


int no_main(int argc, char **argv) {

  printf("%s(%s)[%d]\n", __FILE__, __FUNCTION__, __LINE__);

  return 0;
}
