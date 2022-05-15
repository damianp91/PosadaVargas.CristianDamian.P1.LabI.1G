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


int menu();
int altaBicicleta(eBicicleta lista[], int tam, int* pId);
int initBicicleta(eBicicleta lista[], int tam);
int buscarLibre(eBicicleta lista[], int tam);
int modificarBicicleta(eBicicleta lista[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol);
int buscarBicicleta(eBicicleta lista[], int tam, int iD);
int cargaDescripTipo(eTipo tipos[], int tamTip, int idTipo, char descripTipo[]);
int cargaDescripColor(eColor colores[], int tamCol, int idCol, char descripColor[]);
void moatrarBicicleta(eBicicleta bicicleta, eTipo tipos[], int tamTip, eColor colores[], int tamCol);
int mostrarBicicletas(eBicicleta lista[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol);
int menuModificar();
int bajaBicicleta(eBicicleta lista[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol);
int ordenarListadoBicis(eBicicleta bicicletas[], int tam, int criterio);
