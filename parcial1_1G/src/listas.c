#include <stdio.h>
#include <stdlib.h>
#include "bicicleta.h"
#include "trabajo.h"



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



void listarServicio(eServicio servicio){

	printf("%2d          %-10s            %2.f ARS\n", servicio.iD,
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


