#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_get.h"
#include "arrayPassenger.h"


int initPassengers(Passenger* list, int len){
	int i;
	int errorCode=-1;
	if(list != NULL && len > 0)
	{
		for(i=0; i<len; i++)
		{
			list[i].isEmpty = EMPTY;
			list[i].id = EMPTY;
			errorCode=0;
		}
	}
	return errorCode;
}

int searchFreePosition(Passenger* list, int len)
{
	int i;
	int index=-1;

	if(list != NULL && len > 0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty==EMPTY)
			{
				index=i;
				break;
			}
		}
	}

	return index;
}

int searchForTakenPositions(Passenger* list, int len)
{
	int i;
	int takenPosition = -1;

	if(list != NULL && len > 0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty==TAKEN)
			{
				takenPosition=0;
				break;
			}
		}
	}

	return takenPosition;
}

int takenPositionsCounter(Passenger* list, int len)
{
	int i;
	int takenPosition = 0;

	if(list != NULL && len > 0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty==TAKEN)
			{
				takenPosition++;
			}
		}
	}

	return takenPosition;
}

int verifyFlightCode(FlightCode list[], int len, int toVerify)
{
	int i;
	int exists = -1;

	for(i=0;i<len;i++)
	{
		if(list[i].idFlyCode == toVerify)
		{
			exists=0;
			break;
		}
	}
	return exists;
}

int idGenerator(Passenger list[], int len)
{
	int i;
	int id=0;
	int max=0;

	for(i=0;i<len;i++)
	{
		if(list[i].id>max)
		{
			max=list[i].id;
		}
	}

	id=max+1;

	return id;
}

/*---------------------------------------------------------Alta lista-------------------------------------------------------------------------*/

int askForPassenger(Passenger list[], int len, FlightCode listflightCode[], int flightCodeLen, TypePassenger listTypePassenger[], int lenTypePassenger, char name[], char lastName[], float* price, int* flightCode, int* typePassenger)
{
	char auxName[LIMIT_CHARACTERS];
	char auxLastName[LIMIT_CHARACTERS];
	float auxPrice;
	int auxFlightCode;
	int auxTypePassenger;
	int correctName=ERROR;
	int correctLastName=ERROR;
	int correctPrice=ERROR;
	int correctFlightCode=ERROR;
	int correctTypePassenger=ERROR;
	int verify=ERROR;

	int errorCode=FALSE;


	correctName=getStringChar(auxName,"Ingrese Nombre del Pasajero: \n","Error ha superado el limite\n", LIMIT_CHARACTERS, 5, 1);
	correctLastName=getStringChar(auxLastName,"Ingrese Apellido del Pasajero: \n","Error ha superado el limite\n", LIMIT_CHARACTERS, 5, 1);
	correctPrice=getFloatNumber(&auxPrice,"Ingrese Precio del Vuelo: \n", "Error el precio ingresado es invalido\n",1,5000000,5);

	do
	{
		puts("Ingrese uno de los siguientes vuelos disponibles:");
		printFlightCodes(listflightCode, flightCodeLen);
		correctFlightCode=getIntNumber(&auxFlightCode,"Ingrese ID de Vuelo:\n ","Error, el numero de vuelo ingresado no existe\n",1000,1500,5);
		verify=verifyFlightCode(listflightCode, flightCodeLen, auxFlightCode);
		if(verify==ERROR)
		{
			puts("Error, el numero de vuelo ingresado no existe");
		}
	}while(verify==ERROR);

	puts("Ingrese la Clase del pasaje:");
	printTypePassengers(listTypePassenger, lenTypePassenger);
	correctTypePassenger=getIntNumber(&auxTypePassenger,"Ingrese ID del tipo Pasaje:\n ","Error el numero ingresado es invalido\n",1,3,5);

	if(correctName !=ERROR && 	correctLastName !=ERROR && correctPrice !=ERROR && correctFlightCode !=ERROR && correctTypePassenger !=ERROR)
	{
		strcpy(name,auxName);
		strcpy(lastName,auxLastName);
		*price=auxPrice;
		*flightCode=auxFlightCode;
		*typePassenger=auxTypePassenger;
	}else
	{
		errorCode=ERROR;
	}

	return errorCode;
}

