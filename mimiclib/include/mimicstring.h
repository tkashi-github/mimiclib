/*
 * File Name   : mimicstring.h
 * Description : instead of string.h
 * Author      : Takashi Kashiwagi
 * URL         : https://github.com/tkashi-github
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
#ifndef INCG_MIMIC_STRING_H
#define INCG_MIMIC_STRING_H

#if __STDC_VERSION__ < 201112L 
#error /* This Library supports C11 or later */
#endif

#include <stdint.h>
#include <stdbool.h>

#ifndef NULL
#define NULL	(0u)
#endif

static inline _Bool mimic_memcmp(uintptr_t p1, uintptr_t p2, uint32_t u32ByteCnt){
	/*-- var --*/
	uint8_t *pu81 = (uint8_t*)p1;
	uint8_t *pu82 = (uint8_t*)p2;
	_Bool bret = false;

	/*-- begin --*/
	for(uint32_t i=0u;i<u32ByteCnt;i++){
		if(pu81[i] != pu82[i]){
			bret = false;
			break;
		}
	}

	return bret;
}

static inline uint32_t mimic_strlen(const char pszStr[]){
	/*-- var --*/
	uint32_t u32Cnt = 0u;

	/*-- begin --*/
	if(pszStr != NULL){
		while(pszStr[u32Cnt] != '\0'){
			u32Cnt++;
		}
	}

	return u32Cnt;
}
static inline char *mimic_strcpy(char szDst[], const char szSrc[], uint32_t u32DstSize){
	/*-- var --*/
	uint32_t u32Cnt = 0u;

	/*-- begin --*/
	if((szDst != NULL) && (szSrc != NULL)){
		while(szSrc[u32Cnt] != '\0'){
			szDst[u32Cnt] = szSrc[u32Cnt];
			u32Cnt++;
			if(u32Cnt >= u32DstSize){
				szDst[u32Cnt - 1u] = '\0';
				break;
			}
		}
	}

	return szDst;
}

static inline _Bool mimic_strcmp(const char szStr1[], const char szStr2[]){
	/*-- var --*/
	uint32_t u32Cnt = 0u;
	_Bool bret = false;

	/*-- begin --*/
	if((szStr1 != NULL) && (szStr2 != NULL)){
		bret = true;
		for(;;){
			if(szStr1[u32Cnt] != szStr2[u32Cnt]){
				bret = false;
				break;
			}
			if(szStr1[u32Cnt] == '\0'){
				break;
			}
			u32Cnt++;
		}
	}

	return bret;
}

static inline char *mimic_strtok(char szStr[], const char szDelm[], char **ctx){
	/*-- var --*/
	char *pret = NULL;
	uint32_t u32=0u;

	/*-- begin --*/
	if(szDelm != NULL){
		uint32_t delmLen = mimic_strlen(szDelm);

		if(szStr != NULL){
			while(szStr[u32] != '\0'){
				if(mimic_memcmp((uintptr_t)&szStr[u32], (uintptr_t)szDelm, delmLen) != false){
					szStr[u32] = '\0';
					*ctx = &szStr[u32 + delmLen]; 
				}
				u32++;
			}
			pret = szStr;
		}else{
			char *pszTmp = *ctx;
			while(pszTmp[u32] != '\0'){
				if(mimic_memcmp((uintptr_t)&pszTmp[u32], (uintptr_t)szDelm, delmLen) != false){
					pszTmp[u32] = '\0';
					*ctx = &pszTmp[u32 + delmLen]; 
				}
				u32++;
			}
			pret = szStr;
		}
	}
	return pret;
}


#endif
