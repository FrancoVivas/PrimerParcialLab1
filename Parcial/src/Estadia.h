#ifndef ESTADIA_H_
#define ESTADIA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Perros.h"
#include "Funciones.h"

#define TAMESTADIA 3
#define TAMNOMBREDOS 51
#define VACIO 1
#define OCUPADO 0

typedef struct
{
	int id;
	char nombreDuenio[TAMNOMBREDOS];
	int telefonoContacto;
	int idPerro;
	int fechaDia;
	int fechaMes;
	int estado;

}sEstadiaDiaria;


void estadia_inicializarEstadia(sEstadiaDiaria estadias[], int tam);
int estadia_buscarEspacio(sEstadiaDiaria estadias[], int tam);
int estadia_agregarUna(sEstadiaDiaria estadias[], int tam, int* id);
int estadia_establecerEstadia(sEstadiaDiaria* estadias, int i, int id);
void estadia_ordenarEstadia(sEstadiaDiaria estadias[], int tam);
void estadia_listarUna(sEstadiaDiaria* estadias);
void estadia_listarVarias(sEstadiaDiaria estadias[], int tam);
int estadia_borrarUna(sEstadiaDiaria estadias[], int tam);
int estadia_buscarPorId(sEstadiaDiaria estadias[], int tam, int i);
int estadia_verificarConfirmacion(char* mensaje);
void estadia_mostrarModificacion(sEstadiaDiaria estadias[], int index, char* mensaje);
int estadia_modificarUna(sEstadiaDiaria estadias[], int tam);

#endif /* ESTADIA_H_ */
