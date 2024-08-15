/*VERGARA, Romijn
C_EXER_5-7a
*/

//params07_exer1.c

#include<stdio.h>

//input function
void input( char *n) { //uses the name variable from the main function
	printf("What is your name? ");
	scanf("%s",n);
	
}

//prints your input name
void output(char *n){
	printf("Your name is %s.\n",n);
	
}
	

int main(){
	char name[20]; //can store up to 19 input chars
	input(name); 
	output(name);
	
}


