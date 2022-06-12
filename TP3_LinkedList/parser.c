#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	char id[20];
	char nombre[50];
	char apellido[50];
	char precio[20];
	char codigoVuelo[10];
	char tipoPasajero[20];
	char estatus[20];
	Passenger* aPassenger;

	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estatus);

	while(!feof(pFile))
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estatus);
		aPassenger=Passenger_newParametros(id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estatus);
		if(aPassenger!=NULL)
		{
			ll_add(pArrayListPassenger, aPassenger);
		}
	}

    return 1;
}

int parser_FlyCodeFromText(FILE* pFile , LinkedList* pArrayListFlyCodes)
{
	char id[20];
	char codigoVuelo[10];
	char destino[50];
	FlyCode* aFlyCode;

	fscanf(pFile,"%[^,],%[^,],%[^\n]\n",id,codigoVuelo,destino);

	while(!feof(pFile))
	{
		fscanf(pFile,"%[^,],%[^,],%[^\n]\n",id, codigoVuelo, destino);
		aFlyCode=FlyCode_newParametros(id, codigoVuelo, destino);
		if(aFlyCode!=NULL)
		{
			ll_add(pArrayListFlyCodes, aFlyCode);
		}
	}

    return 1;
}

int parser_TypePassengerFromText(FILE* pFile , LinkedList* pArrayTypePassengers)
{
	char id[20];
	char tipoPasajero[20];
	TypePassenger* aTypePassenger;

	fscanf(pFile,"%[^,],%[^\n]\n",id,tipoPasajero);

	while(!feof(pFile))
	{
		fscanf(pFile,"%[^,],%[^\n]\n",id,tipoPasajero);
		aTypePassenger=TypePassenger_newParametros(id,tipoPasajero);
		if(aTypePassenger!=NULL)
		{
			ll_add(pArrayTypePassengers, aTypePassenger);
		}
	}

    return 1;
}

int parser_StatusPassengerFromText(FILE* pFile , LinkedList* pArrayStatusPassengers)
{
	char id[20];
	char statusPasajero[20];
	StatusPassenger* aStatusPassenger;

	fscanf(pFile,"%[^,],%[^\n]\n",id,statusPasajero);

	while(!feof(pFile))
	{
		fscanf(pFile,"%[^,],%[^\n]\n",id,statusPasajero);
		aStatusPassenger=StatusPassenger_newParametros(id,statusPasajero);
		if(aStatusPassenger!=NULL)
		{
			ll_add(pArrayStatusPassengers, aStatusPassenger);
		}
	}

    return 1;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

	int retorno=-1;
	Passenger* aPassenger;


	while(!feof(pFile))
	{
		aPassenger=Passenger_new();
		if(aPassenger!=NULL)
		{
			fread(aPassenger,sizeof(Passenger),1,pFile);
			ll_add(pArrayListPassenger,aPassenger);
			retorno=0;
		}

	}

	return retorno;
}
