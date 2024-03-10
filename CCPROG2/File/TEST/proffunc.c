#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "proffunc.h"


void blank(){

    printf("---------------------------------------------------\n");

}


void printProfile(Profile profile) {
    printf("Profile Name: %s\n", profile.name);
    printf("  Games Won:\n");
    printf("     Classic-Easy: %d\n", profile.wonGame[0]);
    printf("     Classic-Difficult: %d\n", profile.wonGame[1]);
    printf("     Custom: %d\n", profile.wonGame[2]);
    printf("  Games Lost:\n");
    printf("     Classic-Easy: %d\n", profile.lostGame[0]);
    printf("     Classic-Difficult: %d\n", profile.lostGame[1]);
    printf("     Custom: %d\n", profile.lostGame[2]);
}

Profile createProfile(){
    Profile profileArr[10];
    int numProf = 0;
    int check = 0;

    Profile profile;
    blank();

    while (check != 1){
        printf("Profile Name (3-20 characters) (ex. AkiIsClown): ");
        scanf("%s", profile.name);

        if (strlen(profile.name) >= 3 && strlen(profile.name) <= 20) {
            printf("Valid Profile Name. Thank you!\n");
            check = 1; // Exit the loop if the name is valid
        } else {
            printf("Invalid name length. Please enter a name with 3 to 20 characters.\n");
            while (getchar() != '\n'); // Clear input buffer
        }
    }

    int i;

    for (i = 0; i < 3; i++){
        profile.wonGame[i] = 0;
        profile.lostGame[i] = 0;
    }


    profileArr[numProf] = profile;

    FILE *file = fopen("prof.txt", "a");
    if (file == NULL){
        printf("Error Opening File.");
    }

    fprintf(file, "%s ", profile.name);
    for (int i = 0; i < 3; i++) {
        fprintf(file, "%d ", profile.wonGame[i]);
    }
    for (int i = 0; i < 3; i++) {
        fprintf(file, "%d ", profile.lostGame[i]);
    }
    fprintf(file, "\n");

    fclose(file);

    blank();
    printf("Profile is Saved.\n");

    blank();
    printProfile(profileArr[numProf]);

    numProf++;

    return profile;
}



void viewStat(string name){

    int found = 0;
    Profile profile;

    FILE *file = fopen("prof.txt", "r");
    if (file == NULL){
        printf("Error Opening File.");
    }

    while (fscanf(file, "%s %d %d %d %d %d %d", profile.name, 
            &profile.wonGame[0], &profile.wonGame[1], &profile.wonGame[2], 
            &profile.lostGame[0], &profile.lostGame[1], &profile.lostGame[2]) != EOF) {
        if (strcmp(profile.name, name) == 0) {
            found = 1;
            break;
        }
    }

    fclose(file);

    if (found) {
        blank();
        printf("Profile found.\n");
        blank();
        printProfile(profile);
    } else {
        blank();
        printf("Profile not found.\n");
    }


}

void mainMenu() {

    int userInput;
    string name;

    printf("1: Create Profile\n");
    printf("2: Select Existing Profile\n");
    printf("3: Delete Existing Profile\n");
    printf("4: View Statistics\n");
    printf("What is your Choice: ");
    scanf("%d", &userInput);

  switch (userInput) {
    case 1:
        createProfile();
        break;
    case 2:
        // selProfile();
        break;
    case 3:
        // delProfile();
        break;
    case 4:
        blank();
        printf("Profile Name: ");
        scanf("%s", name);
        viewStat(name);
    default:
        break;
    }

}