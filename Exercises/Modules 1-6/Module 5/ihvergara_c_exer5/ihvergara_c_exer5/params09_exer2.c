/*VERGARA, Romijn
C_EXER_5-9b
*/


//params09_exer2.c

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

void input(node a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		input1(&a[i]);
	}
}

void output(node *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		output1(a[i]);
	}
}

char* getHighest(node *a, int n)
{	//should return the name of the student
	// with the highest grade out of the
	// n entries from "array a in main"
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[max].grade > a[i].grade)
			max = i;
	}

	return a[max].name;


}

int main()
{
	int i, n = 3;
	node a[n];

	//get user inputs for n records and store it into array a
	input(a, n);

	//display the contents of array a
	output(a, n);

	//Exercise: call getHighest to get the name of the student
	//          with the highest grade
	printf("%s has the highest grade\n", getHighest(a, n));
}
