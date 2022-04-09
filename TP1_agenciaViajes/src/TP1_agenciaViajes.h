/*
 * TP1_agenciaViajes.h
 *
 *  Created on: 7 abr. 2022
 *      Author: ezequ
 */

#ifndef TP1_AGENCIAVIAJES_H_
#define TP1_AGENCIAVIAJES_H_

int kilometersOfTravel(char []);
float flightPrice(char []);
float debitDiscount(float price, float discount);
float creditInterest(float price, float interest);
float priceInBitcoin(float price, float bitcoinPrice);
float pricePerKilometer(int kilometer, float price);
float priceDiference(float price1, float price2);

void showMenu(char texto[], float dato1, float dato2, float dato3, float dato4, float dato5);




#endif /* TP1_AGENCIAVIAJES_H_ */
