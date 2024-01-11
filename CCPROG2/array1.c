#include<stdio.h>

int main(){

    float grdList[100];
    int i, x;

    printf("How many students do you have? ");
    scanf("%d", &x);

    for(i = 0; i < x; i++){
        printf("Enter Grade of Student %d: ", i + 1);
        scanf("%f", &grdList[i]);
    }

    for(i = 0; i < x; i++){
        printf("The Grade of Student %d:%.2f\n", i + 1 , grdList[i]);
    }

    return 0;
}