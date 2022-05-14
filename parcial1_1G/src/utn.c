#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int get_NumEnte(int* pResultado, char* pMensaje, char* pMensError, int min, int max){
	int retorno = 0;
	int numero;
	if(pResultado != NULL && pMensaje != NULL && pMensError != NULL && min <= max){

		printf("%s", pMensaje);
		fflush(stdin);
		scanf("%d", &numero);

		if(numero >= min && numero <= max){
			*pResultado = numero;
			retorno = 1;
		}
		else{
			printf("%s", pMensError);
		}

	}

	return retorno;
}


int get_NumFlota(float* pResultado, char* pMensaje, char* pMensError, float min, float max){
	int retorno = 0;
	float numero;
	if(pResultado != NULL && pMensaje != NULL && pMensError != NULL && min <= max){

		printf("%s", pMensaje);
		fflush(stdin);
		scanf("%f", &numero);

		if(numero >= min && numero <= max){
			*pResultado = numero;
			retorno = 1;
		}
		else{
			printf("%s", pMensError);
		}

	}

	return retorno;

}


int get_Caracter(char* pResultado, char* pMensaje, char* pMensError, char min, char max){
	int retorno = 0;
	char caracter;
	if(pResultado != NULL && pMensaje != NULL && pMensError != NULL && min <= max){

		printf("%s", pMensaje);
		fflush(stdin);
		scanf("%c", &caracter);

		if(caracter >= min && caracter <= max){
			*pResultado = caracter;
			retorno = 1;
		}
		else{
			printf("%s", pMensError);
		}

	}

	return retorno;
}


int get_String(char pString[], char* pMensaje, char* pMensError, int max){
	int retorno = 0;
	char auxString[100];

	if(pString != NULL && pMensaje != NULL && pMensError != NULL){

		printf("%s", pMensaje);
		fflush(stdin);
		gets(auxString);

		if(strlen(auxString) < max){
			strcpy(pString, auxString);
			retorno = 1;

		}else{
			printf("%s", pMensError);
		}

	}

	return retorno;
}




















