#include<stdio.h>

void Change(int *hp, int *atk,int *def,int *spd){

    printf("HP: ");
    scanf("%d", hp);
    printf("ATK: ");
    scanf("%d", atk);
    printf("DEF: ");
    scanf("%d", def);
    printf("SPD: ");
    scanf("%d", spd);
}

int main(){
    int hp = 100;
    int atk = 10;
    int def = 10;
    int spd = 10;
    float Cr = 0.15;

    Change(&hp, &atk, &def, &spd);

    printf("New\n");
    printf("HP: %d\n", hp);
    printf("ATK: %d\n", atk);
    printf("DEF: %d\n", def);
    printf("SPD: %d\n", spd);
    printf("Crit Rate: %.2f\n", Cr);

    return 0;
}