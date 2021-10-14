/*
 * Estadia-Perros.c
 *
 *  Created on: 14 oct. 2021
 *      Author: N3630024213
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Perros.h"
#include "Estadia.h"

void estadiaPerros_menuOpciones(sEstadiaDiaria estadias[], int opcionMenu, int *idEstadia, sPerro perros[], int* contadorEstadias, float promedio)
{
	do
		{
			pedirEntero(&opcionMenu, "------------------Menu------------------\n"
										"1. RESERVAR ESTADIA.\n"
										"2. MODIFICAR ESTADIA.\n"
										"3. CANCELAR ESTADIA.\n"
										"4. LISTAR ESTADIAS.\n"
										"5. LISTAR PERROS.\n"
										"6. Promedio de edad de los perros.\n"
										"7. Salir\n"
									"-----------------------------------------\n"
										"Ingrese la opcion deseada: ",
										"------------------Menu------------------\n"
										"1. RESERVAR ESTADIA.\n"
										"2. MODIFICAR ESTADIA.\n"
										"3. CANCELAR ESTADIA.\n"
										"4. LISTAR ESTADIAS.\n"
										"5. LISTAR PERROS.\n"
										"6. Promedio de edad de los perros.\n"
										"7. Salir\n"
									"-----------------------------------------\n"
										"ERROR - Reingrese una opcion valida: \n", 1, 7);

			switch(opcionMenu)
			{
				case 1 :
					if(estadia_agregarUna(estadias, TAMESTADIA, idEstadia) == 0)
					{
						contadorEstadias++;
					}
					system("pause");
				break;
				case 2 :
					if(contadorEstadias > 0)
					{
						estadia_modificarUna(estadias, TAMESTADIA);
					}
					else
					{
						printf("ERROR - Aun no se ah agregado ninguna estadia.\n");
					}
				break;
				case 3 :
					if(contadorEstadias > 0)
					{
						estadia_borrarUna(estadias, TAMESTADIA);
						contadorEstadias--;
					}
					else
					{
						printf("ERROR - Aun no se ah agregado ninguna estadia.\n");
					}
					system("pause");
				break;
				case 4 :
					if(contadorEstadias > 0)
					{
						estadia_ordenarEstadia(estadias, TAMESTADIA);
						printf("Ordenando estadias...");
						system("pause");
						estadia_listarVarias(estadias, TAMESTADIA);
					}
					else
					{
						printf("ERROR - Aun no se ah agregado ninguna estadia.\n");
					}

				break;
				case 5 :
					perros_listar(perros, TAMPERROS);
					system("pause");
				break;
				case 6 :
					promedio = perros_promediarEdad(perros, TAMPERROS);
					perros_mostrarPromedio(promedio);
				break;
				case 7 :
					printf("Cerrando el programa...");
				break;
			}


		}while(opcionMenu != 7);
}
