#include<stdio.h>

int main() {

    float nPerimeter;
    float nLength;
    float nBaseArea;
    float nSa;

    printf("Enter Square Perimeter:  ");
    scanf("\n%f", &nPerimeter);
    printf("Enter Slant Legth:  ");
    scanf("\n%f", &nLength);
    printf("Enter Base Area:  ");
    scanf("\n%f", &nBaseArea);

    nSa = 0.5 * nPerimeter * nLength + nBaseArea;
    printf("\nSurface Area:  ");
    printf("%d", nSa);


    return 0;
}