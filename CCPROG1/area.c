#include<stdio.h>
#include<math.h>

int main() {

    float nSide;
    float nThree;
    float nArea;

    printf("Enter Side:  ");
    scanf("\n%f", &nSide);
    
    nThree = sqrt(3);
    nArea = (nThree / 4) * pow(nSide, 2);

    printf("\nArea:  ");
    printf("%.2f", nArea);

    return 0;
}