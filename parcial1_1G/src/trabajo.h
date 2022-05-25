#include "bicicleta.h"
#include "servicio.h"
#include "fecha.h"


#ifndef TRABAJO_H_
#define TRABAJO_H_


typedef struct{
	int id;
	eBicicleta idBici;
	eServicio idServicio;
	eFecha fecharServicio;
	int isEmpty;

}eTrabajo;


#endif /* TRABAJO_H_ */



/**
 * \Brief recibe 2 parametros con los cuales inicializa un array struct en su campo isEmpty con un 1
 * \param lista struc eTrabajo
 * \param tam de tipo int
 *
 * return retorna un 0 si no se logra efectuar la funcion y 1 si se puede efectuar la funcion
 *
 */
int initTrabajo(eTrabajo lista[], int tam);



/**
 * \Brief recibe 2 parametros con los cuales busca en array struct en la primera interacion el campo libre
 * \param lista struc eTrabajo
 * \param tam de tipo int
 *
 * return retorna un -1 si no se logra efectuar la funcion y el indice en el que esta ubicado el espacio libre
 *
 */
int buscarLibreTrabajo(eTrabajo lista[], int tam);



/**
 * \Brief recibe 10 parametros con los cuales se agrega informacion en los campos de trabajo
 * \param trabajo de tipo struct eTrabajo
 * \param tam tipo int indica tamnio de lista
 * \param bicicletas de tipo struct eBicicleta
 * \param tamBici de tipo int indica tamnio de lista
 * \param servicios de tipo struct eServicio
 * \param tamServ tipo int indica tamnio de lista
 * \param tipos de tipo struct eTipo array
 * \param tamTip de tipo int indica el tamaño del array
 * \param colores de tipo struct eColores
 * \param tamCol de tipo int indica el tamaño del array
 * \param pId puntero int
 *
 * return retorna un 0 si no se logra efectuar la funcion y 1 si se puede efectuar la funcion
 *
 */
int altaTrabajo(eTrabajo trabajo[], int tam, eBicicleta bicicletas[], int tamBici, eServicio servicios[], int tamServ, eTipo tipos[], int tamTip, eColor colores[], int tamCol, int* pId);



/**
 * \Brief recibe 3 parametros con los cuales imprime la informacion del valor trabajo
 * \param trabajo de tipo struct eTrabajo
 * \param servicios de tipo struct eServicio
 * \param tamServ tipo int indica tamnio de lista
 *
 * return void
 *
 */
void listarTrabajo(eTrabajo trabajo, eServicio servicios[], int tamServ);



/**
 * \Brief recibe 4 parametros con los cuales imprime la informacion de la lista trabajo
 * \param trabajo de tipo struct eTrabajo
 * \param tam tipo int indica tamnio de lista
 * \param servicios de tipo struct eServicio
 * \param tamServ tipo int indica tamnio de lista
 *
 * return retorna un 0 si no se logra efectuar la funcion y 1 si se puede efectuar la funcion
 *
 */
int listarTrabajos(eTrabajo trabajos[], int tam, eServicio servicios[], int tamServ);



/**
 * \Brief recibe 2 parametros con los cuales ordena una lista segun criterio 1 ascendente 0 descendente
 * \param trabajos de lista struct eTrabajo
 * \param tam de tipo int indica tamnio de lista
 *
 * return retorna un 0 si no se logra efectuar la funcion y 1 si se puede efectuar la funcion
 *
 */
int ordenarListTrabajo(eTrabajo trabajos[], int tam);


