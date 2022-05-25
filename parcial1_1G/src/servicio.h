#ifndef SERVICIO_H_
#define SERVICIO_H_

typedef struct{
	int iD;
	char descripcion[25];
	float precio;

}eServicio;

#endif /* SERVICIO_H_ */


/**
 * \Brief recibe un parametro struct del cual imprime su informacion
 * \param servicio de tipo struct eServicio
 *
 * return void
 *
 */
void listarServicio(eServicio servicio);


/**
 * \Brief recibe 2 parametros struct de los cuales imprime su informacion
 * \param servicios de tipo eServicios
 * \param tam de tipo int indica el tamaño del array tipos
 *
 * return void
 *
 */
void listarServicios(eServicio servicios[], int tam);



/**
 * \Brief recibe 4 parametrso con los cuales en una ocurrencia busca el codigo requerido para hacer una copia de la descripcion del id
 * \param servicios de tipo struct eServicio array
 * \param tamServ de tipo int indica el tamaño del array
 * \param iDserv de tipo int es el criterio de busqueda
 * \param descripServicio de tipo char cadena de caracter
 *
 * return retorna un 0 si no se logra efectuar la funcion y 1 si se puede efectuar la funcion
 *
 */
int cargaDescripServ(eServicio servicios[], int tamServ, int iDserv, char descripServicio[]);


