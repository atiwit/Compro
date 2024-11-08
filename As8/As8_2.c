#include<stdio.h>
#include<string.h>

    typedef struct 
    {
        char name[10];
        int score;    
    }student_info;
    
    student_info student[100];

void swap(student_info *x, student_info *y){
    student_info tmp = *x;
    *x = *y;
    *y = tmp;
}

void selectionSort(student_info student[], int count){
    int i, j, minPos;
    for(i = 0; i < count-1; i++){
        minPos = i;
        for(j = i+1; j < count; j++){
            if(student[j].score < student[minPos].score)
            minPos = j;
        }
        swap(&student[i], &student[minPos]);
    }
}

int main(){
    char file_path[100];
    printf("Enter a file name to load student scores: ");
    scanf(" %s", file_path);
    FILE *input, *output;
    input = fopen(file_path,"r");
    int i = 0;
    while (fscanf(input,"%s %d", student[i].name, &student[i].score) != EOF) i++;
    for(int j = 0; j < i; j++){
        printf("Student %d: %s, Score = %d \n", j+1, student[j].name, student[j].score);
    }

    while(1){
        char new_name[10];
        int new_score;
        printf("Enter new student name (type “END” to sort student score and end the program):");
        scanf(" %s", new_name);
        if(strcmp(new_name,"END") == 0)break;
        strcpy(student[i].name,new_name);
        printf("Enter %s’s score: ", student[i].name);
        scanf(" %d", &new_score);
        student[i].score = new_score;
        i++;
    }
    fclose(input);

    printf("---------------Sort students by scores---------------\n");
    output = fopen(file_path,"w");
    selectionSort(student , i);
    for(int j = 0; j < i; j++){
        printf("Student %d: %s, Score = %d \n", j+1, student[j].name, student[j].score);
        fprintf(output, "%s %d \n",student[j].name, student[j].score);
    }
    
    fclose(output);
    printf("End of program. Goodbye.\n");
}