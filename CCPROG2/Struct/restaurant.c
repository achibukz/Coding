#include <stdio.h>
#include <string.h>
#define MAX_INGREDIENTS_PER_RECIPE 50
#define MAX_INGREDIENTS_IN_MARKET 200

typedef char String[51];

struct RecipeTag
{
  String dishName;
  int n;
  String ingredientList[MAX_INGREDIENTS_PER_RECIPE];
  int quantityList[MAX_INGREDIENTS_PER_RECIPE];
};

struct IngredientTag
{
  String name;
  int cost;
};

struct
{
  int n;
  struct IngredientTag ingredientList[MAX_INGREDIENTS_IN_MARKET];
} theMarket;

void displayRecipe(struct RecipeTag recipe)
{
  int i;
  printf("==================\n");
  printf("DISH NAME: %s\n", recipe.dishName);
  printf("INGREDIENT LIST:\n");
  for (i = 0; i < recipe.n; i++)
  {
    printf("%s -- %d\n", recipe.ingredientList[i], recipe.quantityList[i]);
  }
  printf("==================\n");
}

struct IngredientTag makeNewIngredient(String name, int cost)
{
  struct IngredientTag result;

  strcpy(result.name, name);
  result.cost = cost;

  return result;
}

int addIngredientToMarket(struct IngredientTag toAdd)
{
  if (theMarket.n < MAX_INGREDIENTS_IN_MARKET)
  {
    theMarket.ingredientList[theMarket.n] = toAdd;
    theMarket.n++;
    return 1;
  }
  else
  {
    return 0;
  }
}

int canCookRich(struct RecipeTag recipe)
{
  int i, j, count;
  String currentIngredient;

  for (i = 0; i < recipe.n; i++)
  {  
    strcpy(currentIngredient, recipe.ingredientList[i]);

    count = 0;
    for (j = 0; j < theMarket.n; j++)
    {
      if (strcmp(theMarket.ingredientList[j].name, currentIngredient) == 0)
      {
        count++;
      }
    }

    if (count < recipe.quantityList[i])
    {
      return 0;
    }
  }

  return 1;
}

int main()
{
  struct RecipeTag myRecipe;
  int i;

  printf("Enter the name of the recipe: ");
  scanf("%s", myRecipe.dishName);
  printf("Enter the number of ingredients: ");
  scanf("%d", &myRecipe.n);

  for (i = 0; i < myRecipe.n; i++)
  {
    printf("Enter the ingredient name: ");
    scanf("%s", myRecipe.ingredientList[i]);
    printf("Enter the quantity: ");
    scanf("%d", &myRecipe.quantityList[i]);
  }

  displayRecipe(myRecipe);

  addIngredientToMarket(makeNewIngredient("APPLE", 10));
  addIngredientToMarket(makeNewIngredient("APPLE", 10));
  addIngredientToMarket(makeNewIngredient("APPLE", 10));
  addIngredientToMarket(makeNewIngredient("APPLE", 10));
  addIngredientToMarket(makeNewIngredient("APPLE", 20));
  addIngredientToMarket(makeNewIngredient("APPLE", 20));
  addIngredientToMarket(makeNewIngredient("BANANA", 5));
  addIngredientToMarket(makeNewIngredient("BANANA", 5));
  addIngredientToMarket(makeNewIngredient("BANANA", 5));
  addIngredientToMarket(makeNewIngredient("BANANA", 6));
  addIngredientToMarket(makeNewIngredient("BANANA", 6));
  addIngredientToMarket(makeNewIngredient("HOTDOG", 50));
  addIngredientToMarket(makeNewIngredient("BANANA", 35));

  for (i = 0; i < theMarket.n; i++)
  {
    printf("%s   %d\n", theMarket.ingredientList[i].name, theMarket.ingredientList[i].cost);
  }

  printf("Result of can cook recipe: %d\n", canCookRich(myRecipe));

  return 0;
}