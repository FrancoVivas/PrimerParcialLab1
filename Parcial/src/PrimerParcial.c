/*
 ============================================================================
 Name        : PrimerParcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Perros.h"
#include "Estadia.h"
#include "Estadia-Perros.h"


int main(void)
{
	setbuf(stdout, NULL);

	int opcionMenu = 0;
	int idEstadia = 100000;
	int contadorEstadias = 0;
	float promedio = 0;

	sPerro perros[TAMPERROS];
	sEstadiaDiaria estadias[TAMESTADIA];

	estadia_inicializarEstadia(estadias, TAMESTADIA);
	perros_hardCodear(perros, TAMPERROS);
	estadiaPerros_menuOpciones(estadias, opcionMenu, &idEstadia, perros, &contadorEstadias, promedio);

	return EXIT_SUCCESS;
}
