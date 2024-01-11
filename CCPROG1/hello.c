#include<stdio.h>

int main(){
    
float fFuck;

printf("Amount: ");
scanf("%d", &fFuck);

float fTax = fFuck * 0.12;
float fTotal = fFuck + fTax;

printf("Tax: %f\n", fTax);
printf("Total: %f", fTotal);

    return 0;
}