#ifndef _STRUCTS_H
#define _STRUCTS_H

typedef char string[21];

typedef struct Profile {

  string name;
  int wonGame[3];
  int lostGame[3];
  // Board board;

} Profile;

/*
  typedef struct Board{

    int row;
    int column;
    

} Board;

*/

void blank();
void printProfile(Profile profile);
void arrProf(string names[], int *numNames);
void selSort(string arr[], int n);
int profFinder(string arr[], string name, int n);
Profile createProfile();
void selProfile();
void viewStat(string name);
void cursorStart(FILE *file, string target);
void profileChanger(Profile *profile, int type, int diff, int win);
void delProfile(string name);
void profile_mainMenu();


#endif