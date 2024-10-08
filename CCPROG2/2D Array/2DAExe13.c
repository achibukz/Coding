#include <stdio.h>

int main(){
    int n, i, j;
    int multi = 1;
    int inmul;
    int x;
    int arr[10][10];

    do{
        printf("Pick a number from 2 to 10: ");    
        scanf("%d", &n);
    }
    while((n < 2) || (n > 10));

    printf("Number: %d\n", n);

    for (i = 0; i < n; i++){
        inmul = 2;
        for (j = 0; j < n; j++){
            arr[i][j] = j + 1 * multi;
            if(i != 0 && j != 0){
                arr[i][j] = multi;
                arr[i][j] *= inmul;
                inmul++;
            }
        }
        multi++;
    }

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("[%2d] ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}