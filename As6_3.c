//67070501048 Atiwit Thongngoen
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10
#define MAX_NAME_LENGTH 8

int main() {
    char Name[MAX_STUDENTS][MAX_NAME_LENGTH + 1]; 
    int count = 0; 
    char input[MAX_NAME_LENGTH + 20];
    char temp[MAX_NAME_LENGTH + 1];
    printf("Enter student names (type END to print all names)\n");

    while (count < MAX_STUDENTS) {
        printf("Enter name of student %d: ", count + 1);
        scanf("%s", input);

        if (strcmp(input, "END") == 0) {
            break;
        }
        if (strlen(input) > MAX_NAME_LENGTH) {
            printf("The name is too long. Please try again.\n");
        } else {
            strcpy(Name[count], input);
            count++;
        }
    }
    printf("Name list: ");
    for (int i = 0; i < count; i++) {
        printf("%s ", Name[i]);
    }
    printf("\n");
    printf("The first order name sorted alphabetically: %s",Name[0]);

    return 0;
}
