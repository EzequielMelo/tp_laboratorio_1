#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "FuncionesGetAgenciaViajes.h"
#include "TP1_agenciaViajes.h"

int kilometersOfTravel(char text[])
{
	int dato;

	getIntNumber(&dato, text, "Error ingrese kilometros validos", 1, 9999999, 5);

	return dato;
}

float flightPrice(char text[])
{
	float dato;

	getFloatNumber(&dato, text,"Error, Ingrese un precio correcto: ", 1, 9999999, 5);

	return dato;
}

float debitDiscount(float price, float discount)
{
	float totalDiscount;

	totalDiscount = price * discount;

	return totalDiscount;
}

float creditInterest(float price, float interest)
{
	float totalWithInterest;

	totalWithInterest = price * interest;

	return totalWithInterest;
}

float priceInBitcoin(float price, float bitcoinPrice)
{
	float totalInBitcoin;

	totalInBitcoin = price / bitcoinPrice;

	return totalInBitcoin;
}

float pricePerKilometer(int kilometer, float price)
{
	float pricePerKilometer;

	pricePerKilometer= price / kilometer;

	return pricePerKilometer;
}

float priceDiference(float price1, float price2)
{
	float diference;

	if(price1>price2)
	{
		diference= price1-price2;
	}else
	{
		diference= price2-price1;
	}

	return diference;
}

void showMenu(char texto[], float dato1, float dato2, float dato3, float dato4, float dato5)
{
	printf("--------------%s--------------\n", texto);
	printf("Precio %s: $%.2f\n",texto, dato1);
	printf("Precio con tarjeta de debito: %.2f\n",dato2);
	printf("Precio con tarjeta de credito: %.2f\n",dato3);
	printf("Precio pagando con Bitcoin: %f\n",dato4);
	printf("Precio unitario: %.2f\n",dato5);
}
