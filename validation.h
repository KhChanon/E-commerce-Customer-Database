/**************************************************
    validaiton.h
    Chanon Khanijoh
    63070503408
***************************************************/

#define TRUE 1//TRUE will always equal to 1
#define FALSE 0// FALSE will always equal to 0

/* Sets the pointer for day, month and year 
 * to the correct values for today.
 * Code by: Ajarn Sally
 */
void dateToday(int* pDay, int *pMonth, int* pYear);

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
 * Code by: Ajarn Sally
 */
int dateCompare(int day1,int month1,int year1,int day2,int month2,int year2);

/*Check if the date is in future or not
 *return 0 if not 
 *return 1 if it is
 */
int checkfuture(char date_input[]);

/*Validate date return 1 if valid
 */
int dateInput(char date_input[]);

/*Validate email return 1 if valid
 */
int emailInput(char email_input[]);

/*Validate password return 1 if valid
 */
int passwordInput(char pass_input[]);

/*Validate country code return 1 if valid
 */
int countryCodeInput(char country_input[]);

/*Validate address return 1 if valid
 */
int addressInput(char address_input[]);

/*Validate name return 1 if valid
 */
int nameInput(char name_input[]);