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
    Last modified: Novemver 23, 2023
    Version: 1.5
    [Acknowledgements: ]
*/

#include <stdio.h>
#include <stdlib.h> //rand and srand
#include <time.h> // time(NULL) for srand (To make it different every iteration)
#include<string.h> // strcpy

/*
    (EDIT)
*/
void battlePhase(int* nP1hp,int* nP1atk, int* nP1def, int* nP1spd, int* nP1Cr , int* nP2hp, int* nP2atk, int* nP2def, int* nP2spd,int* nP2Cr);

/*
    This Function changes the values of each stat of each player. It also
    ignores the Equipment Picking Phase and goes straight to the Battle Phase.
*/
void devMode(){
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

    printf("You have finished setting up your stats. Opening Battle Phase........\n");
    battlePhase(&nP1hp, &nP1atk, &nP1def, &nP1spd, &nP1Cr, &nP2hp, &nP2atk, &nP2def, &nP2spd, &nP2Cr);
}

/*
    This function lets the player choose what Weapon and Equipment
    they want to use for the battle. It also lets the opponent randomly
    pick what Weapon and Equipment they will use too.
*/
void equipPhase(){

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
    int nChecker2 = 1;
    int nChecker3 = 1;

    printf("Welcome to the Equipment Picking Phase.\n You and your Opponent will pick ONE Weapon and ONE Armor each before the Battle Phase.\n Choose your weapons wisely. ");
    printf("Press the Number of your desired weapon of choice.");
    printf("\n\nWeapons: \n\n");
    printf("1: Dagger = ATK +15, SPD +3\n");
    printf("2: Katana = ATK +20\n");
    printf("3: Broad Sword = ATK +40, SPD -5\n");
    printf("4: Fist (No Weapon) = SPD +10\n\n");
    
    while(nChecker2 != 0){
        printf("What is your choice? ");
        scanf("%d", &nWCase);

        switch(nWCase){
            case 1:
                nP1atk = nP1atk + 15;
                nP1spd = nP1spd + 3;
                printf("You have chosen 'Dagger'.");
                strcpy(cP1Weapon, "Dagger");
                nChecker2 = 0;
                break;
            case 2:
                nP1atk = nP1atk + 20;
                printf("You have chosen 'Katana'.");
                strcpy(cP1Weapon, "Katana");
                nChecker2 = 0;
                break;
            case 3:
                nP1atk = nP1atk + 40;
                nP1spd = nP1spd - 5;
                printf("You have chosen 'Broad Sword'.");
                strcpy(cP1Weapon, "Broad Sword");
                nChecker2 = 0;
                break;
            case 4:
                nP1spd = nP1spd + 10;
                printf("You have chosen 'Fist(No Weapon)'.");
                strcpy(cP1Weapon, "Fist (No Weapon)");
                nChecker2 = 0;
                break;
            default:
                printf("Invalid Input. Try again please.\n");
        }
    }
    

    

    printf("\n\nEquipments: \n\n");
    printf("1: Mythril = DEF +3, SPD +3\n");
    printf("2: Chain Mail = DEF +8, HP +5\n");
    printf("3: Adamantite Armor = DEF +18, HP +10, SPD -4\n");
    printf("4: Bare (No Armor) = SPD +10\n\n");
    
    
    while(nChecker3 != 0){
        printf("What is your choice? ");
        scanf("%d", &nECase);

        switch(nECase){
            case 1:
                nP1def = nP1def + 3;
                nP1spd = nP1spd + 3;
                printf("You have chosen 'Mythril'.");
                strcpy(cP1Equip, "Mythril");
                nChecker3 = 0;
                break;
            case 2:
                nP1def = nP1def + 8;
                nP1hp = nP1hp +5;
                printf("You have chosen 'Chain Mail'.");
                strcpy(cP1Equip, "Chain Mail");
                nChecker3 = 0;
                break;
            case 3:
                nP1def = nP1def + 18;
                nP1hp = nP1hp + 10;
                nP1spd = nP1spd - 4;
                printf("You have chosen 'Adamantite Armor'.");
                strcpy(cP1Equip, "Adamantite Armor");
                nChecker3 = 0;
                break;
            case 4:
                nP1spd = nP1spd + 10;
                printf("You have chosen 'Bare(No Armor)'.");
                strcpy(cP1Equip, "Bare (No Armor)");
                nChecker3 = 0;
                break;
            default:
                printf("Invalid Input. Try again please.\n");
        }
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
    printf("\nThe Opponent chose %s and %s.\n\n", cP2Weapon, cP2Equip);
    printf("Both of you have equipped your weapons of choice. Opening Battle Phase........\n");
    battlePhase(&nP1hp, &nP1atk, &nP1def, &nP1spd, &nP1Cr, &nP2hp, &nP2atk, &nP2def, &nP2spd, &nP2Cr);
}

/*
    This function is to create any non-positive number into 0.
*/
int zero(int x){
    if(x < 0){
        return 0;
    }
    else{
        return x;
    }
}

/*
    (EDIT)
*/
void battlePhase(int* nP1hp,int* nP1atk, int* nP1def, int* nP1spd, int* nP1Cr , int* nP2hp, int* nP2atk, int* nP2def, int* nP2spd,int* nP2Cr){
    srand(time(NULL));
    int ntie = 0;
    int nP1Chrg, nP2Chrg, nP1Blck, nP2Blck;
    nP1Chrg = 0;
    nP2Chrg = 0;
    nP1Blck = 0;
    nP2Blck = 0;
    // lmao

    while(*nP1hp >= 0 || *nP2hp >= 0 || ntie == 1){
        int nP1Action, nP2Action, nChecker1;
        int nP1Dmg, nP2Dmg, nP1ChrgEnd, nP2ChrgEnd; 
        int nP1CrChck, nP2CrChck, nP1CritHit, nP2CritHit;

        nChecker1 = 1;
        nP1ChrgEnd = 0;
        nP2ChrgEnd = 0;

        nP2Action = rand() % 3 + 1;

        while(nChecker1 != 0){
            printf("What Action will you choose?\n");
            printf("1: Attack\n");
            printf("2: Charge\n");
            printf("3: Block\nAction: ");
            scanf("%d", &nP1Action);

            switch(nP1Action){
                case 1:
                    nChecker1 = 0;
                    break;
                case 2:
                    nChecker1 = 0;
                    break;
                case 3:
                    nChecker1 = 0;
                    break;
                default:
                    printf("Invalid Input. Try again please.\n");
            }
        }
        

        /*
        Stat Changes from the Actions
        */
        if(nP1Action == 2 && nP1Chrg == 0){
            *nP1atk *= 2;
            *nP1spd *= 2;
        }

        if(nP2Action == 2 && nP2Chrg == 0){
            *nP2atk *= 2;
            *nP2spd *= 2;
        }

        if(nP1Action == 3){
            *nP1def *= 2;
        }
        if(nP2Action == 3){
            *nP2def *= 2;
        }

        /*
        Crit Rate Check and Damage Formula
        */
        nP1CrChck = rand() % 100 + 1;
        nP2CrChck = rand() % 100 + 1;

        if(nP1CrChck <= *nP1Cr){
            nP1CritHit = 1;
            nP1Dmg = *nP1atk;
        }
        else{
            nP1CritHit = 0;
            nP1Dmg = *nP1atk - *nP2def;
        }

        if(nP2CrChck <= *nP2Cr){
            nP2CritHit = 1;
            nP2Dmg = *nP2atk;
        }
        else{
            nP2CritHit = 0;
            nP2Dmg = *nP2atk - *nP1def;
        }

        nP1Dmg = zero(nP1Dmg);
        nP2Dmg = zero(nP2Dmg);

        /*
        Start of Action
        */
        printf("Your opponent chose %d\n\n", nP2Action);

        if(nP1Action == 3 && nP2Action == 3){
            printf("Both have blocked each other.\n");
            nP1Blck = 1;
            nP2Blck = 1;

            if (nP1Chrg == 1){
                nP1ChrgEnd = 1;
            }
            if (nP2Chrg == 1){
                nP2ChrgEnd = 1;
            }
        }
        else if(nP1Action == 2 && nP2Action == 3){
            printf("The opponent blocked the attack.\n");
            printf("You charged for the next turn.\n");
            nP1Chrg = 1;
            nP2Blck = 1;
            
        }
        else if(nP1Action == 3 && nP2Action == 2){
            printf("You blocked the attack.\n");
            printf("The opponent charged for the next turn.\n");
            nP2Chrg = 1;
            nP1Blck = 1;
        }
        else if(nP1Action == 1 && nP2Action == 3){
                printf("The opponent blocked the attack.\n");
                if (nP1CritHit == 1){
                    printf("You landed a critical hit!\n");
                }
                printf("You attacked the opponent!\n");
                printf("You dealt %d damage to the opponent.\n", nP1Dmg);
                *nP2hp -= nP1Dmg;
                nP2Blck = 1;
                
                if (nP1Chrg == 1){
                nP1ChrgEnd = 1;
                }
                if (nP2Chrg == 1){
                nP2ChrgEnd = 1;
                }
        }
        else if(nP1Action == 3 && nP2Action == 1){
                printf("You blocked the attack.\n");
                if (nP2CritHit == 1){
                    printf("The opponent landed a critical hit!\n");
                }
                printf("The opponent attacked you!\n");
                printf("They dealt %d damage to you.\n", nP2Dmg);
                *nP1hp -= nP2Dmg;
                nP1Blck = 1;
                
                if (nP1Chrg == 1){
                nP1ChrgEnd = 1;
                }
                if (nP2Chrg == 1){
                nP2ChrgEnd = 1;
                }   
        }
        else if(nP1Action == 1 && nP2Action == 1){
            if(*nP1spd > *nP2spd){
                printf("You attacked first!\n");
                if (nP1CritHit == 1){
                    printf("You landed a critical hit!\n");
                }
                printf("You dealt %d damage to the opponent.\n", nP1Dmg);
                *nP2hp -= nP1Dmg;
                if(*nP2hp == 0){
                    printf("You win!");
                    break;
                }
                printf("The opponent attacked you!\n");
                if (nP2CritHit == 1){
                    printf("The opponent landed a critical hit!\n");
                }
                printf("They dealt %d damage to you.\n", nP2Dmg);
                *nP1hp -= nP2Dmg;
                if (nP1Chrg == 1){
                    nP1ChrgEnd = 1;
                }
                if (nP2Chrg == 1){
                    nP2ChrgEnd = 1;
                }
            }
            else if(*nP1spd < *nP2spd){
                printf("They attacked first!\n");
                if (nP2CritHit == 1){
                    printf("The opponent landed a critical hit!\n");
                }
                printf("They dealt %d damage to you.\n", nP2Dmg);
                *nP1hp -= nP2Dmg;
                if(*nP1hp == 0){
                    printf("You win!");
                    break;
                }
                printf("You attacked the opponent!\n");
                if (nP1CritHit == 1){
                    printf("You landed a critical hit!\n");
                }
                printf("You dealt %d damage to the opponent.\n", nP1Dmg);
                *nP2hp -= nP1Dmg;
                if (nP1Chrg == 1){
                    nP1ChrgEnd = 1;
                }
                if (nP2Chrg == 1){
                    nP2ChrgEnd = 1;
                }
            }
            else if(*nP1spd == *nP2spd){
                printf("Both attacked at the same time!\n");
                if (nP1CritHit == 1){
                    printf("You landed a critical hit!\n");
                }
                else if(nP2CritHit == 1){
                    printf("The opponent landed a critical hit!\n");
                }
                else if(nP1CritHit == 1 && nP2CritHit == 1){
                    printf("Both landed a critical hit!\n");
                }
                printf("You dealt %d damage to the opponent while the opponent dealt %d damage to you.\n", nP1Dmg, nP2Dmg);
                *nP1hp -= nP2Dmg;
                *nP2hp -= nP1Dmg;

                if(*nP1hp <= 0 && *nP2hp <= 0){
                    printf("Both died at the same time!\n");
                    printf("It is a draw!.\n");
                    ntie = 1;
                    break;
                }
                else{
                    ntie = 0;
                }
                
                if (nP1Chrg == 1){
                    nP1ChrgEnd = 1;
                }
                if (nP2Chrg == 1){
                    nP2ChrgEnd = 1;
                }
            }
        }
        else if(nP1Action == 2 && nP2Action == 2){
            printf("Both charged for the next turn!\n");
            nP1Chrg = 1;
            nP2Chrg = 1;
        }
        else if(nP1Action == 1 && nP2Action == 2){
            printf("You attacked the opponent!\n");
            if(nP1CritHit == 1){
                printf("You landed a critical hit!\n");
            }
            printf("You dealt %d damage to the opponent.\n", nP1Dmg);
            *nP2hp -= nP1Dmg;

            if(*nP2hp <= 0){
                printf("You win!\n");
                break;
            }

            printf("The opponent charged for the next turn.\n");
            nP2Chrg = 1;

            if (nP1Chrg == 1){
                nP1ChrgEnd = 1;
            }
        }
        else if(nP1Action == 2 && nP2Action == 1){
            printf("The opponent attacked you!\n");
            if(nP2CritHit == 1){
                printf("The opponent landed a critical hit!\n");
            }
            printf("The opponent dealt %d damage to you.\n", nP2Dmg);
            *nP1hp -= nP2Dmg;

            if(*nP1hp <= 0){
                printf("You lose!\n");
                break;
            }

            printf("You charged for the next turn.\n");
            nP1Chrg = 1;
            
            if (nP2Chrg == 1){
                nP2ChrgEnd = 1;
            }   
        }

        /*
        Reset All Stats
        */
        if(nP1ChrgEnd == 1){
            *nP1atk /= 2;
            *nP1spd /= 2;
            nP1Chrg = 0;
        }

        if(nP2ChrgEnd == 1){
            *nP2atk /= 2;
            *nP2spd /= 2;
            nP2Chrg = 0;
        }

        if(nP1Blck == 1){
            *nP1def /= 2;
            nP1Blck = 0;
        }
        if(nP2Blck == 1){
            *nP2def /= 2;
            nP2Blck = 0;
        }

        printf("Your HP: %d\n", zero(*nP1hp));
        printf("Opponent's HP: %d\n", zero(*nP2hp));

        if(*nP2hp <=0){
            printf("You win!\n");
            break;
        }
        else if(*nP1hp <= 0){
            printf("You lose!\n");
            break;
        }

    }

}


/*
    This function is for the main menu of the program/game.
*/
void displayMenu(){
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
                equipPhase();
                nChecker = 0;
                break;
            case 2:
                devMode();
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
    displayMenu();

    return 0;
}