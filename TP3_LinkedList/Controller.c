#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "utn_get.h"
#include "Controller.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	int errorCode=-1;

	if((pFile=fopen(path, "r"))!=NULL)
	{
		ll_clear(pArrayListPassenger);

		if(!parser_PassengerFromText(pFile, pArrayListPassenger))
		{
			errorCode= 0;
		}

	}
	fclose(pFile);
    return errorCode;
}

int controller_loadFlyCodeFromText(char* path , LinkedList* pArrayListFlyCodes)
{
	FILE* pFile;
	int errorCode=-1;

	if((pFile=fopen(path, "r"))!=NULL)
	{
		ll_clear(pArrayListFlyCodes);

		if(!parser_FlyCodeFromText(pFile, pArrayListFlyCodes))
		{
			errorCode= 0;
		}

	}
	fclose(pFile);
    return errorCode;
}

int controller_loadTypePassengerFromText(char* path , LinkedList* pArrayTypePassengers)
{
	FILE* pFile;
	int errorCode=-1;

	if((pFile=fopen(path, "r"))!=NULL)
	{
		ll_clear(pArrayTypePassengers);

		if(!parser_TypePassengerFromText(pFile, pArrayTypePassengers))
		{
			errorCode= 0;
		}

	}
	fclose(pFile);
    return errorCode;
}

