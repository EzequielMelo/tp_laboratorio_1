#include "arrayType.h"

void printTypePassenger(TypePassenger list)
{
	printf("|%2d     |%13s   |\n",list.idTypePassenger, list.typePassenger);
	puts("|_______|________________|");
}

void printTypePassengers(TypePassenger list[], int len)
{
	int i;

	if(list!=NULL && len>0)
	{
		puts("_________________________");
		puts("| ID:   |     Asiento:   |");
		puts("|_______|________________|");
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty==TAKEN)
			{
				printTypePassenger(list[i]);
			}
		}
	}
}
