/*
 ============================================================================
 Name        : TP2_administrarPasajeros.c
 Author      : Ezequiel Melo 1°B
 Version     :
 Copyright   : @EzzMellow
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "utn_get.h"
#include "arrayPassenger.h"

#define LIMIT_CHARACTERS 51
#define LENCODES 100
#define LENTYPE 3
#define LENSTATUS 3
#define EMPTY 0
#define TAKEN 1
#define FALSE 0
#define TRUE 1
#define ERROR -1

int main(void){
	int auxId=5;
	char name[LIMIT_CHARACTERS]="";
	char lastName[LIMIT_CHARACTERS]="";
	float price=0;
	int typePassenger=0;
	int flyCode=0;
	int statusFlight=0;

	int option;
	int subOption;

	Passenger aPassenger[LENPASSENGERS];
	FlightCode Codes[LENCODES];
	addFlightHardcode(Codes, LENCODES);
	TypePassenger PassengersType[LENTYPE]={{1,"Primera Clase",TAKEN},{2,"Turista",TAKEN},{3,"Ejecutiva",TAKEN}};
	StatusFlight Status[LENSTATUS]={{1,"ACTIVO",TAKEN},{2,"DEMORADO",TAKEN},{3,"CANCELADO",TAKEN}};

	initPassengers(aPassenger, LENPASSENGERS);

	setbuf(stdout,NULL);

	puts("~~~~~~~~~~~~~Bienvenido~~~~~~~~~~~~~");
	do
	{
		puts("ingrese una de las opciones siguientes: ");
		getIntNumber(&option,"\n1- Alta pasajero \n2- Modificar pasajero \n3- Baja pasajero \n4- Informar (Listado, total y promedio) \n5- Opciones de vuelos (añadir/eliminar) \n6- Alta forzada\n7- Salir\n","\nError ingrese una opcion correcta\n", 1, 7, 5);
		switch(option)
		{
		case 1:
			idGeneratorFinal(&auxId);
			addPassenger(aPassenger, LENPASSENGERS, Codes, LENCODES, PassengersType, LENTYPE, Status, LENSTATUS, auxId, name, lastName, price, flyCode, typePassenger, statusFlight);
			break;
		case 2:
			passengerModifier(aPassenger, LENPASSENGERS, Codes, LENCODES, PassengersType, LENTYPE, Status, LENSTATUS);
			break;
		case 3:
			passengerRemover(aPassenger, LENPASSENGERS, Codes, LENCODES, PassengersType, LENTYPE, Status, LENSTATUS);
			break;
		case 4:
			if(searchForTakenPositions(aPassenger, LENPASSENGERS)!=ERROR)
			{
				getIntNumber(&subOption,"1- Listado completo por ID: \n2- Listar por apellido y tipo pasajero(tipo de asiento): \n3- Listar por codigo de vuelo y estado ACTIVO: \n4- Total, promedio de pasajes y cuantos pasajes superan el promedio: \n5- Salir\n","\nError ingrese una opcion correcta\n", 1, 5, 5);
				switch(subOption)
				{
				case 1:
					getIntNumber(&subOption,"1- De Menor a Mayor: \n2- De Mayor a Menor\n","\nError ingrese una opcion correcta\n", 1, 2, 5);
					switch(subOption)
					{
					case 1:
						sortPassengersById(aPassenger, LENPASSENGERS, subOption);
						printPassengers(aPassenger, LENPASSENGERS, Codes, LENCODES, PassengersType, LENTYPE, Status, LENSTATUS);
						break;
					case 2:
						sortPassengersById(aPassenger, LENPASSENGERS, subOption);
						printPassengers(aPassenger, LENPASSENGERS, Codes, LENCODES, PassengersType, LENTYPE, Status, LENSTATUS);
						break;
					}
					break;
				case 2:
					getIntNumber(&subOption,"1- De la A a la Z: \n2- De la Z a la A:\n","\nError ingrese una opcion correcta\n", 1, 2, 5);
					switch(subOption)
					{
					case 1:
						sortPassengersByLastNameAndType(aPassenger, LENPASSENGERS, subOption, Codes, LENCODES, PassengersType, LENTYPE, Status, LENSTATUS);
						break;
					case 2:
						sortPassengersByLastNameAndType(aPassenger, LENPASSENGERS, subOption, Codes, LENCODES, PassengersType, LENTYPE, Status, LENSTATUS);
						break;
					}
					break;
				case 3:
					printPassengersTwo(aPassenger, LENPASSENGERS, Codes, LENCODES, PassengersType, LENTYPE, Status, LENSTATUS);
					break;
				case 4:
					operationsManager(aPassenger, LENPASSENGERS, Codes, LENCODES, PassengersType, LENTYPE, Status, LENSTATUS);
					break;
				}
			}else
			{
				puts("Error. No hay pasajeros para mostrar o hacer operaciones");
			}
			break;
		case 5:
			getIntNumber(&option,"1- Añadir nuevo vuelo\n2- Eliminar vuelo\n","\nError ingrese una opcion correcta\n", 1, 2, 5);
			switch(option)
			{
			case 1:
				addFlight(Codes, LENCODES);
				break;
			case 2:
				removeFlight(Codes, LENCODES);
				break;
			}
			break;
		case 6:
			addPassengerHardcode(aPassenger);
			break;
		}
	}while(option!=7);
	puts("Muchas gracias por utilizar el programa!!!");
	return EXIT_SUCCESS;
}

