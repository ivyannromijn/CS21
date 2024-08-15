
// Vergara, Ivyann Romijn H. 
// CMSC 21 - ST-2L

#include <stdio.h>

// Function Prototypes
int daysOfMonth(int);
void printCalendaOfMonth2021(int, int, char*);
void firstDayOfMonth2021(int, char*, char*);



//main functiom
void main()
{
    int input;
    
    printf("Enter a number (1-12): ");
    scanf("%d", &input);

    if(input <= 12 && input > 0) 
    {
        int total = 0, increment, remainder, counter = 1;
        char *day, *month; 

        while (counter <= input)
        {
            increment = daysOfMonth(counter);
            
            total += increment; 
            counter++;
        }

        total -= increment; 
        remainder = (total+5)%7; 

        if(input == 1) month = "January";
        else if(input == 2) month = "February";
        else if(input == 3) month = "March";
        else if(input == 4) month = "April";
        else if(input == 5) month = "May";
        else if(input == 6) month = "June";
        else if(input == 7) month = "July";
        else if(input == 8) month = "August";
        else if(input == 9) month = "September";
        else if(input == 10) month = "October";
        else if(input == 11) month = "November";
        else if(input == 12) month = "December";

        firstDayOfMonth2021(remainder, month, day); // function for first day of the month
        printf("\n");
        printCalendaOfMonth2021(increment, remainder, month); // function for printing the month calendar
    }

    else printf("Invalid input\n");
    
}

//number of days in a month function (since there are more than 2 possible number of days of month )
int daysOfMonth(int counter) 
{
    int increment;

    switch(counter)
    {
        case(2):
            increment = 28;
            break;
        case(4):
        case(6):
        case(9):
        case(11):
            increment = 30;
            break;
        default:
            increment = 31;
    }

    return increment;
}



//function for exer1a
void firstDayOfMonth2021(int remainder, char *month, char *day)
{
    if(remainder == 5) day = "Friday";
    else if(remainder == 6) day = "Saturday";
    else if(remainder == 0) day = "Sunday";
    else if(remainder == 1) day = "Monday";
    else if(remainder == 2) day = "Tuesday";
    else if(remainder == 3) day = "Wednesday";
    else if(remainder == 4) day = "Thursday";
    printf("\n1 %s 2021 is %s.\n", month, day);
}



//function for exer 1b
void printCalendaOfMonth2021(int increment, int remainder, char *month) 
{
    printf("\t %s 2021", month);
    printf("\n______________________________________");
	printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );
    int i;
    
    for(i = 1; i <= 1+ remainder*5; i++)
    {
        printf(" ");
    }

    for(i = 1; i <= increment; i++)
    
    {
    printf("%2d", i);
    if ( ( i + remainder ) % 7 > 0 )
				printf("   " );
			else
				printf("\n " );
	}
    
}


