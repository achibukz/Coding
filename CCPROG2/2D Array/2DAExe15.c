#include <stdio.h>


void ave(float A[][100], float B[], int n, int m){
    int i,j;
    float count;
    float ave;

    for(i = 0; i < n; i++){
        ave = 0;
        for(j = 0; j < m; j++){
            count += A[i][j];
        }
        ave = count / m;
        B[i] = ave;
    }
}


int main(){

    int i;
    float arr1[100][100] = {{1,2,3,4}, {0,0,0,0}, {1,1,1,1}};
    float arr2[100];

    ave(arr1, arr2, 3, 4);

    for(i = 0; i < 3; i++){
        printf("%.2f\n", arr2[i]);
    }

    return 0;
}