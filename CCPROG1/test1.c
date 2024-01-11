#include<stdio.h>

void test(int* x){
    *x = 10 + *x;
}

void test2(int* x){
    *x = 10 + *x;
}


int main() {
    int amt;
    scanf("%d", &amt);
    
    test(&amt);
    test2(&amt);
    
    printf("%d", amt);
    return 0;
}

// How to compile
// gcc -Wall -std=c99 hello.c -o hello
// -o -> specifies the name
// -std=c99 -> version of C
// -Wall -> Show warnings and Errors