#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"


void listarServicio(eServicio servicio){

	printf("%2d          %-10s           %2.f ARS\n", servicio.iD,
							                          servicio.descripcion,
											          servicio.precio);

}


void listarServicios(eServicio servicios[], int tam){

	printf("================================================\n");
	printf("\t   ***LISTA SERVICIOS***\n");
	printf("================================================\n");
	printf("ID             SERVICIO             PRECIO\n");
	printf("------------------------------------------------\n");
	for(int i = 0; i < tam; i ++){
		listarServicio(servicios[i]);
	}
	printf("================================================\n");

}




int cargaDescripServ(eServicio servicios[], int tamServ, int iDserv, char descripServicio[]){
	int retorno = 0;

	if(servicios != NULL && descripServicio != NULL && tamServ > 0){

		for(int i = 0; i < tamServ; i ++){

			if(servicios[i].iD == iDserv){

				strcpy(descripServicio, servicios[i].descripcion);
				break;

			}

		}

		retorno = 1;

	}

	return retorno;
}
