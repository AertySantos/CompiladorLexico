#include <stdio.h>

#ifndef __WCHAR_H_SOURCED__
 /* ...which is exclusive to <wchar.h>, do we assert the multiple
  * inclusion guard for <stdio.h> itself.
  */
#define __USE_XOPEN
#endif 

#ifdef __WCHAR_H_SOURCED__
 /* ...which is exclusive to <wchar.h>, do we assert the multiple
  * inclusion guard for <stdio.h> itself.
  */
#define __USE_XOPEN
#endif 

#if __GNUC__ >= 3 && ! defined __PCC__
#pragma GCC system_header
#else
printf("cade o else\n");
#endif

int main(void) {
  
  #if __USE_XOPEN
    printf("Hello World\n");
    return 0;
  #else
    printf("Hello new World\n");
    return 22;
  #endif
  #if !__USE_UNIX98
    printf("Hello World2\n");
    return 0;
  #else
    printf("Hello new World2\n");
    return 0;
  #endif

}