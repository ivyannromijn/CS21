//Vergara, Ivyann Romijn H.
//CMSC 21ST2L- Exer 2 Indiv



#include <stdio.h>

 //recursive function to check if prime
int Prime_checker(int i, int x){                           
    if (i == 1) return 0; else                              //1 is not a prime number
    if (i == x) return 1; else                              
    if (i%x == 0) return 0; else                            // the modulo operator was used to identify if a number is prime 
    return Prime_checker(i, x+1);                           //x+! ensures that every integer until the input-1 is checked that 
                                                            //will be used in the modulo
}


//main function
int main(){
    int n, i;
    printf("Enter a positive number: ");
    scanf("%d", &n);

//when the input is greater than 2
    if (n>2)
    {
    printf("The prime numbers from 1 to %d are : ",n );
    for(i=1; i <= n; i++)                                   //checks integers from 1 to n
        if(Prime_checker(i,2) == 1)
        {
            printf("%d ", i);                   //prints the prime numbers of the given range
        } 
    }
    
//when the input is less than 2
    if (n<2)
    {printf("No prime number values present.");}
    return 0; 
} 