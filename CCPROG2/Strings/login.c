#include <stdio.h>
#include <string.h>

typedef char string100[101];

int login(string100 userNames[], string100 passwords[],
  string100 loginUserName, string100 loginPassword, int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    if (strcmp(userNames[i], loginUserName) == 0 &&
        strcmp(passwords[i], loginPassword) == 0)
    {
      return i;
    }
  }
  return -1;
}