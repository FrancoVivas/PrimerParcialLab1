/*
 ============================================================================
 Name        : Parte.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "nexo.h"
#define TAMESTADIAS 100
#define TAMPERROS 3

int main(void) {
	setbuf(stdout,NULL);
	eEstadia estadia[TAMESTADIAS];
	ePerro perro[TAMPERROS]={{7000,"Lobo","Sharpie",2,OCUPADO},{7001,"Sheila","Golden",12,OCUPADO},{7002,"Reina","Galgo",13,OCUPADO}};
	int opcion;
	int ultimoId=100000;
	int contEstadias=0;

	if(estadia_inicializarEstadiaLibre(estadia, TAMESTADIAS))
	{
		printf("ERROR.En el tamaño o el puntero a estadia.\n");
	}
	do
	{

		requestNumber(&opcion,			     "-------------------------------------\n"
											 "1. RESERVAR Estadia\n"
											 "2. MODIFICAR Estadia\n"
											 "3. CANCELAR Estadia\n"
											 "4. LISTAR Estadia\n"
											 "5. LISTAR Perros\n"
											 "6. PROMEDIO de edad Perros\n"
											 "7. SALIR\n"
											 "-------------------------------------\n"
											 "Ingrese una opcion: ",
											 "-------------------------------------\n"
											 "1. RESERVAR Estadia\n"
											 "2. MODIFICAR Estadia\n"
											 "3. CANCELAR Estadia\n"
											 "4. LISTAR Estadia\n"
											 "5. LISTAR Perros\n"
											 "6. PROMEDIO de edad Perros\n"
											 "7. SALIR\n"
											 "-------------------------------------\n"
											 "Opcion invalida, reingrese: ", 1, 7);

				switch(opcion)
				{
					case 1:
						if(estadia_reservarEstadiaConPerroCargado(estadia, TAMESTADIAS, perro, TAMPERROS, &ultimoId, &contEstadias))
						{
							printf("ERROR.En el puntero a estadia,perro o tamanios del array menor a 0.\n");
						}
						systemPause("Pulse una tecla para continuar.....");
						break;
					case 2:
						if(contEstadias>0)
						{
							if(estadia_modificarEstadiaDePerro(estadia, TAMESTADIAS, perro, TAMPERROS))
							{
								printf("ERROR.En el puntero a estadia,perro o tamanios del array menor a 0.\n");
							}
						}
						else
						{
							printf("\nDebe cargar una estadia antes de poder Modificar.\n");
						}
						systemPause("Pulse una tecla para continuar.....");
						break;
					case 3:
						if(contEstadias>0)
						{
							if(estadia_eliminarEstadiaDePerro(estadia, TAMESTADIAS, perro, TAMPERROS, &contEstadias))
							{
								printf("ERROR.En el puntero a estadia,perro o tamanios del array menor a 0.\n");
							}
						}
						else
						{
							printf("\nDebe cargar una estadia antes de poder eliminar.\n");
						}
						systemPause("Pulse una tecla para continuar.....");
						break;
					case 4:
						if(contEstadias>0)
						{
							estadia_ordenarPorfecha(estadia, TAMESTADIAS);
							if(estadia_listarEstadiasConPerros(estadia, TAMESTADIAS, perro, TAMPERROS))
							{
								printf("ERROR.En el puntero a perro , estadia o tamanio de los array menor a 0.\n");
							}
						}
						else
						{
							printf("\nDebe cargar una estadia antes de poder mostrar.\n");
						}
						systemPause("Pulse una tecla para continuar.....");
						break;
					case 5:
						if(perro_ListarPerros(perro, TAMPERROS))
						{
							printf("ERROR.En el puntero a perro o tamanio del array menor a 0.\n");
						}
						systemPause("Pulse una tecla para continuar.....");
						break;
					case 6:
						if(perro_ListarPromedioEdadPerros(perro, TAMPERROS))
						{
							printf("ERROR.En el puntero a perro o tamanio del array menor a 0.\n");
						}
						systemPause("Pulse una tecla para continuar.....");
						break;
					case 7:
						printf("\nGracias por usar el organiza estadiadoreitor 9000!!.\n");
						break;
				}

	}while(opcion!=7);

	return EXIT_SUCCESS;
}
