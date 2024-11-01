#include <stdio.h>
#include <string.h>

FILE *input, *output;
int score[10];
char name[10][10];
int i = 0;

void swap(int *x, int *y) 
{ 
    int tmp = *x; 
    *x = *y; 
    *y = tmp; 
} 
 
void selectionSort(int data[], int count) 
{ 
    int j, minPos; 
    for (int k = 0; k < count - 1; k++) 
    { 
        minPos = k; 
        for (j = k + 1; j < count; j++) 
        { 
            if (data[j] < data[minPos]) 
                minPos = j; 
        } 
        swap(&data[k], &data[minPos]); 
    } 
}

int main() {
    char txt[10];
    char ans_name[20];
    int ans_score;

    printf("Enter a file name to load student scores: ");
    scanf("%s", txt);

    input = fopen(txt, "r"); 
    output = fopen(txt, "a");

    if (input == NULL || output == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(input, "%s %d", name[i], &score[i]) != EOF && i < 10) {
        i++;
    }
    fclose(input);

    for (int j = 0; j < i; j++) {
        printf("Student %d: %s, Score = %d\n", j + 1, name[j], score[j]);
    }

    while (1) {
        printf("Enter new student name (type 'END' to sort student score and end the program): ");
        scanf("%s", ans_name);

        if (strcmp(ans_name, "END") == 0) {
            break;
        }

        printf("Enter %s's Score: ", ans_name);
        scanf("%d", &ans_score);

        if (i < 10) {
            strcpy(name[i], ans_name);
            score[i] = ans_score;
            fprintf(output, "\n%s %d", ans_name, ans_score);
            i++;
        } else {
            printf("Maximum number of students reached.\n");
            break;
        }
    }
    fclose(output);

    selectionSort(score, i);

    printf("--------------- Sorted students by scores ---------------\n");
    for (int j = 0; j < i; j++) {
        printf("Student %d: %s, Score = %d\n", j + 1, name[j], score[j]);
    }

    printf("End of program. Goodbye.\n");
    return 0;
}
