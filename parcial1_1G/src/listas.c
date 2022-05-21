#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"
#include "trabajo.h"
#include "utn.h"


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



//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------



int listaColorSelec(eBicicleta lista[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol){
	int retorno = 0;
	int eleccion;

	if(lista != NULL && tipos != NULL && colores != NULL && tam > 0 && tamTip > 0 && tamCol > 0){

		listarColores(colores, tamCol);

		while(!get_NumEnte(&eleccion, "Elija opcion: ","Error. opcion debe ser entre 5000 a 5004\n",5000, 5004)){
			printf("Vuelva a ingresar dato.\n");
		}

		if(eleccion >= 5000){

			printf("=====================================================================================================================\n");
			printf("\t                        ***LISTA BICICLETAS***\n");
			printf("---------------------------------------------------------------------------------------------------------------------\n");
			printf(" ID         MARCA             TIPO                RODADO               COLOR          MATERIAL            CLIENTE\n");
			printf("---------------------------------------------------------------------------------------------------------------------\n");
			for(int i = 0; i < tam; i ++){

				if(lista[i].idColor.id == eleccion){
					moatrarBicicleta(lista[i], tipos, tamTip, colores, tamCol);

				}
			}
			printf("=====================================================================================================================\n");

			retorno = 1;

		}

		else{

			printf("Eleccion incorrecta.\n");

		}



	}

	return retorno;

}



int listaTipoSelec(eBicicleta lista[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol){
	int retorno = 0;
	int eleccion;

	if(lista != NULL && tipos != NULL && colores != NULL && tam > 0 && tamTip > 0 && tamCol > 0){

		listarTipos(tipos, tamTip);

		while(!get_NumEnte(&eleccion, "Elija opcion: ","Error. opcion debe ser entre 1000 a 1003\n",1000, 1003)){
			printf("Vuelva a ingresar dato.\n");
		}

		if(eleccion >= 1000){

			printf("=====================================================================================================================\n");
			printf("\t                        ***LISTA BICICLETAS***\n");
			printf("---------------------------------------------------------------------------------------------------------------------\n");
			printf(" ID         MARCA             TIPO                RODADO               COLOR          MATERIAL            CLIENTE\n");
			printf("---------------------------------------------------------------------------------------------------------------------\n");
			for(int i = 0; i < tam; i ++){

				if(lista[i].idTipo.iD == eleccion){
					moatrarBicicleta(lista[i], tipos, tamTip, colores, tamCol);

				}
			}
			printf("=====================================================================================================================\n");

			retorno = 1;

		}

		else{

			printf("Eleccion incorrecta.\n");

		}



	}

	return retorno;

}



int listaTiposBici(eBicicleta bicicletas[], int tam, int criterio){
	int retorno = 0;
	eBicicleta auxBicicleta;

	if(bicicletas != NULL && tam > 0){

		for(int i = 0; i < tam - 1; i ++){
			for(int j = i + 1; j < tam; j ++){

				if(strcmp(bicicletas[i].idTipo.descripcion, bicicletas[j].idTipo.descripcion) > 0){

					auxBicicleta = bicicletas[i];
					bicicletas[i] = bicicletas[j];
					bicicletas[j] = auxBicicleta;

				}

			}

		}

		retorno = 1;

	}

	return retorno;
}



int listaBiciMaterial(eBicicleta bicicletas[], int tam){
	int retorno = 0;
	int contBiciCar = 0;
	int contBiciAl = 0;

	if(bicicletas != NULL && tam > 0){

		for(int i = 0; i < tam; i ++){

			if(bicicletas[i].material == 'a'){

				contBiciAl ++;

			}

			else if(bicicletas[i].material == 'c'){

				contBiciCar ++;

			}

		}

		printf("===================================================\n");
		printf("     CONTEO DE BICICLETAS POR MATERIAL\n");
		printf("===================================================\n");
		if(contBiciCar > contBiciAl){

			printf("HAY MAS BICICLETAS DE CARBONO\n");
			printf("TOTAL: %d\n", contBiciCar);
		}

		else if(contBiciCar < contBiciAl){

			printf("HAY MAS BICICLETAS DE ALUMINIO\n");
			printf("TOTAL: %d\n", contBiciAl);
		}

		else{

			printf("HAY LA MISMA CANTIDAD DE CARBONO Y ALUMINIO\n");
			printf("TOTAL DE BICICLETAS: %d\n", contBiciCar + contBiciAl);

		}

		retorno = 1;

	}

	return retorno;

}



int litaConteoTipoColor(eBicicleta lista[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol){
	int retorno = 0;
	int eleccion1;
	int eleccion2;
	int cont = 0;

	if(lista != NULL && tipos != NULL && colores != NULL && tam > 0 && tamTip > 0 && tamCol > 0){

		listarTipos(tipos, tamTip);

		while(!get_NumEnte(&eleccion1, "Elija opcion: ","Error. opcion debe ser entre 1000 a 1003\n",1000, 1003)){
			printf("Vuelva a ingresar dato.\n");
		}

		listarColores(colores, tamCol);

		while(!get_NumEnte(&eleccion2, "Elija opcion: ","Error. opcion debe ser entre 5000 a 5004\n",5000, 5004)){
			printf("Vuelva a ingresar dato.\n");
		}

		if(eleccion1 >= 1000 && eleccion2 >= 5000){

			printf("=====================================================================================================================\n");
			printf("\t                        ***LISTA BICICLETAS***\n");
			printf("---------------------------------------------------------------------------------------------------------------------\n");
			printf(" ID         MARCA             TIPO                RODADO               COLOR          MATERIAL            CLIENTE\n");
			printf("---------------------------------------------------------------------------------------------------------------------\n");
			for(int i = 0; i < tam; i ++){

				if(!lista[i].isEmpty && lista[i].idTipo.iD == eleccion1 && lista[i].idColor.id == eleccion2){
					moatrarBicicleta(lista[i], tipos, tamTip, colores, tamCol);
					cont ++;

				}
			}
			printf("=====================================================================================================================\n");
			printf("TOTAL DE BICICLETAS: %d\n", cont);

			retorno = 1;

		}

		else{

			printf("Eleccion incorrecta.\n");

		}



	}

	return retorno;

}



int contColSelec(eBicicleta bicicletas[], int tam){
	int retorno = 0;

	int contGris = 0;
	int contBlanco = 0;
	int contAzul = 0;
	int contNegro = 0;
	int contRojo = 0;


	if(bicicletas != NULL && tam > 0){

		for(int i = 0; i < tam; i ++){

			if(strcmp(bicicletas[i].idColor.nombreColor, "GRIS") == 0 ){

				contGris ++;

			}

			else if(strcmp(bicicletas[i].idColor.nombreColor, "BLANCO") == 0 ){

				contBlanco ++;

			}

			else if(strcmp(bicicletas[i].idColor.nombreColor, "AZUL") == 0 ){

				contAzul ++;

			}

			else if(strcmp(bicicletas[i].idColor.nombreColor, "NEGRO") == 0 ){

				contNegro ++;

			}

			else if(strcmp(bicicletas[i].idColor.nombreColor, "ROJO") == 0 ){

				contRojo ++;

			}

		}

		printf("=====================================\n");
		printf("         COLORES MAS ELEGIDOS\n");
		printf("=====================================\n");
		printf("EL COLOR O COLORES MAS ELEGIGOS SON:\n");

		if(contGris >= contBlanco && contGris >= contAzul && contGris >= contNegro && contGris >= contRojo){

			printf("gris %d\n", contGris);


		}

		else if(contBlanco >= contGris && contBlanco >= contAzul && contBlanco >= contNegro && contBlanco >= contRojo){

			printf("blanco %d\n", contBlanco);

		}


		else if(contAzul >= contGris && contAzul >= contBlanco && contAzul >= contNegro && contAzul >= contRojo){

			printf("azul %d\n", contAzul);

		}

		else if(contNegro >= contGris && contNegro >= contBlanco && contNegro >= contAzul && contNegro >= contRojo){

			printf("negro %d\n", contNegro);

		}

		else if(contRojo >= contGris && contRojo >= contBlanco && contRojo >= contAzul && contRojo >= contNegro){

			printf("rojo %d\n", contRojo);

		}

		printf("=====================================\n");

		retorno = 1;

	}

	return retorno;
}



