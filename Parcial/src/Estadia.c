#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estadia.h"
#include "Perros.h"
#include "Funciones.h"

void estadia_inicializarEstadia(sEstadiaDiaria estadias[], int tam)
{
	int i;

	for(i = 0; i < tam; i++)
	{
		estadias[i].estado = VACIO;
	}
}
int estadia_buscarEspacio(sEstadiaDiaria estadias[], int tam)
{
	int i;
	int index = -1;

	for(i = 0; i < tam; i++)
	{
		if(estadias[i].estado == VACIO)
		{
			index = i;
			break;
		}
	}

	return index;
}
int estadia_agregarUna(sEstadiaDiaria estadias[], int tam, int* id)
{
	int retorno = -1;
	int index = estadia_buscarEspacio(estadias, tam);
	int idIncrementada = *id;

	if(index != -1)
	{
		if(!estadia_establecerEstadia(estadias, index, *id))
		{
			printf("Se establecio la estadia.\n\n");
			idIncrementada++;
			*id = idIncrementada;

		}
		else
		{
			printf("Se cancelo la carga de la estadia.\n\n");
		}
		retorno = 0;
	}
	else
	{
		printf("NO hay espacio disponible.\n\n");
	}
	return retorno;
}
int estadia_establecerEstadia(sEstadiaDiaria estadias[], int i, int id)
{
	int retorno = -1;

	estadias[i].id = id;
	pedirString(estadias[i].nombreDuenio, "Ingrese el nombre del dueño: ", "ERROR - reingrese el nombre correctamente: ", TAMNOMBREDOS);
	pedirEntero(&estadias[i].telefonoContacto, "Ingrese el telefono del dueño: ", "ERROR - reingrese el numero correctamente: ", 10000000, 99999999);
	pedirEntero(&estadias[i].idPerro, "Ingrese el ID del perro deseado: ", "ERROR - reingrese el ID correctamente: ",7000, 7002);
	pedirEntero(&estadias[i].fechaDia, "Ingrese el dia deseado (1 - 30): ", "ERROR - Ingrese un dia valido (1 - 30): ", 1, 30);
	pedirEntero(&estadias[i].fechaMes, "Ingrese el mes deseado (1 - 12): ", "ERROR - Ingrese un mes valido (1 - 12): ", 1 , 12);

	estadia_mostrarModificacion(estadias, i, "Desea agregar la siguiente estadia?: \n");
	if(estadia_verificarConfirmacion("\nIngrese 'S' para confirmar la carga de la estadia: ") == 0)
	{
		estadias[i].estado = OCUPADO;
		retorno = 0;
	}

	return retorno;
}
int estadia_borrarUna(sEstadiaDiaria estadias[], int tam)
{
	int retorno = -1;
	int id;
	int index;

	pedirEntero(&id, "Ingrese el ID de la estadia que desea cancelar: ", "ERROR - Ese ID no existe, reingrese: ", 100000, 100003);
	index = estadia_buscarPorId(estadias, tam, id);

	estadia_mostrarModificacion(estadias, index, "\nDesea eliminar la siguiente estadia?: \n");
	if(index != -1)
	{
		if(estadia_verificarConfirmacion("Ingrese 'S' para confirmar la baja de la estadia: \n") == 0)
		{
			estadias[index].estado = VACIO;
			printf("\nEstadia de %s dada de baja correctamente!\n", estadias[index].nombreDuenio);
		}
		else
		{
			printf("\nSe cancelo la baja de la estadia\n");
		}
		retorno = 0;

	}
	else
	{
		printf("\nERROR - Estadia no encontrada...\n");
	}

	return retorno;
}
int estadia_buscarPorId(sEstadiaDiaria estadias[], int tam, int id)
{
	int i;
	int index = -1;

	for(i = 0; i < tam; i++)
		{
			if(estadias[i].estado == OCUPADO && estadias[i].id == id)
			{
				index = i;
				break;
			}
		}
	return index;
}
int estadia_modificarUna(sEstadiaDiaria estadias[], int tam)
{
	int retorno = -1;
	int opcionSubMenu;
	int idIngresada;
	int index;

	pedirEntero(&idIngresada, "Ingrese el ID de la estadia a modificar: ", "ERROR - Esa ID no existe, reingrese: ", 100000, 100003);
	index = estadia_buscarPorId(estadias, tam, idIngresada);

	pedirEntero(&opcionSubMenu, "1. Modificar telefono\n"
								"2. Modificar id del Perro\n"
								"---------------------------\n"
								"Ingrese la opcion deseada: ",
								"---------------------------\n"
								"1. Modificar telefono\n"
								"2. Modificar id del Perro\n"
								"---------------------------\n"
								"ERROR - reingrese la opcion deseada: ", 1, 2);
	switch(opcionSubMenu)
	{
		case 1 :
			if(index != -1)
			{
				estadia_mostrarModificacion(estadias, index, "Desea modificar el telefono de la siguiente estadia?: \n");
				if(estadia_verificarConfirmacion("Ingrese 'S' para confirmar: ") == 0)
				{
					pedirEntero(&estadias[index].telefonoContacto, "Ingrese el nuevo numero del cliente: ", "ERROR - Ese no es un numero valido, reingrese: ",10000000 , 99999999);
					printf("Numero modificado correctamente...\n");
				}
				else
				{
					printf("Se cancelo la modificacion del telefono...\n");
				}
			retorno = 0;
			}
			system("pause");
		break;
		case 2 :
			if(index != -1)
			{
				estadia_mostrarModificacion(estadias, index, "Desea modificar el ID del perro de la siguiente estadia?: \n");
				if(estadia_verificarConfirmacion("Ingrese 'S' para confirmar: ") == 0)
				{
					pedirEntero(&estadias[index].idPerro, "Ingrese el nuevo ID del perro nuevo: ", "ERROR - Ese ID de perro no existe, reingrese: ", 7000, 7002);
					printf("ID del perro modificado correctamente...\n");
				}
				else
				{
					printf("Se cancelo la modificacion del ID del perro...\n");
				}
			}
			system("pause");
		break;
	}

	return retorno;
}
void estadia_ordenarEstadia(sEstadiaDiaria estadias[], int tam)
{
	int flagSwap;
	int i;
	sEstadiaDiaria auxEstadia;
	int nuevoLimite;

	do
	{
		nuevoLimite = tam -1;
		flagSwap = 0;
		for(i = 0; i < nuevoLimite; i++)
		{
			if(estadias[i].fechaDia < estadias[i+1].fechaDia && estadias[i].fechaMes < estadias[i+1].fechaMes)
			{
				auxEstadia = estadias[i];
				estadias[i] = estadias[i+1];
				estadias[i+1]= auxEstadia;

				flagSwap = 1;

			}
			else
			{
				if(estadias[i].fechaDia == estadias[i+1].fechaDia && estadias[i].fechaMes == estadias[i+1].fechaMes)
				{
					if(strcmp(estadias[i].nombreDuenio, estadias[i+1].nombreDuenio) == 1)
					{
						auxEstadia = estadias[i];
						estadias[i] = estadias[i+1];
						estadias[i+1] = auxEstadia;

					}

				}
			}
		}

	}while(flagSwap);
}
void estadia_mostrarModificacion(sEstadiaDiaria estadias[], int index, char* mensaje)
{

	printf("%s", mensaje);
	printf("%-10s - %-20s - %-20s - %-20s - %-20s\n\n", "ID", "Nombre", "Telefono", "ID del Perro", "Fecha");
	printf("%-10d - %-20s - %-20d - %-20d - %d/%d\n", estadias[index].id, estadias[index].nombreDuenio, estadias[index].telefonoContacto, estadias[index].idPerro, estadias[index].fechaDia, estadias[index].fechaMes);
}
void estadia_listarUna(sEstadiaDiaria* estadias)
{
	printf("%-10d - %-20s - %-20d - %-20d - %d/%d\n",
	(*estadias).id, (*estadias).nombreDuenio, (*estadias).telefonoContacto, (*estadias).idPerro, (*estadias).fechaDia,(*estadias).fechaMes);
}
void estadia_listarVarias(sEstadiaDiaria estadias[], int tam)
{
	int i;

	printf("%-10s - %-20s - %-20s - %-20s - %-20s\n\n", "ID", "Nombre", "Telefono", "ID del Perro", "Fecha");
	for(i = 0; i < tam; i++)
	{
		if(estadias[i].estado == OCUPADO)
		{
			estadia_listarUna(&estadias[i]);
		}

	}
}
int estadia_verificarConfirmacion(char* mensaje)
{
	int retorno = -1;
	char respuesta;

	pedirCaracter(&respuesta, mensaje);
	if(respuesta == 's' || respuesta == 'S')
	{
		retorno = 0;
	}

return retorno;
}
