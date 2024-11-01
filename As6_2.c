#include <stdio.h>

int findMinimum(int num1, int num2)
{
    if (num1 < num2)
        return num1;
    else
        return num2;
}

void findMaximum(int num1, int num2)
{
    if (num1 > num2)
        printf("Maximum value is: %d\n", num1);
    else
        printf("Maximum value is: %d\n", num2);
}

int main()
{
    int num1, num2, option = 0, min;
    printf("Enter 2 numbers: ");
    scanf("%d%d", &num1, &num2);

    while (option != 3)
    {
        printf("Choose what to do from options below\n");
        printf("1. Find minimum\n");
        printf("2. Find maximum\n");
        printf("3. Exit program\n");
        printf("Enter option no.: ");
        scanf("%d", &option);

        if (option == 1)
        {
            min = findMinimum(num1, num2);
            printf("Minimum value is: %d\n", min);
        }
        else if (option == 2)
        {
        findMaximum(num1, num2);
        }
        else if (option == 3)
        {
            printf("End of program. Goodbye.\n");
        }
    }

    return 0;
}