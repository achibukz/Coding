#include <stdio.h>

int linearSearch(int list[], int key, int n){
    int i;

    for (i = 0; i < n; i++){
        if (list[i] == key){
            return i;
        }
    }

    return -1;
}

int binarySearch(int key, int A[], int n){
    int low = 0;
    int high = n - 1;
    int mid;
    int found = 0;

    while (!found && low <= high){
        mid = low + (high - low)/2; // (low + high) / 2

        if (key == A[mid]) // found
            found = 1;
        else if (key < A[mid]) // search lower half
            high = mid - 1;
        else // search upper half
            low = mid + 1;
    }

    if (found)
        return mid;
    else
        return -1;
}


int main(){



    return 0;
}