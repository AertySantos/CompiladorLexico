#include <stdio.h>

#define __USE_XOPEN

#define !_GCC_MAX_ALIGN_

int main(void) {
  
  if(b == 10){
    printf "33";
  }

  int x = 0;
  
  printf("Hello World 0\n");
  i = 0;
  
  #if __USE_XOPEN
    printf("__USE_XOPEN 1\n");
    i = 1;
  #else
    printf("!__USE_XOPEN 2\n");
    i = 2;
  #endif
  
  #if _GCC_MAX_ALIGN_
    printf("_GCC_MAX_ALIGN_ 3\n");
    i = 3;
  #else
    printf("!_GCC_MAX_ALIGN_ 4\n");
    i = 4;
  #endif
  
  
    
}