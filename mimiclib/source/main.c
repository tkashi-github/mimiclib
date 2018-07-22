

#include "mimicstring.h"
#include "mimicio.h"


int main(int argc, char *argv[]){

	// Addo Unit Test Here
	_Bool brt;
	mimic_printf("TEST suite :mimic_memcmp\r\n");
	mimic_printf("TEST CASE 1-1 input all o\r\n");
	brt = mimic_memcmp(0,0,0);
	if(brt == false){
		mimic_printf("TEST CASE 1-1 OK\r\n"); 
	}else{
		mimic_printf("TEST CASE 1-1 NG\r\n");
	}


	return 0;
}