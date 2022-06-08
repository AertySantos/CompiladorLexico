#include <stdio.h>

#define _GCC_MAX_ALIGN_
#define __USE_XOPEN

int main(void) {
  
  if(b == 10){
    printf "33";
  }

  int x = 0;
  
  printf("Hello World 0\n");
  i = 0;
  
  #if __USE_XOPEN
    printf("Hello World 1\n");
    i = 1;
  #else
    printf("Hello World 2\n");
    i = 2;
  #endif
  
  #if _GCC_MAX_ALIGN_
    printf("Hello World 3\n");
    i = 3;
  #else
    printf("Hello World 4\n");
    i = 4;
  #endif
  
  
    
}