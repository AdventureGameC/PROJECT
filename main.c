#include <stdio.h>
#include <unistd.h>
#include <string.h>

void typeEffect(const char *text, int delay) {
    for (int i = 0; i < strlen(text); i++) {
        printf("%c", text[i]);
        fflush(stdout);
        usleep(delay * 1000);
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
            printf("Enter your choice: ");
            scanf("%d", &mainChoice);

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
                printf("\n\033[0;32mYou are in the jungle. It's lush and humid.\033[0m\n");
                printf("\033[1;32m1. Walk deeper\033[0m\n");
                printf("\033[1;32m2. Look for shelter\033[0m\n");
                printf("\033[1;32m3. Climb a tree\033[0m\n");
                printf("\033[1;32m4. Gather fruits\033[0m\n");
                printf("\033[1;32m5. Return to beach\033[0m\n");
                printf("Choice: ");
                scanf("%d", &roomChoice);

                switch (roomChoice) {
                    case 1: printf("You find a hidden waterfall.\n"); inRoom = 2; break;
                    case 2: printf("You build a small shelter.\n"); break;
                    case 3: printf("You see smoke from a volcano.\n"); break;
                    case 4: printf("You collect wild berries.\n"); break;
                    case 5: inRoom = 0; break;
                    default: printf("\033[1;31mInvalid choice.\033[0m\n");
                }
            }

            while (inRoom == 2) {
                printf("\n\033[1;30mYou are inside a dark, echoing cave.\033[0m\n");
                printf("\033[1;36m1. Approach glowing object\033[0m\n");
                printf("\033[1;36m2. Light a torch\033[0m\n");
                printf("\033[1;36m3. Look for bats\033[0m\n");
                printf("\033[1;36m4. Return to jungle\033[0m\n");
                printf("Choice: ");
                scanf("%d", &roomChoice);

                switch (roomChoice) {
                    case 1: printf("You find a mysterious artifact.\n"); inRoom = 3; break;
                    case 2: printf("The cave lights up revealing ancient drawings.\n"); break;
                    case 3: printf("Bats flutter overhead.\n"); break;
                    case 4: inRoom = 1; break;
                    default: printf("\033[1;31mInvalid choice.\033[0m\n");
                }
            }

            while (inRoom == 3) {
                printf("\n\033[1;31mYou are near a rumbling volcano.\033[0m\n");
                printf("\033[1;91m1. Climb the volcano\033[0m\n");
                printf("\033[1;91m2. Search volcanic rocks\033[0m\n");
                printf("\033[1;91m3. Rest near hot spring\033[0m\n");
                printf("\033[1;91m4. Return to cave\033[0m\n");
                printf("Choice: ");
                scanf("%d", &roomChoice);

                switch (roomChoice) {
                    case 1:
                        printf("\033[1;32mYou discover an ancient temple. You win!\033[0m\n");
                        inGame = 0;
                        break;
                    case 2: printf("You collect shiny obsidian.\n"); break;
                 //   case 3: printf("You relax at the warm spring.\n"); break;
                    case 4: inRoom = 2; break;
                    default: printf("\033[1;31mInvalid choice.\033[0m\n");
             

    typeEffect("\n\033[1;32mThanks for playing The Mysterious Island Adventure!\033[0m\n", 30);
    return 0;
}

