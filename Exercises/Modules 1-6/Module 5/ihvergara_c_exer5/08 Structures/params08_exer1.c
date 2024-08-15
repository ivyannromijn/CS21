/*VERGARA, Romijn
C_EXER_5-8
*/


//params08_exer1.c
#include <stdio.h>

struct node_tag
{
	char name[20];
	float grade;
};

void input(struct node_tag *r1)
{ //store values for r1

	printf("What is your name? ");
	scanf("%s", r1->name);

	printf("What is your GWA? ");
	scanf("%f", &r1->grade);
}

void output(struct node_tag r1)
{ //display values of fields of r1
	printf("Name: %s\n", r1.name);
	printf("GWA: %0.2f\n", r1.grade);
}


int main(){
	struct node_tag r1;
	

	input(&r1); //passes the address to the function 'input'
	output(r1); //prints using the value of r1
	
}

