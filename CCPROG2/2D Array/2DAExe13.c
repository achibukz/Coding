#include <stdio.h>

int main(){
    int n;

    do{
        printf("Pick a number from 2 to 10: ");    
        scanf("%d", &n);
    }
    while((n < 2) || (n > 10));

    printf("Number: %d", n);

    return 0;
}