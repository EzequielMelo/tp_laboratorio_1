/*
 * funcionesGet.h
 * Author: Ezequiel Melo 1°C
 */

#ifndef FUNCIONESGET_H_
#define FUNCIONESGET_H_
#define LIMITE_BUFFER 100

/**Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado
 * en cadena un maximo de lenght-1 caracteres
 * char* string --> string al que va a devolver el valor final luego de analizarla
 * int lenght --> maximo del largo del string a verificar
 */
int myGets(char*, int);
/**Verifica que lo que le llega sean valores numericos.
 * Recorre cada posicion del string que recibe por parametro verificando
 * que en la primera posicion haya un '-' o '+' o un numero y en las siguientes
 * posiciones solo numeros.
 * char* string --> string que va a recorrer y verificar.
 * int limit --> tamaño del string a recorrer.
 */
int isANumber(char*, int);

/**Verifica que lo que le llega sean valores numericos.
 * Recorre cada posicion del string que recibe por parametro verificando
 * que sean solo numeros y que solo haya un maximo de un '.' o ',' y que
 * que en la primera posicion haya un '-' o '+' o un numero
 * char* string --> string que va a recorrer y verificar.
 * int limit --> tamaño del string a recorrer.
 */
int isAFloatNumber(char*, int);

/**Verifica que lo que le llega sean solo caracteres alfabeticos
 * Recorre cada posicion del string que recibe por parametro verificando
 * que sean solo letras en mayuscula o minuscula
 * char* string --> string que va a recorrer y verificar.
 * int limit --> tamaño del string a recorrer.
 */
int isAChar(char*, int);

/**Obtiene un numero entero
 *int* pResult Puntero al espacio de memoria donde se dejara el resultado
 *de la funcion
 *retorna 0 (EXITO) si se obtiene un numero entero y -1(ERROR) si no
 */
int getInt(int*);

/**Obtiene un numero flotante
 *float* pResult Puntero al espacio de memoria donde se dejara el resultado
 *de la funcion
 *retorna 0 (EXITO) si se obtiene un numero entero o flotante y -1(ERROR) si no
 */
int getFloat(float*);

/**Obtiene un caracter
 *char* pResult Puntero al espacio de memoria donde se dejara el resultado
 *de la funcion
 *retorna 0 (EXITO) si se obtiene un caracter y -1(ERROR) si no
 */
int getChar(char*);

int getIntNumber(int*, char*, char*, int, int, int);
int getFloatNumber(float*, char*, char*, float, float, int);
int getStringChar(char*, char*, char*, int, int, int);

#endif /* FUNCIONESGET_H_ */

