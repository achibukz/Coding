#include <stdio.h>

int checkIncreasing(int arr[], int elem){
    int i;
    int check = 1;
    
    for(i = 1; i < elem; i++){
        if(arr[i] <= arr[i - 1]){
            check = 0;
            break;
        }
    }

    return check;
}