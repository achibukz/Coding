#include<stdio.h>

void mul(){
    int x;

    x = 2;
    test(x);
}

void test(int* x){
    *x *= 2;

    printf("%d", x);
}


int main(){

    mul();

    return 0;
}