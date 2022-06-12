#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_get.h"

int myGets(char* string, int lenght)
{
	int rtn = -1;
	char bufferString[LIMITE_BUFFER];
	if(string != NULL && lenght > 0)
	{
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1]=='\n')
			{
				//bufferString[strcspn(bufferString,"\n\r")]= '\0';
				bufferString[strnlen(bufferString,sizeof(bufferString))-1]= '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= lenght)
			{
				strncpy(string,bufferString,lenght);
				rtn = 0;
			}
		}
	}
	return rtn;
}


int isANumber(char* string, int limit)
{
	int rtn = 1;
	int i;

	for(i=0; i<limit && string[i]!='\0'; i++)
	{
		if(i==0 && (string[i] == '-' || string[i] == '+'))
		{
			continue;
		}
		if(string[i]<'0' || string[i]>'9')
		{
			rtn = 0;
			break;
		}
	}

	return rtn;
}

int isAFloatNumber(char* string, int limit)
{
	int rtn = 1;
	int p = 0;
	int i;

	for(i=0; i<limit && string[i]!= '\0'; i++)
	{
		if(i==0 && (string[i] == '-' || string[i] == '+'))
		{
			continue;
		}
		if(i>0 && (string[i] == '.' || string[i] == ',') && p<1)
		{
			p++;
			continue;
		}
		if(string[i]<'0' || string[i]>'9' )
		{
			rtn = 0;
			break;
		}
	}
	return rtn;
}

int isAChar(char* string, int limit)
{
	int rtn = 1;
	int i;

	for(i=0; i<limit && string[i]!= '\0'; i++)
	{
		if((string[i]<'a' || string[i]>'z') && (string[i]<'A' || string[i]>'Z'))
		{
			rtn = 0;
			break;
		}
	}
	return rtn;
}

int getInt(int* pResult)
{
	int rtn = -1;
	char bufferString[LIMITE_BUFFER];
	if(pResult != NULL && myGets(bufferString,sizeof(bufferString)) == 0 &&
	   isANumber(bufferString,sizeof(bufferString)))
	{
		*pResult = atoi(bufferString);
		rtn = 0;

	}
	return rtn;
}

int getFloat(float* pResult)
{
	int rtn = -1;
	char bufferString[LIMITE_BUFFER];
	if(pResult != NULL && myGets(bufferString,sizeof(bufferString)) == 0 &&
	   isAFloatNumber(bufferString,sizeof(bufferString)))
	{
		*pResult = atof(bufferString);
		rtn = 0;
	}
	return rtn;
}

int getChar(char* pResult)
{
	int rtn = -1;
	char bufferString[LIMITE_BUFFER];
	if(pResult != NULL && myGets(bufferString,sizeof(bufferString)) == 0 &&
	   isAChar(bufferString,sizeof(bufferString)))
	{
		strcpy(pResult, bufferString);
		rtn = 0;
	}
	return rtn;
}


int getIntNumber(int* pResult, char* message, char* errorMessage, int min, int max, int attemps)
{
	int rtn = -1;
	int bufferInt;
	do
	{
		printf("%s", message);
		if(getInt(&bufferInt)==0 &&
			bufferInt>=min && bufferInt<=max)
		{
			*pResult = bufferInt;
			rtn = 0;
			break;
		}
		printf("%s", errorMessage);
		attemps--;
	}while(attemps >= 0);

	return rtn;
}

int getFloatNumber(float* pResult, char* message, char* errorMessage, float min, float max, int attemps)
{
	int rtn = -1;
	float bufferFloat;

	do
	{
		printf("%s", message);
		if(getFloat(&bufferFloat)==0 &&
		   bufferFloat>=min && bufferFloat<=max)
		{
			*pResult = bufferFloat;
			rtn = 0;
			break;
		}
		printf("%s", errorMessage);
		attemps--;
	}while(attemps >= 0);

	return rtn;
}

int getStringChar(char* pResult, char* message, char* errorMessage, int limit, int attemps, int caseToUpper)
{
	int rtn = -1;
	char bufferString[LIMITE_BUFFER];
	int i;

	do
	{
		printf("%s", message);
		if(getChar(bufferString) == 0 &&
		   strlen(bufferString)<=limit)
		{
			switch(caseToUpper)
			{
			case 1:
				bufferString[0] = toupper(bufferString[0]);
				for(i = 1; bufferString[i] != '\0'; i++)
				{
					bufferString[i] = tolower(bufferString[i]);
				}
				strncpy(pResult, bufferString, limit);
				rtn = 0;
			break;
			case 2:
				for(i = 0; bufferString[i] != '\0'; i++)
				{
					bufferString[i] = toupper(bufferString[i]);
				}
				strncpy(pResult, bufferString, limit);
				rtn = 0;
			break;
			case 3:
				for(i = 0; bufferString[i] != '\0'; i++)
				{
					bufferString[i] = tolower(bufferString[i]);
				}
				strncpy(pResult, bufferString, limit);
				rtn = 0;
			break;
			}
			break;
		}
		printf("%s", errorMessage);
		attemps--;
	}while(attemps >= 0);

	return rtn;
}

