#include <stdio.h>

FILE *input, *output; //ประกาศ pointer
int score[10];// สร้าง array socre
char name[10][10];//สร้าง array name ไม่เกิน9อักษร จำนวน 10 คำ
int i = 0;
void swap(int *x, int *y)   //ฟังก์ชั่นสลับตัว
{ 
    int tmp = *x;
    *x = *y; 
    *y = tmp; 
} 
 
void selectionSort(int data[], int count) //ฟังก์ชันจัดเรียงคำใหม่
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
    char txt[10];   //ประกาศ array txt ไม่เกิน10ตัว
    int avg,max,min;
    printf("Enter a file name to load student scores: ");
    scanf("%s", txt);   //รับค่า string ลงไปที่ array txt

    input = fopen(txt, "r");    //ให้ input คือเปิดไฟล์ที่ชื่อเดียวกับ array txt ที่รับมาโหมด อ่าน
    if (input == NULL) {
        printf("Error: Could not open file %s\n", txt);
        return 1;
    }

    output = fopen("stat.txt", "w");//ให้ output สร้างไฟล์ที่ชื่อ stat.txt โหมดเขียน
    if (output == NULL) {
        printf("Error: Could not open file stat.txt\n");
        fclose(input);
        return 1;
    }

    while (fscanf(input, "%s %d", name[i], &score[i]) != EOF) { //ให้ทำการ loop ค้นหาค่า name และ score
        i++;
    }

    for (int j = 0; j < i; j++) {   //ให้พิมพ์ค่าname และ scoreที่ได้จากการ loop
        printf("Student %d: %s, Score =  %d\n", j+1,name[j], score[j]);
    }
    for(i=0;i <= 5;i++){
        avg += score[i];
    }
    selectionSort(score,5);//เรียงจากน้อยไปมาก
    min = score[0]; //ให้ min = ตัวแรกของ array
    max = score[4]; //ให้ max = ตัวสุดท้ายของ array
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
