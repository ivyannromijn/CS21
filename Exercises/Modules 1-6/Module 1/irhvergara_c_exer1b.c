// Vergara, Ivyann Romijn H. 
// CMSC 21 - ST-2L


#include <stdio.h>

int main()
{
    int input, total = 0, increment, new, remainder, counter = 1, day;
    char *daycode, *month; 

    printf("Enter a number (1-12): ");
    scanf("%d", &input);
    printf("\n");
    
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


    //Respective months
    if(input == 1) month = "JANUARY";
    else if(input == 2) month = "FEBRUARY";
    else if(input == 3) month = "MARCH";
    else if(input == 4) month = "APRIL";
    else if(input == 5) month = "MAY";
    else if(input == 6) month = "JUNE";
    else if(input == 7) month = "JULY";
    else if(input == 8) month = "AUGUST";
    else if(input == 9) month = "SEPTEMBER";
    else if(input == 10) month = "OCTOBER";
    else if(input == 11) month = "NOVEMBER";
    else if(input == 12) month = "DECEMBER";

    //heading of the calendar
    printf("\t %s 2021", month);
    printf("\n______________________________________");
	printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );
	
    total -= increment;
    remainder = (total+5)%7;	
	
        //prints the first date of the month on its correct corresponding day
	for ( day = 1; day <= 1 + remainder * 5; day++ )
		{
			printf(" ");
		}
		
		//prints all the dates from first day to the last day of the point (Numbers 1-total days of the month)
	    for ( day = 1; day <= increment; day++ ) { printf("%2d", day ); 

        //new line for days beyond saturday, this part of the code is responsible for the rows
        if ( ( day + remainder ) % 7 > 0 )

				printf("   " );
			else
				printf("\n " );
		}
		
    }else printf("Invalid input\n Run the program again..."); 	//if user input is greater than 12 and less than 1

    return 0;
}