int addPassenger(Passenger* list, int len, FlightCode* listflightCode, int flightCodeLen, TypePassenger* listTypePassenger,  int lenTypePassenger, StatusFlight* listFLights, int lenFlights, int id, char name[], char lastName[], float price, int flyCode, int typePassenger, int statusFlight){
	int errorCode;
	int index;
	int option;

	index=searchFreePosition(list, len);

	if(list != NULL && len > 0 && index!=ERROR)
	{
		errorCode=askForPassenger(list, len, listflightCode, flightCodeLen, listTypePassenger, lenTypePassenger, name, lastName, &price, &flyCode, &typePassenger);
		if(errorCode!=ERROR)
		{
			list[index].id=idGenerator(list, len);
			strcpy(list[index].name,name);
			strcpy(list[index].lastName,lastName);
			list[index].price=price;
			list[index].flyCode=flyCode;
			list[index].typePassenger=typePassenger;
			list[index].statusFlight=TAKEN;
			list[index].isEmpty=TAKEN;
			puts("Desea cargar el siguiente pasajero:");
			title();
			printAPassenger(list[index], listflightCode, flightCodeLen, listTypePassenger, lenTypePassenger, listFLights, lenFlights);
			getIntNumber(&option,"1-Para SI\n2-Para NO\n","Error. Opcion incorrecta",1, 2, 5);
			if(option==1)
			{
				puts("Pasajero cargado con EXITO");
			}
			else
			{
				list[index].isEmpty=EMPTY;
				puts("No se ha cargado el pasajero, volviendo al menu principal");
			}
		}else
		{
			puts("Error. No se ha podido cargar el producto debido a un problema en la carga de uno o mas de los datos");
		}
	}else
	{
		puts("Error. No queda mas lugar");
	}

	return errorCode;

}
/*---------------------------------------------------------Modificar lista-------------------------------------------------------------------------*/

int findPassengerById(Passenger* list, int len,int id){
	int i;
	int passengerIndex=-1;

	if(list!=NULL && len>0 && id>0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].id==id && list[i].isEmpty==TAKEN)
			{
				passengerIndex=i;
				break;
			}
		}
	}
	return passengerIndex;
}

void modifyPassenger(Passenger list[], int index, FlightCode listflightCode[], int flightCodeLen, TypePassenger listTypePassenger[], int lenTypePassenger, StatusFlight* listFLights, int lenFlights){
	int option;
	char auxName[LIMIT_CHARACTERS];
	char auxLastName[LIMIT_CHARACTERS];
	float auxPrice;
	int auxFlightCode;
	int auxTypePassenger;
	int auxStatusFlight;
	int correctValue=ERROR;
	int verify;


	do{
		puts("Modificando:");
		title();
		printAPassenger(list[index], listflightCode, flightCodeLen, listTypePassenger, lenTypePassenger, listFLights, lenFlights);
		getIntNumber(&option,"Que desea modificar: \n1-Nombre\n2-Apellido\n3-Precio\n4-Vuelo\n5-Clase de pasaje\n6-Status del vuelo\n7-Salir","Error. Opcion incorrecta",1,7,5);
		switch(option)
		{
		case 1:
			correctValue=getStringChar(auxName,"Ingrese Nombre del Pasajero: \n","Error. ha superado el limite\n", LIMIT_CHARACTERS, 5, 1);
			if(correctValue!=ERROR)
			{
			strcpy(list[index].name,auxName);
			}else
			{
				puts("Error. Se ha superado el limite de intentos, no se ha modificado el valor");
			}
			break;
		case 2:
			correctValue=getStringChar(auxLastName,"Ingrese Apellido del Pasajero: \n","Error ha superado el limite\n", LIMIT_CHARACTERS, 5, 1);
			if(correctValue!=ERROR)
			{
			strcpy(list[index].lastName,auxLastName);
			}else
			{
				puts("Error. Se ha superado el limite de intentos, no se ha modificado el valor");
			}
			break;
		case 3:
			correctValue=getFloatNumber(&auxPrice,"Ingrese el Precio; \n","Error ha superado el limite\n",1,5000000,5);
			if(correctValue!=ERROR)
			{
			list[index].price=auxPrice;
			}else
			{
				puts("Error. Se ha superado el limite de intentos, no se ha modificado el valor");
			}
			break;
		case 4:
			do
			{
				puts("Ingrese uno de los siguientes vuelos disponibles:");
				printFlightCodes(listflightCode, flightCodeLen);
				correctValue=getIntNumber(&auxFlightCode,"Ingrese ID del Vuelo:\n ","Error, el numero de vuelo ingresado no existe\n",1000,1500,5);
				verify=verifyFlightCode(listflightCode, flightCodeLen, auxFlightCode);
				if(verify==ERROR)
				{
					puts("Error, el numero de vuelo ingresado no existe");
				}else
				{
					list[index].flyCode=auxFlightCode;
				}
			}while(verify==ERROR);
			break;
		case 5:
			puts("Ingrese Una de las siguientes Clases disponibles:");
			printTypePassengers(listTypePassenger, lenTypePassenger);
			correctValue=getIntNumber(&auxTypePassenger,"Ingrese ID del tipo de pasaje:\n ","Error el numero ingresado es invalido\n",1,3,5);
			list[index].typePassenger=auxTypePassenger;
			break;
		case 6:
			puts("Ingrese el Status actual del vuelo:");
			printStatusFlights(listFLights, lenFlights);
			correctValue=getIntNumber(&auxStatusFlight,"Ingrese el ID del Status:\n ","Error el numero ingresado es invalido\n",1,3,5);
			list[index].statusFlight=auxStatusFlight;
			break;
		}

	}while(option!=7);
}

