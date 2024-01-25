#include<stdio.h>

int isMagicSquare(int square[][100], int s){
    int i, j;
    int totalRow = 0;
    int totalCol = 0;
    int totalDia = 0;

    for(i = 0; i < s; i++){
        for(j = 0; j < s; j++){
            totalRow += square[i][j];
        }
    }
    totalRow /= 3;

    printf("%d\n", totalRow);

    for(i = 0; i < s; i++){
        for(j = 0; j < s; j++){
            totalCol += square[j][i];
        }
    }
    totalCol /= 3;

    printf("%d\n", totalCol);

    for(i = 0; i < s; i++){
        for(j = 0; j < s; j++){
            if(i == j){
                totalDia += square[i][j];
            }
        }
    }

    for(i = 0; i < s; i++){
        for(j = 0; j < s; j++){
            if(i + j == s - 1){
                totalDia += square[i][j];
            }
        }
    }
    totalDia /= 2;

    printf("%d\n", totalDia);

    if(totalRow == totalCol && totalCol == totalDia){
        printf("Is Magic Square\n");
        return 1;
    }
    else{
        printf("Is NOT Magic Square\n");
        return 0;
    }

}


int main(){
    int square[100][100] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int square2[100][100] = {{1,1,1}, {1,1,1}, {1,1,1}};

    printf("%d\n", isMagicSquare(square, 3));

    return 0;
}