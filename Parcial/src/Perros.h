#ifndef PERROS_H_
#define PERROS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estadia.h"
#include "Funciones.h"

#define TAMNOMBRE 21
#define TAMPERROS 3

typedef struct
{
	int id;
	char nombre[TAMNOMBRE];
	char raza [TAMNOMBRE];
	int edad;
}sPerro;

void perros_hardCodear(sPerro perros[], int tam);
void perros_listar(sPerro perros[], int tam);
float perros_promediarEdad(sPerro perros[], int tam);
void perros_mostrarPromedio(float promedio);
#endif /* PERROS_H_ */
