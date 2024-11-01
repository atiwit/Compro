#include <stdio.h>

int main() {
    int row1,col1,row2,col2;
    int M1[100][100];
    int M2[100][100];
    int Ma[100][100];
    printf("Matrix Addition\n");
    printf("Enter matrix dimension of M1 (rows columns): ");
    scanf("%d %d", &row1,&col1);
    // M1
    printf("Enter M1 matrix elements:\n");
    for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++){
            scanf("%d", &M1[i][j]);
        }
    }
    printf("Enter matrix dimension of M2 (rows columns): ");
    scanf("%d %d", &row2,&col2);
    // M2
    printf("Enter M2 matrix elements:\n");
    for(int i=0;i<row2;i++){
        for(int j=0;j<col2;j++){
            scanf("%d", &M2[i][j]);
        }
    }
    // add value Ma
    if(row1 == row2 && col1 == col2) {
        for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++){
            Ma[i][j] = M1[i][j] + M2[i][j];
        }
    }
    printf("Resultant of Matrix Ma (M1 + M2):\n");
    for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++){
            printf("%d ", Ma[i][j]);
        }
        printf("\n");
    }
    } else {
        printf("Invalid matrices dimension. The 2 matrices must have the same dimension.");

    }
    // show Ma
    return 0;
}