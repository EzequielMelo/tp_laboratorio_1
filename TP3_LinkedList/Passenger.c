/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_get.h"
#include "Passenger.h"
#include "LinkedList.h"
#include "Controller.h"

Passenger* Passenger_new()
{
	Passenger* newPassenger = NULL;
	newPassenger= (Passenger*)malloc(sizeof(Passenger));
	return newPassenger;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char*precioStr,char*codigoStr,char*tipoStr,char*estatusStr)
{
	Passenger* newPassenger = NULL;
	newPassenger= Passenger_new();

	if(newPassenger!=NULL)
	{
		newPassenger->id=atoi(idStr);
		strcpy(newPassenger->nombre, nombreStr);
		strcpy(newPassenger->apellido, apellidoStr);
		newPassenger->precio=atof(precioStr);
		strcpy(newPassenger->codigoVuelo, codigoStr);
		strcpy(newPassenger->tipoPasajero, tipoStr);
		strcpy(newPassenger->estatus, estatusStr);
	}
	return newPassenger;
}

FlyCode* FlyCode_newParametros(char* idStr,char* codigoStr,char* destinoStr)
{
	FlyCode* newFlyCode = NULL;
	newFlyCode= (FlyCode*)malloc(sizeof(FlyCode));

	if(newFlyCode!=NULL)
	{
		newFlyCode->id=atoi(idStr);
		strcpy(newFlyCode->codigoVuelo, codigoStr);
		strcpy(newFlyCode->destino, destinoStr);
	}
	return newFlyCode;
}

TypePassenger* TypePassenger_newParametros(char* idStr,char* tipoStr)
{
	TypePassenger* newTypePassenger = NULL;
	newTypePassenger= (TypePassenger*)malloc(sizeof(TypePassenger));

	if(newTypePassenger!=NULL)
	{
		newTypePassenger->id=atoi(idStr);
		strcpy(newTypePassenger->tipoPasajero, tipoStr);
	}
	return newTypePassenger;
}

StatusPassenger* StatusPassenger_newParametros(char* idStr,char* estatusStr)
{
	StatusPassenger* newStatusPassenger = NULL;
	newStatusPassenger= (StatusPassenger*)malloc(sizeof(StatusPassenger));

	if(newStatusPassenger!=NULL)
	{
		newStatusPassenger->id=atoi(idStr);
		strcpy(newStatusPassenger->statusPasajero, estatusStr);
	}
	return newStatusPassenger;
}

int Passenger_setId(Passenger* this,int id)
{
	int errorCode=-1;
	if(this!=NULL && id>0)
	{
		this->id = id;
		errorCode=0;
	}
	return errorCode;
}

int Passenger_getId(Passenger* this,int* id)
{
	int errorCode=-1;
	if(this!=NULL)
	{
		*id=this->id;
		errorCode=0;
	}
	return errorCode;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int errorCode=-1;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre, nombre);
		errorCode=0;
	}
	return errorCode;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int errorCode=-1;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre, this->nombre);
		errorCode=0;
	}
	return errorCode;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int errorCode=-1;
	if(this!=NULL && apellido!=NULL)
	{
		strcpy(this->apellido, apellido);
		errorCode=0;
	}
	return errorCode;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int errorCode=-1;
	if(this!=NULL && apellido!=NULL)
	{
		strcpy(apellido, this->apellido);
		errorCode=0;
	}
	return errorCode;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int errorCode=-1;
	if(this!=NULL && precio>0)
	{
		this->precio= precio;
		errorCode=0;
	}
	return errorCode;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int errorCode=-1;
	if(this!=NULL && precio>0)
	{
		*precio = this->precio;
		errorCode=0;
	}
	return errorCode;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int errorCode=-1;
	if(this!=NULL && codigoVuelo!=NULL)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		errorCode=0;
	}
	return errorCode;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int errorCode=-1;
	if(this!=NULL && codigoVuelo!=NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		errorCode=0;
	}
	return errorCode;
}

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int errorCode=-1;
	if(this!=NULL && tipoPasajero!=NULL)
	{
		strcpy(this->tipoPasajero, tipoPasajero);
		errorCode=0;
	}
	return errorCode;
}

int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int errorCode=-1;
	if(this!=NULL && tipoPasajero!=NULL)
	{
		strcpy(tipoPasajero, this->tipoPasajero);
		errorCode=0;
	}
	return errorCode;
}

int Passenger_setEstatusPasajero(Passenger* this, char* estatus)
{
	int errorCode=-1;
	if(this!=NULL && estatus!=NULL)
	{
		strcpy(this->estatus, estatus);
		errorCode=0;
	}
	return errorCode;
}

int Passenger_getEstatusPasajero(Passenger* this, char* estatus)
{
	int errorCode=-1;
	if(this!=NULL && estatus!=NULL)
	{
		strcpy(estatus, this->estatus);
		errorCode=0;
	}
	return errorCode;
}