int controller_loadStatusPassengerFromText(char* path , LinkedList* pArrayStatusPassengers)
{
	FILE* pFile;
	int errorCode=-1;

	if((pFile=fopen(path, "r"))!=NULL)
	{
		ll_clear(pArrayStatusPassengers);

		if(!parser_StatusPassengerFromText(pFile, pArrayStatusPassengers))
		{
			errorCode= 0;
		}

	}
	fclose(pFile);
    return errorCode;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	int errorCode=ERROR;
	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		pFile=fopen(path,"rb");
		if(pFile!=NULL)
		{
			ll_clear(pArrayListPassenger);
			if(!parser_PassengerFromBinary(pFile, pArrayListPassenger))
			{
				errorCode=FALSE;
			}
			fclose(pFile);
		}
	}
	return errorCode;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int id;
	char nombre[LIMIT_CHARACTERS];
	char apellido[LIMIT_CHARACTERS];
	float precio;
	char codigoVuelo[LIMIT_FLYCODE];
	char tipoPasajero[LIMIT_TYPEANDSTATUS];
	char estatus[LIMIT_TYPEANDSTATUS];
	int passengerVerifier=ERROR;
	int idVerifier=ERROR;
	int option;
	Passenger* passenger;
	LinkedList* listaCodigosVuelo = ll_newLinkedList();
	LinkedList* listaTiposPasajeros = ll_newLinkedList();
	passenger=Passenger_new();

	if(pArrayListPassenger!=NULL && passenger!=NULL)
	{
		passengerVerifier=Passenger_askForOne(listaCodigosVuelo, listaTiposPasajeros, nombre, apellido, &precio, codigoVuelo, tipoPasajero);
		idVerifier=Passenger_idGenerator(&id);
		strcpy(estatus,"En Horario");
		if(passengerVerifier!=ERROR && idVerifier!=ERROR)
		{
			puts("Esta seguro que desea cargar el siguiente pasajero:");
			PassengerHeader();
			showSimplePassenger(id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estatus);
			getIntNumber(&option, "Ingrese:\n1- SI\n2- NO\n",
					"Error opcion invalida\n", 1, 2, 5);
			if(option==1)
			{
				Passenger_setId(passenger,id);
				Passenger_setNombre(passenger,nombre);
				Passenger_setApellido(passenger,apellido);
				Passenger_setPrecio(passenger,precio);
				Passenger_setCodigoVuelo(passenger,codigoVuelo);
				Passenger_setTipoPasajero(passenger,tipoPasajero);
				Passenger_setEstatusPasajero(passenger,estatus);
				ll_add(pArrayListPassenger,passenger);
				puts("Pasajero cargado con exito");
			}else
			{
				puts("Se ha cancelado la operacion");
			}
		}

	}
	ll_deleteLinkedList(listaCodigosVuelo);
	ll_deleteLinkedList(listaTiposPasajeros);
    return 1;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int id;
	char nombre[LIMIT_CHARACTERS];
	char apellido[LIMIT_CHARACTERS];
	float precio;
	int opcionCodigoVuelo;
	char codigoVuelo[LIMIT_FLYCODE];
	int opcionTipoPasajero;
	char tipoPasajero[LIMIT_TYPEANDSTATUS];
	int opcionStatusPasajero;
	char estatusPasajero[LIMIT_TYPEANDSTATUS];
	int verify;
	int idToGet;
	int len;
	int i;
	int option;
	Passenger* passenger;
	LinkedList* listaCodigosVuelo = ll_newLinkedList();
	LinkedList* listaTiposPasajeros = ll_newLinkedList();
	LinkedList* listaEstatusPasajeros= ll_newLinkedList();

	controller_loadFlyCodeFromText("flyCode.csv", listaCodigosVuelo);
	controller_loadTypePassengerFromText("typePassenger.csv", listaTiposPasajeros);
	controller_loadStatusPassengerFromText("status.csv" , listaEstatusPasajeros);


	getIntNumber(&option,"Ingrese:\n1- Si desea ver la lista de pasajeros\n2- Si desea ingresar el ID del pasajero a modificar\n","Error. Opcion incorrecta\n",1,2,5);
	if(option==1)
	{
		PassengerHeader();
		controller_ListPassenger(pArrayListPassenger);
	}

	getIntNumber(&idToGet,"Ingrese el ID del pasajero que desea modificar:\n","Error. Ha excedido el limite de id\n",1,100000,5);
	len=ll_len(pArrayListPassenger);
	for(i=0;i<len;i++)
	{
		passenger=ll_get(pArrayListPassenger, i);
		if(passenger->id == idToGet)
		{
			Passenger_getId(passenger, &id);
			Passenger_getNombre(passenger, nombre);
			Passenger_getApellido(passenger, apellido);
			Passenger_getPrecio(passenger, &precio);
			Passenger_getCodigoVuelo(passenger, codigoVuelo);
			Passenger_getTipoPasajero(passenger, tipoPasajero);
			Passenger_getEstatusPasajero(passenger, estatusPasajero);
			puts("Este es el pasajero que desea modificar:");
			PassengerHeader();
			showSimplePassenger(id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estatusPasajero);
			getIntNumber(&option, "Ingrese\n1- SI desea modificar:\n2- NO desea modificar:\n",
												"Error opcion invalida\n", 1, 2, 5);
			if(option==1)
			{
				do
				{
					puts("Modificando:");
					PassengerHeader();
					showSimplePassenger(id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estatusPasajero);
					getIntNumber(&option, "Modificar:\n1- Nombre:\n2- Apellido\n3- Precio\n4- Vuelo\n5- Tipo Pasaje\n6- Estatus Vuelo\n7- Confirmar cambios\n8- Salir(Recuerde confirmar los cambios):\n",
																	"Error opcion invalida\n", 1, 8, 5);
					switch(option)
					{
					case 1:
						getStringChar(nombre,"Ingrese Nombre del Pasajero: \n","Error ha superado el limite\n", LIMIT_CHARACTERS, 5, 1);
						break;
					case 2:
						getStringChar(apellido,"Ingrese Apellido del Pasajero: \n","Error ha superado el limite\n", LIMIT_CHARACTERS, 5, 1);
						break;
					case 3:
						getFloatNumber(&precio,"Ingrese Precio del Vuelo: \n", "Error el precio ingresado es invalido\n", 1, 5000000, 5);
						break;
					case 4:
						do
						{
						puts("Ingrese un ID de uno de los siguientes vuelos: ");
						controller_ListFlyCodes(listaCodigosVuelo);
						getIntNumber(&opcionCodigoVuelo,"Ingrese ID de Codigo de Vuelo: \n","Error ha superado el limite\n", 1, 1000, 1);
						verify=Passenger_codeAssigner(listaCodigosVuelo, opcionCodigoVuelo, codigoVuelo);
						if(verify==ERROR)
						{
							puts("Error. La opcion ingresada es incorrecta. Intente nuevamente");
						}
						}while(verify==ERROR);
						break;
					case 5:
						do
						{
						puts("Ingrese un ID de una de las siguientes clases: ");
						controller_ListTypePassengers(listaTiposPasajeros);
						getIntNumber(&opcionTipoPasajero,"Ingrese ID del tipo Pasaje:\n ","Error el numero ingresado es invalido\n", 1, 1000, 5);
						verify=Passenger_typeAssigner(listaTiposPasajeros, opcionTipoPasajero, tipoPasajero);
						}while(verify==ERROR);
						break;
					case 6:
						do
						{
						puts("Ingrese un ID de una de las siguientes clases: ");
						controller_ListStatus(listaEstatusPasajeros);
						getIntNumber(&opcionStatusPasajero,"Ingrese ID del estatus del Pasaje:\n ","Error el numero ingresado es invalido\n", 1, 1000, 5);
						verify=Passenger_statusAssigner(listaEstatusPasajeros, opcionStatusPasajero, estatusPasajero);
						}while(verify==ERROR);
						break;
					case 7:
						Passenger_setNombre(passenger,nombre);
						Passenger_setApellido(passenger,apellido);
						Passenger_setPrecio(passenger,precio);
						Passenger_setCodigoVuelo(passenger,codigoVuelo);
						Passenger_setTipoPasajero(passenger,tipoPasajero);
						Passenger_setEstatusPasajero(passenger,estatusPasajero);
						puts("Se han guardado los cambios...");
						break;
					case 8:
						puts("Saliendo...");
						break;
					}
				}while(option!=8);
			}else
			{
				puts("Se ha cancelado la operacion");
			}
			break;
		}else if(i==len-1 && passenger->id!=idToGet)
		{
			puts("El pasajero ingresado no existe");
		}

	}
	ll_deleteLinkedList(listaCodigosVuelo);
	ll_deleteLinkedList(listaTiposPasajeros);
	ll_deleteLinkedList(listaEstatusPasajeros);
    return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int id;
	char nombre[LIMIT_CHARACTERS];
	char apellido[LIMIT_CHARACTERS];
	float precio;
	char codigoVuelo[LIMIT_FLYCODE];
	char tipoPasajero[LIMIT_TYPEANDSTATUS];
	char estatusPasajero[LIMIT_TYPEANDSTATUS];
	int idToGet;
	int len;
	int i;
	int option;
	Passenger* passenger;

	getIntNumber(&option,"Ingrese:\n1- Si desea ver la lista de pasajeros\n2- Si desea ingresar el ID del pasajero a eliminar\n","Error. Opcion incorrecta\n",1,2,5);
	if(option==1)
	{
		PassengerHeader();
		controller_ListPassenger(pArrayListPassenger);
	}

	getIntNumber(&idToGet,"Ingrese el ID del pasajero que desea eliminar:\n","Error. Ha excedido el limite de id\n",1,100000,5);
	len=ll_len(pArrayListPassenger);
	for(i=0;i<len;i++)
	{
		passenger=ll_get(pArrayListPassenger, i);
		if(passenger->id == idToGet)
		{
			Passenger_getId(passenger, &id);
			Passenger_getNombre(passenger, nombre);
			Passenger_getApellido(passenger, apellido);
			Passenger_getPrecio(passenger, &precio);
			Passenger_getCodigoVuelo(passenger, codigoVuelo);
			Passenger_getTipoPasajero(passenger, tipoPasajero);
			Passenger_getEstatusPasajero(passenger, estatusPasajero);
			puts("Este es el pasajero que desea eliminar:");
			PassengerHeader();
			showSimplePassenger(id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estatusPasajero);
			getIntNumber(&option, "Ingrese\n1- SI desea eliminar:\n2- NO desea eliminar:\n",
												"Error opcion invalida\n", 1, 2, 5);
			if(option==1)
			{
				puts("Pasajero eliminado con exito...");
				ll_remove(pArrayListPassenger, i);
				break;
			}else
			{
				puts("Operacion cancelada...");
			}
			break;
		}else if(i==len-1 && passenger->id!=idToGet)
		{
			puts("El pasajero ingresado no existe");
		}
	}
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
void selectPage(LinkedList* pArrayListPassenger, int option, int* inicio, int* final, int* flag)
{
	int len;
	len = ll_len(pArrayListPassenger);

	if(option==2)
	{
		if((len - *final)<300 && *flag<len)
		{
			*inicio=*final;
			*final=len;
			*flag=*final+1;
		}else if(*flag<len)
		{
			*final+=300;
			*inicio+=300;
			*flag=*final+1;
		}
		else if(*final<300)
		{
			*inicio+=*final;
			*final=*inicio+300;
			*flag=*final+1;
			*flag=0;
		}
	}else if(option==1)
		{
			if(*final>=300 && *inicio>=1)
			{
				*final-=300;
				*inicio-=300;
				*flag=*final+1;
				if((len-*inicio)<300)
				{
					*final=*inicio;
					*inicio=0;
					*flag=*final+1;
				}
				if(*inicio<0)
				{
					*inicio=0;
				}
			}
		}
}

