#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "nexo.h"

void estadia_swapEstadias(eEstadia* estadia,int tamEstadia,int i)
{
	eEstadia auxEstadia;

	auxEstadia=estadia[i];
	estadia[i]=estadia[i+1];
	estadia[i+1]=auxEstadia;
}

int estadia_ordenarPorfecha(eEstadia* estadia,int tamEstadia)
{
	int ret=-1;
	int i;
	int flagSwap;
	int newLimite;

	if(estadia!=NULL && tamEstadia>0)
	{
		newLimite=tamEstadia;
		do
		{
			flagSwap=0;
			for(i=0;i<newLimite;i++)
			{
				if(estadia[i].vacio==OCUPADO && estadia[i+1].vacio==OCUPADO)
				{
					if(estadia[i].fecha.anio<estadia[i+1].fecha.anio)
					{
						estadia_swapEstadias(estadia, tamEstadia, i);
						flagSwap=1;
					}
					else if(estadia[i].fecha.anio==estadia[i+1].fecha.anio)
					{
						if(estadia[i].fecha.mes<estadia[i+1].fecha.mes)
						{
								estadia_swapEstadias(estadia, tamEstadia, i);
								flagSwap=1;
						}
						else if(estadia[i].fecha.mes==estadia[i+1].fecha.mes)
						{
							if(estadia[i].fecha.dia<estadia[i+1].fecha.dia)
							{
								estadia_swapEstadias(estadia, tamEstadia, i);
								flagSwap=1;
							}
							else if(estadia[i].fecha.dia==estadia[i+1].fecha.dia)
							{
								if(strcmp(estadia[i].nombreDuenio,estadia[i+1].nombreDuenio)==1)
								{
									estadia_swapEstadias(estadia, tamEstadia, i);
									flagSwap=1;
								}
							}
						}
					}
				}
			}

			newLimite--;
		}while(flagSwap);
		ret=0;
	}
	return ret;
}
int estadia_buscarEstadiaCargada(eEstadia* estadia,int tam,int* indice,int idEstadia)
{
	int ret=-1;
	if(estadia!=NULL && tam>0)
	{
		*indice=-1;
		for(int i=0;i<tam;i++)
		{
			if(estadia[i].vacio==OCUPADO)
			{
				if(idEstadia==estadia[i].id)
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
int estadia_buscarIndicelibre(eEstadia* estadia,int tam, int* idVacio)
{
	int ret=-1;
	if(estadia!=NULL && tam>0)
	{
		*idVacio=-1;
		for(int i=0;i<tam;i++)
		{
			if(estadia[i].vacio==LIBRE)
			{
				*idVacio=i;
				break;
			}
		}
		ret=0;
	}
	return ret;
}

int estadia_inicializarEstadiaLibre(eEstadia* estadia,int tam)
{
	int ret=-1;
	int i;
	if(estadia!=NULL && tam>0)
	{
		for(i=0;i<tam;i++)
		{
			estadia[i].vacio=LIBRE;
		}
		ret=0;
	}
	return ret;
}
