/*
 ============================================================================
 Name        : parcial1_1G.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "bicicleta.h"
#include "listas.h"


typedef struct{
	int dia;
	int mes;
	int anio;

}eFecha;


typedef struct{
	int iD;
	char descripcion[25];
	float precio;

}eServicio;



typedef struct{
	int id;
	eBicicleta idBici;
	eServicio idServicio;
	eFecha fecharServicio;

}eTrabajo;



#define TAM 3
#define TAM_TIP 4
#define TAM_COL 5

int main(void) {
	setbuf(stdout, NULL);
	eBicicleta bicicletas[TAM];
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

	int iDbici = 1;
	char seguir = 's';

	initBicicleta(bicicletas, TAM);

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

			mostrarBicicletas(bicicletas, TAM, tipos, TAM_TIP, colores, TAM_COL);

			break;

		case 5:

			listarTipos();

			break;

		case 6:

			listarColores();

			break;

		case 7:

			listarServicios();

			break;

		case 8:

			printf("Alta trabajo.\n");

			break;

		case 9:

			printf("Listar trabajo.\n");

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


















































