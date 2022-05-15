/*
 ============================================================================
 Name        : parcial1_1G.c
 Author      : Cristian Damian Posada Vargas
 Version     : 1
 Copyright   : Your copyright notice
 Description : ABM de bicicletas.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "bicicleta.h"
#include "trabajo.h"
#include "listas.h"


#define TAM 5
#define TAM_TIP 4
#define TAM_COL 5
#define TAM_SERV 4
#define ASC 1
#define DESC 0


int main(void) {
	setbuf(stdout, NULL);
	int iDbici = 1;
	int iDTrabajo = 1;
	char seguir = 's';
	eBicicleta bicicletas[TAM];
	eTrabajo trabajos[TAM];
	eTipo tipos[TAM_TIP] = {

		{1000, "RUTERA"},
		{1001, "CARRERA"},
		{1002, "MOUNTAIN"},
		{1003, "BMX"},

	};
	eColor colores[TAM_COL] = {

		{5000, "GRIS"},
		{5001, "BLANCO"},
		{5002, "AZUL"},
		{5003, "NEGRO"},
		{5004, "ROJO"}

	};
	eServicio servicios[TAM_SERV] = {

		{20000, "LIMPIEZA", 30},
		{20001, "PARCHE", 400},
		{20002, "CENTRADO", 500},
		{20003, "CADENA", 450},

	};

	initBicicleta(bicicletas, TAM);
	initTrabajo(trabajos, TAM);

	do{
		switch(menu()){

		case 1:

			if(altaBicicleta(bicicletas, TAM, &iDbici)){
				printf("Alta de bicicleta exitosa.\n");
			}

			break;

		case 2:

			if(modificarBicicleta(bicicletas, TAM, tipos, TAM_TIP, colores, TAM_COL)){
				printf("Modificacion de bicicleta exitosa.\n");
			}

			break;

		case 3:

			if(bajaBicicleta(bicicletas, TAM, tipos, TAM_TIP, colores, TAM_COL)){
				printf("Baja de bicicleta exitosa.\n");
			}

			break;

		case 4:

			if(!ordenarListadoBicis(bicicletas, TAM, ASC)){
				printf("No se pudo hacer el ordenamiento de la lista.\n");
			}
			if(mostrarBicicletas(bicicletas, TAM, tipos, TAM_TIP, colores, TAM_COL)){
				printf("Listado de bicicletas final.\n");
			}

			break;

		case 5:

			listarTipos(tipos, TAM_TIP);

			break;

		case 6:

			listarColores(colores, TAM_COL);

			break;

		case 7:

			listarServicios(servicios, TAM_SERV);

			break;

		case 8:

			if(altaTrabajo(trabajos, TAM, bicicletas, TAM, servicios, TAM_SERV, tipos, TAM_TIP, colores, TAM_COL, &iDTrabajo)){
				printf("Alta de trabajo dada con exito.\n");

			}

			break;

		case 9:

			ordenarListTrabajo(trabajos, TAM);
			listarTrabajos(trabajos, TAM, servicios, TAM_SERV);

			break;

		case 10:

			printf("Saliendo...");
			printf("\n\n");
			seguir = 'n';

			break;

		}

		system("pause");

	}while(seguir == 's');

	return EXIT_SUCCESS;

}

