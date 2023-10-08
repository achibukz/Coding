#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL));
    int x, y;

    x = rand() % 100 + 1;
    y = 50;

    if(x <= y){
        printf("%d\n", x);
        printf("You hit a critical!");
    }
    else{
        printf("%d\n", x);
        printf("No Critical");
    }

    return 0;
}