int Passenger_codeAssigner(LinkedList* pArrayListFlyCodes, int id, char* class)
{
	int errorCode=ERROR;
	FlyCode* this;
	int i;
	int len=ll_len(pArrayListFlyCodes);

	if(pArrayListFlyCodes!=NULL && id>0)
	{
		for(i=0; i<len; i++)
		{
			this=ll_get(pArrayListFlyCodes, i);
			if(this->id==id)
			{
				strcpy(class,this->codigoVuelo);
				errorCode=FALSE;
				break;
			}
		}
	}

	return errorCode;
}

int Passenger_typeAssigner(LinkedList* pArrayTypePassengers, int id, char* type)
{
	int errorCode=ERROR;
	TypePassenger* this;
	int i;
	int len=ll_len(pArrayTypePassengers);

	if(pArrayTypePassengers!=NULL && id>0)
	{
		for(i=0; i<len; i++)
		{
			this=ll_get(pArrayTypePassengers, i);
			if(this->id==id)
			{
				strcpy(type,this->tipoPasajero);
				errorCode=FALSE;
				break;
			}
		}
	}

	return errorCode;
}

int Passenger_statusAssigner(LinkedList* pArrayStatusPassengers, int id, char* status)
{
	int errorCode=ERROR;
	StatusPassenger* this;
	int i;
	int len=ll_len(pArrayStatusPassengers);

	if(pArrayStatusPassengers!=NULL && id>0)
	{
		for(i=0; i<len; i++)
		{
			this=ll_get(pArrayStatusPassengers, i);
			if(this->id==id)
			{
				strcpy(status,this->statusPasajero);
				errorCode=FALSE;
				break;
			}
		}
	}

	return errorCode;
}

int Passenger_idGenerator(int* id)
{
	int errorCode=ERROR;
	FILE *pFile;
	int auxId;
	pFile=fopen("id.bin","rb");
	fread(&auxId, sizeof(int), 1, pFile);
	if(auxId>0)
	{
		auxId+=1;
		*id=auxId;
		pFile=fopen("id.bin","wb");
		fwrite(&auxId, sizeof(int), 1, pFile);
		errorCode=FALSE;
	}else
	{
		auxId=1001;
		*id=auxId;
		pFile=fopen("id.bin","wb");
		fwrite(&auxId, sizeof(int), 1, pFile);
		errorCode=FALSE;
	}
	fclose(pFile);
	return errorCode;
}

int Passenger_askForOne(LinkedList* pArrayListFlyCodes, LinkedList* pArrayTypePassengers, char* name, char* lastName, float* price, char* flightCode, char* typePassenger)
{
	char auxName[LIMIT_CHARACTERS];
	char auxLastName[LIMIT_CHARACTERS];
	float auxPrice;
	int idFlightCode;
	char auxFlightCode[LIMIT_FLYCODE];
	int idTypePassenger;
	char auxTypePassenger[LIMIT_TYPEANDSTATUS];
	int correctName=ERROR;
	int correctLastName=ERROR;
	int correctPrice=ERROR;
	int correctFlightCode=ERROR;
	int correctTypePassenger=ERROR;
	int verify=ERROR;
	int errorCode=FALSE;


	controller_loadFlyCodeFromText("flyCode.csv", pArrayListFlyCodes);
	controller_loadTypePassengerFromText("typePassenger.csv", pArrayTypePassengers);

	correctName=getStringChar(auxName,"Ingrese Nombre del Pasajero: \n","Error ha superado el limite\n", LIMIT_CHARACTERS, 5, 1);
	correctLastName=getStringChar(auxLastName,"Ingrese Apellido del Pasajero: \n","Error ha superado el limite\n", LIMIT_CHARACTERS, 5, 1);
	correctPrice=getFloatNumber(&auxPrice,"Ingrese Precio del Vuelo: \n", "Error el precio ingresado es invalido\n", 1, 5000000, 5);

	do
	{
	puts("Ingrese un ID de uno de los siguientes vuelos: ");
	controller_ListFlyCodes(pArrayListFlyCodes);
	correctFlightCode=getIntNumber(&idFlightCode,"Ingrese ID de Codigo de Vuelo: \n","Error ha superado el limite\n", 1, 1000, 1);
	verify=Passenger_codeAssigner(pArrayListFlyCodes, idFlightCode, auxFlightCode);
	if(verify==ERROR)
	{
		puts("Error. La opcion ingresada es incorrecta. Intente nuevamente");
	}
	}while(verify==ERROR);

	do
	{
	puts("Ingrese un ID de una de las siguientes clases: ");
	controller_ListTypePassengers(pArrayTypePassengers);
	correctTypePassenger=getIntNumber(&idTypePassenger,"Ingrese ID del tipo Pasaje:\n ","Error el numero ingresado es invalido\n", 1, 1000, 5);
	verify=Passenger_typeAssigner(pArrayTypePassengers, idTypePassenger, auxTypePassenger);
	}while(verify==ERROR);

	if(correctName !=ERROR && 	correctLastName !=ERROR && correctPrice !=ERROR && correctFlightCode !=ERROR && correctTypePassenger !=ERROR)
	{
		strcpy(name,auxName);
		strcpy(lastName,auxLastName);
		*price=auxPrice;
		strcpy(flightCode,auxFlightCode);
		strcpy(typePassenger,auxTypePassenger);
	}else
	{
		errorCode=ERROR;
	}

	return errorCode;
}

