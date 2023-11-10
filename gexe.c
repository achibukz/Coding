#include<stdio.h>

void deposit(float *fMoney){
    int nChecker1 = 1;
    int nDepMoney, nCheck;

    nCheck = nDepMoney % 100;

    while(nChecker1 != 0){
            printf("Deposited Money: \n");
            scanf("%d", &nDepMoney);
        if (nCheck == 0){
            *fMoney += nDepMoney;
            nChecker1 = 0;
        }
        else{
            printf("It is an ivalid amount. Please try again.\n");
        }
    }
}

void DisplayMenu(){
    int nCase;
    int nChecker = 1;
    float fMoney = 10000.00;

    while(nChecker != 0){
        printf("Select Option:\n");
        printf("1: Deposit\n");
        printf("2: Withdraw\n");
        printf("3: Check Balance\n");
        printf("Option: ");
        scanf("%d", &nCase);

        switch(nCase){
            case 1:
                deposit(&fMoney);
                nChecker = 0;
                break;
            case 2:
                withdraw(&fMoney);
                nChecker = 0;
                break;
            case 3:
                checkBalance(&fMoney);
                nChecker = 0;
                break;
            case 4:
                printf("Shut Down.....\n");
                nChecker = 0;
                break;
            default:
                printf("Invalid Input.");
                break;
        }

    }
}



int main(){
    DisplayMenu();

    return 0;
}