int passengerModifier(Passenger* list, int len, FlightCode listflightCode[], int flightCodeLen, TypePassenger listTypePassenger[], int lenTypePassenger, StatusFlight* listFLights, int lenFlights){
	int id;
	int auxIndex;
	int option;
	int errorCode=0;

	if(list!=NULL && len>0 && searchForTakenPositions(list, len)!=ERROR)
	{
		getIntNumber(&id,"Ingrese el ID del Pasajero a modificar: ","Error. ID invalido", 1, 100000, 5);

		auxIndex=findPassengerById(list, len, id);

		if(auxIndex!=ERROR)
		{
			puts("Desea modificar el siguiente pasajero?");
			title();
			printAPassenger(list[auxIndex], listflightCode, flightCodeLen, listTypePassenger, lenTypePassenger, listFLights, lenFlights);
			getIntNumber(&option,"Ingrese 1(SI) o 2(NO): ","Error. Opcion Incorrecta", 1, 2, 5);
			if(option==1)
			{
				modifyPassenger(list, auxIndex, listflightCode, flightCodeLen, listTypePassenger, lenTypePassenger, listFLights, lenFlights);
			}else
			{
				puts("Se ha cancelado la operacion");
			}
		}else
		{
			puts("El pasajero que ingreso no existe o ya se ha dado de baja");
		}
	}
	else
	{
		puts("Error, no hay pasajeros cargados para modificar");
		errorCode=-1;
	}
	return errorCode;
}

/*---------------------------------------------------------Eliminar uno de la lista-------------------------------------------------------------------------*/

int removePassenger(Passenger* list, int len, int id){

	int i;
	int errorCode=-1;

	for(i=0;i<len;i++)
	{
		if(list[i].id==id)
		{
			list[i].isEmpty=EMPTY;
			puts("Pasajero eliminado exitosamente");
			errorCode=0;
			break;
		}
	}

	return errorCode;
}

int passengerRemover(Passenger* list, int len, FlightCode listflightCode[], int flightCodeLen, TypePassenger listTypePassenger[], int lenTypePassenger, StatusFlight* listFLights, int lenFlights){
	int id;
	int auxIndex;
	int option;
	int errorCode=0;

	if(list!=NULL && len>0 && searchForTakenPositions(list, len)!=ERROR)
	{
		getIntNumber(&id,"Ingrese el ID del Pasajero que desea eliminar: ","Error. ID invalido", 1, 100000, 5);

		auxIndex=findPassengerById(list, len, id);

		if(auxIndex!=ERROR)
		{
			puts("Desea eliminar el siguiente pasajero?");
			title();
			printAPassenger(list[auxIndex], listflightCode, flightCodeLen, listTypePassenger, lenTypePassenger, listFLights, lenFlights);
			getIntNumber(&option,"Ingrese 1(SI) o 2(NO): ","Error. Opcion Incorrecta", 1, 2, 5);
			if(option==1)
			{
				removePassenger(list, len, id);
			}else
			{
				puts("Se ha cancelado la operacion");
			}
		}else
		{
			puts("El pasajero que ingreso no existe o ya se ha dado de baja");
		}
	}else
	{
		puts("Error, no hay pasajeros cargados para eliminar");
		errorCode=-1;
	}
	return errorCode;
}

/*---------------------------------------------------------Operaciones(promedios, sumas etc)-------------------------------------------------------------------------*/

float totalPrice(Passenger* list, int len)
{
	int i;
	float total=0;

	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty==TAKEN)
		{
			total=total+list[i].price;
		}
	}
	return total;
}

float averagePrice(Passenger* list, int len, float total)
{
	float average=0;
	int passengers=0;

	passengers=takenPositionsCounter(list, len);
	total=totalPrice(list, len);

	average=(float)(total/passengers);

	return average;
}

