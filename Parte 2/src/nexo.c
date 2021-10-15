#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "nexo.h"



int estadia_modificarEstadiaDePerro(eEstadia* estadia,int tamEstadia,ePerro* perro,int tamPerro)
{
	int ret=-1;
	int idEstadia;
	int indice;
	int indicePerro;
	int opcion;
	int idPerro;
	eEstadia auxEstadia;
	if(estadia!=NULL && perro!=NULL && tamEstadia>0 && tamPerro>0)
	{
		if(estadia_listarEstadiasConPerros(estadia, tamEstadia, perro, tamPerro))
		{
			printf("ERROR.En el puntero a perro , estadia o tamanio de los array menor a 0.\n");
		}
		if(requestNumber(&idEstadia, "Ingrese el Id de la estadia a modificar: ", "ERROR.El id Ingresado no es valido.\nReingrese id de Estadia: ", 100000, 200000))
		{
			printf("ERROR.En el puntero a mensaje ,numero o mensaje error.\n");
		}
		if(estadia_buscarEstadiaCargada(estadia, tamEstadia, &indice, idEstadia))
		{
			printf("ERROR.En el puntero estadia o tamanio de array menor a 0.\n");
		}
		if(indice!=-1)
		{

			perro_buscarPerroCargado(perro, tamPerro, &indicePerro, estadia[indice].idPerro);
			estadia_listarEstadiaConPerro(estadia[indice], perro[indicePerro]);
			printf("\n");

			do
			{
				perro_buscarPerroCargado(perro, tamPerro, &indicePerro, estadia[indice].idPerro);
				auxEstadia=estadia[indice];
				requestNumber(&opcion,		 "-------------------------------------\n"
											 "1. MODIFICAR telefono de contacto\n"
											 "2. MODIFICAR Perro\n"
											 "3. ATRAS\n"
											 "-------------------------------------\n"
											 "Ingrese una opcion: ",
											 "-------------------------------------\n"
											 "1. MODIFICAR telefono de contacto\n"
											 "2. MODIFICAR Perro\n"
											 "3. ATRAS\n"
											 "-------------------------------------\n"
											 "Opcion invalida, reingrese: ", 1,3);
				switch(opcion)
				{
					case 1:
						estadia_listarEstadiaConPerro(estadia[indice], perro[indicePerro]);
						if(requestNumberPhone(auxEstadia.telefonoContacto,"Ingrese un numero contacto del dueño de la mascota: ", "ERROR.El Numero ingresado no es valido,no debe contener letras o caracteres y debe tener un 10digitos.\nReingrese numero de contacto: ", 10))
						{
							printf("ERROR.En el puntero a string\n");
						}
						printf("\nEstadia luego de la modificacion: \n\n");
						estadia_listarEstadiaConPerro(auxEstadia, perro[indicePerro]);
						if(!requestCharacterAnswer("ingrese (s) para modificar la estadia: "))
						{
							estadia[indice]=auxEstadia;
							printf("\n\nLa modificacion se realizo correctamente.\n\n");
						}
						else
						{
							printf("\n\nSe cancelo la modificacion del contacto.\n\n");
						}

						break;
					case 2:
						estadia_listarEstadiaConPerro(estadia[indice], perro[indicePerro]);
						printf("\n\n");
						if(perro_ListarPerros(perro, tamPerro))
						{
							printf("ERROR.En el puntero perro o tamanio de array menor a 0.\n");
						}
						if(requestNumber(&idPerro, "Ingrese el id del perro que estara en la estadia: ", "ERROR.El numero ingresado es invalido, no puede contener caracteres,signos y el rango es (7000 a 8000).\nReingrese id del perro que estara en la estadia: ", 7000, 8000))
						{
							printf("ERROR.En el puntero a num\n");
						}
						if(perro_buscarPerroCargado(perro, tamPerro, &indicePerro, idPerro))
						{
							printf("ERROR.En el puntero a perro o en el tam menor a 0\n");
						}

						if(indicePerro!=-1)
						{
							auxEstadia.idPerro=idPerro;
							printf("\nEstadia luego de la modificacion: \n\n");
							printf("\n%-20s %-20s %-20s %-5s    %-20s %-20s\n\n","ID ESTADIA","NOMBRE DUEÑO","CONTACTO","ID PERRO","NOMBRE PERRO","FECHA DE ESTADIA");
							estadia_listarEstadiaConPerro(auxEstadia, perro[indicePerro]);
							if(!requestCharacterAnswer("ingrese (s) para modificar la estadia: "))
							{
								estadia[indice]=auxEstadia;
								printf("\n\nLa modificacion se realizo correctamente.\n\n");
							}
							else
							{
								printf("\n\nSe cancelo la modificacion del Perro.\n\n");
							}

						}
						else
						{
							printf("\n\nERROR.El id ingresado no pertenece a un perro cargado.\n");
						}

						break;
					case 3:
						printf("\nSe regreso al menu anterior.\n");
						break;
				}

			}while(opcion!=3);



		}
		else
		{
			printf("\n\nERROR.El id ingresado no se encuentra cargado.\n");
		}


		ret=0;
	}
	return ret;
}
int estadia_eliminarEstadiaDePerro(eEstadia* estadia,int tamEstadia,ePerro* perro,int tamPerro,int* contEstadias)
{
	int ret=-1;
	int idEstadia;
	int indice;
	int indicePerro;
	if(estadia!=NULL && perro!=NULL && tamEstadia>0 && tamPerro>0)
	{
		if(estadia_listarEstadiasConPerros(estadia, tamEstadia, perro, tamPerro))
		{
			printf("ERROR.En el puntero a perro , estadia o tamanio de los array menor a 0.\n");
		}
		if(requestNumber(&idEstadia, "Ingrese el Id de la estadia a dar de baja: ", "ERROR.El id Ingresado no es valido.\nReingrese id de Estadia: ", 100000, 200000))
		{
			printf("ERROR.En el puntero a mensaje ,numero o mensaje error.\n");
		}
		if(estadia_buscarEstadiaCargada(estadia, tamEstadia, &indice, idEstadia))
		{
			printf("ERROR.En el puntero estadia o tamanio de array menor a 0.\n");
		}
		if(indice!=-1)
		{
			perro_buscarPerroCargado(perro, tamPerro, &indicePerro, estadia[indice].idPerro);
			estadia_listarEstadiaConPerro(estadia[indice], perro[indicePerro]);
			printf("\n");
			if(!requestCharacterAnswer("ingrese (s) para dar de baja la estadia: "))
			{
				*contEstadias=*contEstadias-1;
				estadia[indice].vacio=LIBRE;
				printf("\n\nLa baja se realizo correctamente.\n\n");
			}
			else
			{
				printf("\n\nSe cancelo la baja de la estadia.\n\n");
			}

		}
		else
		{
			printf("\n\nERROR.El id ingresado no se encuentra cargado.\n");
		}
		ret=0;
	}
	return ret;
}

