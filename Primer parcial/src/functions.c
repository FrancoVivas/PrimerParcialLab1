#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>


int requestDate(int* day,int* month,int* year)
{
	int ret=-1;
	int auxDay;
	int auxMonth;
	int auxYear;

	if(day!=NULL && month!=NULL && year!=NULL)
	{
		requestNumber(&auxDay, "Ingrese el dia: ", "ERROR.El dia ingresado debe estar entre el rango (1 y 31).\nReingrese dia: ", 1, 31);
		requestNumber(&auxMonth, "Ingrese el mes: ", "ERROR.El mes ingresado debe estar entre el rango (1 y 12).\nReingrese mes: ", 1, 12);
		requestNumber(&auxYear, "Ingrese el año: ", "ERROR.El año ingresado debe estar entre el rango (2021 y 2050).\nReingrese año: ",2021,2050);
		while(validateDate(auxDay, auxMonth)==0)
		{
			requestNumber(&auxDay, "ERROR.El dia ingresado no pertenece al mes.\nReingrese dia: ", "ERROR.El dia ingresado debe estar entre el rango (1 y 31).\nReingrese dia: ", 1, 31);
			requestNumber(&auxMonth, "reingrese el mes: ", "ERROR.El mes ingresado debe estar entre el rango (1 y 12).\nReingrese mes: ", 1, 12);
			requestNumber(&auxYear, "reingrese el año: ", "ERROR.El año ingresado debe estar entre el rango (2021 y 2050).\nReingrese año: ",2021,2050);
		}
		*day=auxDay;
		*month=auxMonth;
		*year=auxYear;
		ret=0;
	}
	return ret;
}
int validateDate(int day, int month)
{
	int ret=-1;

	if(month==4 || month==6 || month==9 || month==11)
	{
		if(day>30)
		{
			ret=0;
		}
	}
	else
	{
		if(month==2)
		{
			if(day>28)
			{
				ret=0;
			}
		}
	}

	return ret;
}
int isNumberNoSigns(char* string)
{
	int ret=-1;
	int i;
	int len;

	if(string!=NULL)
	{
		len=strlen(string);

		for(i=0;i<len;i++)
		{
			if(isdigit(string[i])==0)
			{
				ret=0;
				break;
			}
		}
	}
	return ret;
}
int requestNumberPhone(char* string,char* message,char* messageError,int max)
{
	int ret=-1;
	int len;
	if(string!=NULL && message!=NULL && message!=NULL && max>0)
	{
		printf("%s",message);
		fflush(stdin);
		scanf("%[^\n]",string);
		len=strlen(string);
		while(!isNumberNoSigns(string) || len!=max)
		{
			printf("%s",messageError);
			fflush(stdin);
			scanf("%[^\n]",string);
			len=strlen(string);
		}

		ret=0;
	}
	return ret;
}


int upperFirstLetter(char* string)
{
	int ret=-1;
	int len;
	int i;
	if(string!=NULL)
	{
		len=strlen(string);
		for(i=0;i<len;i++)
		{
			if(i==0)
			{
				string[i]=toupper(string[i]);
			}
			if(string[i]==' ')
			{
				string[i+1]=toupper(string[i+1]);
			}
		}
		ret=0;
	}
	return ret;
}

int tolowerString(char* string)
{
	int ret=-1;
	int i;
	int len;
	if(string!=NULL)
	{
		len=strlen(string);
		for(i=0;i<len;i++)
		{
			string[i]=tolower(string[i]);
		}

		ret=0;
	}
	return ret;
}
int validateSigns(char* string)
{
	int i;
	int len;
	int ret=-1;
	if(string!=NULL)
	{
		len=strlen(string);
		tolowerString(string);
		for(i=0;i<len;i++)
		{

			if(string[i] < 97 || string[i] > 122)
			{
				ret=0;
				break;
			}
		}
	}
	return ret;
}
int requestNameOrLastName(char* string,char* message,char* messageError,int max)
{
	int ret=-1;
	char chainAux[200];
	if(string!=NULL && max>0)
	{
		printf("%s",message);
		fflush(stdin);
		scanf("%[^\n]",chainAux);

		while(strlen(chainAux)>max || isNumberWhitSigns(chainAux)==-1 || validateSigns(chainAux)==0)
		{
			printf("%s",messageError);
			fflush(stdin);
			scanf("%[^\n]",chainAux);
		}
		tolowerString(chainAux);
		upperFirstLetter(chainAux);
		strcpy(string,chainAux);
		ret=0;
	}
	return ret;
}

