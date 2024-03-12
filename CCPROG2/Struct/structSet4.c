#include <stdio.h>
#include <string.h>

struct PersonTag{

    char name[15];
    int year;
    char sex;
    struct PersonTag *spouse;
    struct PersonTag *mother;
    struct PersonTag *father;

};

typedef struct PersonTag prs;

int marry(prs *x, prs *y){

    if (x -> year > 2006 && y -> year > 2006){
        return 0;
    }
    if (x -> spouse != NULL && y -> spouse != NULL){
        return 0;
    }
    if (x -> sex == 'M' && y -> sex == 'M'){
        return 0;
    }
    if (x -> sex == 'F' && y -> sex == 'F'){
        return 0;
    }

    x -> spouse = y;
    y -> spouse = x;


    return 1;
}

int assignChild(prs *x, prs *y, prs *z){
    if (x->year > (z->year - 18) && y->year > (z->year - 18)) {
        return 0; // Child's parents are not at least 18 years older than the child
    }
    if (x -> sex == 'M' && y -> sex == 'M'){
        return 0;
    }
    if (x -> sex == 'F' && y -> sex == 'F'){
        return 0;
    }
    if (z ->mother != NULL && z -> father != NULL){
        return 0;
    }

    if (x -> sex == 'M'){
        z -> mother = y;
        z -> father = x;
    }
    else if (x -> sex == 'F'){
        z -> mother = x;
        z -> father = y;
    }

    return 1;
}

int areSiblings(prs *x, prs *y){

    if (x == NULL || y == NULL) {
        return 0; // Cannot determine sibling relationship if one person is NULL
    }

    if (x->father == y ->father || x->mother == y->mother){
        return 1;
    }

    return 0;
}


int main(){
    prs person1, person2, child;
    int x;
    
    // Initialize person1 (father)
    strcpy(person1.name, "John");
    person1.year = 1970;
    person1.sex = 'M';
    person1.spouse = NULL;
    person1.mother = NULL;
    person1.father = NULL;

    // Initialize person2 (mother)
    strcpy(person2.name, "Jane");
    person2.year = 1980;
    person2.sex = 'F';
    person2.spouse = NULL;
    person2.mother = NULL;
    person2.father = NULL;

    // Initialize child
    strcpy(child.name, "Alice");
    child.year = 2010;
    child.sex = 'F';
    child.spouse = NULL;
    child.mother = NULL;
    child.father = NULL;

    if (marry(&person1, &person2)) {
        printf("Marriage successful!\n");
    } else {
        printf("Marriage failed!\n");
    }


    x = assignChild(&person1, &person2, &child);
    
    if (x == 1) {
        printf("Child assigned successfully!\n");
        printf("Child's mother: %s\n", child.mother->name);
        printf("Child's father: %s\n", child.father->name);
    } else {
        printf("Child assignment failed!\n");
    }

    return 0;
}