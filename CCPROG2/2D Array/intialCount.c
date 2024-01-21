#include<stdio.h>


int main(){

    int i, j;
    int arr[10][10];
    int multi1 = 1;
    int multi2 = 1;
    int n = 8;

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (i != 0 && j != 0){
                arr[i][j] -= 1;
                arr[i][j] *= multi2;
            }
            else{
                arr[i][j] = j + 1 * multi1;
            }
            multi2++;
        }
        multi1++;
    }

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("[%d] ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}