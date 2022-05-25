#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"


void listarColor(eColor color){

	printf("%2d          %-10s\n", color.id,
				                   color.nombreColor);

}



void listarColores(eColor colores[], int tam){

	printf("============================\n");
	printf("   ***LISTA COLORES***\n");
	printf("============================\n");
	printf("ID            TIPO\n");
	printf("-----------------------------\n");
	for(int i = 0; i < tam; i ++){
		listarColor(colores[i]);
	}
	printf("============================\n");

}




int cargaDescripColor(eColor colores[], int tamCol, int idCol, char descripColor[]){
    int retorno = 0;

	if(colores != NULL && descripColor != NULL && tamCol > 0){

		for(int i = 0; i < tamCol; i ++){

			if(colores[i].id == idCol){

				strcpy(descripColor, colores[i].nombreColor);
				break;

			}

		}

		retorno = 1;

	}

	return retorno;
}



