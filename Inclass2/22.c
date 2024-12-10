#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void summary(int guess[], int count, int points) {
    printf("\nSummary:\n");
    printf("You played %d rounds.\n", count);
    printf("You scored %d points.\n", points);
    printf("Your guesses were:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", guess[i]);
    }
    printf("\n");
}

int generateRandomNumber() {
    return rand() % 100 + 1; // Generate a number between 1 and 100
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int number = generateRandomNumber();
    int guess[100];    // Array to store up to 100 guesses
    int points = 0, round = 0;

    printf("Guess my number (1-100). Type 'END' to quit.\n");

    while (1) {
        char input[10];
        printf("Chance #%d: ", round + 1);
        scanf("%s", input);

        // Check if the user wants to end the game
        if (strcasecmp(input, "END") == 0) {
            summary(guess, round, points);
            break;
        }

        // Convert input to integer
        int userGuess = atoi(input);

        // Store the guess
        guess[round] = userGuess;

        // Compare the guess with the random number
        if (userGuess > number) {
            printf("Too high!\n");
        } else if (userGuess < number) {
            printf("Too low!\n");
        } else {
            printf("Correct! You get +1 point.\n");
            points++;
            number = generateRandomNumber(); // Generate a new random number
        }

        round++;
        if (round >= 100) {
            printf("Maximum number of guesses reached.\n");
            summary(guess, round, points);
            break;
        }
    }

    return 0;
}
