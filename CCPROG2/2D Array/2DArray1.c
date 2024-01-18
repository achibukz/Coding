#include<stdio.h>

int main(){

    int i, j;
    int arr[3][3];
    char arr2[2][4];

    char crntLetter = 'A';

    for (i = 0; i < 2; i++){

        for (j = 0; j < 4; j++){
            arr2[i][j] = crntLetter;
            crntLetter++;
        }
    }

    for (i = 0; i < 2; i++){

        for (j = 0; j < 4; j++){
            
            printf("%c ", arr2[i][j]);

        }

        printf("\n");
    }


    return 0;
}