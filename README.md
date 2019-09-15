# mimiclib


 ## Notes:
 The MIMIC lib is a library for learning, and it is created with reference 
 to the C standard library. The purpose of learning is mainly as follows.
 * As small footprint as possible
 * Compliant with MISRA-C when possible
 * Learning Standard library for RTOS in C11
 * unusing <stdio.h>, <stdlib.h> and <string.h>

## Porting
Please implements following functions.

```
void MIMICLIB_GetChar(TCHAR *ch);
void MIMICLIB_PutChar(TCHAR ch);
void MIMICLIB_PutString(const TCHAR pszStr[], uint32_t SizeofStr);
_Bool MIMICLIB_kbhit(void);
uintptr_t MIMICLIB_MALLOC(uint32_t u32Size);
void MIMICLIB_FREE(uintptr_t ptr);
```

 ## using Libraries
 * cpputest (https://github.com/cpputest/cpputest) BSD-3-cause
  
 ## Change log
 See the [CAHNGELOG.md](https://github.com/tkashi-github/mimiclib/blob/master/CHANGELOG.md).

# Static Lib Information (MCUXpressoIDE)
```
make -r all 
Building file: ../source/mimiclib.c
Invoking: MCU C Compiler
arm-none-eabi-gcc -std=c11 -O2 -fno-common -g3 -Wall -Wextra -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -mcpu=cortex-m7 -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -fstack-usage -MMD -MP -MF"source/mimiclib.d" -MT"source/mimiclib.o" -MT"source/mimiclib.d" -o "source/mimiclib.o" "../source/mimiclib.c"
Finished building: ../source/mimiclib.c
 
Building target: libmimic.a
Invoking: MCU Archiver
arm-none-eabi-ar -r  "libmimic.a"  ./source/mimiclib.o   
arm-none-eabi-ar: creating libmimic.a
Finished building target: libmimic.a
 
make --no-print-directory post-build
Performing post-build steps
arm-none-eabi-size "libmimic.a" ; # arm-none-eabi-objdump -h -S "libmimic.a" >"libmimic.lss"
   text	   data	    bss	    dec	    hex	filename
   3748	      0	      0	   3748	    ea4	mimiclib.o (ex libmimic.a)
```

# Style
- indent is TAB
- 1 tab == 4 spaces
- UTF8 encoding
 