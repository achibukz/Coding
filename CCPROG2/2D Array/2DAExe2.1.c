#include<stdio.h>

int main(){

    int i, j;
    int arr[4][3];
    int cnt = 1;

    for (i = 0; i < 4; i++){
        for (j = 0; j < 3; j++){
            arr[i][j] = cnt;
            cnt++;
        }
        cnt = 1;
    }

    for (i = 0; i < 4; i++){
        for (j = 0; j < 3; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}