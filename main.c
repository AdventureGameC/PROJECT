
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


void typeEffect(const char *text, int delay) {
    for (int i = 0; i < strlen(text); i++) {
        printf("%c", text[i]);
        fflush(stdout);
        usleep(delay * 1000);
    }
}


int getIntInput(const char *prompt) {
    char input[100];
    int value;
    while (1) {
        printf("%s", prompt);
        if (fgets(input, sizeof(input), stdin)) {
            if (sscanf(input, "%d", &value) == 1) {
                return value;
            } else {
                printf("\033[1;31mInvalid input. Please enter a number.\033[0m\n");
            }
        }
    }
}

int main() {
    int mainChoice, roomChoice;
    int inGame = 1, inRoom = 0;

    typeEffect("\033[1;32mWelcome to The Mysterious Island Adventure!\033[0m\n", 30);
    typeEffect("You are stranded on a mysterious island filled with secrets.\n", 20);
    typeEffect("Explore wisely and survive...\n", 20);
    sleep(1);

    while (inGame) {
        if (inRoom == 0) {
            printf("\n\033[1;34mWhere do you want to go?\033[0m\n");
            printf("\033[1;33m1. Explore the jungle\033[0m\n");
            printf("\033[1;33m2. Enter the cave\033[0m\n");
            printf("\033[1;33m3. Visit the volcano\033[0m\n");
            printf("\033[1;33m4. Check the swamp\033[0m\n");
            printf("\033[1;33m5. Visit the abandoned village\033[0m\n");
            printf("\033[1;31m6. Exit the game\033[0m\n");

            mainChoice = getIntInput("Enter your choice: ");

            if (mainChoice >= 1 && mainChoice <= 5) {
                inRoom = mainChoice;
                printf("\n\033[1;35mLoading area...\033[0m\n");
                sleep(1);
            } else if (mainChoice == 6) {
                printf("\n\033[1;32mYou leave the island. Farewell!\033[0m\n");
                inGame = 0;
            } else {
                printf("\033[1;31mInvalid choice.\033[0m\n");
            }
            
            while (inRoom == 1) {
            printf("\n\033[0;32mYou are in the dense jungle, surrounded by towering trees and wildlife.\033[0m\n");
            printf("\033[1;32m1. Walk deeper into jungle (find hidden cave entrance)\033[0m\n");
            printf("\033[1;32m2. Look for shelter (resting spot)\033[0m\n");
            printf("\033[1;32m3. Climb a tall tree (see distant volcano smoke)\033[0m\n");
            printf("\033[1;32m4. Gather fruits (find some berries)\033[0m\n");
            printf("\033[1;32m5. Return to beach\033[0m\n");

            roomChoice = getIntInput("Choice: ");

            if (step == 1 && roomChoice == 3) {
                printf("From the treetop, you spot smoke rising from the volcano far away.\n");
                step = 2;
                inRoom = 2;
            } else if (roomChoice == 5) {
                inRoom = 0;
            } else {
                printf("\033[1;33mThat doesn't seem to be the right path. Try exploring other places.\033[0m\n");
                inRoom = 0;
            }
        }

            

       

    typeEffect("\n\033[1;32mThanks for playing The Mysterious Island Adventure!\033[0m\n", 30);
    return 0;
}


