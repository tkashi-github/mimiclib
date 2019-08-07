# mimiclib


 ## Notes:
 The MIMIC library is a library for learning, and it is created with reference 
 to the C standard library. The purpose of learning is mainly as follows.
 * As small footprint as possible
 * Compliant with MISRA-C when possible
 * Learning Standard library for RTOS in C11
 * unusing <stdio.h>, <stdlib.h> and <string.h>

## Porting
Please implements following 4 functions.

```
void MIMICLIB_GetChar(TCHAR *ch);
void MIMICLIB_PutChar(TCHAR ch);
void MIMICLIB_PutString(const TCHAR pszStr[]);
_Bool MIMICLIB_kbhit(void);
```

 ## using Libraries
 * cpputest (https://github.com/cpputest/cpputest) BSD-3-cause
  
 ## Change log
 See the [CAHNGELOG.md](https://github.com/tkashi-github/mimiclib/blob/master/CHANGELOG.md).

# Style
- indent is TAB
- 1 tab == 4 spaces
- UTF8 encoding
 