#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// โครงสร้างข้อมูลสำหรับนักเรียน
typedef struct {
    char name[10]; //ชื่อ
    int score;    //คะแนน
} student_info;

//ฟังก์ชั่น insertSort
void insertionSort(student_info *num_student, int num) {
    for (int i = 1; i < num; i++) {
        student_info key = num_student[i];
        int j = i - 1;
        while (j >= 0 && num_student[j].score > key.score) {
            num_student[j + 1] = num_student[j];
            j = j - 1;
        }
        num_student[j + 1] = key;
    }
}

int main() {
    char file_path[100];
    int i = 0, num;

    printf("Enter a number of students in the class: ");
    scanf("%d", &num);

    // จองหน่วยความจำให้ student_info
    student_info *num_student = (student_info *)malloc(num * sizeof(student_info));
    if (num_student == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter a file name to load student scores: ");
    scanf(" %s", file_path);
    //ประกาศ Pointer input
    FILE *input = fopen(file_path, "r");
    if (input == NULL) {
        printf("Failed to open the file.\n");
        free(num_student);
        return 1;
    }

    // อ่านข้อมูลจากไฟล์ลงใน num_student
    while (fscanf(input, "%s %d", num_student[i].name, &num_student[i].score) != EOF) i++;
    fclose(input);

    for (int j = 0; j < i; j++) {
        printf("Student %d: %s, Score = %d\n", j + 1, num_student[j].name, num_student[j].score);
    }

    num = i;
    //รับข้อมูลนักเรียนใหม่
    while (1) {
        char new_name[10];
        int new_score;

        printf("Enter new student name (type \"END\" to sort student score and end the program): ");
        scanf(" %s", new_name);
        if (strcmp(new_name, "END") == 0) break;

        printf("Enter %s’s score: ", new_name);
        scanf(" %d", &new_score);

        // เพิ่มขนาดหน่วยความจำให้ข้อมูลใหม่
        num_student = (student_info *)realloc(num_student, (num + 1) * sizeof(student_info));
        if (num_student == NULL) {
            printf("Memory reallocation failed.\n");
            return 1;
        }
        
        strcpy(num_student[num].name, new_name);
        num_student[num].score = new_score;
        num++;
    }

    printf("---------------Sort students by scores---------------\n");
    //จัดข้อมูล
    insertionSort(num_student, num);
    //แสดงผลนักเรียนที่จัดเรียงแล้ว
    for (int j = 0; j < num; j++) {
        printf("Student %d: %s, Score = %d\n", j + 1, num_student[j].name, num_student[j].score);
    }

    //คืนค่า memory ที่จอง
    free(num_student);
    printf("End of program. Goodbye.\n");

    return 0;
}
