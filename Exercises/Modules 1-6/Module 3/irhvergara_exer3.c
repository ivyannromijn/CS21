#include <stdio.h>
#include <stdlib.h>


  // Gets user input x and y
void inputXY(int *x, int *y) {                                    
    printf("Enter value of x: ");
    scanf("%d", x); 
    printf("Enter value of y: ");
    scanf("%d", y);  
}

// swap function, swaps the value of the integer using pointer
void swap(int *x, int *y) {                                        
    int temp; 
    temp = *x; 
    *x = *y;  
    *y = temp;   
}


// recursive function to check if prime (from previous exercise)
int Prime_checker(int i, int x){                                      
    if (i == 1) return 0; else       //1 is not considered as prime                       
    if (i == x) return 1; else 
    if (i%x == 0) return 0; else   //modulo operator for every value of x to check if prime, if it has a remainder then it is not divisible
    return Prime_checker(i, x+1); 

} 


//gets 3 largest prime integer
void getlargest(int x, int y, int *a, int *b, int *c, int *count){
    //initialize variable that holds if it is prime
    int PRIME; 

    //iterative statement to checks numbers from x to y 
    for (y; y>=x; y--) { 
        //checks the number if it is prime, calls the primechecker function
        PRIME = Prime_checker(y,2); 

        /* If the number is prime  then the count variable is incremented by 1 which will then be used
        by the printing function, it "counts" if there are 3 prime numbers present
        */
        if (PRIME){ 
            *count += 1; 
            
            //The first largest prime number (y) is held by pointer *a
            if (*count == 1) {
                *a = y; 
            }
            //The second largest prime number (y) is held by pointer *b
            else if (*count == 2) {
                *b = y;
            }
            //The third largest prime number (y) is held by pointer *c
            else if (*count == 3) { 
                *c = y;

                //breaks from the loop and exits the function
                break; 
            }
        }
    }
}


//print function
void print_largest(int x, int y, int a, int b, int c, int count){

    printf("The range you entered is from %d to %d \n", x, y);

    //if there are no function
    if (count == 0){
        printf("No Prime numbers found\n");
    }
    //if there are 1 prime
    else if (count == 1){
        printf("There is one prime number: %d", a);
    }
    //if there are 2 prime
    else if (count == 2){
        printf("There are two prime numbers: %d %d\n", a, b);
    }
    //if there are 3 prime
    else if (count == 3){
        printf("The three largest prime numbers are: %d %d %d\n", a, b, c);
    }


}


//main function
int main(){
    // initialize variables
    int  x, y;
    int a, b, c, count = 0;

    //gets user input function
    inputXY(&x, &y);
    
    //if input is invalid (negative integer or 1) then it is an invalide range
    if ((x<2) && (y<2)){
        printf("Invalid Range!\n");}
    else{ 
        //if x>y it swaps the value
        if (x>y){
            swap(&x, &y);}
        
        //gets the three largest prime
        getlargest(x, y, &a, &b, &c, &count);

        //print function
        print_largest(x, y, a, b, c,count);
    }

    return 0;
} 
