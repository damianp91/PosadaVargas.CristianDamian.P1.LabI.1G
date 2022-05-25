#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"


void listarTipo(eTipo tipo){

	printf("%2d          %-10s\n", tipo.iD,
			                       tipo.descripcion);

}



void listarTipos(eTipo tipos[], int tam){

	printf("============================\n");
	printf("     ***LISTA TIPOS***\n");
	printf("============================\n");
	printf("ID            TIPO\n");
	printf("-----------------------------\n");
	for(int i = 0; i < tam; i ++){
		listarTipo(tipos[i]);
	}
	printf("============================\n");

}



int cargaDescripTipo(eTipo tipos[], int tamTip, int idTipo, char descripTipo[]){
	int retorno = 0;

	if(tipos != NULL && descripTipo != NULL && tamTip > 0){

		for(int i = 0; i < tamTip; i ++){

			if(tipos[i].iD == idTipo){
				strcpy(descripTipo, tipos[i].descripcion);
				break;
			}

		}

		retorno = 1;

	}

	return retorno;
}


