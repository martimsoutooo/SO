#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[]){

    if (argc != 3){
        printf("Usage: %s <min> <max>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int firstNumber = atoi(argv[1]);
    int secondNumber = atof(argv[2]);

    if (secondNumber < firstNumber){
        printf("Usage: %s <min> <max>\n", argv[0]);
        return EXIT_FAILURE;
    }

    srand(time(NULL));
    
    int number = rand() % (secondNumber - firstNumber + 1) + firstNumber;

    
    int guess;
    printf("Guess the number: ");
    scanf("%d", &guess);

    while (guess != number){
        if (guess > number){
            printf("Too high, try again: ");
        }
        else{
            printf("Too low, try again: ");
        }
        scanf("%d", &guess);
    }

    printf("Congratulations! You guessed the number.\n");

    return EXIT_SUCCESS;
    
}