#include <stdio.h>
#include <string.h>
#include <time.h>

// Function Prototypes
void printMenu(int *menu);
void summation(int guess[], int *sum);
void multiple(int guess[], int *product);
void hint(int guess[]);
void guess_1(int guess[], int *win, int *lose);
void guess_2(int guess[], int *win, int *lose);
void guess_3(int guess[], int *win, int *lose);

int main(void) {
    int menu, round = 0, win = 0, lose = 0;
    char con;
    int guess[10];
    do {
        printMenu(&menu);
        if (menu == 1) {
            guess_1(guess,&win,&lose);
        } else if (menu == 2) {
            guess_2(guess,&win,&lose);
        } else if (menu == 3) {
            guess_3(guess,&win,&lose);
        }
        round++;
        printf("Do you want to play again (y/n)? : ");
        scanf(" %c", &con);
    } while (con == 'y');
    printf("Your stats: Total rounds = %d, Wins = %d, Losses = %d\n", round, win, lose);
    printf("Goodbye!\n");
    return 0;
}

// Menu Display Function
void printMenu(int *menu) {
    printf("Please select a difficulty level (1-3):\n");
    printf("1. Easy\n2. Medium\n3. Hard\n");
    scanf("%d", menu);
}

// Summation Calculation Functions
void summation(int guess[], int *sum) {
    *sum = guess[1] + guess[3] + guess[5];
}

// Multiple Calculation Functions
void multiple(int guess[], int *product) {
    *product = guess[1] * guess[3] * guess[5];
}

// Hint Calculation Functions
void hint(int guess[]) {
    int sum, product;
    summation(guess, &sum);
    multiple(guess, &product);
    printf("Hint:\n");
    printf("The summation of the numbers at positions 1, 3, and 5 is %d\n", sum);
    printf("The product of the numbers at positions 1, 3, and 5 is %d\n", product);
}

// Easy Mode
void guess_1(int guess[], int *win, int *lose) {
    srand(time(NULL));
    int number = (rand() * 32768 + rand()) % 1000000 + 1;
    int i = 1;
    guess[1] = number % 10;
    guess[3] = (number/100) % 10;
    guess[5] = (number/10000) % 10;
    hint(guess);
    while(i <= 10) {
        printf("Chance #%d: Your guess >> ", i);
        scanf("%d", &guess[i]);
        if(number < guess[i]) {
            printf("Too high\n");
        } 
        else if(number > guess[i]) {
            printf("Too low\n");
        } 
        else {
            printf("You win\n");
            (*win)++;
            break;
        }
        i++;
    }
    if(i > 10){
        printf("You lose the answer is: %d\n", number);
        (*lose)++;
    }
}

// Medium Mode
void guess_2(int guess[], int *win, int *lose) {
    srand(time(NULL));
    int number = (rand() * 32768 + rand()) % 1000000 + 1;
    int i = 1;
    guess[1] = number % 10;
    guess[3] = (number/100) % 10;
    guess[5] = (number/10000) % 10;
    hint(guess);
    while(i <= 7) {
        printf("Chance #%d: Your guess >> ", i);
        scanf("%d", &guess[i]);
        if(number < guess[i]) {
            printf("Too high\n");
        } 
        else if(number > guess[i]) {
            printf("Too low\n");
        } 
        else {
            printf("You win\n");
            (*win)++;
            break;
        }
        i++;
    }
    if(i > 7){
        printf("You lose the answer is: %d\n", number);
        (*lose)++;
    }
}

// Hard Mode
void guess_3(int guess[], int *win, int *lose) {
    srand(time(NULL));
    int number = (rand() * 32768 + rand()) % 1000000 + 1;
    int i = 1;
    guess[1] = number % 10;
    guess[3] = (number/100) % 10;
    guess[5] = (number/10000) % 10;
    hint(guess);
    while(i <= 5) {
        printf("Chance #%d: Your guess >> ", i);
        scanf("%d", &guess[i]);
        if(number < guess[i]) {
            printf("Too high\n");
        } 
        else if(number > guess[i]) {
            printf("Too low\n");
        } 
        else {
            printf("You win\n");
            (*win)++;
            break;
        }
        i++;
    }
    if(i > 5){
        printf("You lose the answer is: %d\n", number);
        (*lose)++;
    }
}