void showFromTo(LinkedList* pArrayListPassenger)
{
	int option;
	int inicio=0;
	int final=300;
	int flag=0;

	LinkedList* listaPasajerosAuxiliar = ll_newLinkedList();

	do
	{
		listaPasajerosAuxiliar=ll_subList(pArrayListPassenger,inicio,final);
		listPassenger(listaPasajerosAuxiliar);
		getIntNumber(&option,"Ingrese:\n1- Pagina Anterior(<---)           2- Pagina Siguiente(--->)\n3- Salir\n",
					"Error. Ha ingresado una opcion incorrecta\n",1,3,5);
		ll_clear(listaPasajerosAuxiliar);
		selectPage(pArrayListPassenger, option, &inicio, &final, &flag);
	}while(option!=3);

	ll_deleteLinkedList(listaPasajerosAuxiliar);
}

void listPassenger(LinkedList* pArrayListPassenger)
{
	int len;

	len=ll_len(pArrayListPassenger);
	Passenger_showPassenger(pArrayListPassenger, 0, len);
}

int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int rtn=-1;

	if(pArrayListPassenger != NULL)
	{
		showFromTo(pArrayListPassenger);
		rtn=1;
	}
    return rtn;
}

int controller_ListFlyCodes(LinkedList* pArrayListFlyCodes)
{
	int rtn=-1;
	int len;

	if(pArrayListFlyCodes != NULL)
	{
		len=ll_len(pArrayListFlyCodes);
		FlyCodesHeader();
		FlyCode_showFlyCodes(pArrayListFlyCodes, 0, len);
		rtn=1;
	}
    return rtn;
}

