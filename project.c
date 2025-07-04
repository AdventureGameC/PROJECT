#include <stdio.h>

int main() {
    int mainchoice, roomchoice;
    int inGame = 1;
    int inRoom = 0;

    // basic instruction code for the players to understand what the game is basically about
    printf("Welcome to The Mysterious Island Adventure!\n");
    printf("You are stuck on a strange island filled with unknown dangers and treasures.\n");
    printf("You are currently on a beach on the island.\n");
    printf("Your goal is to explore the island, find hidden clues, and possibly escape.\n");
    printf("Make wise choices to survive and unlock the mysteries of the island.\n");

    while (inGame) {
        if (inRoom == 0) {
            // Main island menu
            printf("\nYou are on The Mysterious Island. What will you do next?\n");
            printf("1. Explore the jungle\n");
            printf("2. Enter the cave\n");
            printf("3. Visit the volcano\n");
            printf("4. Check the swamp\n");
            printf("5. Visit the abandoned village\n");
            printf("6. Exit the game\n");

            printf("Enter your choice: ");
            scanf("%d", &mainchoice);

            if (mainchoice == 1) {
                inRoom = 1;  // Jungle
            } else if (mainchoice == 2) {
                inRoom = 2;  // Cave
            } else if (mainchoice == 3) {
                inRoom = 3;  // Volcano
            } else if (mainchoice == 4) {
                inRoom = 4;  // Swamp
            } else if (mainchoice == 5) {
                inRoom = 5;  // Village
            } else if (mainchoice == 6) {
                printf("You have decided to leave the island. Goodbye!\n");
                inGame = 0;
            } else {
                printf("Invalid choice. Try again.\n");
            }
        }

        // Jungle room
        if (inRoom == 1) {
            printf("\nYou are in the dense jungle. The trees are very tall, and the air is full of mist.\n");
            printf("You can hear strange animal noises in the distance. What will you do now?\n");
            printf("1. Walk deeper into the jungle\n");
            printf("2. Look for a shelter\n");
            printf("3. Go back to where you were before\n");
            printf("Enter your choice: ");
            scanf("%d", &roomchoice);

            if (roomchoice == 1) {
                printf("You go further into the jungle and see a hidden waterfall. There's a cave behind it!\n");
                inRoom = 2;  // Move to cave
            } else if (roomchoice == 2) {
                printf("You discover a quiet, open spot and set up a temporary shelter.\n");
                printf("You rest for a while before continuing your adventure.\n");
                // Stay in jungle
            } else if (roomchoice == 3) {
                printf("You head back to the beach, unsure of your next step.\n");
                inRoom = 0;  // Back to main menu
            } else {
                printf("Invalid choice. Try again.\n");
            }
        }


    }

    return 0;
}
