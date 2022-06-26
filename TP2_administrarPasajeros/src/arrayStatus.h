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
