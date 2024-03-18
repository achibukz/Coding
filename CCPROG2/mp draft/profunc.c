#include "profunc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void blank() {

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

void arrProf(string names[], int *numNames) {
    FILE *file = fopen("prof.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    *numNames = 0;
    while (*numNames < 20 && fscanf(file, "%20s", names[*numNames]) != EOF) {
        (*numNames)++;
        while (fgetc(file) != '\n' && !feof(file)); 
    }

    fclose(file);
}

void selSort(string arr[], int n) {
    int i, j, min;
    string temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (strcmp(arr[j], arr[min]) < 0) {
                min = j;
            }
        }
        if (min != i) {
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[min]);
            strcpy(arr[min], temp);
        }
    }
}

int profFinder(string arr[], string name, int n){
  int found = 1;
  int i = 0;
  int end = 0;

  

  while (end != 1){
    
    if (strcmp(arr[i], name) == 0){
      found = 0;
      end = 1;
    }
    i++;

    if (i == 20){
      end = 1;
    }
  }

  return found;
}

// NEED TO MAKE IT UNIQUE LANG AND MAXIMUM OF 10 PROFILES
Profile createProfile() {
  Profile profileArr[20];
  int numProf = 0;
  int check = 0;
  int numNames;
  string arr[20];
  int nCheck = 0;

  arrProf(arr, &numNames);
  selSort(arr, numNames);

  Profile profile;
  blank();

  while (check != 1) {
    printf("Profile Name (3-20 characters): ");
    scanf("%s", profile.name);

    nCheck = profFinder(arr, profile.name, numNames);
    printf("%d\n", nCheck);

    if (strlen(profile.name) >= 3 && strlen(profile.name) <= 20 && nCheck == 1) {
      printf("Valid Profile Name. Thank you!\n");
      check = 1; // Exit the loop if the name is valid
    } 
    else if (strlen(profile.name) < 3 && strlen(profile.name) > 20){
      printf("Invalid name length. Please enter a name with 3 to 20 "
             "characters.\n");
      while (getchar() != '\n')
        ; // Clear input buffer
    }
    else if (nCheck == 0){
      printf("Name is already used. Please enter a unique name.\n");
      while (getchar() != '\n')
        ; // Clear input buffer
    }
  }

  int i;

  for (i = 0; i < 3; i++) {
    profile.wonGame[i] = 0;
    profile.lostGame[i] = 0;
  }

  profileArr[numProf] = profile;

  FILE *file = fopen("prof.txt", "a");
  if (file == NULL) {
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


    mainMenu(&profile);
    return profile;
}

void viewStat(string name) {
    blank();
    printf("View Statistics\n");
    blank();
  int found = 0;
  Profile profile;

  FILE *file = fopen("prof.txt", "r");
  if (file == NULL) {
    printf("Error Opening File.");
  }

  while (fscanf(file, "%s %d %d %d %d %d %d", profile.name, &profile.wonGame[0],
                &profile.wonGame[1], &profile.wonGame[2], &profile.lostGame[0],
                &profile.lostGame[1], &profile.lostGame[2]) != EOF) {
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

  mainMenu(&profile);
}

// ALPHABETICAL ORDER
void selProfile(){
    Profile profile;
    int name;
    string arr[20];
    int numNames, i;
    int nCheck = 0;

    arrProf(arr, &numNames);
    selSort(arr, numNames);

    printf("Select Your Profile: \n");
    for (i = 0; i < numNames; i++) {
        printf("%d: %s\n",i + 1, arr[i]);
    }
    

  while (nCheck != 1){
    printf("What profile will you use? (Select The Number) ");
    scanf("%d", &name);

    if (1 <= name && name <= numNames - 1) {
        blank();
        printf("Profile found.\n");
        blank();
        nCheck = 1;
    } 
    else {
        blank();
        printf("Profile not found.\n");
        printf("Please Try Again.\n");
    }
  }

  name -= 1;

    FILE *file = fopen("prof.txt", "r");
    if (file == NULL) {
        printf("Error Opening File.");
    }

    while (fscanf(file, "%s %d %d %d %d %d %d", profile.name, &profile.wonGame[0],
                &profile.wonGame[1], &profile.wonGame[2], &profile.lostGame[0],
                &profile.lostGame[1], &profile.lostGame[2]) != EOF) {
        if (strcmp(profile.name, arr[name]) == 0) {
            break;
        }
    }

    fclose(file);

    mainMenu(&profile);
    


}

void cursorStart(FILE *file, string target) {
    char buffer[256]; 
    long startPos; 

    rewind(file);

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (strstr(buffer, target) != NULL) {
            startPos = ftell(file) - strlen(buffer);
            break;
        }
    }

    fseek(file, startPos - 1, SEEK_SET);
}


void profileChanger(Profile *profile, int type, int diff, int win){

    if (type == 1 && diff == 1 && win == 1){
        profile->wonGame[0]++;
    }
    else if (type == 1 && diff == 2 && win == 1){
        profile->wonGame[1]++;
    }
    else if (type == 2 && win == 1){
        profile->wonGame[2]++;
    }
    else if (type == 1 && diff == 1 && win == 0){
        profile->lostGame[0]++;
    }
    else if (type == 1 && diff == 2 && win == 0){
        profile->lostGame[1]++;
    }
    else if (type == 1 && win == 0){
        profile->lostGame[2]++;
    }


  FILE *file = fopen("prof.txt", "r+");
  if (file == NULL) {
    printf("Error Opening File.");
  }

  cursorStart(file, profile->name);
  fprintf(file, "%s %d %d %d %d %d %d", profile->name, 
          profile->wonGame[0], profile->wonGame[1], profile->wonGame[2],
          profile->lostGame[0], profile->lostGame[1], profile->lostGame[2]);

  fclose(file);
  blank();
}


void profile_mainMenu() {

  int userInput;

  printf("1: Create Profile\n");
  printf("2: Select Existing Profile\n");
  printf("3: Delete Existing Profile\n");
  printf("What is your Choice: ");
  scanf("%d", &userInput);

  switch (userInput) {
  case 1:
    createProfile();
    break;
  case 2:
    selProfile();
    break;
  case 3:
    // string name;
    // printf("Who do you want to delete? ");
    // scanf("%s", name);
    // delProfile(name);
    // IF NAME EXISTS, ASK CONFIRMATION
    break;
  default:
    break;
  }
}