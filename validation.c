/**************************************************
    validaiton.c
    Chanon Khanijoh
    63070503408
***************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "validation.h"
#include "fileio.h"

#define TRUE 1//TRUE will always equal to 1
#define FALSE 0// FALSE will always equal to 0

/* Sets the pointer for day, month and year 
 * to the correct values for today. */
 
void dateToday(int* pDay, int *pMonth, int* pYear)
{
    time_t seconds = 0;    
    struct tm * pTimeStruct;

    seconds = time(&seconds);
    pTimeStruct = localtime(&seconds);
    *pDay = pTimeStruct->tm_mday;
    *pMonth = pTimeStruct->tm_mon + 1;
    *pYear = pTimeStruct->tm_year + 1900;
}


/* Compares two dates. Returns 1 if the 
 * first date is later than the second, -1 if the 
 * first date is earlier than the second, and 0 if
 * they are the same.
 * Arguments: day1   - day of first date
 *            month1 - month of first date
 *            year1  - year of first date
 *            day2   - day of second date
 *            month2 - month of second date
 *            year2  - year of second date
 */
int dateCompare(int day1,int month1,int year1, 
                int day2,int month2,int year2)
{
    int compareValue = 0;
    if (year1 > year2)
       {
       compareValue = 1;
       }
    else if (year1 < year2)
       {
       compareValue = -1;
       } 
    else if (month1 > month2)
       {
       compareValue = 1;
       }
    else if (month1 < month2)
       {
       compareValue = -1;
       } 
    else if (day1 > day2)
       {
       compareValue = 1;
       }
    else if (day1 < day2)
       {
       compareValue = -1;
       } 
    /* otherwise they are the same */

    return compareValue;
}    

int checkfuture(char date_input[])
{
	int result = 0;
	int daynow;
	int monthnow;
	int yearnow;
	int day2;
	int month2;
	int year2;
	int datecmp;
	char month[4];
	
	dateToday(&daynow,&monthnow,&yearnow);//get today date
	
	sscanf(date_input,"%d %s %d",&day2,month,&year2);
	
	if(strcmp(month,"JAN") == 0)
	{
		month2 = 1;
	}
	else if(strcmp(month,"FEB") == 0)
	{
		month2 = 2;
	}
	else if(strcmp(month,"MAR") == 0)
	{
		month2 = 3;
	}
	else if(strcmp(month,"APR") == 0)
	{
		month2 = 4;
	}
	else if(strcmp(month,"MAY") == 0)
	{
		month2 = 5;
	}
	else if(strcmp(month,"JUN") == 0)
	{
		month2 = 6;
	}
	else if(strcmp(month,"JUL") == 0)
	{
		month2 = 7;
	}
	else if(strcmp(month,"AUG") == 0)
	{
		month2 = 8;
	}
	else if(strcmp(month,"SEP") == 0)
	{
		month2 = 9;
	}
	else if(strcmp(month,"OCT") == 0)
	{
		month2 = 10;
	}
	else if(strcmp(month,"NOV") == 0)
	{
		month2 = 11;
	}
	else if(strcmp(month,"DEC") == 0)
	{
		month2 = 12;
	}
	
	datecmp = dateCompare( day2, month2, year2, daynow, monthnow, yearnow);//comparing the date
	
	if(datecmp == -1)//if date is before today date
	{
		result = 1;
	}
	else if(datecmp == 1)//if date is after today date
	{
		printf("Date is in the futre\n");
	}
	else if(datecmp == 0)//if date is today date
	{
		result = 1;
	}
	
	return result;
}

