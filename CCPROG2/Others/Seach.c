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

// Function to perform binary search on a sorted 2D array
int binarySearch2D(int matrix[][4], int rows, int cols, int target) {
    int low = 0, high = rows * cols - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int midValue = matrix[mid / cols][mid % cols];
        if (midValue == target)
            return mid; // Element found
        else if (midValue < target)
            low = mid + 1; // Search in the right half
        else
            high = mid - 1; // Search in the left half
    }
    return -1; // Element not found
}


int main(){



    return 0;
}