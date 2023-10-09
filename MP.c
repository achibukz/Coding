/******************************************************************
This is to certify that this project is my own work, based on my personal efforts in studying and
applying the concepts learned. I have constructed the functions and their respective algorithms
and corresponding code by myself. The program was run, tested, and debugged by my own efforts. I
further certify that I have not copied in part or whole or otherwise plagiarized the work of other
students and/or persons.
Abram Aki R. Bukuhan, DLSU ID# 12313467
******************************************************************/

/*
    Description:
    Programmed by: Abram Aki R. Bukuhan
    Last modified: October 8, 2023
    Version: 0.1
    [Acknowledgements: ]
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>

void BattlePhase(int* nP1hp,int* nP1atk, int* nP1def, int* nP1spd, int* nP1Cr , int* nP2hp, int* nP2atk, int* nP2def, int* nP2spd,int* nP2Cr){
    srand(time(NULL));


}

/*
    This Function changes the values of each stat of each player. It also
    ignores the Equipment Picking Phase and goes straight to the Battle Phase.
*/
void DevMode(){
    int nP1hp, nP1atk, nP1def, nP1spd, nP1Cr;
    int nP2hp, nP2atk, nP2def, nP2spd, nP2Cr;

    printf("You are now in Dev Mode\nYou are now allowed to manipulate the stats of both the opponent and yourself.\nEntering this mode will skip the equipment picking phase for both players. Have Fun.\n");
    printf("\n For the Critical Rate. Use Percent Form\n");

    printf("Your HP: ");
    scanf("%d", &nP1hp);
    printf("Your ATK: ");
    scanf("%d", &nP1atk);
    printf("Your DEF: ");
    scanf("%d", &nP1def);
    printf("Your SPD: ");
    scanf("%d", &nP1spd);
    printf("Your Crit Rate: ");
    scanf("%d", &nP1Cr);

    printf("Opponent's HP: ");
    scanf("%d", &nP2hp);
    printf("Opponent's ATK: ");
    scanf("%d", &nP2atk);
    printf("Opponent's DEF: ");
    scanf("%d", &nP2def);
    printf("Opponent's SPD: ");
    scanf("%d", &nP2spd);
    printf("Opponent's Crit Rate: ");
    scanf("%d", &nP2Cr);

    printf("You have finished setting up your stats. Opening Battle Phase........");
    BattlePhase(nP1hp, nP1atk, nP1def, nP1spd, nP1Cr, nP2hp, nP2atk, nP2def, nP2spd, nP2Cr);
}