int isNumberWhitSigns(char* string)
{
	int ret=-1;
	int i;
	int tam;

	if(string!=NULL)
	{
		tam=strlen(string);

		for(i=0;i<tam;i++)
		{
			if(isdigit(string[i])==0 && string[i]!='.' && string[0]!='+' && string[0]!='-')
			{
				ret=0;
				break;
			}

		}

	}
	return ret;
}
int validateSpace(char* string)
{
	int returned=-1;
	int i;
	int tam;
	tam=strlen(string);
	for(i=0;i<tam;i++)
	{
		if(string[i] == ' ' || string[i] == '\t' || string[i] == '\v')
		{
			returned=0;
			break;
		}

	}
	return returned;
}


int requestNumber(int* num,char* message,char* messageError,int min, int max)
{
	int returned=-1;
	char numAux[51];
	int numIntAux;


	if(num!=NULL && message!=NULL && messageError!=NULL)
	{

		printf("%s",message);
		fflush(stdin);
		scanf("%[^\n]",numAux);
		numIntAux=atoi(numAux);


		while((!isNumberWhitSigns(numAux) && !validateSpace(message)) || (numIntAux>max||numIntAux<min))
		{
			printf("%s",messageError);
			fflush(stdin);
			scanf("%[^\n]",numAux);
			numIntAux=atoi(numAux);
		}

		*num=atoi(numAux);

		returned=0;
	}


	return returned;
}


int requestString(char* chain,char* message,char* messageError,int max)
{
	int returned=-1;
	char chainAux[200];

	if(chain!=NULL && max>0)
	{
		printf("%s",message);
		fflush(stdin);
		scanf("%[^\n]",chainAux);

		while(strlen(chainAux)>max)
		{
			printf("%s",messageError);
			fflush(stdin);
			scanf("%[^\n]",chainAux);
		}
		tolowerString(chainAux);
		strcpy(chain,chainAux);
		returned=0;
	}

	return returned;
}

int requestNumberFloat(float* num, char* message,char* messageError,int min,int max)
{
	int returned=-1;
	char numAux[51];
	float numFloatAux;
	if(num!=NULL && message!=NULL && messageError!=NULL)
	{
		printf("%s",message);
		fflush(stdin);
		scanf("%[^\n]",numAux);
		numFloatAux=atof(numAux);
		while((!isNumberWhitSigns(numAux) && !validateSpace(message)) || (numFloatAux<min ||numFloatAux>max))
		{
			printf("%s",messageError);
			fflush(stdin);
			scanf("%[^\n]",numAux);
			numFloatAux=atof(numAux);
		}
		*num=atof(numAux);
		returned=0;
	}
	return returned;
}
int requestCharacterAnswer(char* message)
{
	int ret=-1;
	char respuesta;
	if(message!=NULL)
	{
		requestCharacter(&respuesta,message);
		if(respuesta=='s'||respuesta=='S')
		{
			ret=0;
		}

	}
	return ret;
}

int requestCharacter(char* character, char* message)
{
	int ret = -1;

	if(character != NULL && message != NULL)
	{
		printf("%s", message);
		fflush(stdin);
		*character = getchar();
		ret = 0;
	}

	return ret;
}
int divideFloat(float* result,float num1,int num2)
{
	int ret=-1;

	if(result!=NULL)
	{
		*result=num1/num2;
		ret=0;
	}
	return ret;
}

int systemPause(char* message)
{
	int ret=-1;
	if(message!=NULL)
	{
		fflush(stdin);
		printf("\n%s",message);
		getchar();
		ret=0;
	}
	return ret;
}
