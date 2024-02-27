#include <stdio.h>

void swap(int *x, int *y){
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSortAscending1(int arr[], int n){
    int i, j, min;

    for (i = 0; i < n - 1; i++){
        min = i; // min is the lowest element

        for (j = i + 1; j < n; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }

        if (i != min)
            swap(&arr[i], &arr[min]);
    }

}
void selectionSortAscending2(int arr[], int n){
    int i, j, min, temp;

    for (i = 0; i < n -1; i++){
        min = i; // min is the lowest element

        for (j = i + 1; j < n; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

}

void selectionSort2D(int matrix[][4], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols - 1; j++) {
            // Find the minimum element in the unsorted part
            int min_index = j;
            for (int k = j + 1; k < cols; k++) {
                if (matrix[i][k] < matrix[i][min_index]) {
                    min_index = k;
                }
            }
            // Swap the found minimum element with the first element
            swap(&matrix[i][min_index], &matrix[i][j]);
        }
    }
}

// Not Yet Fixed
void selectionSortDescending(int arr[], int n){
    int i, j, max, temp;

    for (i = 0; i < n -1; i++){
        max = i; // min is the lowest element

        for (j = i + 1; j < n; j++){
            if (arr[j] < arr[max]){
                max = j;
            }
        }

        temp = arr[max];
        arr[i] = arr[max];
        arr[max] = temp;
    }
}

// Sorting Characters

// Sorting Strings

int main(){
    int i;
    int arr[10] = {15, 1, 7, 6, 54, 94, 62, 32, 2, 4};

    selectionSortAscending1(arr, 10);

    for (i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}