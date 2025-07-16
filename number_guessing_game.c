#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main(){
    int number, guess, attempts = 0;

    srand(time(NULL));
    number = rand() % 100 + 1;

    printf("I have chosen a number between 1 and 100. Try to guess it!\n");
    do{
        printf("Enter your guess: ");
        scanf(" %d", &guess);
        attempts++;

        if(guess > number){
            printf("Try a smaller number.\n");
        }else if (guess < number){
            printf("Try a bigger number.\n");
        }else{
            printf("Congrats! You guessed it in %d attempts.\n", attempts);
        }
    } while(guess != number);

    return 0;
}