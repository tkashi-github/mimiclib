/**
* @file mimicio.h
* @brief mimicio is insteadof stdio.h
* @author Takashi Kashiwagi
* @date 2018/7/5
* @details 
*/

#ifndef INCG_MIMICIO_H
#define INCG_MIMICIO_H

#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>

void mimic_printf(const char* fmt, ...);

#endif
