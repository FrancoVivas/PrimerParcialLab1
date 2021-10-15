#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "nexo.h"

int duenio_listarDuenios(eDuenio* duenio,int tamDuenio)
{
	int ret=-1;
	if(duenio!=NULL && tamDuenio>0)
	{
		printf("\n%-5s %-20s %-20s\n\n","ID","NOMBRE","CONTACTO");
		for(int i=0;i<tamDuenio;i++)
		{
			duenio_listarDuenio(duenio[i]);
		}
		ret=0;
	}
	return ret;
}

void duenio_listarDuenio(eDuenio duenio)
{
	printf("%-5d %-20s %-20s\n",duenio.id,duenio.nombre,duenio.contacto);
}

int duenio_buscarDuenioCargado(eDuenio* duenio,int tam,int* indice,int idDuenio)
{
	int ret=-1;
	if(duenio!=NULL && tam>0 && indice!=NULL)
	{
		*indice=-1;
		for(int i=0;i<tam;i++)
		{
			if(duenio[i].vacio==OCUPADO)
			{
				if(duenio[i].id==idDuenio)
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
