#include<stdio.h>

void biggerNuke(int arr[][100], int targetRow, int targetColumn, int row, int column){

    arr[targetRow][targetColumn] = -1;
    if(targetRow != row - 1)
        arr[targetRow + 1][targetColumn] = -1;
    if(targetRow != 0)
        arr[targetRow - 1][targetColumn] = -1;
    if(targetColumn != column - 1)
        arr[targetRow][targetColumn + 1] = -1;
    if(targetRow != 0)
        arr[targetRow][targetColumn - 1] = -1;
}


int main(){

    int i, j;
    int arr[8][8];

    for (i = 0; i < 8; i++){
        for (j = 0; j < 8; j++){
            arr[i][j] = j + 1;
        }
    }


    biggerNuke(arr, 4, 3, 8, 8);

    for (i = 0; i < 8; i++){
        for (j = 0; j < 8; j++){
            printf("[%d] ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}