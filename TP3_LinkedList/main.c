#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn_get.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
    int option = 0;
    int flag=ERROR;
    LinkedList* listaPasajeros = ll_newLinkedList();
    setbuf(stdout, NULL);
    do{
    	puts("------------------------------------MENU------------------------------------");
    	puts("1- Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).");
    	puts("2- Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).");
    	puts("3- Alta pasajero.");
    	puts("4- Modificar pasajero.");
    	puts("5- Eliminar pasajero.");
    	puts("6- Listar pasajeros.");
    	puts("7- Odenar pasajeros.");
    	puts("8- Guardar los datos de los pasajeros en el archivo data.csv (modo texto).");
    	puts("9- Guardar los datos de los pasajeros en el archivo data.bin (modo binario).");
    	puts("10- Salir.");
		getIntNumber(&option, "Ingrese una opcion del menu:",
				"Error opcion invalida", 1, 10, 5);
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv", listaPasajeros);
                flag=FALSE;
                break;
            case 2:
            	controller_loadFromBinary("data.bin", listaPasajeros);
            	flag=FALSE;
            	break;
            case 3:
            	if(flag!=ERROR)
            	{
            		controller_addPassenger(listaPasajeros);
            	}else
            	{
            		puts("Error. Antes debe cargar los datos de los pasajeros.");
            	}
            	break;
            case 4:
            	if(flag!=ERROR)
            	{
            		controller_editPassenger(listaPasajeros);
            	}else
            	{
            		puts("Error. Antes debe cargar los datos de los pasajeros.");
            	}
            	break;
            case 5:
            	if(flag!=ERROR)
            	{
            		controller_removePassenger(listaPasajeros);
            	}else
            	{
            		puts("Error. Antes debe cargar los datos de los pasajeros.");
            	}
            	break;
            case 6:
            	if(flag!=ERROR)
            	{
            		controller_ListPassenger(listaPasajeros);
            	}else
            	{
            		puts("Error. Antes debe cargar los datos de los pasajeros.");
            	}
            	break;
            case 7:
            	if(flag!=ERROR)
            	{
            		controller_sortPassenger(listaPasajeros);
            	}else
            	{
            		puts("Error. Antes debe cargar los datos de los pasajeros.");
            	}
            	break;
            case 8:
            	if(flag!=ERROR)
            	{
            		controller_saveAsText("data.csv", listaPasajeros);
            	}else
            	{
            		puts("Error. Antes debe cargar los datos de los pasajeros.");
            	}
            	break;
            case 9:
            	if(flag!=ERROR)
            	{
            		controller_saveAsBinary("data.bin", listaPasajeros);
            	}else
            	{
            		puts("Error. Antes debe cargar los datos de los pasajeros.");
            	}
            	break;
        }
    }while(option != 10);
    return 0;
}

