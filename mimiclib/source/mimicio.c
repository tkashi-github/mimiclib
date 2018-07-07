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
#ifdef DWIN_TEST
#include <stdio.h>	//	TODO íœ‚·‚é
#include <stdlib.h>	//	TODO íœ‚·‚é
#endif

void mimic_printf(const char* fmt, ...){
	va_list arg;
	char szBuffer[1024];

	va_start(arg, fmt);
#ifdef DWIN_TEST
	vsnprintf(szBuffer, sizeog(szBuffer), fmt, arg);
#endif
	va_end(arg);
	
#ifdef DWIN_TEST
	puts(szBuffer);
#endif
}

#endif