int dateInput(char date_input[])
{
	char stringInput[128];
	int dateval = FALSE;
	int result = 0;
	char datestring[3];
	char monthstring[4];
	char yearstring[5];
	int idate;
	int iyear;
	
	if(strlen(date_input) == 11)
	{
		if(isdigit(date_input[0]) && isdigit(date_input[1]))
		{	
			datestring[0]=date_input[0];
			datestring[1]=date_input[1];
			datestring[2]=0;
			yearstring[0]=date_input[7];
			yearstring[1]=date_input[8];
			yearstring[2]=date_input[9];
			yearstring[3]=date_input[10];
			yearstring[4]=0;

			iyear=atoi(yearstring);
			idate=atoi(datestring);
			
			if(date_input[2] == 32 && date_input[6] == 32)
			{
				monthstring[0]=date_input[3];
				monthstring[1]=date_input[4];
				monthstring[2]=date_input[5];
				monthstring[3]=0;
				
				if(strcmp(monthstring,"JAN") == 0 || strcmp(monthstring,"FEB") == 0 || strcmp(monthstring,"MAR") == 0 || strcmp(monthstring,"APR") == 0 
				   || strcmp(monthstring,"MAY") == 0 || strcmp(monthstring,"JUN") == 0 || strcmp(monthstring,"JUL") == 0 || strcmp(monthstring,"AUG") == 0 
				   || strcmp(monthstring,"SEP") == 0 || strcmp(monthstring,"OCT") == 0 || strcmp(monthstring,"NOV") == 0 || strcmp(monthstring,"DEC") == 0)
				{
					if(isdigit(date_input[7]) && isdigit(date_input[8]) && isdigit(date_input[9]) && isdigit(date_input[10]))
					{
						if(iyear >= 1920)
						{			
							if(iyear%4 == 0 && strcmp(monthstring,"FEB") == 0 )
							{
								if(idate >=1 && idate <=29)
								{
									dateval = TRUE;
									result = 1;
								}
								else
								{
									printf("There are only 29 days in FEB this year\n");
								}
							}
							else if(strcmp(monthstring,"JAN") == 0 || strcmp(monthstring,"MAR") == 0 || strcmp(monthstring,"MAY") == 0 || strcmp(monthstring,"JUL") == 0 
									|| strcmp(monthstring,"AUG") == 0 || strcmp(monthstring,"OCT") == 0 || strcmp(monthstring,"DEC") == 0)
							{
								if(idate >=1 && idate <=31)
								{
									dateval = TRUE;
									result = 1;
								}
								else
								{
									printf("There are only 31 days in the month you entered\n");
								}
							}
							else if(strcmp(monthstring,"APR") == 0 || strcmp(monthstring,"JUN") == 0 
									|| strcmp(monthstring,"SEP") == 0 || strcmp(monthstring,"NOV") == 0)
							{
								if(idate >=1 && idate <=30)
								{
									dateval = TRUE;
									result = 1;
								}
								else
								{
									printf("There are only 30 days in the month you entered\n");
								}
							}
							else if(strcmp(monthstring,"FEB") == 0)
							{
								if(idate >=1 && idate <=28)
								{
									dateval = TRUE;
									result = 1;
								}
								else
								{
									printf("There are only 28 days in FEB this year\n");
								}
							}
						}
						else
						{
							printf("Year should be 100 years before today year\\\n");
						}
					}
					else
					{
						printf("Year should be 4 digits number\n");
					}
				}
				else
				{
					printf("Incorrect Month input(MMM only)\n");
				}
			}
			else
			{
				printf("Space in between DD and MMM and YYYY\n");
			}
		}
		else
		{
			printf("Date should be 2 digits\n");
		}
	}
	else
	{
		printf("Should be in DD MMM YYYY format\n");
	}

	return result;
}

