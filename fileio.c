/**************************************************
    fileio.c
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

typedef struct
{
    char name[128];
    char email[128];
    char password[128];
    char lastOrderDate[128];
	char country[128];
    char address[128];
} ECOMMERCE_T; 

char stringInput[128];
ECOMMERCE_T customer[10000000];


int maxline()
{
	int readcount = 0;
	FILE *pInFile = NULL;
	
	pInFile = fopen("Database.txt", "r");

	if (pInFile == NULL)
    {
		printf("Cannot open file Database.txt");
    } 
	
	while(fgets(stringInput, sizeof(stringInput), pInFile) != NULL)
	{
		readcount++;
	}
	
	fclose(pInFile);
	
	return readcount/6;
}

void readFile()
{
	FILE *pInFile = NULL;
	int count = 0;
	int namecount = 0;
	int emailcount = 0;
	int passwordcount = 0;
	int lastOrderDatecount = 0;
	int countrycount = 0;
	int addresscount = 0;
	
	pInFile = fopen("Database.txt", "r");

	if (pInFile == NULL)
    {
		printf("Cannot open file Database.txt");
		exit(0);
    } 
	
	while(fgets(stringInput, sizeof(stringInput), pInFile) != NULL)
	{
		if(count % 6 == 0)
		{
			sscanf(stringInput,"%[^\n]",customer[namecount].name);
			namecount++;
		}
		else if(count % 6 == 1)
		{
			sscanf(stringInput,"%[^\n]",customer[emailcount].email);
			emailcount++;
		} 
		else if(count % 6 == 2)
		{
			sscanf(stringInput,"%[^\n]",customer[passwordcount].password);
			passwordcount++;
		}
		else if(count % 6 == 3)
		{
			sscanf(stringInput,"%[^\n]",customer[lastOrderDatecount].lastOrderDate);
			lastOrderDatecount++;
		}
		else if(count % 6 == 4)
		{
			sscanf(stringInput,"%[^\n]",customer[countrycount].country);
			countrycount++;
		}
		else if(count % 6 == 5)
		{
			sscanf(stringInput,"%[^\n]",customer[addresscount].address);
			addresscount++;
		}
		
		count++;
	}
	
	fclose(pInFile);
}

void display()
{	
	int max = maxline();
	readFile();
	
	printf("========================================\n");
	
	for(int i = 0; i<max; i++)
	{
		printf("Data #%d\n", i+1);
		printf("Name: %s\n",customer[i].name);
		printf("Email: %s\n",customer[i].email);
		printf("Password: %s\n",customer[i].password);
		printf("Last Order Date: %s\n",customer[i].lastOrderDate);
		printf("Country: %s\n",customer[i].country);
		printf("Address: %s\n",customer[i].address);
		printf("========================================\n");
	}
}

void search()
{
	int emailName;
	char searchemail[64];
	char searchname[64];
	int max = maxline();
	char edityn = 'a';
	int emailsearched = FALSE;
	int namesearched = FALSE;
	
	readFile();
	
	while(-1)
	{
		printf("****************************************\n");
		printf("      What you want to search\n\n");
		printf("      \t1 - Email\n");
		printf("      \t2 - Name\n");
		printf("      \t3 - Exit\n\n");
		printf("****************************************\n");
		fgets(stringInput,sizeof(stringInput),stdin);
		sscanf(stringInput,"%d",&emailName);
		
		if(emailName == 1)
		{
			printf("****************************************\n");
			printf("Please Input email you want to search: ");
			fgets(stringInput,sizeof(stringInput),stdin);
			sscanf(stringInput,"%s",searchemail);
			printf("========================================\n");
			
			for(int i = 0;i < max;i++)
			{
				if(strncmp(searchemail,customer[i].email,strlen(searchemail)) == 0)
				{
					emailsearched = TRUE;
					
					printf("Data #%d\n", i+1);
					printf("Name: %s\n",customer[i].name);
					printf("Email: %s\n",customer[i].email);
					printf("Password: %s\n",customer[i].password);
					printf("Last Order Date: %s\n",customer[i].lastOrderDate);
					printf("Country: %s\n",customer[i].country);
					printf("Address: %s\n",customer[i].address);
					printf("========================================\n");
				}
			}
			
			if (emailsearched == TRUE)
			{
				while(-1)
				{
					printf("Do you want to edit(y/n)? ");
					fgets(stringInput,sizeof(stringInput),stdin);
					sscanf(stringInput,"%c",&edityn);
					
					if(edityn == 'Y' || edityn == 'y')
					{
						edit();
						break;
					}
					else if(edityn == 'N' || edityn == 'n')
					{
						break;
					}
				}
			}
			else
			{
				printf("No email found\n");
				break;
			}			
		}
		else if(emailName == 2)
		{
			printf("****************************************\n");
			printf("Please Input name you want to search: ");
			fgets(stringInput,sizeof(stringInput),stdin);
			sscanf(stringInput,"%s",searchname);
			printf("========================================\n");
			
			for(int i = 0;i < max;i++)
			{
				if(strncmp(searchname,customer[i].name,strlen(searchname)) == 0)
				{
					namesearched = TRUE;
					
					printf("Data #%d\n", i+1);
					printf("Name: %s\n",customer[i].name);
					printf("Email: %s\n",customer[i].email);
					printf("Password: %s\n",customer[i].password);
					printf("Last Order Date: %s\n",customer[i].lastOrderDate);
					printf("Country: %s\n",customer[i].country);
					printf("Address: %s\n",customer[i].address);
					printf("========================================\n");
				}
			}
			
			if (namesearched == TRUE)
			{
				while(-1)
				{
					printf("Do you want to edit(y/n)? ");
					fgets(stringInput,sizeof(stringInput),stdin);
					sscanf(stringInput,"%c",&edityn);
					
					if(edityn == 'Y' || edityn == 'y')
					{
						edit();
						break;
					}
					else if(edityn == 'N' || edityn == 'n')
					{
						break;
					}
				}
			}
			else
			{
				printf("No name found\n");
				break;
			}	
		}
		else if(emailName == 3)
		{
			break;
		}
	}
}


void addrec()
{
	FILE *pOutFile = NULL;
	char outFileName[128];
	int i = maxline()+1;
	int max = maxline()+1;
	int emailexist = FALSE;
	
	pOutFile = fopen("Database.txt", "a");
	
	printf("****************************************\n");
	
	while(-1)
	{
		printf("Enter Name:");
		fgets(stringInput,sizeof(stringInput), stdin);
		sscanf(stringInput,"%[^\n]",customer[i].name);
		
		if(nameInput(customer[i].name) == 1)
		{
			break;
		}
	}
	
	while(-1)
	{
		printf("Enter email:");
		fgets(stringInput,sizeof(stringInput), stdin);
		sscanf(stringInput,"%[^\n]",customer[i].email);
	
		if(emailInput(customer[i].email) == 1)
		{
			for(int j = 0; j<max;j++)
			{
				if(strcmp(customer[j].email,customer[i].email) == 0)
				{
					emailexist = TRUE;
				}
			}
			
			if(emailexist == FALSE)
			{
				break;
			}
			else
			{
				printf("Email already exist\n");
				emailexist = FALSE;
			}
		}
	}
	
	while(-1)
	{
		printf("Enter password:");
		fgets(stringInput,sizeof(stringInput), stdin);
		sscanf(stringInput,"%[^\n]",customer[i].password);
	
		if(passwordInput(customer[i].password) == 1)
		{
			break;
		}
	}
	
	while(-1)
	{
		printf("Enter Last Order Date:");
		fgets(stringInput,sizeof(stringInput), stdin);
		sscanf(stringInput,"%[^\n]",customer[i].lastOrderDate);
	
		if(dateInput(customer[i].lastOrderDate) == 1)
		{
			if(checkfuture(customer[i].lastOrderDate))
			{
				break;
			}
		}
	}
	
	while(-1)
	{
		printf("Enter Country Code:");
		fgets(stringInput,sizeof(stringInput), stdin);
		sscanf(stringInput,"%[^\n]",customer[i].country);
	
		if(countryCodeInput(customer[i].country) == 1)
		{
			break;
		}
	}
	
	while(-1)
	{
		printf("Enter Address:");
		fgets(stringInput,sizeof(stringInput), stdin);
		sscanf(stringInput,"%[^\n]",customer[i].address);
		
		if(addressInput(customer[i].address) == 1)
		{
			break;
		}
		
	}
	
	fprintf(pOutFile, "%s\n", customer[i].name);
	fprintf(pOutFile, "%s\n", customer[i].email);
	fprintf(pOutFile, "%s\n", customer[i].password);
	fprintf(pOutFile, "%s\n", customer[i].lastOrderDate);
	fprintf(pOutFile, "%s\n", customer[i].country);
	fprintf(pOutFile, "%s\n", customer[i].address);
	
	printf("\nDONE\n");
	
	fclose(pOutFile);
}

void edit()
{
	int datasearch = -1;
	int editwhat = -1;
	int max = maxline();
	FILE *pOutFile = NULL;
	int emailexist = FALSE;
	
	pOutFile = fopen("Database.txt", "w");
	
	readFile();
	
	while(-1)
	{
		printf("Enter which data you want to edit:");
		fgets(stringInput,sizeof(stringInput), stdin);
		sscanf(stringInput,"%d",&datasearch);
		
		if(datasearch > max || datasearch < 1)
		{
			printf("No data exist\n");
		}
		else
		{
			break;
		}
	}
	
	while(-1)
	{
		printf("****************************************\n");
		printf("      What you want to edit\n\n");
		printf("      \t1 - Name\n");
		printf("      \t2 - Email\n");
		printf("      \t3 - Password\n");
		printf("      \t4 - Last Order Date\n");
		printf("      \t5 - Country Code\n");
		printf("      \t6 - Address\n");
		printf("      \t7 - All\n");
		printf("      \t8 - Done\n");
		printf("****************************************\n");
		fgets(stringInput,sizeof(stringInput), stdin);
		sscanf(stringInput,"%d",&editwhat);
		
		if(editwhat == 1)
		{
			while(-1)
			{
				printf("Enter new Name:");
				fgets(stringInput,sizeof(stringInput), stdin);
				sscanf(stringInput,"%[^\n]",customer[datasearch-1].name);
				
				if(nameInput(customer[datasearch-1].name) == 1)
				{
					break;
				}
			}
		}
		else if(editwhat == 2)
		{
			while(-1)
			{
				printf("Enter new email:");
				fgets(stringInput,sizeof(stringInput), stdin);
				sscanf(stringInput,"%[^\n]",customer[datasearch-1].email);
			
				if(emailInput(customer[datasearch-1].email) == 1)
				{
					break;
				}
			}			
		}
		else if(editwhat == 3)
		{
			while(-1)
			{
				printf("Enter new password:");
				fgets(stringInput,sizeof(stringInput), stdin);
				sscanf(stringInput,"%[^\n]",customer[datasearch-1].password);
			
				if(passwordInput(customer[datasearch-1].password) == 1)
				{
					break;
				}
			}			
		}
		else if(editwhat == 4)
		{
			while(-1)
			{
				printf("Enter new Last Order Date:");
				fgets(stringInput,sizeof(stringInput), stdin);
				sscanf(stringInput,"%[^\n]",customer[datasearch-1].lastOrderDate);
			
				if(dateInput(customer[datasearch-1].lastOrderDate) == 1)
				{
					if(checkfuture(customer[datasearch-1].lastOrderDate))
					{
						break;
					}
				}
			}
		}
		else if(editwhat == 5)
		{
			while(-1)
			{
				printf("Enter new Country Code:");
				fgets(stringInput,sizeof(stringInput), stdin);
				sscanf(stringInput,"%[^\n]",customer[datasearch-1].country);
			
				if(countryCodeInput(customer[datasearch-1].country) == 1)
				{
					break;
				}
			}
		}
		else if(editwhat == 6)
		{
			while(-1)
			{
				printf("Enter new Address:");
				fgets(stringInput,sizeof(stringInput), stdin);
				sscanf(stringInput,"%[^\n]",customer[datasearch-1].address);
				
				if(addressInput(customer[datasearch-1].address) == 1)
				{
					break;
				}
				
			}
		}
		else if(editwhat == 7)
		{
			while(-1)
			{
				printf("Enter Name:");
				fgets(stringInput,sizeof(stringInput), stdin);
				sscanf(stringInput,"%[^\n]",customer[datasearch-1].name);
				
				if(nameInput(customer[datasearch-1].name) == 1)
				{
					break;
				}
			}
			
			while(-1)
			{
				printf("Enter email:");
				fgets(stringInput,sizeof(stringInput), stdin);
				sscanf(stringInput,"%[^\n]",customer[datasearch-1].email);
			
				if(emailInput(customer[datasearch-1].email) == 1)
				{
					break;
				}
			}
			
			while(-1)
			{
				printf("Enter password:");
				fgets(stringInput,sizeof(stringInput), stdin);
				sscanf(stringInput,"%[^\n]",customer[datasearch-1].password);
			
				if(passwordInput(customer[datasearch-1].password) == 1)
				{
					break;
				}
			}
			
			while(-1)
			{
				printf("Enter Last Order Date:");
				fgets(stringInput,sizeof(stringInput), stdin);
				sscanf(stringInput,"%[^\n]",customer[datasearch-1].lastOrderDate);
			
				if(dateInput(customer[datasearch-1].lastOrderDate) == 1)
				{
					if(checkfuture(customer[datasearch-1].lastOrderDate))
					{
						break;
					}
				}
			}
			
			while(-1)
			{
				printf("Enter Country Code:");
				fgets(stringInput,sizeof(stringInput), stdin);
				sscanf(stringInput,"%[^\n]",customer[datasearch-1].country);
			
				if(countryCodeInput(customer[datasearch-1].country) == 1)
				{
					break;
				}
			}
			
			while(-1)
			{
				printf("Enter Address:");
				fgets(stringInput,sizeof(stringInput), stdin);
				sscanf(stringInput,"%[^\n]",customer[datasearch-1].address);
				
				if(addressInput(customer[datasearch-1].address) == 1)
				{
					break;
				}
				
			}
		}
		else if(editwhat == 8)
		{
			break;
		}
	}
	
	for(int i = 0; i<max; i++)
	{
		fprintf(pOutFile, "%s\n", customer[i].name);
		fprintf(pOutFile, "%s\n", customer[i].email);
		fprintf(pOutFile, "%s\n", customer[i].password);
		fprintf(pOutFile, "%s\n", customer[i].lastOrderDate);
		fprintf(pOutFile, "%s\n", customer[i].country);
		fprintf(pOutFile, "%s\n", customer[i].address);
	}
	
	fclose(pOutFile);
}