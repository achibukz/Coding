#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL));

    int x;
    x = rand() % 4 + 1;

    printf("%d", x);

    return 0;
}