int estadia_reservarEstadiaConPerroCargado(eEstadia* estadia,int tamEstadia,ePerro* perro,int tamPerro, int* ultimoId,int* contEstadias)
{
	int ret=-1;
	int idVacio;
	eEstadia auxEstadia;
	int idPerro;
	int indicePerro;
	if(estadia!=NULL && tamEstadia>0 && perro!=NULL && tamPerro>0)
	{
		if(estadia_buscarIndicelibre(estadia, tamEstadia, &idVacio))
		{
			printf("ERROR.En el tamaño o el puntero a estadia.\n");
		}
		if(idVacio!=-1)
		{
			if(perro_ListarPerros(perro, tamPerro))
			{
				printf("ERROR.En el tamaño o el puntero a perro.\n");
			}
			if(requestNumber(&idPerro, "Ingrese el id del perro que estara en la estadia: ", "ERROR.El numero ingresado es invalido, no puede contener caracteres,signos y el numero maximo es 8000.\nReingrese id del perro que estara en la estadia: ", 7000, 8000))
			{
				printf("ERROR.En el puntero a num\n");
			}
			if(perro_buscarPerroCargado(perro, tamPerro, &indicePerro, idPerro))
			{
				printf("ERROR.En el puntero a perro o en el tam menor a 0\n");
			}
			if(indicePerro!=-1)
			{
				printf("\n%-5s %-20s %-20s %-5s\n\n","ID","NOMBRE","RAZA","EDAD");
				perro_ListarPerro(perro[indicePerro]);
				printf("\n");
				auxEstadia.idPerro=idPerro;
				auxEstadia.id=*ultimoId;
				auxEstadia.vacio=OCUPADO;
				if(requestNameOrLastName(auxEstadia.nombreDuenio, "Ingrese el nombre del dueño: ", "ERROR.El nombre no debe contener ningun signo y un maximo de 35 caracteres.\nReingrese el nombre del dueño:", 35))
				{
					printf("ERROR.En el puntero a string\n");
				}
				if(requestNumberPhone(auxEstadia.telefonoContacto,"Ingrese un numero contacto del dueño de la mascota: ", "ERROR.El Numero ingresado no es valido,no debe contener letras o caracteres y debe tener un 10digitos.\nReingrese numero de contacto: ", 10))
				{
					printf("ERROR.En el puntero a num\n");
				}
				requestDate(&auxEstadia.fecha.dia, &auxEstadia.fecha.mes, &auxEstadia.fecha.anio);
				printf("\n%-20s %-20s %-20s %-5s    %-20s %-20s\n\n","ID ESTADIA","NOMBRE DUEÑO","CONTACTO","ID PERRO","NOMBRE PERRO","FECHA DE ESTADIA");
				estadia_listarEstadiaConPerro(auxEstadia, perro[indicePerro]);
				printf("\n");
				if(!requestCharacterAnswer("ingrese (s) para cargar la estadia: "))
				{
					*ultimoId=*ultimoId+1;
					*contEstadias=*contEstadias+1;
					estadia[idVacio]=auxEstadia;
					printf("\n\nSe cargo correctamente la estadia.\n");
				}
				else
				{
					printf("\n\nSe cancelo la carga de la estadia.\n");
				}
			}
			else
			{
				printf("\n\nERROR.El id ingresado no pertenece a un perro cargado.\n");
			}
		}
		else
		{
			printf("\n\nERROR. No hay Espacio libre para cargar mas estadias\n");
		}
		ret=0;
	}
	return ret;
}

