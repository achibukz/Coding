#include <stdio.h>

void deposit(float amt, float* bal){
    *bal += amt;
}

int main() {
    float bal = 10000, amt;

    printf("How much will you deposit? ");
    scanf("%f", &amt);

    deposit(amt, &bal);

    printf("Your new balance is %.2f.", bal);

    return 0;
}