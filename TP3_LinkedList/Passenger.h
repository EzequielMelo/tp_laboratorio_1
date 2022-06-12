/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#include "LinkedList.h"
#define LIMIT_CHARACTERS 50
#define LIMIT_FLYCODE 10
#define LIMIT_TYPEANDSTATUS 20
#define ERROR -1
#define FALSE 0
#define TRUE 1

typedef struct
{
 int id;
 char statusPasajero[20];
}StatusPassenger;

typedef struct
{
	int id;
	char tipoPasajero[20];
}TypePassenger;

typedef struct
{
	int id;
	char codigoVuelo[10];
	char destino[50];
}FlyCode;

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[10];
	char tipoPasajero[20];
	char estatus[20];
}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char*precioStr,char*codigoStr,char*tipoStr,char*estatusStr);
FlyCode* FlyCode_newParametros(char* idStr,char* codigoStr,char* destinoStr);
TypePassenger* TypePassenger_newParametros(char* idStr,char* tipoStr);
StatusPassenger* StatusPassenger_newParametros(char* idStr,char* estatusStr);

void Passenger_delete();

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

int Passenger_setEstatusPasajero(Passenger* this,char* tipoPasajero);
int Passenger_getEstatusPasajero(Passenger* this,char* tipoPasajero);

int Passenger_codeAssigner(LinkedList* pArrayListFlyCodes, int id, char* class);
int Passenger_typeAssigner(LinkedList* pArrayTypePassengers, int id, char* type);
int Passenger_statusAssigner(LinkedList* pArrayStatusPassengers, int id, char* status);
int Passenger_idGenerator(int* id);
int Passenger_askForOne(LinkedList* pArrayListFlyCodes, LinkedList* pArrayTypePassengers, char* name, char* lastName, float* price, char* flightCode, char* typePassenger);
int Passenger_compareParameter(char* message);
int Passenger_comparebyId(void* emp1, void* emp2);
int Passenger_comparebyName(void* emp1, void* emp2);
int Passenger_comparebyPrice(void* emp1, void* emp2);
int Passenger_minLenghtList(char* path);

void Passenger_showPassenger(LinkedList* pArrayListEPassengers, int min, int max);
void PassengerHeader();
void FlyCode_showFlyCodes(LinkedList* pArrayListFlyCodes, int min, int max);
void FlyCodesHeader();
void FlyCode_showTypePassengers(LinkedList* pArrayTypePassengers, int min, int max);
void TypePassengerHeader();
void FlyCode_showStatusPassengers(LinkedList* pArrayStatusPassengers, int min, int max);
void StatusHeader();
void showSimplePassenger(int id, char nombre[], char apellido[], float precio, char codigoVuelo[], char tipoPasajero[], char estatus[]);



#endif /* PASSENGER_H_ */
