#include<stdio.h>

int main() {

    float nPrice;
    float nRate;
    float nBefore;
    float nTax;

    printf("Enter Item Price:  ");
    scanf("\n%f", &nPrice);
    printf("Enter Tax Rate:  ");
    scanf("\n%f", &nRate);
    
    nRate = nRate / 100;
    nTax = nPrice * nRate;
    nBefore = nPrice - nTax;

    printf("\nBefore Tax:  ");
    printf("%.2f", nBefore);
    printf("\nTax:  ");
    printf("%.2f", nTax);
    printf("\nTotal:  ");
    printf("%.2f", nPrice);


    return 0;
}