#include <stdio.h>
#include <ctype.h>

int main() {

    char questions[5][100] = {{"What is the farest planet from earth?"},
                             {"\nWhat is the hottest planet in our solar system?"}, 
                             {"\nWhat was the name of the first moon landing mission?"}, 
                             {"\nWhat planet is the closest to earth?"}, 
                             {"\nWhat is the name of our galaxy?"}};

    char options[5][200] = {{"A. Earth.  B. Jupiter.\nC. Neptune.  D. Mars.\n"},
                           {"A. Sun.  B. Mercury.\nC. Neptune.  D. Saturn.\n"},
                           {"A. Artemis.  B. Voyager.\nC. Space Shuttle.  D. Apollo.\n"},
                           {"A. Saturn.  B. Mercury.\nC. Jupiter.  D. Mars.\n"},
                           {"A. Andromeda. B. Triangulum.\nC. Milky Way. D. Sombrero\n"}};
    
    char exit = '\0';

    do {
        int questionSize = sizeof(questions) / sizeof(questions[0]);
        char answers[5] = {'C', 'A', 'D', 'B', 'C'};
        char guess = '\0';
        int valid = 0;
        int valid1 = 0;
        int correct = 0;

            for(int i = 0; i < questionSize; i++) {
                printf("%s\n", questions[i]);
                printf("%s", options[i]);

                do {
                    valid = 0;
                    printf("\nChoose your answer: ");
                    scanf("%c", &guess);

                    if(isdigit(guess)) {
                        valid = 1;
                        printf("\nInvalid Input!.\n");
                    }
                    while(getchar() != '\n');
                } while(valid != 0);

                if (guess == answers[i]) {
                    correct++;
                    printf("\nYOU CHOOSE THE CORECT ANSWER!\n");
                    } else {
                    printf("\nYOU CHOOSE THE WORNG ANSWER.\n");
                } 
            }

            printf("\nYOU GOT %d QUESTIONS OUT OF %d.\n", correct, questionSize);
            while(getchar() != '\n');

            do {
                valid1 = 0;
                printf("Do you want to play the game again?(Y/N): ");
                scanf("%c", &exit);

                if(isdigit(exit)) {
                    valid1 = 1;
                    printf("\nInvalid Input!\n");
                }
            } while (valid1 != 0);

            if(isdigit(exit)) {
                printf("\nInvalid Input!\n");
            }
            while(getchar() != '\n');
    }while (exit != 'N' && exit != 'n');

    return 0;
}