int estadia_listarEstadiasConPerros(eEstadia* estadia,int tamEstadia,ePerro* perro,int tamPerro)
{
	int ret=-1;
	int i;
	int indice;
	if(estadia!=NULL && tamEstadia>0 && perro!=NULL && tamPerro>0)
	{
		printf("\n%-20s %-20s %-20s %-5s    %-20s %-20s\n\n","ID ESTADIA","NOMBRE DUEÑO","CONTACTO","ID PERRO","NOMBRE PERRO","FECHA DE ESTADIA");
		for(i=0;i<tamEstadia;i++)
		{
			if(estadia[i].vacio==OCUPADO)
			{
				indice=i;
				if(perro_buscarPerroCargado(perro, tamPerro, &indice, estadia[i].idPerro))
				{
					printf("ERROR.En el puntero a perro o en el tam menor a 0\n");
				}
				estadia_listarEstadiaConPerro(estadia[i], perro[indice]);
			}
		}
		printf("\n");

		ret=0;
	}
	return ret;
}
void estadia_listarEstadiaConPerro(eEstadia estadia,ePerro perro)
{
	printf("%-20d %-20s %-20s %-5d       %-20s %d/%d/%d\n",estadia.id,estadia.nombreDuenio,estadia.telefonoContacto,perro.id,perro.nombre,estadia.fecha.dia,estadia.fecha.mes,estadia.fecha.anio);
}
