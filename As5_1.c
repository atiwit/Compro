// 67070501048 Atiwit Thongngoen
#include <stdio.h>


int main()
{
    int i = 0,j,index = 0,size= 10,count = 0;
    int score[size];
    printf("Enter student scores (type -1 to start calculation)\n");
    for (j = 0; j < size; j++)
    {
        printf("Enter score of student %d: ", j + 1);
        scanf("%d", &score[j]);
        if (score[j] == -1)
        {
            break;
        }
        count++;
    }
    //findMin
    if (count > 0)
    {
        for(i = 1; i < count; i++){
            if(score[i] < score[index]) {
                index = i;
            }
        }
    }
    printf("The minimum score is %d.\n",score[index]);
    printf("Student %d has minimum score.",index +1);

}