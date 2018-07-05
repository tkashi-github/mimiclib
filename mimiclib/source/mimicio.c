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
#include <stdio.h>	//	TODO íœ‚·‚é
#include <stdlib.h>	//	TODO íœ‚·‚é


void mimic_printf(const char* fmt, ...){
	va_list arg;
	char szBuffer[1024];

	va_start(arg, fmt);
	vsnprintf(szBuffer, sizeog(szBuffer), fmt, arg);
	va_end(arg);
	
	puts(szBuffer);
}

#endif
