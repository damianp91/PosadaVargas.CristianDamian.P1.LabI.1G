#ifndef LISTAS_H_
#define LISTAS_H_


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




int listaColorSelec(eBicicleta lista[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol);



int listaTipoSelec(eBicicleta lista[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol);



int listaTiposBici(eBicicleta bicicletas[], int tam, int criterio);



int listaBiciMaterial(eBicicleta bicicletas[], int tam);



int litaConteoTipoColor(eBicicleta lista[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol);


#endif /* LISTAS_H_ */


