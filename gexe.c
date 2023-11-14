#include <stdio.h>
 
void checkBalance(float *fMoney){
    printf("Balance: %.2f\n", *fMoney);
}
 
void withdraw(float *fMoney) {
    int nAmount, nOneThousand, nOTRemain, nFiveHundred, nFHRemain, nTwoHundred, nTHRemain, nOneHundred;
 
    do {
        printf("How much money do you want to withdraw: ");
        scanf("%d", &nAmount);
 
        if (nAmount > *fMoney) {
            printf("Withdrawal amount is greater than current money in the bank\n");
        }
        else if (nAmount % 100 != 0) {
            printf("Withdrawal amount must be divisible by 100\n");
        }
    }
    while (nAmount % 100 != 0 || nAmount > *fMoney);
 
 
    *fMoney -= nAmount;
 
    printf("You have withdrawn P%d\n", nAmount);
    nOneThousand = nAmount / 1000;
    nOTRemain = nAmount - (1000 * nOneThousand);
    
    nFiveHundred = nOTRemain / 500;
    nFHRemain = nOTRemain - (500 * nFiveHundred);
    
    nTwoHundred = nFHRemain / 200;
    nTHRemain = nFHRemain - (200 * nTwoHundred);
 
    nOneHundred = nTHRemain / 100;
 
    printf("P 1000: %d\n", nOneThousand);
    printf("P 500: %d\n", nFiveHundred);
    printf("P 200: %d\n", nTwoHundred);
    printf("P 100: %d\n", nOneHundred);
}
 
void deposit(float *fMoney){
    int nDepMoney;
    
    do {
        printf("How much money do you want to deposit: ");
        scanf("%d", &nDepMoney);
 
        if (nDepMoney % 100 != 0) {
            printf("Deposited amount must be divisible by 100\n");
        }
    }
    while (nDepMoney % 100 != 0);

    *fMoney += nDepMoney;
}
 
void displayMenu(float *fMoney, int *nExit){
    int nCase;
 
    printf("Select Option:\n");
    printf("1: Deposit\n");
    printf("2: Withdraw\n");
    printf("3: Check Balance\n");
    printf("4: Exit\n");
    printf("Option: ");
    scanf("%d", &nCase);

    switch(nCase){
        case 1:
            deposit(fMoney);
            break;
        case 2:
            withdraw(fMoney);
            break;
        case 3:
            checkBalance(fMoney);
            break;
        case 4:
            printf("Shut Down.....\n");
            *nExit = 1;
            break;
        default:
            printf("Invalid Input.\n");
            break;
    }
 
    
}
  
int main(){     
    int nExit;
    float fMoney;

    fMoney = 10000.00;
    nExit = 0;
    while (nExit != 1) {
        displayMenu(&fMoney, &nExit);
    }
    return 0;
}