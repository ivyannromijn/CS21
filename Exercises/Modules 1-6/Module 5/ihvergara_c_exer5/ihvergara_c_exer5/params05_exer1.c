/*VERGARA, Romijn
C_EXER_5-5
*/

//params05_exer1.c

#include<stdio.h>



//user input function
void input(int a[][3] , int m, int n){ 
	int i, j;
	for(i=0;i<m;i++) {
		printf("\nEnter %i integers for row %i\n", n,i+1);
		for(j=0;j<n;j++) {
			printf("Enter an integer: ");
			scanf("%i",&a[i][j]);
		}		
	}
}


//printing function
void output(int a[][3] , int m, int n){ 
	int i, j; 

		for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			printf("%3i ",a[i][j]); 
		}		
		printf("\n"); //for new line (row)
	}	
}


int main(){
	int m=2, n=3;
	int a[m][n];
	int i,j;
	

	input(a, m, n); // pass a 2D array variable a as parameter into input function
		
	output(a, m, n);// pass a 2D array variable a as parameter into output function
}
					


