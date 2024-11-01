//67070501048 Atiwit Thongngoen
#include <stdio.h>

int findMinimum(int num1, int num2)
{
    if (num1 > num2)
        return num2; else return num1;
}

void findMaximum(int num1, int num2)
{

    int max;
    if (num1 > num2) {
        max = num1;
    }
    else {
        max = num2;
    }
    printf("\nMaximum value is: %d", max);
}
void again(int num1,int num2){
    int option = 0;
    while (option != 3)
    {
        printf("\n1. Find minimum");
        printf("\n2. Find maximum");
        printf("\n3. Exit program");
        printf("\nEnter option no.: ");
        scanf("%d", &option);
        if (option == 1)
        {
            int min = findMinimum(num1,num2);
            printf("\nMinimum value is: %d", min);
        } else if (option == 2){
            findMaximum(num1,num2);        }
        else if(option == 3){
            printf("\nEnd of program. Goodbye.");
            break;
        }
}
}
int main()
{
    int num1, num2, option = 0, min;
    printf("Enter 2 numbers: ");
    scanf("%d %d", &num1, &num2);
    while (option != 3)
    {
        printf("\nChoose what to do from options below");
        printf("\n1. Find minimum");
        printf("\n2. Find maximum");
        printf("\n3. Exit program");
        printf("\nEnter option no.: ");
        scanf("%d", &option);
        if (option == 1)
        {
            min = findMinimum(num1,num2);
            printf("\nMinimum value is: %d", min);
            again(num1,num2);
            break;
        } else if (option == 2){
            findMaximum(num1,num2);
            again(num1,num2);
            break;
        }
        else if(option == 3){
            printf("\nEnd of program. Goodbye.");
            break;
        }
    }
      return 0;
}