/*
    This function lets the player choose what Weapon and Equipment
    they want to use for the battle. It also lets the opponent randomly
    pick what Weapon and Equipment they will use too.
*/
void EquipPickPhase(){
    srand(time(NULL));

    int nP1hp = 100;
    int nP1atk = 10;
    int nP1def = 10;
    int nP1spd = 10;
    int nP1Cr = 15;

    int nP2hp = 100;
    int nP2atk = 10;
    int nP2def = 10;
    int nP2spd = 10;
    int nP2Cr = 15;


    char cP1Weapon[20], cP1Equip[20], cP2Weapon[20], cP2Equip[20];
    int nWCase, nECase;
    int nWRand = rand() % 4 + 1;
    int nERand = rand() % 4 + 1;

    printf("\nWelcome to the Equipment Picking Phase.\n You and your Opponent will pick ONE Weapon and ONE Armor each before the Battle Phase.\n Choose your weapons wisely. ");
    printf("Press the Number of your desired weapon of choice.");
    printf("\n\nWeapons: \n\n");
    printf("1: Dagger = ATK +15, SPD +3\n");
    printf("2: Katana = ATK +20\n");
    printf("3: Broad Sword = ATK +40, SPD -5\n");
    printf("4: Fist (No Weapon) = SPD +10\n\n");
    printf("What is your choice? ");
    scanf("%d", &nWCase);

    switch(nWCase){
        case 1:
            nP1atk = nP1atk + 15;
            nP1spd = nP1spd + 3;
            printf("You have chosen 'Dagger'.");
            strcpy(cP1Weapon, "Dagger");
            break;
        case 2:
            nP1atk = nP1atk + 20;
            printf("You have chosen 'Katana'.");
            strcpy(cP1Weapon, "Katana");
            break;
        case 3:
            nP1atk = nP1atk + 40;
            nP1spd = nP1spd - 5;
            printf("You have chosen 'Broad Sword'.");
            strcpy(cP1Weapon, "Broad Sword");
            break;
        case 4:
            nP1spd = nP1spd + 10;
            printf("You have chosen 'Fist(No Weapon)'.");
            strcpy(cP1Weapon, "Fist (No Weapon)");
            break;
    }

    printf("\n\nEquipments: \n\n");
    printf("1: Mythril = DEF +3, SPD +3\n");
    printf("2: Chain Mail = DEF +8, HP +5\n");
    printf("3: Adamantite Armor = DEF +18, HP +10, SPD -4\n");
    printf("4: Bare (No Armor) = SPD +10\n\n");
    printf("What is your choice? ");
    scanf("%d", &nECase);

    switch(nECase){
        case 1:
            nP1def = nP1def + 3;
            nP1spd = nP1spd + 3;
            printf("You have chosen 'Mythril'.");
            strcpy(cP1Equip, "Mythril");
            break;
        case 2:
            nP1def = nP1def + 8;
            nP1hp = nP1hp +5;
            printf("You have chosen 'Chain Mail'.");
            strcpy(cP1Equip, "Chain Mail");
            break;
        case 3:
            nP1def = nP1def + 18;
            nP1hp = nP1hp + 10;
            nP1spd = nP1spd - 4;
            printf("You have chosen 'Adamantite Armor'.");
            strcpy(cP1Equip, "Adamantite Armor");
            break;
        case 4:
            nP1spd = nP1spd + 10;
            printf("You have chosen 'Bare(No Armor)'.");
            strcpy(cP1Equip, "Bare (No Armor)");
            break;
    }

    switch(nWRand){
        case 1:
            nP2atk = nP2atk + 15;
            nP2spd = nP2spd + 3;
            strcpy(cP2Weapon, "Dagger");
            break;
        case 2:
            nP2atk = nP2atk + 20;
            strcpy(cP2Weapon, "Katana");
            break;
        case 3:
            nP2atk = nP2atk + 40;
            nP2spd = nP2spd - 5;
            strcpy(cP2Weapon, "Broad Sword");
            break;
        case 4:
            nP2spd = nP2spd + 10;
            strcpy(cP2Weapon, "Fist (No Weapon)");
            break;
    }

    switch(nERand){
        case 1:
            nP2def = nP2def + 3;
            nP2spd = nP2spd + 3;
            strcpy(cP2Equip, "Mythril");
            break;
        case 2:
            nP2def = nP2def + 8;
            nP2hp = nP2hp +5;
            strcpy(cP2Equip, "Chain Mail");
            break;
        case 3:
            nP2def = nP2def + 18;
            nP2hp = nP2hp + 10;
            nP2spd = nP2spd - 4;
            strcpy(cP2Equip, "Adamantite Armor");
            break;
        case 4:
            nP2spd = nP2spd + 10;
            strcpy(cP2Equip, "Bare (No Armor)");
            break;
    }


    printf("\n\nYou chose %s and %s.", cP1Weapon, cP1Equip);
    printf("\nThe Opponent chose %s and %s.\n", cP2Weapon, cP2Equip);
    printf("Both of you have equipped your weapons of choice. Opening Battle Phase........");
    BattlePhase(&nP1hp, &nP1atk, &nP1def, &nP1spd, &nP1Cr, &nP2hp, &nP2atk, &nP2def, &nP2spd, &nP2Cr);
 
}


/*
    This function is for the main menu of the program/game.
*/
int DisplayMenu(){
    int nCase;
    int nChecker = 1;

    while(nChecker != 0){
        printf("Select Option:\n");
        printf("1: Normal Mode\n");
        printf("2: Developer Mode\n");
        printf("3: Exit\n");
        printf("Option: ");
        scanf("%d", &nCase);

        switch(nCase){
            case 1:
                EquipPickPhase();
                nChecker = 0;
                break;
            case 2:
                DevMode();
                nChecker = 0;
                break;
            case 3:
                printf("Shut Down.....\n");
                nChecker = 0;
                break;
            default:
                printf("Invalid Input.");
                break;
        }

    }
}


/*
    This function calls the Main Menu function. It is also the required function
    to use in C.
*/
int main(){
    DisplayMenu();

    return 0;
}