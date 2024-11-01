#include <stdio.h>

int main() {
    char arr[100];
    int sum = 0,i = 0;
    printf("Enter a word:");
    scanf("%s",&arr);
    while(arr[i] != '\0'){
        if(arr[i] == 'a') {
            sum += 1; 
        }
        i++;
    }
    printf("Total number of 'a' is %d.",sum);
}