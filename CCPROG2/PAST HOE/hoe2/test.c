#include <stdio.h>
#include <string.h>

typedef char string[20];

int
Search(string key, string A[], int nElem)
{
   int i;
   int cmp;

	for (i = 0; i < nElem; i++){
      cmp = strcmp(A[i], key);

      if (cmp == 0){
         return i;
      }   
   }

	return -1;  //remember to update the return statement
}

int main(){
    string x = "or";
    string y = "forever";
    string z = "or";
    string a = "Hii";
    int res1, res2, res3;

    res1 = strcmp(y, x);
    res2 = strcmp(x, z);
    res3 = strcmp(a, x);

    printf("%d\n", res1);
    printf("%d\n", res2);
    printf("%d\n", res3);

    return 0;
}