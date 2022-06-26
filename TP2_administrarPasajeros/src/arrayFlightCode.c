#include "arrayFlightCode.h"

int initFlights(FlightCode* list, int len){
	int i;
	int errorCode=-1;
	if(list != NULL && len > 0)
	{
		for(i=0; i<len; i++)
		{
			list[i].isEmpty = EMPTY;
			errorCode=0;
		}
	}
	return errorCode;
}

void addFlightHardcode(FlightCode list[], int len)
{
	int id[4]={1133,1218,1301,1353};
	char flightCode[4][8]={"ARG1133","ARG1218","ARG1301","ARG1353"};
	int isEmpty[4]={TAKEN,TAKEN,TAKEN,TAKEN};

	for(int i=0; i<4; i++)
	{
		list[i].idFlyCode=id[i];
		strcpy(list[i].flyCode,flightCode[i]);
		list[i].isEmpty=isEmpty[i];
	}
}

int addFlight(FlightCode list[], int len)
{
	int errorCode=-1;
	char countryCode[8];
	char numberCodeAux[5];
	int numberCode;
	int itsOkay=0;
	int index;

	puts("Vuelos actuales:");
	printFlightCodes(list, len);
	puts("Añadir nuevo vuelo:");
	getStringChar(countryCode,"Ingrese codigo de entre uno y tres letras descriptivas del pais(Ejemplo:ARG->Argentina)\nEl codigo restante se generara automaticamente:\n",
			"Error ha excedido el limite\n",3,5,2);
	do
	{
		srand(time(NULL));
		numberCode=rand() % 901 + 1000;
		itsOkay=verifyCodeFlight(list, numberCode, len);
	}while(itsOkay==-1);

	itoa(numberCode, numberCodeAux, 10);

	index=searchFreePositionFlight(list, len);

	if(list != NULL && len > 0 && index!=ERROR)
	{
		list[index].idFlyCode=numberCode;
		strcpy(list[index].flyCode,strcat(countryCode, numberCodeAux));
		list[index].isEmpty=TAKEN;
		errorCode=0;
	}

	puts("Se ha añadido el siguiente vuelo:");
	puts("_________________________");
	puts("| ID:   |     Vuelo:     |");
	puts("|_______|________________|");
	printFlightCode(list[index]);

	return errorCode;
}

void removeFlight(FlightCode list[], int len)
{
	int id;
	int itsOkay=-1;
	int option;

	puts("Vuelos actuales:");
	printFlightCodes(list, len);
	getIntNumber(&id,"Ingrese el ID del vuelo que desea eliminar:\n","Error numero fuera de rango\n",1000,2000,5);

	itsOkay=verifyCodeFlight(list, id, len);

	if(itsOkay==-1)
	{
		puts("Esta seguro que desea eliminar el siguiente vuelo?");
		puts("Recuerde que dejaran de mostrarse los pasajeros pertenecientes al vuelo eliminado");
		for(int i=0;i<len;i++)
		{
			if(list[i].idFlyCode==id)
			{
				puts("_________________________");
				puts("| ID:   |     Vuelo:     |");
				puts("|_______|________________|");
				printFlightCode(list[i]);
				getIntNumber(&option,"Ingrese:\n1- Eliminar vuelo\n2- Cancelar operacion\n","Error numero fuera de rango\n",1,2,5);
				if(option==1)
				{
					list[i].isEmpty=EMPTY;
					puts("Vuelo eliminado exitosamente");
					break;
				}
				else
				{
					puts("Se ha cancelado la operacion con Exito");
					break;
				}
			}
		}
	}
	else
	{
		puts("El id ingresado no existe");
	}

}

int verifyCodeFlight(FlightCode list[], int code, int len)
{
	int errorCode=0;

	for(int i=0; i<len; i++)
	{
		if(list[i].idFlyCode==code)
		{
			errorCode=-1;
			break;
		}
	}

	return errorCode;
}

int searchFreePositionFlight(FlightCode list[], int len)
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
