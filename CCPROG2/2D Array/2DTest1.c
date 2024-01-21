#include <stdio.h>

int callMe(int numElements, int list[]){
    int i;
    int even = 0;
    for (i = 0; i <=  numElements - 1; i++){
        if (list[i] % 2 == 0){
            even++;
        }
        return even;
    }

}

int main(){

    int arr[6] = {1,2,3,4,5,6};
    int elem = 6;
    int x;

    x = callMe(elem, arr);

    printf("%d", x);

    return 0;
}