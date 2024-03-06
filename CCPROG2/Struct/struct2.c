#include <stdio.h>
#include <string.h>

struct PersonTag {
    char name[20];
    int age;
};

struct OrgTag{
    char name[20];
    int numMem;
    struct PersonTag *memList[10];
};

struct PersonTag createPerson(char name[], int age){
    struct PersonTag CreatePrs;
    strcpy(CreatePrs.name, name);
    CreatePrs.age = age;

    return CreatePrs;
}

struct OrgTag createOrg(char name[]){
    
    struct OrgTag CreateOrgg;
    strcpy(CreateOrgg.name, name);
    CreateOrgg.numMem = 0;

    return CreateOrgg;
}

void joinOrg(struct OrgTag *org, struct PersonTag *prs){

    org -> memList[org -> numMem] = prs;
    org -> numMem++;

}

void printMem(struct OrgTag org){
    int i;

    printf("Members of %s\n", org.name);

    for (i = 0; i < org.numMem; i++){
        printf("   Member %d: %s\n", i + 1, org.memList[i] -> name);
    }
}

void printBlnk(){
    printf("------------------------------------------------\n");
}


int main(){
    struct PersonTag p1;
    struct OrgTag o1;
    struct OrgTag o2;

    p1 = createPerson("Xi", 19);
    o1 = createOrg("CORG");
    o2 = createOrg("BORG");

    printf("%s\n", p1.name);
    printf("%s\n", o1.name);
    printf("%s\n", o2.name);
    printBlnk();

    joinOrg(&o1, &p1);
    joinOrg(&o2, &p1);

    printMem(o1);
    printBlnk();
    printMem(o2);
    printBlnk();

    strcpy(p1.name, "Atlas");

    printMem(o1);
    printBlnk();
    printMem(o2);
    printBlnk();




    return 0;
}