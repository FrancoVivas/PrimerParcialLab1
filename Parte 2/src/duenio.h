#ifndef DUENIO_H_
#define DUENIO_H_
#define OCUPADO 1
#define LIBRE 0

typedef struct
{
	int id;
	char nombre[41];
	char contacto[11];
	int vacio;

}eDuenio;

void duenio_listarDuenio(eDuenio duenio);
int duenio_listarDuenios(eDuenio* duenio,int tamDuenio);
int duenio_buscarDuenioCargado(eDuenio* duenio,int tam,int* indice,int idDuenio);
#endif /* DUENIO_H_ */
