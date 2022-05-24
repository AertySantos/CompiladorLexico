#include <stdio.h>

int main(void) {
  #if defined __USE_XOPEN
    printf("Hello World\n");
    return 0;
  #else
    printf("Hello new World\n");
    return 0;
  #endif
}