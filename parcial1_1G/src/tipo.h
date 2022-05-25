
#ifndef TIPO_H_
#define TIPO_H_

typedef struct{
	int iD;
	char descripcion[20];

}eTipo;

#endif /* TIPO_H_ */



/**
 * \Brief recibe un parametro struct del cual imprime su informacion
 * \param tipo de tipo struct eTipo
 *
 * return void
 *
 */
void listarTipo(eTipo tipo);



/**
 * \Brief recibe 2 parametros struct de los cuales imprime su informacion
 * \param tipos de tipo eTipos
 * \param tam de tipo int indica el tamaño del array tipos
 *
 * return void
 *
 */
void listarTipos(eTipo tipos[], int tam);




/**
 * \Brief recibe 4 parametrso con los cuales en una ocurrencia busca el codigo requerido para hacer una copia de la descripcion del id
 * \param tipos de tipo struct eTipo array
 * \param tamTip de tipo int indica el tamaño del array
 * \param idTipo de tipo int es el criterio de busqueda
 * \param descripTipo de tipo char cadena de caracter
 *
 * return retorna un 0 si no se logra efectuar la funcion y 1 si se puede efectuar la funcion
 *
 */
int cargaDescripTipo(eTipo tipos[], int tamTip, int idTipo, char descripTipo[]);


