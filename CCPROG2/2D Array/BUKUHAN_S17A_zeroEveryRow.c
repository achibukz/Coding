#include <stdio.h>

int zeroEveryRow(int arr[][100], int row, int column){
    int i,j;
    int count1 = 0;
    int count2 = 0;

    for (i = 0; i < row; i++){
        count2 = 0;
        for (j = 0; j < column; j++){
            if (arr[i][j] == 0){
                count2++;
                if (count2 > 1){
                    count2 = 1;
                }
            }
        }
        count1 += count2;
    }

    if (count1 == row){
        return 1;
    }
    else{
        return 0;
    }
}