#include <stdio.h>
#include <string.h>

typedef char string100[101];

int main()
{
  string100 nameList[25];
  string100 dummy;
  int n;
  int i;

  printf("Enter the number of students: ");
  scanf("%d", &n);

  gets(dummy);

  for (i = 0; i < n; i++)
  {
    printf("Enter the name of student %d: ", i + 1);
    gets(nameList[i]);
  }

  for (i = 0; i < n; i++)
  {
    printf("%s\n", nameList[i]);
  }

  return 0;
}