#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_get.h"

#define LIMIT_CHARACTERS 51
#define LENPASSENGERS 2000
#define LIMIT_CODE 10
#define EMPTY 0
#define TAKEN 1
#define FALSE 0
#define TRUE 1
#define ERROR -1

typedef struct
{
	int idStatusFlight;
	char statusFlight[LIMIT_CHARACTERS]; //activo o cancelado o demorado
	int isEmpty;
}StatusFlight;

typedef struct
{
	int idTypePassenger;
	char typePassenger[LIMIT_CHARACTERS]; //a mi criterio: primera clase, turista, ejecutiva
	int isEmpty;
}TypePassenger;

typedef struct
{
	int idFlyCode;
	char flyCode[LIMIT_CODE]; //codigo de avion a abordar
	int isEmpty;
}FlightCode;

typedef struct
{
	int id;
	char name[LIMIT_CHARACTERS];
	char lastName[LIMIT_CHARACTERS];
	float price;
	int flyCode;
	int typePassenger;
	int statusFlight;
	int isEmpty;
}Passenger;

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array and the id flag too
* \param list Passenger* Pointer to array of passenger *
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*
*/
int initPassengers(Passenger* list, int len);

/**
 *Indica si encuentra alguna posicion libre y retorna el index de la posicion
 * @param list
 * @param len
 * @return int Return (-1) si no encuentra posiciones libres - (index) si no hay error
 */
int searchFreePosition(Passenger* list, int len);

/**
 * Indica si encuentra alguna posicion tomanda
 * @param list
 * @param len
 * @return int Return (-1) si no encuentra posiciones tomadas - (takenPosition=0) si no hay error
 */
int searchForTakenPositions(Passenger* list, int len);

/**
 * Indica si encuentra alguna posicion tomanda y cuenta cuantas son en total
 * @param list
 * @param len
 * @return int Return (-1) si no encuentra posiciones tomadas - (takenPositions) si no hay error
 */
int takenPositionsCounter(Passenger* list, int len);

/**
 * Recorre la lista y verifica que el numero que le pasamor por (int toVerify) exista en la lista
 * @param list
 * @param len
 * @param toVerify
 * @return int return (-1) si el numero no existe - (int exists 0) si el numero existe
 */
int verifyFlightCode(FlightCode list[], int len, int toVerify);

/**
 * Recorre la lista buscando el mayor numero de id, le suma una unidad y la devuelve por return
 * @param list
 * @param len
 * @return int return (id)
 */
int idGenerator(Passenger list[], int len);

/*---------------------------------------------------------Alta lista-------------------------------------------------------------------------*/

/**
 * Verifica que todos los datos ingresados en los campos esten correctos y los devuelve *
 * @param list
 * @param len
 * @param listflightCode
 * @param flightCodeLen
 * @param listTypePassenger
 * @param lenTypePassenger
 * @param name
 * @param lastName
 * @param price
 * @param flightCode
 * @param typePassenger
 * @return return int Return (-1) if Error - (0) if Ok
 */
int askForPassenger(Passenger list[], int len, FlightCode listflightCode[], int flightCodeLen, TypePassenger listTypePassenger[], int lenTypePassenger, char name[], char lastName[], float* price, int* flightCode, int* typePassenger);

/**
 * brief add in a existing list of passengers the values received as parameters* in the first empty position *
 * @param list
 * @param len
 * @param listflightCode
 * @param flightCodeLen
 * @param listTypePassenger
 * @param lenTypePassenger
 * @param listFLights
 * @param lenFlights
 * @param id
 * @param name
 * @param lastName
 * @param price
 * @param flyCode
 * @param typePassenger
 * @param statusFlight
 * @return return int Return (-1) if Error - (0) if Ok
 */
int addPassenger(Passenger* list, int len, FlightCode* listflightCode, int flightCodeLen, TypePassenger* listTypePassenger,  int lenTypePassenger, StatusFlight* listFLights, int lenFlights, int id, char name[], char lastName[], float price, int flyCode, int typePassenger, int statusFlight);

/*---------------------------------------------------------Modificar lista-------------------------------------------------------------------------*/

/**
 * Busca en la lista que en el array de la variable id exista el id que ingresamos
 * @param list
 * @param len
 * @param id
 * @return return int passengerIndex (-1) si no encuentra o (index) si es correcto y existe
 */
int findPassengerById(Passenger* list, int len,int id);

/**
 * Verifica que todos los datos ingresados en los campos esten correctos y los devuelve *
 * @param list
 * @param index
 * @param listflightCode
 * @param flightCodeLen
 * @param listTypePassenger
 * @param lenTypePassenger
 * @param listFLights
 * @param lenFlights
 */
void modifyPassenger(Passenger list[], int index, FlightCode listflightCode[], int flightCodeLen, TypePassenger listTypePassenger[], int lenTypePassenger, StatusFlight* listFLights, int lenFlights);

/**
 * Modifica los valores que decidas de uno de la lista y los pisa con los nuevos datos que le pasemos
 * @param list
 * @param len
 * @param listflightCode
 * @param flightCodeLen
 * @param listTypePassenger
 * @param lenTypePassenger
 * @param listFLights
 * @param lenFlights
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*
 */
int passengerModifier(Passenger* list, int len, FlightCode listflightCode[], int flightCodeLen, TypePassenger listTypePassenger[], int lenTypePassenger, StatusFlight* listFLights, int lenFlights);

/*---------------------------------------------------------Eliminar uno de la lista-------------------------------------------------------------------------*/

/**
 * Cambia el estado de isEmpty en la lista en el indice correcto de TAKEN a EMPTY
 * @param list
 * @param len
 * @param id
 * @return int Return (-1) if Error - (0) if Ok*
 */
