/*VERGARA, Romijn
C_EXER_5-2a
*/


//params02_exer1.c Passing two integers as parameters

#include<stdio.h>


//user input function
void input(int *a, int *b){ 
	
	printf("Enter two integers (e.g. 21 123): ");
	scanf("%i %i",a,b); //this store your integer input to the variable a and b in the main function, i variable valye changes. We don't need to put &, since it is already a pointer.
}

//printing function
void output(int a, int b){	
	printf("a==%i b==%i\n",a,b); 
}


//main function
int main(){
	int a=21, b=123; //first initialization of variables
	
	input(&a,&b); //pass by reference, we used the address of pointers to be passed on the function

	output(a,b); //pass by value

}
					
/* This exercise is the same as params01 but this time, two variables are used */