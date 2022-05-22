#include <stdio.h>

int main(void) {
  #if  1 = 2
    printf("Hello World\n");
    return 0;
  #else
    printf("Hello new World\n");
    return 0;
  #endif
}