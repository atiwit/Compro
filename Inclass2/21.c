#include <stdio.h>  
#include <time.h>
#include <stdlib.h>

int main (){
    int number, i,guess[6];
    srand(time(NULL)); 
    number = rand()%100+1;
    i = 0;
    printf("Welcome to GuessFking Number %d\n",number);
    while (i < 6)
    {
        printf("Guess it! #%d Chance : ",i+1);
        scanf("%d",&guess[i]);
        if (guess[i] > number) {
            printf("It's too high\n");
        }
        else if(guess[i] < number) {
            printf("It's too low\n");
        }
        else if(guess[i] == number){
            printf("You win!");
            break;
        }
        i++;
    }
        if (i == 6) printf("You lose!");
    

}