int emailInput(char email_input[])
{
	char stringInput[128];
	int atNum = 0;
	char emailFront[128];
	char emailBack[128];
	int atlocation;
	int punctVal = TRUE;
	int frontAlpha = FALSE;
	int alphanumtld = FALSE;
	int noUScore = TRUE;
	int tldval = FALSE;
	int emailval  = FALSE;
	int dotNoStick = TRUE;
	int result = 0;
	
	for(int i = 0; i < strlen(email_input); i++)
	{
		if(ispunct(email_input[i]) && email_input[i] != '@' && email_input[i] != '_' && email_input[i] != '-' && email_input[i] != '.')
		{
			punctVal = FALSE;
		}
		
	}
	
	if(isalnum(email_input[0]))
	{
		frontAlpha = TRUE;
	}
	
	for(int i = 0; i < strlen(email_input); i++)
	{
		if(email_input[i] == '@')
		{
			atNum++;
			atlocation = i;
		}
	}
	
	if(punctVal == TRUE )
	{
		if(atNum != 1)
		{
			printf("Only 1 @ allowed\n");
		}
		else
		{
			if(frontAlpha == TRUE)
			{
				if(isalnum(email_input[atlocation-1]) && isalnum(email_input[atlocation+1]))
				{
					email_input[atlocation] = 32;
					
					sscanf(email_input, "%s %s", emailFront, emailBack);
					
					
					for(int i = 0; i < strlen(emailBack); i++)
					{
						if(emailBack[i] == '_')
						{
							noUScore = FALSE;
						}
					}
					
					for(int i = 0; i < strlen(emailBack); i++)
					{
						if(emailBack[i] == '.' && emailBack[i+1] == '.')
						{
							dotNoStick = FALSE;
						}
					}
					
					int i = strlen(emailBack);
					
					if(emailBack[i-1] == 'm' && emailBack[i-2] == 'o' && emailBack[i-3] == 'c' && emailBack[i-4] == '.')
					{
						tldval = TRUE;
					}
					else if(emailBack[i-1] == 't' && emailBack[i-2] == 'e' && emailBack[i-3] == 'n' && emailBack[i-4] == '.')
					{
						tldval = TRUE;
					}
					else if(emailBack[i-1] == 'h' && emailBack[i-2] == 't' && emailBack[i-3] == '.' && emailBack[i-4] == 'c' && emailBack[i-5] == 'a' && emailBack[i-6] == '.')
					{
						tldval = TRUE;
					}
					else if(emailBack[i-1] == 'h' && emailBack[i-2] == 't' && emailBack[i-3] == '.' && emailBack[i-4] == 'o' && emailBack[i-5] == 'c' && emailBack[i-6] == '.')
					{
						tldval = TRUE;
					}
					
					if(tldval == TRUE)
					{
						if(isalnum(emailBack[strlen(emailBack-4)]) || isalnum(emailBack[strlen(emailBack-6)]))
						{
							alphanumtld = TRUE;
							
							if(noUScore == FALSE)
							{
								printf("There cannot be '_' after '@'\n");
							}
							else if( dotNoStick == FALSE)
							{
								printf("Cannot have '.' next to each other\n");
							}
							else if(noUScore == TRUE && tldval == TRUE && frontAlpha == TRUE && punctVal == TRUE && atNum  == 1 && alphanumtld == TRUE && dotNoStick == TRUE)
							{
								email_input[atlocation] = '@';
								emailval = TRUE;
								result = 1;
							}
						}
						else 
						{
							printf("Should have alphabet or number before TLD \n");
						}
					}
					else
					{
						printf("Should end with '.com', '.net', '.ac.th' or '.co.th' only\n");
					}
				}
				else
				{
					printf("Should have alphabet or number before and after '@' \n");
				}
			}
			else
			{
				printf("Should start with alphanumeric\n");
			}
		}
	}
	else
	{
		printf("Only '@', '-', '_', '.' special character allowed\n");
	}
	return result;
}

int passwordInput(char pass_input[])
{
	int countdigit = 0;
	int valupper = FALSE;
	int vallower = FALSE;
	int valalpha = FALSE;
	int valdigit = FALSE;
	int valspace = TRUE;
	int valnospc = TRUE;
	int passval = FALSE;
	char stringInput[128];
	int result = 0;
	
	if(strlen(pass_input) >= 8 && strlen(pass_input) <= 12)
	{
		for(int i = 0; i < strlen(pass_input); i++)
		{
			if(isupper(pass_input[i]))
			{
				valupper = TRUE;
			}
			
			if(islower(pass_input[i]))
			{
				vallower = TRUE;
			}
			
			if(pass_input[i] == '?' || pass_input[i] == '@' || pass_input[i] == '%' || pass_input[i] == '$' || pass_input[i] == '#' )
			{
				valalpha = TRUE;
			}
			
			if(isdigit(pass_input[i]))
			{
				countdigit++;
			}
			
			if(pass_input[i] == 32)
			{
				valspace = FALSE;
			}
			
			if(pass_input[i] == '~' || pass_input[i] == '`' || pass_input[i] == '!' || pass_input[i] == '^' || pass_input[i] == '&' || pass_input[i] == '*' 
			   || pass_input[i] == '(' || pass_input[i] == ')' || pass_input[i] == '-' || pass_input[i] == '_' || pass_input[i] == '+' || pass_input[i] == '=' 
			   || pass_input[i] == '{' || pass_input[i] == '}' || pass_input[i] == '[' || pass_input[i] == ']' || pass_input[i] == '|' || pass_input[i] == 92 
			   || pass_input[i] == 47 || pass_input[i] == ':' || pass_input[i] == ';' || pass_input[i] == 34 || pass_input[i] == 39 || pass_input[i] == '<' 
			   || pass_input[i] == '>' || pass_input[i] == ',' || pass_input[i] == '.' || pass_input[i] == '?')
			{
				valnospc = FALSE;
			}
		}
		
		if(countdigit >= 2)
		{
			valdigit = TRUE;
		}
		else
		{
			printf("Password should countain at least 2 digits\n");
		}
		
		if(valalpha == TRUE && valupper == TRUE && vallower == TRUE && valdigit == TRUE && valspace == TRUE && valnospc == TRUE)
		{
			passval = TRUE;
			result = 1;
		}
	}
	else
	{
		printf("Password should be between 8 to 12 character long\n");
	}
	
	
	if(strlen(pass_input) == 8 || strlen(pass_input) == 9 || strlen(pass_input) == 10 || strlen(pass_input) == 11 || strlen(pass_input) == 12)
	{
		if(valupper == FALSE)
		{
			printf("No uppercase entered\n");
		}
		
		if(vallower == FALSE)
		{
			printf("No lowercase entered\n");
		}
		
		if(valalpha == FALSE)
		{
			printf("No special character entered\n");
		}
		
		if(valspace == FALSE)
		{
			printf("No space allowed\n");
		}
		
		if(valnospc == FALSE)
		{
			printf("Invalid special character entered\n");
		}
	}
	
	valupper = FALSE;
	vallower = FALSE;
	valalpha = FALSE;
	valdigit = FALSE;
	valspace = TRUE;
	valnospc = TRUE;

	return result;
}

