#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef char string[21];

typedef struct Profile{

    string name;
    int wonGame;
    int lostGame;

}Profile;

/*
typedef struct Game{

    int arr[5][5];

};
*/


void blank(){

    printf("---------------------------------------------------\n");

}


void printProfile(Profile profile) {
    printf("Name: %s\n", profile.name);
    printf("Games Won: %d\n", profile.wonGame);
    printf("Games Lost: %d\n", profile.lostGame);
}

Profile createProfile(){
    Profile profileArr[10];
    int numProf = 0;
    int check = 0;

    Profile profile;
    blank();

    while (check != 1){
        printf("Profile Name (3-20 characters): ");
        scanf("%s", profile.name);

        if (strlen(profile.name) >= 3 && strlen(profile.name) <= 20) {
            printf("Valid Profile Name. Thank you!\n");
            check = 1; // Exit the loop if the name is valid
        } else {
            printf("Invalid name length. Please enter a name with 3 to 20 characters.\n");
            while (getchar() != '\n'); // Clear input buffer
        }
    }

    profile.wonGame = 0;
    profile.lostGame = 0;

    profileArr[numProf] = profile;

    FILE *file = fopen("prof.txt", "a");
    if (file == NULL){
        printf("Error Opening File.");
    }

    fprintf(file, "%s %d %d\n", profileArr[numProf].name, profileArr[numProf].wonGame, profileArr[numProf].lostGame);

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

    while (fscanf(file, "%s %d %d", profile.name, &profile.wonGame, &profile.lostGame) != EOF) {
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

int main(){

    blank();
    mainMenu();


    return 0;
}