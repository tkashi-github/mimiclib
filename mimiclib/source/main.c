
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
#include "mimicstring.h"
#include "mimicio.h"

#define TEST_STRING1	"0123456789"
#define TEST_STRING2	"0123456789\r\n"
#define TEST_STRING3	"cmd 00 11 222 333 444 555 666\r\n"

int main(int argc, char *argv[]){

	// Addo Unit Test Here
	{
		mimic_printf("TEST suite :mimic_memcmp\r\n");
		mimic_printf("TEST CASE 1-1 : mimic_memcmp((uintptr_t)\"00\", (uintptr_t)\"11\", 2) == false");
		mimic_printf("RESULT        : %s", mimic_memcmp((uintptr_t)"00", (uintptr_t)"11", 2)? "NG":"OK");
		mimic_printf("TEST CASE 1-2 : mimic_memcmp((uintptr_t)\"00\", (uintptr_t)\"00\", 2) != true");
		mimic_printf("RESULT        : %s", mimic_memcmp((uintptr_t)"00", (uintptr_t)"00", 2)? "OK":"NG");
		mimic_printf("TEST CASE 1-3 : mimic_memcmp((uintptr_t)\"123\", (uintptr_t)\"12\", 3) != true");
		mimic_printf("RESULT        : %s", mimic_memcmp((uintptr_t)"123", (uintptr_t)"12", 3)? "OK":"NG");
	}
	{
		mimic_printf("TEST suite :mimic_strlen\r\n");
		mimic_printf("TEST CASE 2-1 : mimic_strlen(%s) == 10u", TEST_STRING1);
		mimic_printf("RESULT        : %s", mimic_strlen(TEST_STRING1) == 10u ? "OK":"NG");
		mimic_printf("TEST CASE 2-2 : mimic_strlen(%s) == 12u", TEST_STRING2);
		mimic_printf("RESULT        : %s", mimic_strlen(TEST_STRING2) == 12u ? "OK":"NG");
	}

	{
		char szStr[256];
		char *ctx;
		char *pszStr;
		uint32_t argc = 0;
		mimic_strcpy(szStr, TEST_STRING3, 256);

		pszStr = mimic_strtok(szStr, " ", &ctx);

		while(pszStr != NULL){
			mimic_printf("arg[%02u] %s <%s>\r\n", argc, pszStr, ctx);
			argc++;
			pszStr = mimic_strtok(NULL, " ", &ctx);
		}
	}
	
	return 0;
}