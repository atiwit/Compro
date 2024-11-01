#include <stdio.h>

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
    for (i = 0; i < count - 1; i++) 
    { 
        minPos = i; 
        for (j = i + 1; j < count; j++) 
        { 
            if (data[j] < data[minPos]) 
                minPos = j; 
        } 
        swap(&data[i], &data[minPos]); 
    } 
}
int main() {
    char txt[10];
    int avg,max,min;
    printf("Enter a file name to load student scores: ");
    scanf("%s", txt);

    input = fopen(txt, "r"); 
    if (input == NULL) {
        printf("Error: Could not open file %s\n", txt);
        return 1;
    }

    output = fopen("stat.txt", "w");
    if (output == NULL) {
        printf("Error: Could not open file stat.txt\n");
        fclose(input);
        return 1;
    }

    while (fscanf(input, "%s %d", name[i], &score[i]) != EOF) {
        i++;
    }

    for (int j = 0; j < i; j++) {
        printf("Student %d: %s, Score =  %d\n", j+1,name[j], score[j]);
    }
    for(i=0;i <= 5;i++){
        avg += score[i];
    }
    selectionSort(score,5);
    min = score[0];
    max = score[4];
    printf("Average score is %d.\n",avg/5);
    printf("Miniminum score is %d.\n",min);
    printf("Maximinum score is %d.\n",max);
    printf("End of program. Goodbye.");
    fprintf(output,"Average score is %d.\n",avg/5);
    fprintf(output,"Miniminum score is %d.\n",min);
    fprintf(output,"Maximinum score is %d.\n",max);
    fclose(input);
    fclose(output);
    return 0;
}
