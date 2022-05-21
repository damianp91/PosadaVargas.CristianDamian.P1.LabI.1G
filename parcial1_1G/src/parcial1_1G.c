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


#define TAM 500
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
	int contVal = 0;
	int contTra = 0;
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
				contVal ++;
			}

			break;

		case 2:

			if(contVal){
				modificarBicicleta(bicicletas, TAM, tipos, TAM_TIP, colores, TAM_COL);

			}

			else{

				printf("Primero debe ingresar por lo menos una bicicleta para poder hacer esta accion.\n");

			}

			break;

		case 3:

			if(contVal){
				bajaBicicleta(bicicletas, TAM, tipos, TAM_TIP, colores, TAM_COL);
				contVal --;

			}

			else{

				printf("Primero debe ingresar por lo menos una bicicleta para poder hacer esta accion.\n");

			}

			break;

		case 4:

			if(contVal){

				if(!ordenarListadoBicis(bicicletas, TAM, ASC)){
					printf("No se pudo hacer el ordenamiento de la lista.\n");
				}

				if(mostrarBicicletas(bicicletas, TAM, tipos, TAM_TIP, colores, TAM_COL)){
					printf("Listado de bicicletas final.\n");
				}

			}

			else{

				printf("Primero debe ingresar por lo menos una bicicleta para poder hacer esta accion.\n");

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

			listaColorSelec(bicicletas, TAM, tipos, TAM_TIP, colores, TAM_COL);

			break;

		case 9:

			listaTipoSelec(bicicletas, TAM, tipos, TAM_TIP, colores, TAM_COL);

			break;

		case 10:

			listaBiciMaterial(bicicletas, TAM);

			break;

		case 11:

			listaTiposBici(bicicletas, TAM, ASC);
			mostrarBicicletas(bicicletas, TAM, tipos, TAM_TIP, colores, TAM_COL);

			break;

		case 12:

			litaConteoTipoColor(bicicletas, TAM, tipos, TAM_TIP, colores, TAM_COL);

			break;

		case 13:

			printf("ordenar\n");

			break;

		case 14:

			if(altaTrabajo(trabajos, TAM, bicicletas, TAM, servicios, TAM_SERV, tipos, TAM_TIP, colores, TAM_COL, &iDTrabajo)){
				printf("Alta de trabajo dada con exito.\n");
				contTra ++;

			}

			break;

		case 15:

			if(contTra){

				ordenarListTrabajo(trabajos, TAM);
				listarTrabajos(trabajos, TAM, servicios, TAM_SERV);

			}

			else{

				printf("Primero debe ingresar por lo menos un trabajo para poder hacer esta accion.\n");

			}

			break;

		case 16:

			printf("Saliendo...");
			printf("\n\n");
			seguir = 'n';

			break;

		}

		system("pause");

	}while(seguir == 's');

	return EXIT_SUCCESS;

}

