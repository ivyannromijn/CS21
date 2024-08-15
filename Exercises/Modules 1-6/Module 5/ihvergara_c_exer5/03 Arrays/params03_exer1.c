/*VERGARA, Romijn
C_EXER_5-3a
*/

//params03_exer1.c

#include<stdio.h>

//user input function
void input(int *a, int n){ // n variable from main function and from an array variable
	int i;  
	//get user inputs for n integers and store it into array a
	for(i=0;i<n;i++) {
		printf("Enter an integer: ");
		scanf("%i",&a[i]);
	}
}

//printing function
void output(int *a, int n){ // n variable from main function and from an array variable
	//display the contents of array a
	int i;

	for(i=0;i<n;i++) {
		printf("a[%i]==%i\n",i,a[i]);
	}	
	
}


int main(){
	int i, n=5; //initializing variables
	int a[n];
	
	
	input(a, n); // pass array variable a as parameter into input function
					
	
	output(a, n);// pass array variable a as parameter into output function
}


/*
it is the same as the sample code however, we used array variables as 
parameters to functions instead of putting it in a single function.

C langyuage uses 0 based indexing.

 */


