#include <stdio.h>
#include <string.h>

typedef struct date
{
    int year;
    int mnth;
    int day;
}date;

typedef struct prs{
    char name[101];
    int age;
    char sex; // Either M or F
    date bday
    
}prs;


// typedef struct prs prs;


void displayPrs(prs prs){
    printf("Name: %s\n", prs.name);
    printf("Age: %d\n", prs.age);
    printf("Sex: %c\n", prs.sex);

}

int main(){

    int i;
    prs aki, atlas, xi;
    prs list[10];

    strcpy(aki.name,"Aki");
    aki.age = 20;
    aki.sex = 'M';

    strcpy(atlas.name,"Atlas");
    atlas.age = 19;
    atlas.sex = 'M';

    strcpy(xi.name,"Xi");
    xi.age = 19;
    xi.sex = 'F';

    list[0] = aki;
    list[1] = atlas;
    list[2] = xi;

    for (i = 0; i < 3; i++){
        displayPrs(list[i]);
    }


    return 0;
}