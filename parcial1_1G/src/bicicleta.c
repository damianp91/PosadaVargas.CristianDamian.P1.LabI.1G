#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "bicicleta.h"



int menu(){
	int opcion;

	printf("===================================\n");
	printf("\t   ***TALLER DE BICIS***\n");
	printf("\t1) Alta bicicleta.\n");
	printf("\t2) Modificar bicicleta.\n");
	printf("\t3) Baja bicicleta.\n");
	printf("\t4) listar bicicletas.\n");
	printf("\t5) Listar tipos.\n");
	printf("\t6) Listar colores.\n");
	printf("\t7) Listar servicios.\n");
	printf("\t8) Alta trabajo.\n");
	printf("\t9) Listar trabajo.\n");
	printf("\t10) Salir.\n");
	printf("===================================\n");
	while(!get_NumEnte(&opcion, "Ingrese opcion: ", "Error. Ingrese opcion(1 al 10)\n", 1, 10)){
		printf("Intente de nuevo.\n");
	}

	return opcion;
}



int initBicicleta(eBicicleta lista[], int tam){
	int retorno = 0;

	if(lista != NULL && tam > 0){

		for(int i = 0; i < tam; i ++){
			lista[i].isEmpty = 1;
		}

		retorno = 1;

	}

	return retorno;

}



