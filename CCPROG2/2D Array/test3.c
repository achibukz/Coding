#include<stdio.h>

int mysteryAdd(int list[4][4]){
    int i, j;
    int acc = 0;

    for(i = 0; i < 4; i++){
        for(j = 0; j <4; j++){
            if (j > i){
                acc += list[i][j];
            }
        }
    }

    return acc;
}


int main(){
    int arr[4][4] = {{1,2,3,4}, {1,2,3,4}, {4,3,2,1}, {4,3,2,1}};
    int x;

    x = mysteryAdd(arr);

    printf("%d", x);




    return 0;
}