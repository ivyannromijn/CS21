/*VERGARA, Romijn
C_EXER_5-1
*/

//params01_exer1.c Passing integer as parameter


#include<stdio.h>

void input(int *i){ //using pointers as a parameter (pass by reference)
	
	printf("Enter an integer: ");
	scanf("%i",i); //this store your integer input to the variable i in the main function, i variable value changes. We don't need to put &i, since it is already a pointer.
}


void output(int i){	//using the integer i as the parameter (pass by value)

	printf("i==%i\n",i); //this prints the value of i variable
}

int main(){
	int i=123; 

	input(&i); 
	
	output(i); 
}

/*

The integer i was first initialized to =123, but with using pointers and its operations
( & and *), we were able to change the value of i. 


The line 25 passes the address of i variable to the input function.

The output function used the value of i variable for it to be printed.
*/

