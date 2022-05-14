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
#include"bicicleta.h"
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





int main(void) {
	setbuf(stdout, NULL);
	eBicicleta bicicletas[TAM];
	int iDbici = 1;
	//eTipo tipos[TAM];
	//eColor colores[TAM];
	//eServicio servicios[TAM];
	//eTrabajo trabajos[TAM];
	char seguir = 's';

	initBicicleta(bicicletas, TAM);

	do{
		switch(menu()){

		case 1:

			altaBicicleta(bicicletas, TAM, &iDbici);
			break;

		case 2:

			modificarBicicleta(bicicletas, TAM);
			break;

		case 3:

			bajaBicicleta(bicicletas, TAM);
			break;

		case 4:

			mostrarBicicletas(bicicletas, TAM);
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


















































