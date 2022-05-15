#ifndef TRABAJO_H_
#define TRABAJO_H_

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
	int isEmpty;

}eTrabajo;

#endif /* TRABAJO_H_ */


int initTrabajo(eTrabajo lista[], int tam);
int buscarLibreTrabajo(eTrabajo lista[], int tam);
int altaTrabajo(eTrabajo trabajo[], int tam, eBicicleta bicicletas[], int tamBici, eServicio servicios[], int tamServ, eTipo tipos[], int tamTip, eColor colores[], int tamCol, int* pId);
void listarTrabajo(eTrabajo trabajo, eServicio servicios[], int tamServ);
int listarTrabajos(eTrabajo trabajos[], int tam, eServicio servicios[], int tamServ);
int cargaDescripServ(eServicio servicios[], int tamServ, int iDserv, char descripServicio[]);
int ordenarListTrabajo(eTrabajo trabajos[], int tam);
