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
	int idTypePassenger;
	char typePassenger[LIMIT_CHARACTERS]; //a mi criterio: primera clase, turista, ejecutiva
	int isEmpty;
}TypePassenger;

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
