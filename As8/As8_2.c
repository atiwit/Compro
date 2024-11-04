#include <stdio.h>
#include <string.h>

FILE *input, *output;   //ประกาศ pointer
int score[10];// สร้าง array socre
char name[10][10];//สร้าง array name ไม่เกิน9อักษร จำนวน 10 คำ
int i = 0;

void swap(int *x, int *y) //ฟังก์ชั่นสลับตัว
{ 
    int tmp = *x; 
    *x = *y; 
    *y = tmp; 
} 
 
void selectionSort(int data[], int count) //ฟังก์ชันจัดเรียงคำใหม่
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
    char txt[10];//ประกาศ array txt ไม่เกิน9ตัว
    char ans_name[20];//ประกาศ array ans_name ไม่เกิน19ตัว
    int ans_score;

    printf("Enter a file name to load student scores: ");
    scanf("%s", txt);//รับค่า string ลงไปที่ array txt

    input = fopen(txt, "r"); //ให้ input คือเปิดไฟล์ที่ชื่อเดียวกับ array txt ที่รับมาโหมด อ่าน
    output = fopen(txt, "a");//ให้ input คือเปิดไฟล์ที่ชื่อเดียวกับ array txt ที่รับมาโหมด เพิ่ม

    if (input == NULL || output == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(input, "%s %d", name[i], &score[i]) != EOF && i < 10) { //ให้ทำการ loop ค้นหาค่า name และ score
        i++;
    }
    fclose(input);

    for (int j = 0; j < i; j++) { //ให้พิมพ์ค่าname และ scoreที่ได้จากการ loop
        printf("Student %d: %s, Score = %d\n", j + 1, name[j], score[j]);
    }

    while (1) {
        printf("Enter new student name (type 'END' to sort student score and end the program): ");
        scanf("%s", ans_name);//รับค่า string จาก user เข้า array ans_name 

        if (strcmp(ans_name, "END") == 0) { //ถ้า ans_name มีคำว่า END ให้หยุด
            break;
        }

        printf("Enter %s's Score: ", ans_name); 
        scanf("%d", &ans_score);    //รับค่า score จาก user

        if (i < 10) { //ถ้า i < 10
            strcpy(name[i], ans_name); //ใช้ฟังก์ชัน strcpy name[i] กับ ans_name
            score[i] = ans_score;   //ให้ scoreตัวที่ i = ans_score
            fprintf(output, "\n%s %d", ans_name, ans_score);//ส่งค่าลง output
            i++;
        } 
    }
    fclose(output);

    selectionSort(score, i);    //เรียงลำดับใหม่

    printf("--------------- Sorted students by scores ---------------\n");
    for (int j = 0; j < i; j++) {
        printf("Student %d: %s, Score = %d\n", j + 1, name[j], score[j]);
    }

    printf("End of program. Goodbye.\n");
    return 0;
}