int overAveragePassengers(Passenger* list, int len, float average, FlightCode* listCodes, int lenCodes, TypePassenger* listType, int lenTypes, StatusFlight* listFLights, int lenFlights){
	int overAverage=0;
	int i;

	title();
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty==TAKEN && list[i].price>average)
		{
			printAPassenger(list[i], listCodes, lenCodes, listType, lenTypes, listFLights, lenFlights);
			overAverage++;
		}
	}
	return overAverage;
}

void operationsManager(Passenger* list, int len, FlightCode* listCodes, int lenCodes, TypePassenger* listType, int lenTypes, StatusFlight* listFLights, int lenFlights){
	float total;
	float average;
	int overAverage;

	if(list!=NULL && searchForTakenPositions(list, len)!=ERROR)
	{
		total=totalPrice(list, len);
		average=averagePrice(list, len, total);
		printf("El total de precios de todos los pasajes es: %.2f\nEl promedio de precios de pasajes es: %.2f\n",total, average);
		overAverage=overAveragePassengers(list, len, average, listCodes, lenCodes, listType, lenTypes, listFLights, lenFlights);
		printf("\nTotal de pasajeros que exceden el promedio: %d\n\n", overAverage);
	}else
	{
		if(searchForTakenPositions(list, len)==ERROR)
		{
			puts("Error, no hay pasajeros para ejecutar las operaciones");
		}
	}
}

/*---------------------------------------------------------Ordenar lista-------------------------------------------------------------------------*/

void sort(Passenger* list, int x, int y)
{
	Passenger aux;

	aux=list[x];
	list[x]=list[y];
	list[y]=aux;
}

int sortPassengersByLastNameAndType(Passenger* list, int len, int order, FlightCode listflightCode[], int flightCodeLen, TypePassenger listTypePassenger[], int lenTypePassenger, StatusFlight* listFLights, int lenFlights){

	int x;
	int y;
	int errorCode=-1;

	if(list!=NULL && len>0)
	{
		for(x=0; x<len; x++)
		{
			for(y=x+1; y<len; y++)
			{
				if(strcmp(list[x].lastName,list[y].lastName) > 0 &&
						list[x].isEmpty==TAKEN && list[y].isEmpty==TAKEN && order == 1)
				{
					sort(list, x, y);
				}else
				{
					if(strcmp(list[x].lastName,list[y].lastName) == 0 &&
							list[x].typePassenger > list[y].typePassenger)
					{
						sort(list, x, y);
					}
				}
				if(strcmp(list[x].lastName,list[y].lastName) < 0 &&
						list[x].isEmpty==TAKEN && list[y].isEmpty==TAKEN && order == 2)
				{
					sort(list, x, y);
				}else
				{
					if(strcmp(list[x].lastName,list[y].lastName) == 0 &&
							list[x].typePassenger > list[y].typePassenger)
					{
						sort(list, x, y);
					}
				}
			}
		}
		errorCode=0;
	}
	printPassengers(list, len, listflightCode, flightCodeLen, listTypePassenger, lenTypePassenger, listFLights, lenFlights);

	return errorCode;
}

int sortPassengersById(Passenger* list, int len, int order){
	int x;
	int y;

	if(list!=NULL && len>0)
	{
		for(x=0; x<len; x++)
		{
			for(y=x+1; y<len; y++)
			{
				if(list[x].id > list[y].id && order == 1 && list[x].isEmpty==TAKEN)
				{
					sort(list, x, y);
				}else
				{
					if(list[x].id < list[y].id && order == 2 && list[x].isEmpty==TAKEN)
					{
						sort(list, x, y);
					}
				}
			}
		}
	}
return 0;
}

/*---------------------------------------------------------Mostrar lista-------------------------------------------------------------------------*/

void printAPassengerTwo(Passenger list, TypePassenger* listType, int lenTypes)
{
	int x;

	for(x=0; x<lenTypes; x++)
	{
		if(listType[x].idTypePassenger == list.typePassenger)
		{
			printf("| %04d  |  %10s    |%10s     | %10.2f     | %13s    |\n", list.id,
																			list.name,
																			list.lastName,
																			list.price,
																			listType[x].typePassenger);
			puts("|_______|________________|_______________|________________|__________________|");
		}
	}
}

