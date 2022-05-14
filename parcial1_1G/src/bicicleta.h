#ifndef BICICLETA_H_
#define BICICLETA_H_

typedef struct{
	int iD;
	char descripcion[20];

}eTipo;


typedef struct{
	int idColor;
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
int modificarBicicleta(eBicicleta lista[], int tam);
int buscarBicicleta(eBicicleta lista[], int tam, int iD);
void moatrarBicicleta(eBicicleta bicicleta);
int mostrarBicicletas(eBicicleta lista[], int tam);
int menuModificar();
int bajaBicicleta(eBicicleta lista[], int tam);
