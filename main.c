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

    int foundArtifact = 0;
    int foundMap = 0;

    int step = 0;

    typeEffect("\033[1;32mWelcome to The Mysterious Island Adventure!\033[0m\n", 30);
    typeEffect("You are stranded on a mysterious island filled with secrets.\n", 20);
    typeEffect("Explore wisely to uncover the hidden temple and survive...\n", 20);
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
                printf("\n\033[1;35mHeading there...\033[0m\n");
                sleep(1);
            } else if (mainChoice == 6) {
                printf("\n\033[1;32mYou leave the island. Farewell!\033[0m\n");
                inGame = 0;
            } else {
                printf("\033[1;31mInvalid choice.\033[0m\n");
            }
        }

        // Jungle room (1)
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

        // Cave room (2)
        while (inRoom == 2) {
            printf("\n\033[1;30mYou step inside the dark cave behind the waterfall.\033[0m\n");
            printf("\033[1;36m1. Approach glowing object\033[0m\n");
            printf("\033[1;36m2. Light a torch (see cave paintings and find artifact)\033[0m\n");
            printf("\033[1;36m3. Listen carefully\033[0m\n");
            printf("\033[1;36m4. Exit cave to jungle\033[0m\n");

            roomChoice = getIntInput("Choice: ");

            if (step == 2 && roomChoice == 2) {
                printf("Torchlight reveals cave paintings depicting an ancient temple on the volcano.\n");
                printf("You find an ancient glowing artifact covered in mysterious symbols.\n");
                foundArtifact = 1;
                step = 3;
                inRoom = 5;
            } else if (roomChoice == 4) {
                inRoom = 1;
            } else {
                printf("\033[1;33mNothing useful here for your quest. Try something else.\033[0m\n");
                inRoom = 0;
            }
        }

        // Abandoned Village room (5)
        while (inRoom == 5) {
            printf("\n\033[1;35mYou explore the quiet abandoned village with empty huts and a mysterious totem.\033[0m\n");
            printf("\033[1;95m1. Search huts (find torn map fragment)\033[0m\n");
            printf("\033[1;95m2. Look for supplies\033[0m\n");
            printf("\033[1;95m3. Inspect totem (symbols match your artifact)\033[0m\n");
            printf("\033[1;95m4. Return to beach\033[0m\n");

            roomChoice = getIntInput("Choice: ");

            if (step == 0 && roomChoice == 1) {
                printf("You find a torn map fragment that might help find the temple.\n");
                foundMap = 1;
                step = 1;
                inRoom = 1;
            } else if (step == 3 && roomChoice == 3 && foundArtifact) {
                printf("The totem's symbols match the artifact. They seem connected.\n");
                step = 4;
                inRoom = 3;
            } else if (roomChoice == 4) {
                inRoom = 0;
            } else {
                printf("\033[1;33mThat doesn't help your quest right now. Try something else.\033[0m\n");
                inRoom = 0;
            }
        }

        // Volcano room (3)
        while (inRoom == 3) {
            printf("\n\033[1;31mYou stand at the base of the towering volcano.\033[0m\n");
            printf("\033[1;91m1. Climb the volcano (try to find hidden temple)\033[0m\n");
            printf("\033[1;91m2. Search volcanic rocks\033[0m\n");
            printf("\033[1;91m3. Rest at the hot spring nearby\033[0m\n");
            printf("\033[1;91m4. Return to jungle\033[0m\n");

            roomChoice = getIntInput("Choice: ");

            if (step == 4 && roomChoice == 1) {
                if (foundArtifact && foundMap) {
                    printf("\033[1;32mUsing the artifact and map clues, you discover a hidden path to the ancient temple on the volcano!\033[0m\n");
                    printf("\033[1;32mCongratulations! You have won The Mysterious Island Adventure!\033[0m\n");
                    typeEffect("\n\033[1;32mThanks for playing!\033[0m\n", 30);
                    exit(0);
                } else {
                    printf("\033[1;33mYou lack either the artifact or the map to find the temple.\033[0m\n");
                    inRoom = 0;
                }
            } else if (roomChoice == 4) {
                inRoom = 0;
            } else {
                printf("\033[1;33mThat action doesn't help now. Try climbing the volcano when ready.\033[0m\n");
                inRoom = 0;
            }
        }

        // this portion is made to send back to beach for simplicity.
        if (inRoom == 4) {
            printf("\033[1;33mExploring the swamp won't help you progress in your quest right now. Returning to the beach.\033[0m\n");
            inRoom = 0;
        }
    }

    typeEffect("\n\033[1;32mThanks for playing The Mysterious Island Adventure!\033[0m\n", 30);
    return 0;
}
