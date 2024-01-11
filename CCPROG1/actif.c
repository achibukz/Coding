#include<stdio.h>

int main(){
    int num;
    printf("Pick a Number from 1-3: ");
    scanf("%d",&num);

    if(num == 1){
        printf("Red");
    }
    else if(num == 2){
        printf("Yellow");
    }
    else if(num == 3){
        printf("Red");
    }


    return 0;
}