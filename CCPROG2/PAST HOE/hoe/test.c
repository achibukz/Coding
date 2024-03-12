#include <stdio.h>
#include <string.h>

typedef char String20[21];

int inputWords(String20 words[], int size)
{
    /*
    	Declare your own local variables
    */

   int cnt;
   int cmp0 = 1;
   int cmp;
   String20 input;
   int i = 0;
   int j = 0;
    
	printf("Input in any string with a max of 20 characters. You can input up to %d items.\n", size);
	printf("Duplicate words are not allowed!\n");
	printf("Input 0 if you wish to end the input process.\n");    

	/*
		Place your code here. Do not forget that this function is supposed to return a value.
		Reminder: This function should call the checkDuplicate() function.
	*/

	for (i = 0; i < size; i++){
		scanf("%s", input);

		for (j = 0; j < cnt; j++){
			cmp = strcmp(input, words[j]);
			if (cmp == 0){
				printf("Matching word found! Please input a different word!");
			}
		}

		strcpy(words[i], input);

		//cmp0 = break
		cmp0 = strcmp(input, "0");
		if (cmp0 == 0){
			i = size;
		}
		
		cnt++;
	}


	return cnt; //You may edit this.
}

int main(){

    String20 x[100];
    int count;

    count = inputWords(x, 5);

    printf("%d", count);


    return 0;
}