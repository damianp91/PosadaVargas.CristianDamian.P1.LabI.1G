#ifndef BICICLETA_H_
#define BICICLETA_H_


typedef struct{
	int iD;
	char descripcion[20];

}eTipo;


typedef struct{
	int id;
	char nombreColor[20];

}eColor;


typedef struct{
	int iD;
	char marca[20];
	eTipo idTipo;
	int rodado;
	eColor idColor;
	char material;
	int isEmpty;

}eBicicleta;


#endif /* BICICLETA_H_ */


/**
 * \Brief funcion sin parametros de ingreso que retorna un numero entero y muestra un menu de opciones
 *
 * return un numero de tipo int
 *
 */
int menu();


/**
 * \Brief toma una alista de de tipo struct para ingresar datos en sus campos
 * \param lista de tipo struct eBicicleta
 * \param tam de tipo int indica tamnio de lista
 *
 * \param pId puntero a int para aumetar el id en 1
 *
 * return retorna un 0 si no se logra efectuar la funcion y 1 si se puede efectuar la funcion
 *
 */
int altaBicicleta(eBicicleta lista[], int tam, int* pId);


/**
 * \Brief recibe dos parametros y en lista inicializa los campos isEmpty con 1
 * \param lista de tipo struct eBicicleta
 * \param tam de tipo int indica tamnio de lista
 *
 * return retorna un 0 si no se logra efectuar la funcion y 1 si se puede efectuar la funcion
 *
 */
int initBicicleta(eBicicleta lista[], int tam);


/**
 * \Brief recube dos parametros con los cuales busca en la primera ocurrencia el campo isEmpty vacio
 * \param lista de tipo struct eBicicleta
 * \param tam de tipo int indica tamnio de lista
 *
 * return -1 si no esposible efectuar la accion o el indice de la primera ocurrencia si el campo isEmpty esta vacio
 *
 */
int buscarLibre(eBicicleta lista[], int tam);


/**
 * \Brief recibe 6 parametros con los cuales se busca en el campo especifico para ser modificado
 * \param lista de tipo struct eBicicleta
 * \param tam de tipo int indica tamnio de lista
 * \param tipos de tipo struct eTipo array
 * \param tamTip de tipo int indica el tamaño del array
 * \param colores de tipo struct eColores
 * \param tamCol de tipo int indica el tamaño del array
 *
 * return retorna un 0 si no se logra efectuar la funcion y 1 si se puede efectuar la funcion
 *
 */
int modificarBicicleta(eBicicleta lista[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol);


/**
 * \Brief recibe tres parametros para buscar en la lista en el campo id coicida con el id ingresado
 * \param lista de tipo struct eBicicleta
 * \param tam de tipo int indica tamnio de lista
 * \param iD de tipo int indica el id que hay que buscar en eBicicleta
 *
 * return -1 si no esposible efectuar la accion o el indice de la primera ocurrencia si el campo isEmpty esta vacio
 *
 */
int buscarBicicleta(eBicicleta lista[], int tam, int iD);


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


/**
 * \Brief recibe 5 parametros para imprimir la informacion de los mismos
 * \param bicicleta de tipo struct eBicicleta
 * \param tipos de tipo struct eTipo array
 * \param tamTip de tipo int indica el tamaño del array
 * \param colores de tipo struct eColores
 * \param tamCol de tipo int indica el tamaño del array
 *
 * return void
 *
 */
void moatrarBicicleta(eBicicleta bicicleta, eTipo tipos[], int tamTip, eColor colores[], int tamCol);


/**
 * \Brief recibe 6 parametros con los cuales imprime la informacion de los mismos
 * \param lista de lista struct eBicicleta
 * \param tam de tipo int indica tamnio de lista
 * \param tipos de tipo struct eTipo array
 * \param tamTip de tipo int indica el tamaño del array
 * \param colores de tipo struct eColores
 * \param tamCol de tipo int indica el tamaño del array
 *
 * return retorna un 0 si no se logra efectuar la funcion y 1 si se puede efectuar la funcion
 *
 */
int mostrarBicicletas(eBicicleta lista[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol);


/**
 * \Brief funcion sin parametros de ingreso que retorna un numero entero y muestra un menu de opciones
 *
 * return un numero de tipo int
 *
 */
int menuModificar();


/**
 * \Brief recibe 6 parametros con los cuales buscan en la lista por id para hacer una baja logica del mismo
 * \param lista de lista struct eBicicleta
 * \param tam de tipo int indica tamnio de lista
 * \param tipos de tipo struct eTipo array
 * \param tamTip de tipo int indica el tamaño del array
 * \param colores de tipo struct eColores
 * \param tamCol de tipo int indica el tamaño del array
 *
 * return retorna un 0 si no se logra efectuar la funcion y 1 si se puede efectuar la funcion
 *
 */
int bajaBicicleta(eBicicleta lista[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol);


/**
 * \Brief recibe tres parametros con los cuales ordena una lista segun criterio 1 ascendente 0 descendente
 * \param bicicletas de lista struct eBicicleta
 * \param tam de tipo int indica tamnio de lista
 * \param criterio de tipo struct eTipo array
 *
 * return retorna un 0 si no se logra efectuar la funcion y 1 si se puede efectuar la funcion
 *
 *
 */
int ordenarListadoBicis(eBicicleta bicicletas[], int tam, int criterio);

