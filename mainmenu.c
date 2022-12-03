/**************************************************
    mainmenu.c
    Chanon Khanijoh
    63070503408

***************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "validation.h"
#include "fileio.h"

#define TRUE 1//TRUE will always equal to 1
#define FALSE 0// FALSE will always equal to 0

/*************************************
* gui for mainmenu
*************************************/
int main()
{
	char stringInput[128];
	int mainMenuNumber = 0;
	
	display();
	
	while(-1)
	{
		printf("****************************************\n");
		printf("      E-commerce Customer Database\n\n");
		printf("      \t1 - Display all records\n");
		printf("      \t2 - Add new records records\n");
		printf("      \t3 - Search and Edit records\n");
		printf("      \t4 - Exit Program\n\n");
		printf("****************************************\n");
		printf("What do you want to do:");
		fgets(stringInput,sizeof(stringInput),stdin);
		sscanf(stringInput, "%d", &mainMenuNumber);//input to select validation type
		
		if(mainMenuNumber == 1)
		{
			display();
		}
		else if(mainMenuNumber == 2)
		{
			addrec();
		}
		else if(mainMenuNumber == 3)
		{
			search();
		}
		else if(mainMenuNumber == 4)
		{
			exit(0);
		}
		
		mainMenuNumber = 0;
	}
}
