/*VERGARA, Romijn
C_EXER_5-9a
*/

//params09_exer1.c
//Passing an array of C structures (or records)
//as parameter to functions


#include <stdio.h>

typedef struct node_tag
{
	char name[20];
	float grade;
} node;

void input1(node *r1)
{ //get user input for one record

	printf("What is your name? ");
	scanf("%s", r1->name); //same as scanf("%s",(*r1).name);

	printf("What is your GWA? ");
	scanf("%f", &(r1->grade)); //same as scanf("%f",&((*r1).grade));
}

void output1(node r1)
{ //display values of fields of r1
	printf("Name: %s\n", r1.name);
	printf("GWA: %0.2f\n", r1.grade);
}

void input(node *a, int n)
{ //should get user inputs for n records
	// and store it in "array a in main"
	for (int i = 0; i < n; i++)
	{
		input1(&a[i]);
	}
}

void output(node *a, int n)
{ //should print n records from "array a in main"
	for (int i = 0; i < n; i++)
	{
		output1(a[i]);
	}
}

int main()
{
	int i, n = 3;
	node a[n];


	input(a, n); //pass array variable a as parameter into input function

	

	output(a, n); //pass array variable a as parameter into output function
}
/* this is almost the same as the previous exercises except that there are more than 1 entry */