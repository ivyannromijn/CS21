#include <stdio.h>
#include <stdlib.h>

int main(){
    int choice=0;
    do {
        float kg, lbs, cm, ft; //initialization of variables
        float result=0;
        
        printf("====== MENU ====== \n"); //menu for what unit is preferred
        printf("[1] Enter in kilogram and centimeters \n");
        printf("[2] Enter in pounds and feet \n");
        printf("[3] Exit \n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch(choice){ 
            case (1): //for metric unit
            printf("Enter your weight in kilograms:");
            scanf("%f", &kg);
            printf("Enter your height in centimeters:");
            scanf("%f", &cm);
            result = ((kg / cm) / cm)*10000; //multiplied by 10000 to convert to meters
            break;

            case (2): //for US unit
            printf("Enter your weight in pounds:");
            scanf("%f", &lbs);
            printf("Enter your height in feet:");
            scanf("%f", &ft);
            result=(lbs / ((ft*12)*(ft*12)))*703; //ft is converted to inches
            break;
            case (3):
            printf("Thank you and see you again soon! Stay safe!  \n"); 
            exit(0); //used exit() to terminate the program
            break;
            
            default:
            printf("Incorrect choice, please try again \n"); //error prompt
        }
        if (result > 0 && result < 18.5){ 
            printf("============================== \n"); //categorization of BMI result
            printf("Your BMI is %f.\n", result);
            printf("You are underweight\n");
            }else if(result >= 18.5 && result < 25){
            printf("============================== \n");
            printf("Your BMI is %f.\n", result);
            printf("You are normal.\n");
            }else if(result >= 25 && result < 30){
            printf("============================== \n");
            printf("Your BMI is %f.\n", result);
            printf("You are overweight.\n");
            }else if(result >= 30){
            printf("============================== \n");
            printf("Your BMI is %f. \n", result);
            printf("You are obese\n");
            }
        } while (choice != 3); //program will run continuously until option 3 (exit) is chosen
    return 0;
}