int printPassengersTwo(Passenger* list, int length, FlightCode* listCodes, int lenCodes, TypePassenger* listType, int lenTypes, StatusFlight* listFLights, int lenFlights){
	int rtn = -1;
	int j;
	int x;
	int i;

	if(list!=NULL && length>0 && searchForTakenPositions(list, length)!=ERROR)
	{
		for(x=0; x<lenCodes; x++)
		{
			for(j=0; j<lenFlights; j++)
			{
				if(listFLights[j].idStatusFlight==1)
				{
					puts("_____________________________________________________________________________");
					printf("|  **%4s  |                          %s                              |\n", listCodes[x].flyCode, listFLights[j].statusFlight);
					puts("|_____________|______________________________________________________________|");
					for(i=0; i<length; i++)
					{
						if(list[i].isEmpty==TAKEN && list[i].flyCode==listCodes[x].idFlyCode && list[i].statusFlight==1)
						{
							printAPassengerTwo(list[i], listType, lenTypes);
						}
					}
				}
			}
		}
		rtn=0;
	}else
	{
		if(searchForTakenPositions(list, length)==ERROR)
		{
			puts("Error, no hay pasajeros cargados para mostrar");
		}
	}
	return rtn;
}

void printAPassenger(Passenger list, FlightCode* listCodes, int lenCodes, TypePassenger* listType, int lenTypes, StatusFlight* listFLights, int lenFlights){
	int j;
	int x;
	int y;

	for(y=0; y<lenCodes; y++)
	{
		for(x=0; x<lenTypes; x++)
		{
			for(j=0; j<lenFlights; j++)
			{

				if(listCodes[y].idFlyCode == list.flyCode &&
					listType[x].idTypePassenger == list.typePassenger &&
					listFLights[j].idStatusFlight == list.statusFlight)
				{
					printf("| %04d  |  %10s    |%10s     | %10.2f     | %10s     | %13s    | %10s       |\n", list.id,
																																list.name,
																																list.lastName,
																																list.price,
																																listCodes[y].flyCode,
																																listType[x].typePassenger,
																																listFLights[j].statusFlight);
					puts("|_______|________________|_______________|________________|________________|__________________|__________________|");
				}
			}
		}
	}
}

int printPassengers(Passenger* list, int length, FlightCode* listCodes, int lenCodes, TypePassenger* listType, int lenTypes, StatusFlight* listFLights, int lenFlights){
	int rtn = -1;
	int i;

	if(list!=NULL && length>0 && searchForTakenPositions(list, length)!=ERROR)
	{
		title();
		for(i=0; i<length; i++)
		{
			if(list[i].isEmpty==TAKEN)
			{
				printAPassenger(list[i], listCodes, lenCodes, listType, lenTypes, listFLights, lenFlights);
			}
		}
		rtn=0;
	}else
	{
		if(searchForTakenPositions(list, length)==ERROR)
		{
			puts("Error, no hay pasajeros cargados para mostrar");
		}
	}
	return rtn;
}

void printStatusFlight(StatusFlight list)
{
	printf("|%2d     |%13s   |\n",list.idStatusFlight, list.statusFlight);
	puts("|_______|________________|");
}

void printStatusFlights(StatusFlight list[], int len)
{
	int i;

	if(list!=NULL && len>0)
	{
		puts("_________________________");
		puts("| ID:   |     Status:    |");
		puts("|_______|________________|");
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty==TAKEN)
			{
				printStatusFlight(list[i]);
			}
		}
	}
}

void printTypePassenger(TypePassenger list)
{
	printf("|%2d     |%13s   |\n",list.idTypePassenger, list.typePassenger);
	puts("|_______|________________|");
}

void printTypePassengers(TypePassenger list[], int len)
{
	int i;

	if(list!=NULL && len>0)
	{
		puts("_________________________");
		puts("| ID:   |     Asiento:   |");
		puts("|_______|________________|");
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty==TAKEN)
			{
				printTypePassenger(list[i]);
			}
		}
	}
}

void printFlightCode(FlightCode list)
{
	printf("|%5d  |%10s      |\n",list.idFlyCode, list.flyCode);
	puts("|_______|________________|");
}

void printFlightCodes(FlightCode list[], int len)
{
	int i;

	if(list!=NULL && len>0)
	{
		puts("_________________________");
		puts("| ID:   |     Vuelo:     |");
		puts("|_______|________________|");
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty==TAKEN)
			{
				printFlightCode(list[i]);
			}
		}
	}
}

void title()
{
	puts("_________________________________________________________________________________________________________________");
	puts("| ID:   |     Nombre:    |   Apellido:   |     Precio:    |     Vuelo:     |     Asiento:     |   Status vuelo:  |");
	puts("|_______|________________|_______________|________________|________________|__________________|__________________|");
}