int buscarLibre(eBicicleta lista[], int tam){
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



int altaBicicleta(eBicicleta lista[], int tam, int* pId){
		int retorno = 0;
		int indice;
		eBicicleta auxBicicleta;

		if(lista != NULL && pId != NULL && tam > 0){

			indice = buscarLibre(lista, tam);

			if(indice == -1){

				printf("No hay lugar para guardar mas biicletas.\n");

			}else{

				printf("===================================================================================================\n");
				printf("\t                           ***ALTA BICICLETA***\n");
				auxBicicleta.iD = *pId;
				(*pId)++;

				while(!get_String(auxBicicleta.marca, "Ingrese marca de bicicleta: ", "Error nombre demasiado largo\n", 20)){
					printf("Vuelva a ingresar dato.\n");
				}



				while(!get_NumEnte(&auxBicicleta.idTipo.iD, "\nTIPO:\n1000) Rutera.\n1001) Carrera.\n1002) Mountain.\n1003) BMX.\nElija opcion: ", "Error. opcion debe ser entre 1000 a 1003\n", 1000, 1003)){
					printf("Vuelva a ingresar dato.\n");
				}

				while(!get_NumEnte(&auxBicicleta.rodado, "\nRODADO:\n1) Rodado 16.\n2) Rodado 26.\n3) Rodado 27.\n4) Rodado 29.\nEscriba rodado de eleccion: ", "Error. opcion debe ser entre 16, 26, 27 o 29\n", 16, 29)){
					printf("Vuelva a ingresar dato.\n");
				}

				while(!get_NumEnte(&auxBicicleta.idColor.id, "\nCOLOR:\n5000) Gris.\n5001) Blanco.\n5002) Azul.\n5003) Negro\n5004) Rojo.\nElija opcion: ","Error. opcion debe ser entre 5000 a 5004\n",5000, 5004)){
					printf("Vuelva a ingresar dato.\n");
				}

				while(!get_Caracter(&auxBicicleta.material, "\nMATERIAL:\na) Aluminio.\nc) Carbono.\nElija opcion: ", "Error. Debe elejir entre 'a' o 'c'\n" ,'a','c')){
					printf("Vuelva a ingresar dato.\n");
				}

				auxBicicleta.isEmpty = 0;

				lista[indice] = auxBicicleta;

				printf("===================================================================================================\n");

				retorno = 1;

			}

		}

		return retorno;

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



int ordenarListadoBicis(eBicicleta bicicletas[], int tam, int criterio){
	int retorno = 0;
	eBicicleta auxBicicleta;

	if(bicicletas != NULL && tam > 0){

		for(int i = 0; i < tam - 1; i ++){
			for(int j = i + 1; j < tam; j ++){

				if((bicicletas[i].idTipo.iD == bicicletas[j].idTipo.iD && bicicletas[i].rodado > bicicletas[j].rodado && criterio) || (bicicletas[i].idTipo.iD > bicicletas[j].idTipo.iD && criterio) ||
				   (bicicletas[i].idTipo.iD == bicicletas[j].idTipo.iD && bicicletas[i].rodado < bicicletas[j].rodado && !criterio) || (bicicletas[i].idTipo.iD < bicicletas[j].idTipo.iD && !criterio)){

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



void moatrarBicicleta(eBicicleta bicicleta, eTipo tipos[], int tamTip, eColor colores[], int tamCol){
	char descripTipo[20];
	char descripColor[20];

	cargaDescripTipo(tipos, tamTip, bicicleta.idTipo.iD, descripTipo);


	cargaDescripColor(colores, tamCol, bicicleta.idColor.id, descripColor);


	printf(" %2d   %10s          %10s               %2d            %10s               %c\n", bicicleta.iD,
			                                                                                 bicicleta.marca,
																				             descripTipo,
															                                 bicicleta.rodado,
																					         descripColor,
															                                 bicicleta.material);

}



int mostrarBicicletas(eBicicleta lista[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol){
	int retorno = 0;
	int flag = 1;

	if(lista != NULL && tipos != NULL && colores != NULL && tam > 0 && tamTip > 0 && tamCol > 0){

		printf("===================================================================================================\n");
		printf("\t                        ***LISTA BICICLETAS***\n");
		printf("---------------------------------------------------------------------------------------------------\n");
		printf(" ID         MARCA             TIPO                RODADO               COLOR          MATERIAL \n");
		printf("---------------------------------------------------------------------------------------------------\n");
		for(int i = 0; i < tam; i ++){

			if(!lista[i].isEmpty){
				moatrarBicicleta(lista[i], tipos, tamTip, colores, tamCol);
				flag = 0;

			}
		}
		printf("===================================================================================================\n");

		if(flag){

			printf("No hay bicicletas para mostrar\n");

		}

		retorno = 1;

	}

	return retorno;

}



int buscarBicicleta(eBicicleta lista[], int tam, int iD){
	int retorno = -1;

	if(lista != NULL && tam > 0 && iD){

		for(int i = 0; i < tam; i ++){

			if(!lista[i].isEmpty && lista[i].iD == iD){

				retorno = i;
				break;

			}

		}

	}

	return retorno;

}



int menuModificar(){
	int opcion;

	printf("\t1) Tipo.\n");
	printf("\t2) Rodado.\n");
	printf("\t3) Salir.\n");
	printf("===================================================================================================\n");
	while(!get_NumEnte(&opcion, "Ingrese opcion: ", "Error. Ingrese opcion(1 al 3)\n", 1, 3)){
		printf("Intente de nuevo.\n");
	}

	return opcion;
}



int modificarBicicleta(eBicicleta lista[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol){
	int retorno = 0;
	int iD;
	int indice;
	int auxTipoBici;
	int auxRodado;


	if(lista != NULL && tipos != NULL && colores != NULL && tam > 0 && tamTip > 0 && tamCol > 0){

		printf("===================================================================================================\n");
		printf("\t                ***MODIFICAR BICICLETA***\n");
		if(!get_NumEnte(&iD, "Ingrese id de la bicicleta: ", "Id no esta registrado. ", 1, 500)){
			printf("Intente de nuevo.\n");
		}

		indice = buscarBicicleta(lista, tam , iD);

		if(indice >= 0){
			printf("---------------------------------------------------------------------------------------------------\n");
			printf(" ID         MARCA             TIPO                RODADO               COLOR          MATERIAL \n");
			printf("---------------------------------------------------------------------------------------------------\n");
			moatrarBicicleta(lista[indice], tipos, tamTip, colores, tamCol);
			printf("===================================================================================================\n");

			switch(menuModificar()){

			case 1:

				while(!get_NumEnte(&auxTipoBici, "1000) Rutera.\n1001) Carrera.\n1002) Mountain.\n1003) BMX.\nElija opcion: ", "Error. opcion debe ser entre 1000 a 1003\n", 1000, 1003)){
					printf("Vuelva a ingresar dato.\n");
				}
				lista[indice].idTipo.iD = auxTipoBici;

				break;

			case 2:

				while(!get_NumEnte(&auxRodado, "1) Rodado 16.\n2) Rodado 26.\n3) Rodado 27.\n4) Rodado 29.\nElija opcion: ", "Error. opcion debe ser entre 1 a 4\n", 1, 4)){
					printf("Vuelva a ingresar dato.\n");
				}
				lista[indice].rodado = auxRodado;

				break;

			case 3:

				printf("Regresando a menu principal.\n");

				break;

			}

			printf("Modificacion de bicicleta exitosa.\n");

		}

		else{

			printf("El id ingresado no esta registrado en sistema.\n");

		}

	}

	return retorno;
}



int bajaBicicleta(eBicicleta lista[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol){
	int retorno = 0;
	int iD;
	int  indice;
	char baja;

	if(lista != NULL && tipos != NULL && colores != NULL && tam > 0 && tamTip > 0 && tamCol > 0){

		printf("===================================================================================================\n");
		printf("\t                       ***BAJA BICICLETA***\n");

		if(!get_NumEnte(&iD, "Ingrese id de la bicicleta: ", "Id no esta registrado. ", 1, 500)){
			printf("Intente de nuevo.\n");
		}

		indice = buscarBicicleta(lista, tam, iD);

		if(indice >= 0){
			printf("---------------------------------------------------------------------------------------------------\n");
			printf(" ID         MARCA             TIPO                RODADO               COLOR          MATERIAL \n");
			printf("---------------------------------------------------------------------------------------------------\n");
			moatrarBicicleta(lista[indice], tipos, tamTip, colores, tamCol);
			printf("---------------------------------------------------------------------------------------------------\n");
			while(!get_Caracter(&baja, "¿Esta seguro de dar de baja a esta bicicleta?: ", "Error. Haga una eleccion entre 's' o 'n'\n", 'n', 's')){
				printf("Vuelva a ingresar dato.\n");

			}

			if(baja == 's'){

				lista[indice].isEmpty = 1;
				retorno = 1;
				printf("Baja de bicicleta exitosa.\n");

			}

			else{

				printf("Se ha cancelado baja por usuario.\n");

			}

		}

		else{

			printf("El id ingresado no esta registrado en sistema.\n");

		}

	}

	return retorno;
}


