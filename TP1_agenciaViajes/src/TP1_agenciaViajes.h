/*
 * TP1_agenciaViajes.h
 *
 *  Created on: 7 abr. 2022
 *      Author: Ezequiel Melo 1°B
 */

#ifndef TP1_AGENCIAVIAJES_H_
#define TP1_AGENCIAVIAJES_H_

/**
 * @brief Pide un dato numerico de tipo entero y lo valida
 * @param Le paso el mensaje que deseo que se muestre a la hora de pedir los datos
 * @return retorna un dato numerico de tipo entero
 */
int kilometersOfTravel(char[]);

/**
 * @brief Pide un dato numerico de tipo flotante y lo valida
 * @param Le paso el mensaje que deseo que se muestre a la hora de pedir los datos
 * @return retorna un dato numerico de tipo flotante
 */
float flightPrice(char[]);

/**
 * @brief Recibe un dato numerico de tipo flotante y le aplica el descuento correspondiente
 * @param Le paso el dato numerico al que quiero aplicar el descuento
 * @param le paso la cantidad de descuento que quiero aplicar
 * @return retorna el total luego de aplicar el descuento
 */
float debitDiscount(float, float);

/**
 * @brief Recibe un dato numerico de tipo flotante y le aplica el aumento correspondiente
 * @param Le paso el dato numerico al que quiero aplicar el aumento
 * @param le paso la cantidad de aumento que quiero aplicar
 * @return retorna el total luego de aplicar el aumento
 */
float creditInterest(float, float);

/**
 * @brief Recibe un dato numerico de tipo flotante y pasa su valor a bitcoins
 * @param Le paso el dato numerico al que quiero convertir a bitcoin
 * @param Le paso el valor actual del bitcoin
 * @return Retorna el total luego de convertir a bitcoin
 */
float priceInBitcoin(float, float);

/**
 * @brief Recibe un dato numerico de tipo flotante y te da el valor del viaje por km
 * @param Le paso los kilometros
 * @param Le paso el precio con el que se va a calcular
 * @return Retorna el total de lo que vale el viaje por km
 */
float pricePerKilometer(int, float);

/**
 * @brief Recibe dos flotantes y te da la diferencia que hay entre estos
 * @param Le paso un numero de tipo flotante
 * @param Le paso un numero de tipo flotante
 * @return Retorna la diferencia entre los numeros luego de realizar el calculo
 */
float priceDiference(float, float);

/**
 * @brief Muestra en pantalla un menu con sus respectivos datos
 * @param Mensaje de que Aerolinea se va a mostrar
 * @param Le paso el precio a mostrar
 * @param Le paso el precio con descuento a mostrar
 * @param Le paso el precio con interes a mostrar
 * @param Le paso el precio en Bitcoins a mostrar
 * @param Le paso el precio por kilometro a mostrar
 */
void showMenu(char[], float, float, float, float, float);




#endif /* TP1_AGENCIAVIAJES_H_ */
