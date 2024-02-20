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

int main() {
    // Test cases
    printf("%d\n", isSubstring("STAR", "HEADSTART")); // Output: 1
    printf("%d\n", isSubstring("RAIN", "RAINBOW"));   // Output: 1
    printf("%d\n", isSubstring("ANA", "BANANA"));     // Output: 1
    printf("%d\n", isSubstring("CCPROG", "CCPROG"));  // Output: 1
    printf("%d\n", isSubstring("XYZ", "ABCDEF"));     // Output: 0

    return 0;
}
