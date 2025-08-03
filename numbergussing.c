#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    char start = '\0';

    do {

        srand(time(NULL));
    
        int min = 1;
        int max = 100;
        int Intries = 7;
        int tries = 0;
        int triesLeft = 7;
        int randomNumber = (rand() % (max - min + 1)) + min;
        int valid = 0;
        int guess = 0;

        printf("THE NUMBER IS %d\n", randomNumber);
        printf("=== NUMBER GUESSING GAME ===\n");
        printf("You have %d tries to guess the secret number!\n", Intries);

        do {
            do {
                valid = 0;
                printf("Guess the number between(1-100): ");
                if(scanf("%d", &guess) != 1) {
                    printf("Invalid Input.\n");
                    valid = 1;
                    while (getchar() != '\n');
                }
                while (getchar() != '\n');
            }while (valid != 0);
            tries++;

            if (tries == 8) {
                printf("YOU RAN OUT OF TRIES!.\n");
                printf("THE NUMBER WAS %d", randomNumber);
                return 0;
            } else if (guess > randomNumber) {
                printf("TOO HIGH!\n");
                triesLeft--;
                printf("%d tries left!\n", triesLeft);
            } else if (guess < randomNumber) {
                printf("TOO LOW.\n");
                triesLeft--;
                printf("%d tries left!\n", triesLeft);
            } else {
                printf("YOU GUESSED THE NUMBER!.\n");
                printf("THE NUMBER IS %d\n", randomNumber);
                printf("THIS TOOK YOU %d TRIES!.\n", tries);
            }
            
    }while (guess != randomNumber);

    printf("Do you want to play again?(Y/N): ");
    scanf("%c", &start);
    while(getchar() != '\n');

    }while (start != 'N' && start != 'n');

    return 0;
}