int countryCodeInput(char country_input[])
{
	char stringInput[128];
	int countryval = FALSE;
	int result = 0;
	char countryCode[300][2] = {"AD", "AE", "AF", "AG", "AI", "AL", "AM", "AO", "AQ", "AR", "AS", "AT", "AU", "Aw", "AX", "AZ", "BA", "BB", "BD", "BE", "BF", 
							 "BG", "BH", "BI", "BJ", "BL", "BM", "BN", "BO", "BQ", "BR", "BS", "BT", "BV", "BW", "BY", "BZ", "CA", "CC", "CD", "CF", "CG", 
							 "CH", "CI", "CK", "CL", "CM", "CN", "CO", "CR", "CU", "CV", "CW", "CX", "CY", "CZ", "DE", "DJ", "DK", "DM", "DO", "DZ", "EC", 
							 "EE", "EG", "EH", "ER", "ES", "ET", "FI", "FJ", "FK", "FM", "FO", "FR", "GA", "GB", "GD", "GE", "GF", "GG", "GH", "GI", "GL", 
							 "GM", "GN", "GP", "GQ", "GR", "GS", "GT", "GU", "GW", "GY", "HK", "HM", "HN", "HR", "HT", "HU", "ID", "IE", "IL", "IM", "IN", 
							 "IO", "IQ", "IR", "IS", "IT", "JE", "JM", "JO", "JP", "KE", "KG", "KH", "KI", "KM", "KN", "KP", "KR", "KW", "LA", "LB", "LC", 
							 "LI", "LK", "LR", "LS", "LT", "LU", "LV", "LY", "MA", "MC", "MD", "ME", "MF", "MG", "MH", "MK", "ML", "MM", "MN", "MO", "MP", 
							 "MQ", "MR", "MS", "MT", "MU", "MV", "MW", "MX", "MY", "MZ", "NA", "NC", "NE", "NF", "NG", "NI", "NL", "NO", "NP", "NR", "NU", 
							 "NZ", "OM", "PA", "PE", "PF", "PG", "PH", "PK", "PL", "PM", "PN", "PR", "PS", "PT", "PW", "PY", "QA", "RE", "RO", "RS", "RU", 
							 "RW", "SA", "SB", "SC", "SD", "SE", "SG", "SH", "SI", "SJ", "SK", "SL", "SM", "SN", "SO", "SR", "SS", "ST", "SV", "SX", "SY", 
							 "SZ", "TC", "TD", "TF", "TG", "TH", "TJ", "TK", "TL", "TM", "TN", "TO", "TR", "TT", "TV", "TW", "TZ", "UA", "UG", "UM", "US", 
							 "UY", "UZ", "VA", "VC", "VE", "VG", "VI", "VN", "VU", "WF", "WS", "YE", "ZA", "ZM", "ZW"};	
	
	for(int i = 0; i<300; i++)
	{
		if(strncmp(country_input,countryCode[i],2) == 0)
		{
			countryval = TRUE;
		}
	}
	
	if(countryval == TRUE)
	{
		result = 1;
	}
	else
	{
		printf("Country code entered is invalid\n");
	}
	
	return result;
}

int addressInput(char address_input[])
{
	int result = 0;
	
	for(int i = 0; i< strlen(address_input);i++)
	{
		if(ispunct(address_input[i]) && address_input[i] != '.')
		{
			result = 0;
			break;
		}
		else
		{
			result =1;
		}
	}
	
	if(result == 0)
	{
		printf("Cannot have special character except '.'\n");
	}
	return result;
}

int nameInput(char name_input[])
{
	int result = 0;
	
	for(int i = 0; i< strlen(name_input);i++)
	{
		if(ispunct(name_input[i]))
		{
			result = 0;
			break;
		}
		else
		{
			result =1;
		}
	}
	
	if(result == 0)
	{
		printf("Cannot have special character \n");
	}
	
	return result;
}