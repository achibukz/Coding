#include<stdio.h>

void DevMode(){
    int p1hp, p1atk, p1def, p1spd;
    float p1Cr;
    int p2hp, p2atk, p2def, p2spd;
    float p2Cr;

    printf("You are now in Dev Mode\nYou are now allowed to manipulate the stats of both the opponent and yourself.\nEntering this mode will skip the equipment picking phase for both players. Have Fun.");

    printf("Your HP: ");
    scanf("%d", &p1hp);
    printf("Your ATK: ");
    scanf("%d", &p1atk);
    printf("Your DEF: ");
    scanf("%d", &p1def);
    printf("Your SPD: ");
    scanf("%d", &p1spd);
    printf("Your Crit Rate: ");
    scanf("%f", &p1Cr);

    printf("Opponent's HP: ");
    scanf("%d", &p2hp);
    printf("Opponent's ATK: ");
    scanf("%d", &p2atk);
    printf("Opponent's DEF: ");
    scanf("%d", &p2def);
    printf("Opponent's SPD: ");
    scanf("%d", &p2spd);
    printf("Opponent's Crit Rate: ");
    scanf("%f", &p2Cr);
}

void EquipPickPhase(){
    int nP1hp = 100;
    int nP1atk = 10;
    int nP1def = 10;
    int nP1spd = 10;
    float fP1Cr = 0.15;

    int nP2hp = 100;
    int nP2atk = 10;
    int nPp2def = 10;
    int nP2spd = 10;
    float fP2Cr = 0.15;

 
}

int DisplayMenu(){
    int nCase;
    int nChecker = 1;

    while(nChecker != 0){
        printf("Select Option:\n");
        printf("1: Normal Mode\n");
        printf("2: Developer Mode\n");
        printf("3: Exit\n");
    }

    switch(nCase){
        case 1:
            EquipPickPhase();
            break;
        case 2:
            DevMode();
            break;
        case 3:
            printf("Shut Down.....\n");
            nChecker = 0;
            break;
        case 4:
            printf("Invalid Input.");
            break;

    }

}

int main(){
    DisplayMenu();

    return 0;
}