#include <stdio.h>

#define __USE_XOPEN
int main(void) {
  
  int i = 0;
  printf("Hello World\n");
  i = 0;
  
  #if __USE_XOPEN
    printf("Hello World\n");
    i = 1;
  #else
    printf("Hello new World\n");
    i = 2;
  #endif
  #if _GCC_MAX_ALIGN_
    printf("Hello World5454554\n");
    i = 3;
  #else
    printf("Hello new World2\n");
    i = 4;
  #endif
  
}