/*
 * perros.c
 *
 *  Created on: 15 oct. 2021
 *      Author: N3630024213
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "nexo.h"
#define OCUPADO 1
#define LIBRE 0


int perro_ListarPromedioEdadPerros(ePerro* perro,int tam)
{
	int ret=-1;
	int i;
	int contPerros=0;
	int acumEdad=0;
	float prom;
	if(perro!=NULL && tam>0)
	{
		for(i=0;i<tam;i++)
		{
			if(perro[i].vacio==OCUPADO)
			{
				acumEdad=acumEdad+perro[i].edad;
				contPerros++;
			}
		}
		divideFloat(&prom, acumEdad, contPerros);
		printf("\nEl promedio de edad de los perros es: %.2f años\n\n",prom);
		ret=0;
	}
	return ret;
}
void perro_ListarPerro(ePerro perro)
{
	printf("%-5d %-20s %-20s %-5d\n",perro.id,perro.nombre,perro.raza,perro.edad);
}
int perro_ListarPerros(ePerro* perro,int tam)
{
	int ret=-1;
	if(perro!=NULL && tam>0)
	{
		printf("\n%-5s %-20s %-20s %-5s\n\n","ID","NOMBRE","RAZA","EDAD");
		for(int i=0;i<tam;i++)
		{
			if(perro[i].vacio==OCUPADO)
			{
				perro_ListarPerro(perro[i]);
			}
		}
		printf("\n\n");
		ret=0;
	}
	return ret;
}

int perro_buscarPerroCargado(ePerro* perro,int tam,int* indice,int idPerro)
{
	int ret=-1;
	if(perro!=NULL && tam>0 && indice!=NULL)
	{
		*indice=-1;
		for(int i=0;i<tam;i++)
		{
			if(perro[i].vacio==OCUPADO)
			{
				if(perro[i].id==idPerro)
				{
					*indice=i;
					break;
				}
			}
		}
		ret=0;
	}
	return ret;
}