int Passenger_compareParameter(char* message)
{
	int parameter;
	getIntNumber(&parameter, message,
			"Error opcion invalida", 1, 2, 5);
	if(parameter==1)
	{
		parameter=0;
	}else
	{
		if(parameter==2)
		{
			parameter=1;
		}
	}

	return parameter;
}

int Passenger_comparebyId(void* emp1, void* emp2)
{
	int comp=-1;
	Passenger* passenger1;
	Passenger* passenger2;

	passenger1=emp1;
	passenger2=emp2;

	if(passenger1->id > passenger2->id)
	{
		comp=0;
	}
	else
	{
		if(passenger1->id < passenger2->id)
		{
			comp=1;
		}
	}
	return comp;
}

int Passenger_comparebyName(void* emp1, void* emp2)
{
	int comp=-1;
	Passenger* passenger1;
	Passenger* passenger2;

	passenger1=emp1;
	passenger2=emp2;

	comp= strcmp(passenger1->nombre, passenger2->nombre);

	return comp;
}

int Passenger_comparebyPrice(void* emp1, void* emp2)
{
	int comp=-1;
	Passenger* passenger1;
	Passenger* passenger2;

	passenger1=emp1;
	passenger2=emp2;

	if(passenger1->precio > passenger2->precio)
	{
		comp=0;
	}
	else
	{
		if(passenger1->precio < passenger2->precio)
		{
			comp=1;
		}
	}
	return comp;
}

int Passenger_minLenghtList(char* path)
{
	char id[20];
	char nombre[50];
	char apellido[50];
	char precio[20];
	char codigoVuelo[10];
	char tipoPasajero[20];
	char estatus[20];
	int min = 0;

	FILE *pFile;
	if((pFile=fopen(path, "r"))!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estatus);
		while(!feof(pFile))
		{
			min++;
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estatus);

		}
	}
	fclose(pFile);
	return min;
}

void Passenger_showPassenger(LinkedList* pArrayListPassengers, int min, int max)
{
	int i;
	Passenger* this;

	for(i=0; i<max; i++)
	{
		this=ll_get(pArrayListPassengers, i);

		printf("|%5d  |%15s     |%15s    |%10.2f    |%8s   |%15s   |%15s   |\n", this->id,
																				this->nombre,
																				this->apellido,
																				this->precio,
																				this->codigoVuelo,
																				this->tipoPasajero,
																				this->estatus);
		puts("|_______|____________________|___________________|______________|___________|__________________|__________________|");
	}
}

void PassengerHeader()
{
	puts("___________________________________________________________________________________________________________________");
	puts("|  ID   |        Nombre      |      Apellido     |     Precio   |  Codigo   |   Tipo Pasajero  |   Estatus Vuelo  |");
	puts("|_______|____________________|___________________|______________|___________|__________________|__________________|");
}

void FlyCode_showFlyCodes(LinkedList* pArrayListFlyCodes, int min, int max)
{
	int i;
	FlyCode* this;

	for(i=0; i<max; i++)
	{
		this=ll_get(pArrayListFlyCodes, i);

		printf("|%5d  |%8s    |%15s  |\n", this->id,
								this->codigoVuelo,
								this->destino);
		puts("|_______|____________|_________________|");
	}
}

void FlyCodesHeader()
{
	puts("________________________________________");
	puts("|  ID   |   Codigo   |     Destino     |");
	puts("|_______|____________|_________________|");
}

void FlyCode_showTypePassengers(LinkedList* pArrayTypePassengers, int min, int max)
{
	int i;
	TypePassenger* this;

	for(i=0; i<max; i++)
	{
		this=ll_get(pArrayTypePassengers, i);

		printf("|%5d  |%15s     |\n", this->id,
							this->tipoPasajero);
		puts("|_______|____________________|");
	}
}

void TypePassengerHeader()
{
	puts("______________________________");
	puts("|  ID   |    Tipo Pasajero   |");
	puts("|_______|____________________|");
}

void FlyCode_showStatusPassengers(LinkedList* pArrayStatusPassengers, int min, int max)
{
	int i;
	StatusPassenger* this;

	for(i=0; i<max; i++)
	{
		this=ll_get(pArrayStatusPassengers, i);

		printf("|%5d  |%15s     |\n", this->id,
							this->statusPasajero);
		puts("|_______|____________________|");
	}
}

void StatusHeader()
{
	puts("______________________________");
	puts("|  ID   |     Status vuelo   |");
	puts("|_______|____________________|");
}

void showSimplePassenger(int id, char nombre[], char apellido[], float precio, char codigoVuelo[], char tipoPasajero[], char estatus[])
{
	printf("|%5d  |%15s     |%15s    |%10.2f    |%8s   |%15s   |%15s   |\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estatus);
	puts("|_______|____________________|___________________|______________|___________|__________________|__________________|");
}
