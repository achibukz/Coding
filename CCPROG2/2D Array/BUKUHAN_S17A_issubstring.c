#include <stdio.h>
#include <string.h>

int isSubstring(char A[], char B[]) {
    int lenA = strlen(A);
    int lenB = strlen(B);
    int i;
    int j = 0;


    for (i = 0; i <= lenB - lenA; i++) {
        while (j < lenA && B[i + j] == A[j]) {
            j++;
        }
        if (j == lenA) {
            return 1;
        }
    }

    return 0;
}

