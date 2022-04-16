/*
 ============================================================================
 Name        : TP1_agenciaViajes.c
 Author      : Ezequiel Melo 1°B
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "TP1_agenciaViajes.h"
#include "FuncionesGetAgenciaViajes.h"

int main(void)
{
	int option;
	int subOption;
	int flagKilometres=-1;
	int flagPrice=-1;
	int flagOperations=-1;
	int kilometres=0;
	float priceAerolineas=0;
	float priceLatam=0;
	float debitDiscountAerolineas;
	float creditInterestAerolineas;
	float priceInBitcoinAerolineas;
	float pricePerKilometerAerolineas;
	float debitDiscountLatam;
	float creditInterestLatam;
	float priceInBitcoinLatam;
	float pricePerKilometerLatam;
	float priceDiferenceFinal;



	setbuf(stdout,NULL);
	printf("-------------Bienvenido!!!-------------\n");

	do
	{
		printf("\n-----------MENU DE OPCIONES-----------\n");
		printf("\n1. Ingresar Kilometros\n");
		if(flagKilometres==0)
		{
			printf("Kilometros ingresados: %d\n\n",kilometres);
		}else
		{
			printf("Aun no se han ingresado kilometros\n\n");
		}

		printf("2. Ingresar Precio de Vuelos\n");
		if(flagPrice==0)
		{
			printf("Aerolineas: %.2f\n\n",priceAerolineas);
		}else if(flagPrice==1)
		{
			printf("Latam: %.2f\n\n",priceLatam);
		}else if(flagPrice==2)
		{
			printf("Aerolineas: %.2f || Latam: %.2f\n\n",priceAerolineas, priceLatam);
		}
		else
		{
			printf("Aun no se ha ingresado ningun precio\n\n");
		}

		printf("3. Calcular todos los costos\n");
		printf("4. Informar Resultados\n");
		printf("5. Carga forzada\n");
		printf("6. Salir\n");
		setbuf(stdin,NULL);
		fflush(stdin);
		getIntNumber(&option,"Ingrese una opcion: ", "\nError. Ingrese una opcion correcta (1-6):\n", 1, 6, 5);

	    system ("cls");

		switch(option)
		{
		case 1:
			kilometres= kilometersOfTravel("Ingrese la cantidad de kilometros que desee: ");
			if(kilometres>0)
			{
				flagKilometres=0;
			}
		    system ("pause");
		    system ("cls");
			break;
		case 2:
			getIntNumber(&subOption, "1. Ingresar precio Aerolineas: \n2. Ingresar precio Latam: \n", "Error opcion incorrecta\n", 1, 9999999, 5);
			switch(subOption)
			{
			case 1:
				priceAerolineas= flightPrice("Ingrese el precio que desee para Aerolineas: ");
				break;
			case 2:
				priceLatam= flightPrice("Ingrese el precio que desee para Latam: ");
				break;
			}
			if(priceAerolineas !=0 && priceLatam == 0)
			{
				flagPrice=0;
			}else if(priceAerolineas == 0 && priceLatam != 0)
			{
				flagPrice=1;
			}else if(priceAerolineas > 0 && priceLatam > 0)
			{
				flagPrice=2;
			}
		    system ("pause");
		    system ("cls");
			break;
		case 3:
			if(flagKilometres==-1)
			{
				printf("\nError. Antes debe ingresar Kilometros\n");
			}else if(flagPrice==0)
			{
				printf("\nError. Antes debe ingresar precio valido para Latam\n");
			}else if(flagPrice==1)
			{
				printf("\nError. Antes debe ingresar precio valido para Aerolineas\n");
			}else if(flagPrice==2 && flagKilometres==0)
			{
				debitDiscountAerolineas = debitDiscount(priceAerolineas, 0.90);
				debitDiscountLatam = debitDiscount(priceLatam, 0.90);
				creditInterestAerolineas = creditInterest(priceAerolineas, 1.25);
				creditInterestLatam = creditInterest(priceLatam, 1.25);
				priceInBitcoinAerolineas = priceInBitcoin(priceAerolineas, 4606954.55);
				priceInBitcoinLatam = priceInBitcoin(priceLatam, 4606954.55);
				pricePerKilometerAerolineas = pricePerKilometer(kilometres, priceAerolineas);
				pricePerKilometerLatam = pricePerKilometer(kilometres, priceLatam);
				priceDiferenceFinal = priceDiference(priceAerolineas, priceLatam);
				flagOperations=0;
				printf("\nCalculos realizados con exito...\n\n");
			}else
			{
				printf("\nError. Antes debe ingresar Kilometros y precio de vuelos\n");
			}
		    system ("pause");
		    system ("cls");
			break;
		case 4:
			if(flagOperations==-1)
			{
				printf("\nError. Antes debe calcular los costos\n\n");
			}else
			{
				printf("\nKilometros Ingresados: %d\n\n", kilometres);
				showMenu("Aerolineas", priceAerolineas, debitDiscountAerolineas, creditInterestAerolineas, priceInBitcoinAerolineas, pricePerKilometerAerolineas);
				showMenu("Latam", priceLatam, debitDiscountLatam, creditInterestLatam, priceInBitcoinLatam, pricePerKilometerLatam);
				printf("\nLa diferencia de Precios es: %.2f\n\n",priceDiferenceFinal);
			}
		    system ("pause");
		    system ("cls");
			break;
		case 5:
			kilometres=7090;
			priceAerolineas=162965;
			priceLatam=159339;

			debitDiscountAerolineas = debitDiscount(priceAerolineas, 0.90);
			debitDiscountLatam = debitDiscount(priceLatam, 0.90);
			creditInterestAerolineas = creditInterest(priceAerolineas, 1.25);
			creditInterestLatam = creditInterest(priceLatam, 1.25);
			priceInBitcoinAerolineas = priceInBitcoin(priceAerolineas, 4606954.55);
			priceInBitcoinLatam = priceInBitcoin(priceLatam, 4606954.55);
			pricePerKilometerAerolineas = pricePerKilometer(kilometres, priceAerolineas);
			pricePerKilometerLatam = pricePerKilometer(kilometres, priceLatam);
			priceDiferenceFinal = priceDiference(priceAerolineas, priceLatam);

			printf("\nKilometros Ingresados: %d\n\n", kilometres);
			showMenu("Aerolineas", priceAerolineas, debitDiscountAerolineas, creditInterestAerolineas, priceInBitcoinAerolineas, pricePerKilometerAerolineas);
			showMenu("Latam", priceLatam, debitDiscountLatam, creditInterestLatam, priceInBitcoinLatam, pricePerKilometerLatam);
			printf("\nLa diferencia de Precios es: %.2f\n\n",priceDiferenceFinal);
		    system ("pause");
		    system ("cls");

			kilometres=0;
			priceAerolineas=0;
			priceLatam=0;
			break;
		}
	}while(option!=6);

	printf("\n\nGracias por utilizar nuestro programa. Hasta pronto!!!\n\n");

    system ("pause");

	return EXIT_SUCCESS;
}
