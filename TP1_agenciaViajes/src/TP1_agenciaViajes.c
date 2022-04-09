/*
 ============================================================================
 Name        : TP1_agenciaViajes.c
 Author      : 
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
	float descuentoConDebitoAerolineas;
	float InteresConCreditoAerolineas;
	float precioBitcoinAerolineas;
	float precioPorkilometroAerolineas;
	float descuentoConDebitoLatam;
	float InteresConCreditoLatam;
	float precioBitcoinLatam;
	float precioPorkilometroALatam;
	float diferenciaPrecios;


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
		getIntNumber(&option,"Ingrese una opcion: ", "Error opcion incorrecta: \n", 1, 6, 5);

		switch(option)
		{
		case 1:
			kilometres= kilometersOfTravel("Ingrese la cantidad de kilometros que desee: ");
			if(kilometres>0)
			{
				flagKilometres=0;
			}
			limpiar_pantalla();
		    //system ("pause");
		    //system ("cls");
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
				descuentoConDebitoAerolineas = debitDiscount(priceAerolineas, 0.90);
				descuentoConDebitoLatam = debitDiscount(priceLatam, 0.90);
				InteresConCreditoAerolineas = creditInterest(priceAerolineas, 1.25);
				InteresConCreditoLatam = creditInterest(priceLatam, 1.25);
				precioBitcoinAerolineas = priceInBitcoin(priceAerolineas, 4606954.55);
				precioBitcoinLatam = priceInBitcoin(priceLatam, 4606954.55);
				precioPorkilometroAerolineas = pricePerKilometer(kilometres, priceAerolineas);
				precioPorkilometroALatam = pricePerKilometer(kilometres, priceLatam);
				diferenciaPrecios = priceDiference(priceAerolineas, priceLatam);
				flagOperations=0;
				printf("\nCalculos realizados con exito...\n\n");
			    system ("pause");
			    system ("cls");
			}else
			{
				printf("\nError. Antes debe ingresar Kilometros y precio de vuelos\n");
			}
			break;
		case 4:
			if(flagOperations==-1)
			{
				printf("\nError. Antes debe calcular los costos\n");
			}else
			{
				printf("\nKilometros Ingresados: %d\n", kilometres);
				showMenu("Aerolineas", priceAerolineas, descuentoConDebitoAerolineas, InteresConCreditoAerolineas, precioBitcoinAerolineas, precioPorkilometroAerolineas);
				showMenu("Latam", priceLatam, descuentoConDebitoLatam, InteresConCreditoLatam, precioBitcoinLatam, precioPorkilometroALatam);
				printf("La diferencia de Precios es: %.2f\n",diferenciaPrecios);
			    system ("pause");
			    system ("cls");
			}
			break;
		case 5:
			kilometres=7090;
			priceAerolineas=162965;
			priceLatam=159339;

			descuentoConDebitoAerolineas = debitDiscount(priceAerolineas, 0.90);
			descuentoConDebitoLatam = debitDiscount(priceLatam, 0.90);
			InteresConCreditoAerolineas = creditInterest(priceAerolineas, 1.25);
			InteresConCreditoLatam = creditInterest(priceLatam, 1.25);
			precioBitcoinAerolineas = priceInBitcoin(priceAerolineas, 4606954.55);
			precioBitcoinLatam = priceInBitcoin(priceLatam, 4606954.55);
			precioPorkilometroAerolineas = pricePerKilometer(kilometres, priceAerolineas);
			precioPorkilometroALatam = pricePerKilometer(kilometres, priceLatam);
			diferenciaPrecios = priceDiference(priceAerolineas, priceLatam);

			printf("\nKilometros Ingresados: %d\n", kilometres);
			showMenu("Aerolineas", priceAerolineas, descuentoConDebitoAerolineas, InteresConCreditoAerolineas, precioBitcoinAerolineas, precioPorkilometroAerolineas);
			showMenu("Latam", priceLatam, descuentoConDebitoLatam, InteresConCreditoLatam, precioBitcoinLatam, precioPorkilometroALatam);
			printf("La diferencia de Precios es: %.2f\n",diferenciaPrecios);
		    system ("pause");
		    system ("cls");
			break;
		case 6:
			break;
		}
	    system ("pause");
	    system ("cls");

	}while(option!=6);

	printf("\nGracias por utilizar nuestro programa. Hasta pronto!!!");

	return EXIT_SUCCESS;
}
