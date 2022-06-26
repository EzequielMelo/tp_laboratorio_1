#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

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
	int idFlyCode;
	char flyCode[LIMIT_CODE]; //codigo de avion a abordar
	int isEmpty;
}FlightCode;

int initFlights(FlightCode* list, int len);
void addFlightHardcode(FlightCode list[], int len);
int addFlight(FlightCode list[], int len);
void removeFlight(FlightCode list[], int len);
int verifyCodeFlight(FlightCode list[], int code, int len);
int searchFreePositionFlight(FlightCode list[], int len);
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
