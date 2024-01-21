#include <stdio.h>

int checkIncreasing(int arr[], int elem){
    int i;
    int temp = 0;
    int check = 0;
    
    for(i = 0; i < elem - 1; i++){
        if(i > 0){
            arr[i - 1] = temp;
        }
        if(arr[i] < temp){
            check++;
        }
    }

    return check;
}


int main(){
    int arr[5] = {1,4,3,6,5};
    int elem = 5;
    int x;

    x = checkIncreasing(arr, elem);

    printf("%d", x);

    return 0;
}