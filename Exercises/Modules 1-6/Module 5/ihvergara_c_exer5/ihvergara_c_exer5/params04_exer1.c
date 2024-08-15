/*VERGARA, Romijn
C_EXER_5-4a
*/

//params04_exer1.c

#include<stdio.h>
#include<malloc.h> //for malloc function
#include<stdlib.h> //for exit function


//user input function
void input(int *a , int n){ //gets user input ansf dtores it in an array a from the main function
	int i;
	for(i=0;i<n;i++) {
		printf("Enter an integer: ");
		scanf("%i",&a[i]);
	}	


}

//printing function
void output(int *a, int n){ 
	int i;
	
	for(i=0;i<n;i++) {
	printf("a[%i]==%i\n",i,a[i]); //prints integer that was put in an array a
	}

}

int main(){
	//initalizing variables
	int i, n=5;
	
	
	//dynamic allocation using a pointer "int *a"
	//"int *a" will store the starting address of the contiguously
	//allocated space for  n integers i.e. size n*sizeof(int)
	//making "int *a" a dynamically allocated array of n integers
	int *a = (int *)malloc(n*sizeof(int));
	if (a==NULL){
		printf("insufficient allocation error\n");
		exit(1);
	}

	

	input(a, n); // using dynamic array as a function parameter
				   //  as parameter to the input function
	


	output(a, n); // using dynamic array as a function parameter
	
	//dynamic de-allocation
	if (a!=NULL){
		free(a);  //frees or allows other programs to use the memory
				  // initially assigned to "int *a"
	}
}

