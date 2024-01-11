#include<stdio.h>

int Thousand(int x){
    int y;
    y = x / 1000;

    return y;
}

int FiveHund(int x){
    int y;
    y = x / 500;

    return y;
}

int TwoHund(int x){
    int y;
    y = x / 200;

    return y;
}

int OneHund(int x){
    int y;
    y = x / 100;

    return y;
}

int Fifty(int x){
    int y;
    y = x / 50;

    return y;
}

int Twenty(int x){
    int y;
    y = x / 20;

    return y;
}

int Ten(int x){
    int y;
    y = x / 10;

    return y;
}

int Five(int x){
    int y;
    y = x / 5;

    return y;
}

int One(int x){
    int y;
    y = x / 1;

    return y;
}

int main(){

    int nAmount, nThousand, nThRet, nFiveHund, nFhRet, nTwoHund, nTwRet, nOneHund, nOhRet, nFifty, nFRet, nTwent, nTRet, nTen, nTeRet, nFive, nFiRet, nOne;

    printf("Amount: ");
    scanf("%d", &nAmount);

    nThousand = Thousand(nAmount);
    nThRet = nAmount - (nThousand * 1000);

    nFiveHund = FiveHund(nThRet);
    nFhRet = nThRet - (nFiveHund * 500);

    nTwoHund = TwoHund(nFhRet);
    nTwRet = nFhRet - (nTwoHund * 200);

    nOneHund = OneHund(nTwRet);
    nOhRet = nTwRet - (nOneHund * 100);

    nFifty = Fifty(nOhRet);
    nFRet = nOhRet - (nFifty * 50);

    nTwent = Twenty(nFRet);
    nTRet = nFRet - (nTwent * 20);

    nTen = Ten(nTRet);
    nTeRet = nTRet - (nTen * 10);

    nFive = Five(nTeRet);
    nFiRet = nTeRet - (nFive * 5);

    nOne = One(nFiRet);

    printf("P1000: %d\n", nThousand);
    printf("P500: %d\n", nFiveHund);
    printf("P200: %d\n", nTwoHund);
    printf("P100: %d\n", nOneHund);
    printf("P50: %d\n", nFifty);
    printf("P20: %d\n", nTwent);
    printf("P10: %d\n", nTen);
    printf("P5: %d\n", nFive);
    printf("P1: %d\n", nOne);
    
    return 0;
}