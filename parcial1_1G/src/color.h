#ifndef COLOR_H_
#define COLOR_H_

typedef struct{
	int id;
	char nombreColor[20];

}eColor;


#endif /* COLOR_H_ */



/**
 * \Brief recibe un parametro struct del cual imprime su informacion
 * \param color de tipo struct eColor
 *
 * return void
 *
 */
void listarColor(eColor color);


/**
 * \Brief recibe 2 parametros struct de los cuales imprime su informacion
 * \param colores de tipo eColor
 * \param tam de tipo int indica el tamaño del array colores
 *
 * return void
 *
 */
void listarColores(eColor colores[], int tam);




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
int cargaDescripColor(eColor colores[], int tamCol, int idCol, char descripColor[]);


