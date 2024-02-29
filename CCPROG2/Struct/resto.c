#include <stdio.h>
#include <string.h>

typedef char string[51];

struct RecipeTag{

    string dishName;
    int n;
    string ingredientList[51];
    int quantityList[51];

};

struct IngredientTag{

    string name;
    int cost;

}theMarket;

struct Market{
    int n;
    string ingredientList[51];
};

void printRecipe(struct RecipeTag *rec){
    int i;
    
    printf("Name of the Recipe: %s\n", rec -> dishName);
    printf("Number of Ingredients: %d\n", rec -> n);

    for (i = 0; i < rec -> n; i++){
        printf("Ingredient %d: %s\n", i + 1, rec -> ingredientList[i]);
        printf("Quantity: %d\n", rec -> quantityList[i]);
    }
}

void printBlnk(){
    printf("\n------------------------------------------------\n");
}


int main(){

    struct RecipeTag rcp;
    int i,j;

    printf("What will be the name of your dish?\n");
    scanf("%s", rcp.dishName);

    printf("What will be the number of ingredients?\n");
    scanf("%d", &rcp.n);

    for (i = 0; i < rcp.n; i++){
        printf("Ingredient %d:", i + 1);
        scanf("%s", rcp.ingredientList[i]);
        printf("Quantity of Ingredient %d: ", i + 1);
        scanf("%d", &rcp.quantityList[i]);
    }

    printBlnk();
    printRecipe(&rcp);
    printBlnk();


    return 0;
}