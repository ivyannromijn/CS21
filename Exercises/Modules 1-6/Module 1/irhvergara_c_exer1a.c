// Vergara, Ivyann Romijn H. 
// CMSC 21 - ST-2L

#include <stdio.h>

int main()
{
    int input, total = 0, increment, new, remainder, counter = 1;
    char *day, *month; 

    printf("Enter a number (1-12): ");
    scanf("%d", &input);
    
    if(input <= 12 && input > 0){   //if statement to ensure that the input is from 1-12
    while (counter <= input)
    {
        switch(counter) //the switch case is based on the number of days in the given month
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
        
        total += increment;   //the value of increment is put into total
        counter++;
    }

    total -= increment; //total- latest increment value
    remainder = (total+5)%7; //basis for the day, 1 as remainder is for monday


    //corresponding month as input
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

    //corresponding day 
    if(remainder == 5) day = "Friday";
    else if(remainder == 6) day = "Saturday";
    else if(remainder == 0) day = "Sunday";
    else if(remainder == 1) day = "Monday";
    else if(remainder == 2) day = "Tuesday";
    else if(remainder == 3) day = "Wednesday";
    else if(remainder == 4) day = "Thursday";

    printf("1 %s 2021 is a %s.\n", month, day); //prints the first day of the month and its day
    }else printf("Invalid input\n");            //else statement if the input is less than 1 and greater thsn 12
    return 0;
}