#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
    srand(time(NULL));

    int nP2Action = rand() % 3 + 1;
    
    printf("%d\n", nP2Action);
    
    return 0;
}