#include "stdio.h"

int main(){
    double num1, num2, result;
    char op;

    printf("---sul0's Calculator---\n");
    printf("You can make addition, subtraction, multiplication and division calculations in this program.\n");
    printf("Type first number: ");
    scanf("%lf", &num1);
    printf("Type second number: ");
    scanf("%lf", &num2);
    
    printf("Choose an operator (+, -, *, /): ");
    scanf(" %c", &op);

    switch(op){
        case '+':
            printf("Result is: %.2lf", num1 + num2);
            break;
        case '-':
            printf("Result is: %.2lf", num1 - num2);
            break;
        case '*':
            printf("Result is: %.2lf", num1 * num2);
            break;
        case '/':
            if(num2 != 0){
                printf("Result is: %.2lf", num1 / num2);
            }
            else{
                printf("You cannot divide any number with zero.");
                break;
            }
            break;

        default:
            printf("\n");
            printf("Undefined operation.");
            return 1;
    }




    return 0;
}