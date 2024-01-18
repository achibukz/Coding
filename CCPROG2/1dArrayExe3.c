#include <stdio.h>

int main()
{
  int arr1[15];
  int arr2[15];
  int i;
  int input;
  int elementCount = 0;
  float total = 0.0f;

  printf("Elements of arr1:\n");
  for (i = 0; i < 15; i++)
  {
    printf("%d\n", arr1[i]);
  }
  printf("\n");

  do
  {
    printf("Enter a positive integer (0 or -1 to quit): ");
    scanf("%d", &input);
    if (input > 0)
    {
      arr1[elementCount] = input;
      elementCount++;
    }
  } while (input > 0 && elementCount < 15);

  for (i = 0; i < elementCount; i++)
  {
    total += arr1[i];
  }
  printf("Average: %.2f\n\n", total / elementCount);

  for (int i = 0; i < 15; i++)
  {
    arr2[i] = 0;
  }

  for (int i = 0; i < elementCount; i++)
  {
    arr2[i] = arr1[i];
  }

  printf("Elements of arr2:\n");
  for (int i = 0; i < 15; i++)
  {
    printf("%d\n", arr2[i]);
  }
}