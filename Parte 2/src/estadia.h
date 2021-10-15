#ifndef ESTADIA_H_
#define ESTADIA_H_
#define TAMSTRING 35
#define OCUPADO 1
#define LIBRE 0
typedef struct
{
	int dia;
	int mes;
	int anio;

}eFecha;

typedef struct
{
	int id;
	char nombreDuenio[TAMSTRING];
	char telefonoContacto[10];
	int idPerro;
	eFecha fecha;
	int vacio;

}eEstadia;

void estadia_swapEstadias(eEstadia* estadia,int tamEstadia,int i);
int estadia_inicializarEstadiaLibre(eEstadia* estadia,int tam);
int estadia_buscarIndicelibre(eEstadia* estadia,int tam, int* idVacio);
int estadia_buscarEstadiaCargada(eEstadia* estadia,int tam,int* indice,int idEstadia);
int estadia_ordenarPorfecha(eEstadia* estadia,int tamEstadia);


#endif /* ESTADIA_H_ */
