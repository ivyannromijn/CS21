/*VERGARA, Romijn
C_EXER_5-3b
*/

//params03_exer2.c OPTIONAL EXERCISE
//Exercise: Passing an array as parameter to sorting functions
//NOTE: - this is not a required exercise
//      - you use this later to trace the sorting algorithms
//      - no answer key provided

#include<stdio.h>
#include<malloc.h> //for malloc in merge function


void input(int *a, int n){ 
	
	int i;
	
	for(i=0;i<n;i++) {
		printf("Enter an integer: ");
		scanf("%i",&a[i]);
	}
	
}

void output(int *a, int n){ //see comments in input
	int i;
	
	for(i=0;i<n;i++) {
		printf("a[%i]==%i\n",i,a[i]);
	}	
}

void swap(int *a,int *b){ //swaps values of "a and b in main"
	int temp;

	temp=*a;
	*a=*b;	
	*b=temp;
}

void bubble_sort(int a[], int n){ //sorts the array in ascending order
	int i,j;
	
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			if(a[j]>a[j+1])
				swap(&a[j],&a[j+1]);
			
}

void selection_sort (int a[], int n){
	//you may have to research first this sorting algorithm
}

void insertion_sort(int a[], int n){ //
	//you may have to research first this sorting algorithm
}

void merge(int a[], int lower, int mid, int upper){
	int *temp, i, j, k;
	
	temp=(int *)malloc((upper-lower+1)*sizeof(int));
	
	for(i=0,j=lower,k=mid+1;j<=mid || k<=upper; i++)
		temp[i]=(j<=mid && (k>upper || a[j]<a[k]))?a[j++]:a[k++];
	
	for(i=0,j=lower; j<=upper;i++,j++)
		a[j]=temp[i];
	//the second loop is equivalent to
	//memcpy(&a[lower], temp, (upper-lower+1)*sizeof(int));

	free(temp);
}


void merge_sort(int a[], int lower, int upper){
	//a classic divide-and-conquer algorithm
	//calls the merge function
}


void sort(int a[], int n){
	
	//uncomment one of the lines to test the corresponding algo:
	
	bubble_sort(a,n);
	//selection_sort(a,n);
	//insertion_sort(a,n);
	//merge_sort(a,__,___); //be careful what you put in the blanks
							// the C compiler will not check 
							// "array out of bounds" error for you
	//qsort(___,___,____);  //call the builtin qsort algorithm in C
}


int main(){
	int i, n=5;
	int a[n];
		
	input(a, n);
	output(a, n);
	sort(a, n); //you may have to research first about sorting algorithms
	output(a, n);
}
					