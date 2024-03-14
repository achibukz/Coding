#ifndef _STRUCTS_H
#define _STRUCTS_H

typedef char string[21];

typedef struct Profile {

  string name;
  int wonGame[3];
  int lostGame[3];

} Profile;

/*
typedef struct Game{

    int arr[5][5];

};
*/

void blank();
void printProfile(Profile profile);
Profile createProfile();
void viewStat(string name);
void mainMenu();

#endif