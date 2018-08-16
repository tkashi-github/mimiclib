/**
 * @file mimicio.c
 * @brief mimicio is insteadof stdio.h
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

#ifndef INCG_MIMICIO_H
#define INCG_MIMICIO_H

#include "mimicio.h"
#include <stdarg.h>
#ifdef WIN_TEST
#include <stdio.h>	//	TODO 削除する
#include <stdlib.h>	//	TODO 削除する
#include <string.h>
#endif

void mimic_printf(const char* fmt, ...){
	va_list arg;
	char szBuffer[1024];

	va_start(arg, fmt);
#ifdef WIN_TEST
	vsnprintf(szBuffer, sizeof(szBuffer), fmt, arg);
#endif
	va_end(arg);
	
#ifdef WIN_TEST
	puts(szBuffer);
#endif
}

#endif
