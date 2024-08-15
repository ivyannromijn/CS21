//Vergara, Ivyann Romijn H.
//CMSC 21ST2L- Exer 4 Indiv


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//Palindrome function
int isPalindrome(char *Input1)
{
    int len=strlen(Input1);
    int i; //for left side of the string
    int j; //for right side of the string
    int palCheck=1;


    for(i=0,j=len-1;i < len/2 ;i++,j--)
    {

        if(Input1[i]!=Input1[j])
        { //compares first letter and last letter 

            palCheck = 0;
            break; //exit break if checked that it is not a palindrome

        }
    }
    return palCheck;
}


//function for caps sensitive 
void casesensitive(char*Input1)
{
    for(int l=0; l<strlen(Input1); l++)
    {
        Input1[l]=toupper(Input1[l]); //all caps every letter
    }
}



//main function
int main() {
    char Input1[80];
    char palindromes[100][100];  
    int ctr=0;                                                                
    int k=0;
    int palIden=0;


    while(strcmp("EXIT", Input1) != 0)
    {
        int  len = 0;

        //Read Input String
        printf("Please Enter Input: \n");
        scanf("%s", Input1);

        //function for case sensitive (all caps)
        casesensitive(Input1);


        //if input is exit then it breaks from the loop
        if (strcmp("EXIT", Input1) == 0) 
           { break;}

        
        //Function Call that passes the  input string
        isPalindrome(Input1);
        
        
        
        //Checks if the returned value from isPalindrom() is 1 or 0 that determines if the word is palindrome or not
        palIden=isPalindrome(Input1);
            if(palIden){
            printf("%s is  a Palindrome.\n", Input1);
            strcpy(palindromes[ctr++],Input1); //appends the word if palindrome to the  list
            }else{
            
            printf("%s is NOT Palindrome.\n", Input1);
            }
    }
    //bonus
    printf("Here are all your palindrome: \n");
    for (int k = 0; k < ctr; k++){
        printf("%s\n", palindromes[k]);}
    printf("===PROGRAM TERMINATED===");
    exit(0);
    

    return 0;
}


// check-> Your program doesn't run. There's an error in accessing the array. Also, strupr() doesn't work for all compilers so modify your solution. There's a way to change cases of characters in the handout.
// check-> Global variables are not allowed in CMSC 21. Put your variables where it belongs and use parameter passing. 
//  -> Why did you use pass by reference for length? It wasn't modified in your function so there's no need to do that.
// check -> You can use built-in function like strlen() from the handout to make the program. 
// check-> It would have been better to terminate the loop in isPalindrome() if a character is already found not to be equal. 
// check-> You should check first if the input is exit because there's no point in checking if a string is palindrome if it is already exit. Also, just use (strcmp, "EXIT", Input1) so that there would be less variables. 
// check-> Palcheck comes from the function so you should have caught it. 
// -> Variables should be properly initialized.
