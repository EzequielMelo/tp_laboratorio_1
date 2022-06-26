#include "arrayStatus.h"

void printStatusFlight(StatusFlight list)
{
	printf("|%2d     |%13s   |\n",list.idStatusFlight, list.statusFlight);
	puts("|_______|________________|");
}

void printStatusFlights(StatusFlight list[], int len)
{
	int i;

	if(list!=NULL && len>0)
	{
		puts("_________________________");
		puts("| ID:   |     Status:    |");
		puts("|_______|________________|");
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty==TAKEN)
			{
				printStatusFlight(list[i]);
			}
		}
	}
}
