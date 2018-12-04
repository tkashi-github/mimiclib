
/**
 * @file main.c
 * @brief unit test
 * @author Takashi Kashiwagi
 * @date 2018/7/5
 * @details 
 * --
 * License Type <MIT License>
 * --
 * Copyright 2018 Takashi Kashiwagi
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a 
 * copy of this software and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including without limitation 
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 * and/or sell copies of the Software, and to permit persons to whom the 
 * Software is furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included 
 * in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
 * DEALINGS IN THE SOFTWARE.
 */
#include "mimiclib.h"
#include <stdio.h>
#define TEST_STRING1	"0123456789"
#define TEST_STRING2	"0123456789\n"
#define TEST_STRING3	"cmd 00 11 222 333 444 555 666\n"

static void UnitTeset(void);

static const char *s_pszArgTest[] = {
	"cmd",
	"00",
	"11",
	"222",
	"333",
	"444",
	"555",
	"666\n",
};


int main(int argc, char *argv[]){
	UnitTeset();
	return 0;
}

static void UnitTeset(void){
	mimic_printf("123456\n");
	mimic_printf("123456 = %d\n", 123456);
	mimic_printf("123456 = %u\n", 123456);
	mimic_printf("ABCDE = %s\n", "ABCDE");
	mimic_printf("0x01 = 0x%02X\n", 1);
	mimic_printf("ABCDE = %10s\n", "ABCDE");
	mimic_printf("ABCDE = %-10s\n", "ABCDE");
	// Addo Unit Test Here
		char szStr[256];
	{
		printf("TEST suite :mimic_memcmp\n");
		printf("TEST CASE 1-1 : mimic_memcmp((uintptr_t)\"00\", (uintptr_t)\"11\", 2) == false\n");
		printf("RESULT        : %s\n", mimic_memcmp((uintptr_t)"00", (uintptr_t)"11", 2)? "NG":"OK");
		printf("TEST CASE 1-2 : mimic_memcmp((uintptr_t)\"00\", (uintptr_t)\"00\", 2) != true\r\n");
		printf("RESULT        : %s\n", mimic_memcmp((uintptr_t)"00", (uintptr_t)"00", 2)? "OK":"NG");
		printf("TEST CASE 1-3 : mimic_memcmp((uintptr_t)\"123\", (uintptr_t)\"12\", 3) != true\n");
		printf("RESULT        : %s\n", mimic_memcmp((uintptr_t)"123", (uintptr_t)"12", 3)? "OK":"NG");
	}
	{
		printf("TEST suite :mimic_strlen\n");
		printf("TEST CASE 2-1 : mimic_strlen(%s) == 10u\n", TEST_STRING1);
		printf("RESULT        : %s\n", mimic_strlen(TEST_STRING1) == 10u ? "OK":"NG");
		printf("TEST CASE 2-2 : mimic_strlen(%s) == 12u\n", TEST_STRING2);
		printf("RESULT        : %s\n", mimic_strlen(TEST_STRING2) == 12u ? "OK":"NG");
	}
	{
		mimic_printf("0 = %s\n", mimic_ltoa(0, szStr, sizeof(szStr)));
		mimic_printf("%d = %s\n", INT32_MAX, mimic_ltoa(INT32_MAX, szStr, sizeof(szStr)));
		mimic_printf("%d = %s\n", INT32_MIN, mimic_ltoa(INT32_MIN, szStr, sizeof(szStr)));

		mimic_printf("0 = %s\n", mimic_ultoa(0, szStr, sizeof(szStr), 10));
		mimic_printf("%lu = %s\n", INT32_MAX, mimic_ultoa(INT32_MAX, szStr, sizeof(szStr), 10));
		mimic_printf("%lu = %s\n", UINT32_MAX, mimic_ultoa(UINT32_MAX, szStr, sizeof(szStr), 10));

		mimic_printf("0x0 = %s\n", mimic_ultoa(0, szStr, sizeof(szStr), 16));
		mimic_printf("0x%08lX = %s\n", INT32_MAX, mimic_ultoa(INT32_MAX, szStr, sizeof(szStr), 16));
		mimic_printf("0x%08lX = %s\n", UINT32_MAX, mimic_ultoa(UINT32_MAX, szStr, sizeof(szStr), 16));

		mimic_printf("0 = %s\n", mimic_lltoa(0, szStr, sizeof(szStr)));
		mimic_printf("%lld = %s\n", INT64_MAX, mimic_lltoa(INT64_MAX, szStr, sizeof(szStr)));
		mimic_printf("%lld = %s\n", INT64_MIN, mimic_lltoa(INT64_MIN, szStr, sizeof(szStr)));

		mimic_printf("0 = %s\n", mimic_ulltoa(0, szStr, sizeof(szStr), 10));
		mimic_printf("%llu = %s\n", INT64_MAX, mimic_ulltoa(INT64_MAX, szStr, sizeof(szStr), 10));
		mimic_printf("%llu = %s\n", UINT64_MAX, mimic_ulltoa(UINT64_MAX, szStr, sizeof(szStr), 10));
		mimic_printf("0x%llX = %s\n", INT64_MAX, mimic_ulltoa(INT64_MAX, szStr, sizeof(szStr), 16));
		mimic_printf("0x%llX = %s\n", UINT64_MAX, mimic_ulltoa(UINT64_MAX, szStr, sizeof(szStr), 16));

		mimic_printf("0.123456 = %s\n", mimic_ftoa(0.123456, szStr, sizeof(szStr), 6));
		mimic_printf("-0.123456 = %s\n", mimic_ftoa(-0.123456, szStr, sizeof(szStr), 6));
		mimic_printf("1.23456 = %s\n", mimic_ftoa(1.23456, szStr, sizeof(szStr), 6));
		mimic_printf("-1.23456 = %s\n", mimic_ftoa(-1.23456, szStr, sizeof(szStr), 6));		
	}
	{
		char *ctx;
		char *pszStr;
		
		mimic_strcpy(szStr, TEST_STRING3, 256);

		pszStr = mimic_strtok(szStr, " ", &ctx);
		printf("szStr = %s\n", szStr);
		for(uint32_t i=0u;i<sizeof(s_pszArgTest)/sizeof(char*);i++){
			printf("arg[%02u] %s\n", i, pszStr);
			printf("mimic_strcmp  : %s\n", mimic_strcmp(pszStr, s_pszArgTest[i]) ? "OK":"NG");
			pszStr = mimic_strtok(NULL, " ", &ctx);
		}
	}

}