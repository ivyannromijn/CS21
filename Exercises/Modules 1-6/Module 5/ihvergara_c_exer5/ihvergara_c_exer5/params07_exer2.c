/*VERGARA, Romijn
C_EXER_5-7b
*/


//params07_exer2.c

#include<stdio.h>
#include<string.h>	
#include<ctype.h>	//character manipulation functions

void input(char *s) { 
	printf("What is your name? ");
	scanf("%s",s);
	
}

// in ctype.h to convert string parameter upper case
void toupperStr(char *s){ 
	for (int x = 0; x < strlen(s); x++)
    {
        s[x] = toupper(s[x]);
    }
}

void output(char *s){
	printf("Your name is %s.\n",s);
}
	

int main(){
	char name[20]; 
	input(name); 
	output(name); //prints it in what is the user input
	toupperStr(name); //use toupper function in ctype.h to 
	output(name); // prints in upper case
	
}

/* to uppr function was not new to me since it was used in previous exercises (cexer4 and indiv exer).
used char *s as the parameter, it points to the variable name from the main function. */