int removePassenger(Passenger* list, int len, int id);

/**
 * Elimina un pasajero de la lista y muestra cual y si estas seguro
 * @param list
 * @param len
 * @param listflightCode
 * @param flightCodeLen
 * @param listTypePassenger
 * @param lenTypePassenger
 * @param listFLights
 * @param lenFlights
 * @return int Return (-1) if Error - (0) if Ok*
 */
int passengerRemover(Passenger* list, int len, FlightCode listflightCode[], int flightCodeLen, TypePassenger listTypePassenger[], int lenTypePassenger, StatusFlight* listFLights, int lenFlights);

/*---------------------------------------------------------Operaciones(promedios, sumas etc)-------------------------------------------------------------------------*/

/**
 * Recorre toda la lista sumando los precio para darte la suma total por retorno
 * @param list
 * @param len
 * @return float return (total)
 */
float totalPrice(Passenger* list, int len);

/**
 * Con los datos del total utiliza la funcion de contar la cantidad total de pasajeros para devolver un promedio
 * @param list
 * @param len
 * @param total
 * @return float return (average)
 */
float averagePrice(Passenger* list, int len, float total);

/**
 * Con los datos del promedio busca cuales son los que estan por encima de este y los retorna
 * @param list
 * @param len
 * @param average
 * @param listCodes
 * @param lenCodes
 * @param listType
 * @param lenTypes
 * @param listFLights
 * @param lenFlights
 * @return float return (overAverage)
 */
int overAveragePassengers(Passenger* list, int len, float average, FlightCode* listCodes, int lenCodes, TypePassenger* listType, int lenTypes, StatusFlight* listFLights, int lenFlights);

/**
 * contiene los datos de todas las funciones que hacen operaciones con la lista para poder mostrarlos
 * @param list
 * @param len
 * @param listCodes
 * @param lenCodes
 * @param listType
 * @param lenTypes
 * @param listFLights
 * @param lenFlights
 */
void operationsManager(Passenger* list, int len, FlightCode* listCodes, int lenCodes, TypePassenger* listType, int lenTypes, StatusFlight* listFLights, int lenFlights);

/*---------------------------------------------------------Ordenar lista-------------------------------------------------------------------------*/

/**
 * Contiene los datos necesarios para hacer el burbujeo
 * @param list
 * @param x
 * @param y
 */
void sort(Passenger* list, int x, int y);

/**
 * Ordena los pasajeros alfabeticamente segun decidas y por tipo
 * @param list
 * @param len
 * @param order
 * @param listflightCode
 * @param flightCodeLen
 * @param listTypePassenger
 * @param lenTypePassenger
 * @param listFLights
 * @param lenFlights
 * @return int Return (-1) if Error - (0) if Ok*
 */
int sortPassengersByLastNameAndType(Passenger* list, int len, int order, FlightCode listflightCode[], int flightCodeLen, TypePassenger listTypePassenger[], int lenTypePassenger, StatusFlight* listFLights, int lenFlights);

/**
 * Ordena los pasajeros por id segun decidas
 * @param list
 * @param len
 * @param order
 * @return int Return (-1) if Error - (0) if Ok*
 */
int sortPassengersById(Passenger* list, int len, int order);

/*---------------------------------------------------------Mostrar lista-------------------------------------------------------------------------*/

/**
 * Muestra un pasajero sin el status y sin el codigo
 * @param list
 * @param listType
 * @param lenTypes
 */
void printAPassengerTwo(Passenger list, TypePassenger* listType, int lenTypes);

/**
 * Muestra todos los pasajeros de la lista por Codigo de vuelo y estado activo
 * @param list
 * @param length
 * @param listCodes
 * @param lenCodes
 * @param listType
 * @param lenTypes
 * @param listFLights
 * @param lenFlights
 * @return int Return (-1) if Error - (0) if Ok*
 */
int printPassengersTwo(Passenger* list, int length, FlightCode* listCodes, int lenCodes, TypePassenger* listType, int lenTypes, StatusFlight* listFLights, int lenFlights);

/**
 * Muestra un pasajero con todos sus datos
 * @param list
 * @param listCodes
 * @param lenCodes
 * @param listType
 * @param lenTypes
 * @param listFLights
 * @param lenFlights
 */
void printAPassenger(Passenger list, FlightCode* listCodes, int lenCodes, TypePassenger* listType, int lenTypes, StatusFlight* listFLights, int lenFlights);

/**
 * Muestra todos los pasajeros de la lista con todos sus datos
 * @param list
 * @param length
 * @param listCodes
 * @param lenCodes
 * @param listType
 * @param lenTypes
 * @param listFLights
 * @param lenFlights
 * @return int Return (-1) if Error - (0) if Ok*
 */
int printPassengers(Passenger* list, int length, FlightCode* listCodes, int lenCodes, TypePassenger* listType, int lenTypes, StatusFlight* listFLights, int lenFlights);

/**
 * Muestra un status
 * @param list
 */
void printStatusFlight(StatusFlight list);

/**
 * Muestra todos los status
 * @param list
 * @param len
 */
void printStatusFlights(StatusFlight list[], int len);

/**
 * Muestra un tipo de pasajero
 * @param list
 */
void printTypePassenger(TypePassenger list);

/**
 * Muestra todos los tipo de pasajeros
 * @param list
 * @param len
 */
void printTypePassengers(TypePassenger list[], int len);

/**
 * Muestra un codigo de vuelo
 * @param list
 */
void printFlightCode(FlightCode list);

/**
 * Muestra todos los codigo de vuelo
 * @param list
 * @param len
 */
void printFlightCodes(FlightCode list[], int len);

/**
 * Contiene la cabecera acerca de los datos de los pasajeros que se van a mostrar
 */
void title();

