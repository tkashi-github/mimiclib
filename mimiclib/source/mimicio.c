/**
* @file mimicio.c
* @brief mimicio is insteadof stdio.h
* @author Takashi Kashiwagi
* @date 2018/7/5
* @details 
*/

#ifndef INCG_MIMICIO_H
#define INCG_MIMICIO_H

#include "mimicio.h"
#include <stdarg.h>
#ifdef WIN_TEST
#include <stdio.h>	//	TODO íœ‚·‚é
#include <stdlib.h>	//	TODO íœ‚·‚é
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
