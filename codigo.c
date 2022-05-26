#include <stdio.h>

int main(void) {
  #if defined __USE_XOPEN
    printf("Hello World\n");
    return 0;
  #else
    printf("Hello new World\n");
    return 22;
  #endif
  #if defined __USE_UNIX98 || defined __USE_XOPEN2K
    printf("Hello World22\n");
    return 0;
  #else
    printf("Hello new World2\n");
    return 0;
  #endif
}