int controller_ListTypePassengers(LinkedList* pArrayTypePassengers)
{
	int rtn=-1;
	int len;

	if(pArrayTypePassengers != NULL)
	{
		len=ll_len(pArrayTypePassengers);
		TypePassengerHeader();
		FlyCode_showTypePassengers(pArrayTypePassengers, 0, len);
		rtn=1;
	}
    return rtn;
}

int controller_ListStatus(LinkedList* pArrayStatusPassengers)
{
	int rtn=-1;
	int len;

	if(pArrayStatusPassengers != NULL)
	{
		len=ll_len(pArrayStatusPassengers);
		StatusHeader();
		FlyCode_showTypePassengers(pArrayStatusPassengers, 0, len);
		rtn=1;
	}
    return rtn;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	LinkedList* listPassengersaux;
	int option;
	int parameter;
	listPassengersaux = ll_clone(pArrayListPassenger);
	getIntNumber(&option, "Indique como organizar:\n1- Por ID:\n2- Por Nombre:\n3- Por precio\n4- Salir\n",
				"Error opcion invalida", 1, 4, 5);
	switch(option)
	{
	case 1:
		parameter=Passenger_compareParameter("Indique el modo:\n1. Menor a mayor\n2. Mayor a menor\n");
		puts("Espere esta accion puede tardar unos segundos...");
		ll_sort(listPassengersaux, Passenger_comparebyId, parameter);
		controller_ListPassenger(listPassengersaux);
		break;
	case 2:
		parameter=Passenger_compareParameter("Indique el modo:\n1. De: (Z a A)\n2. De: (A a Z)\n");
		puts("Espere esta accion puede tardar unos segundos...");
		ll_sort(listPassengersaux, Passenger_comparebyName, parameter);
		controller_ListPassenger(listPassengersaux);
		break;
	case 3:
		parameter=Passenger_compareParameter("Indique el modo:\n1. Menor a mayor\n2. Mayor a menor\n");
		puts("Espere esta accion puede tardar unos segundos...");
		ll_sort(listPassengersaux, Passenger_comparebyPrice, parameter);
		controller_ListPassenger(listPassengersaux);
		break;
	}
	ll_deleteLinkedList(listPassengersaux);
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	Passenger* passenger;
	//LinkedList* listPassengersaux = ll_newLinkedList();
	FILE *pFile;
	int errorCode=ERROR;
	int i;
	//int min;
	int len;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{

		len = ll_len(pArrayListPassenger);
		//min = Passenger_minLenghtList(path);
		/*
		printf("minimo:%d\n",min);
		printf("maximo:%d\n",len);
		listPassengersaux = ll_subList(pArrayListPassenger,min,len);
		if(len>min)
		{
			puts("Nuevos pasajeros: ");
			//listPassengersaux = ll_subList(pArrayListPassenger,min,len);
			showFromTo(listPassengersaux);
			ll_deleteLinkedList(listPassengersaux);
		}
		*/
		pFile=fopen(path, "w");
		if(pFile!=NULL)
		{
			fprintf(pFile,"%s,%s,%s,%s,%s,%s,%s\n","id","name","lastname","price","flycode","typePassenger","statusFlight");
			for(i=0; i<len; i++)
			{
				passenger=ll_get(pArrayListPassenger, i);
				fprintf(pFile,"%d,%s,%s,%.2f,%s,%s,%s\n", passenger->id,
															passenger->nombre,
															passenger->apellido,
															passenger->precio,
															passenger->codigoVuelo,
															passenger->tipoPasajero,
															passenger->estatus);
				errorCode=FALSE;
			}
			puts("Se han cargado todos los pasajeros con exito.");
		}
	}
	fclose(pFile);
    return errorCode;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	Passenger* passenger;
	FILE *pFile;
	int errorCode=ERROR;
	int i;
	int len;


	if(path!=NULL && pArrayListPassenger!=NULL)
	{

		len = ll_len(pArrayListPassenger);
		pFile=fopen(path, "wb");

		if(pFile!=NULL)
		{
			for(i=0; i<len-1; i++)
			{
				passenger=ll_get(pArrayListPassenger, i);
				fwrite(passenger, sizeof(Passenger), 1, pFile);
				errorCode=0;
			}
		}
		puts("Se han cargado todos los pasajeros con exito.");
	}
	fclose(pFile);
    return errorCode;
}

