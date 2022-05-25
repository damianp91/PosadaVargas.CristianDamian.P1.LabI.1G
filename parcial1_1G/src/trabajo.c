#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "trabajo.h"



int initTrabajo(eTrabajo lista[], int tam){
	int retorno = 0;

	if(lista != NULL && tam > 0){

		for(int i = 0; i < tam; i ++){
			lista[i].isEmpty = 1;
		}

		retorno = 1;

	}

	return retorno;

}



int buscarLibreTrabajo(eTrabajo lista[], int tam){
	int retorno = -1;

	if(lista != NULL && tam > 0){

		for(int i = 0; i < tam; i ++){

			if(lista[i].isEmpty){
				retorno = i;
				break;
			}

		}

	}

	return retorno;

}



int altaTrabajo(eTrabajo trabajo[], int tam, eBicicleta bicicletas[], int tamBici, eServicio servicios[], int tamServ, eTipo tipos[], int tamTip, eColor colores[], int tamCol, int* pId){
	int retorno = 0;
	eTrabajo auxTrabajo;
	int indice;

	if(trabajo != NULL && bicicletas != NULL && servicios != NULL && tipos != NULL && colores != NULL && pId != NULL && tam > 0 && tamBici > 0 && tamServ > 0 && tamTip > 0 && tamCol > 0){

		indice = buscarLibreTrabajo(trabajo, tam);

		if(indice >= 0){

			printf("===================================================================================================\n");
			printf("\t                           ***ALTA TRABAJO***\n");

			auxTrabajo.id = *pId;
			(*pId)++;

			mostrarBicicletas(bicicletas, tamBici, tipos, tamTip, colores, tamCol);

			while(!get_NumEnte(&auxTrabajo.idBici.iD, "Elija ID de bicicleta a realizar trabajo: ", "Error. opcion debe ser entre el listado de ids desplegados en pantalla\n", 1, 500)){
				printf("Vuelva a ingresar dato.\n");
			}

			listarServicios(servicios, tamServ);

			while(!get_NumEnte(&auxTrabajo.idServicio.iD, "Elija el servicio a realizar en bicicleta: ", "Error. opcion debe ser entre el listado de ids de servicios desplegados en pantalla\n", 20000, 20003)){
				printf("Vuelva a ingresar dato.\n");
			}

			while(!get_NumEnte(&auxTrabajo.fecharServicio.dia, "Ingrese dia inicio de trabajo: ", "Error. Dia fuera de rango.\n", 1, 31)){
				printf("Vuelva a ingresar dato.\n");
			}

			while(!get_NumEnte(&auxTrabajo.fecharServicio.mes, "Ingrese mes inicio de trabajo: ", "Error. mes fuera de rango.\n", 1, 12)){
				printf("Vuelva a ingresar dato.\n");
			}

			while(!get_NumEnte(&auxTrabajo.fecharServicio.anio, "Ingrese anio inicio de trabajo: ", "Error. anio fuera de rango.\n", 2020, 2070)){
				printf("Vuelva a ingresar dato.\n");
			}

			auxTrabajo.isEmpty = 0;

			trabajo[indice] = auxTrabajo;

			printf("===================================================================================================\n");

			retorno = 1;

		}

	}

	return retorno;

}



void listarTrabajo(eTrabajo trabajo, eServicio servicios[], int tamServ){
	char descripServicio[25];

	cargaDescripServ(servicios, tamServ, trabajo.idServicio.iD, descripServicio);

	printf("%2d             %2d              %10s              %02d/%02d/%d\n", trabajo.id,
			                                                                    trabajo.idBici.iD,
								                                                descripServicio,
												                                trabajo.fecharServicio.dia, trabajo.fecharServicio.mes, trabajo.fecharServicio.anio);

}



int ordenarListTrabajo(eTrabajo trabajos[], int tam){
	int retorno = 0;
	eTrabajo auxTrabajos;

	if(trabajos != NULL && tam > 0){

		for(int i = 0; i < tam - 1; i ++){
			for(int j = i + 1; j < tam; j ++){

				if(strcmp(trabajos[i].idServicio.descripcion, trabajos[j].idServicio.descripcion)){

					auxTrabajos = trabajos[i];
					trabajos[i] = trabajos[j];
					trabajos[j] = auxTrabajos;


				}

			}

		}

		retorno = 1;

	}

	return retorno;

}



int listarTrabajos(eTrabajo trabajos[], int tam, eServicio servicios[], int tamServ){
	int retorno = 0;
	int flag = 1;

	if(trabajos != NULL && tam > 0){

		printf("=====================================================================\n");
		printf("\t       ***LISTADO TRABAJOS***\n");
		printf("=====================================================================\n");
		printf(" ID          IDBICI              SERVICIO          FECHA DE SERVICIO\n");
		printf("=====================================================================\n");

		for(int i = 0; i < tam; i ++){

			if(!trabajos[i].isEmpty){

				listarTrabajo(trabajos[i], servicios, tamServ);
				flag = 0;

			}

		}
		printf("=====================================================================\n");

		if(flag){

			printf("No hay trabajos para mostrar.\n");

		}

		retorno = 1;

	}

	return retorno;

}


