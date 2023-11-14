#include<stdio.h>

int main(){
    int i,j,s,rows;

    printf("How many rows: ");
    scanf("%d", &rows);

    for(i = 1; i <= rows; i++){
        j = 0;

        for(s = 1; s <= rows - i; s++){
            printf("  ");
        }
        while(j != 2*i - 1){
            printf("* ");
            j++;
        }

        printf("\n");
    }

    return 0;
}

