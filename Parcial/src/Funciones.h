#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Perros.h"
#include "Estadia.h"

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

int pedirEntero(int* enteroDevuelto, char* mensaje, char* mensajeError, int min, int max);
void pedirString(char* nombre, char* primerMensaje, char* mensajeError, int max);
int pedirFlotante(float* flotanteDevuelto, char* mensaje, char* mensajeError, int min, int max);
void pedirCaracter(char* caracter, char* mensaje);
int validarSigno(char* string);

#endif /* FUNCIONES_H_ */
