/* 
	Hands on Exam 1: WORD LIST SORTER AND REVERSER
   
	Name:    BUKUHAN, Abram Aki R.
   	Section: S17A
*/

#include <string.h>
#include "defs.h"

/*
	TO DO #1: implement inputWords() as described in the problem specs.
	
	@param: words[] - Array storing the words / the list
	@param: size - Refers to the total number of items in the list
	
	NOTE: If a duplicate word is inputted, it will not count towards the total and require the user to enter a different word.
*/
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
		i++;

		//cmp0 = break
		cmp0 = strcmp(input, "0");
		if (cmp0 == 0){
			i = size;
		}
		
		cnt++;
	}


	return cnt; //You may edit this.
}

/*
	TO DO #2: implement checkDuplicate() as described in the problem specs.
	
	@param: words[] - Array storing the words / the list
	@param: word - The word that will be used to match with the items in the list
	@param: size - Refers to the total number of items in the list
	returns TRUE if the string already exists in the list, otherwise returns FALSE.
	
	NOTE: You are required to use the defined TRUE and FALSE constants!
	
*/
int checkDuplicate(String20 words[], String20 word, int size)
{
	/*
		Declare your own local variables.
		DO NOT call printf or scanf in this function.
	*/
	int i;
	int cmp;

	for (i = 0; i < size; i++){
		cmp = strcmp(words[i], word);

		if (cmp == 0){
			return TRUE;
		}
	}

	return FALSE; //You may edit this line.
}

/*
	TO DO #3: implement reverseWords() as described in the problem specs.
	
	@param: words[] - Array storing the words / the list
	@param: size - Refers to the total number of items in the list
*/
void reverseWords(String20 words[], int size)
{
	/*
		Declare your own local variables.
		DO NOT call printf or scanf in this function.
		You are NOT ALLOWED to use the strrev() function.
	*/
	char temp;
	int i;

	for (i = 0; i < size; i++){
		
	}
}

/*
	TO DO #4: implement sortItems() as described in the problem specs.
	
	@param: words[] - Array storing the words / the list
	@param: size - Refers to the total number of items in the list
	@param: sortOrder - Integer value for the selected sorting order (1 for Ascending and 2 for Descending)

*/
void sortItems(String20 words[], int size, int sortOrder)
{
	/*
		Declare your own local variables.
		DO NOT call printf or scanf in this function.
	*/
}

/*
	TO DO #5: implement rotateLeft() as described in the problem specs.
	
	@param: words[] - Array storing the words / the list
	@param: size - Refers to the total number of items in the list
	@param: m - Refers to the number of elements the values will move to the left.
*/
void rotateLeft(String20 words[], int size, int m)
{
	/*
		Declare your own local variables.
		DO NOT call printf or scanf in this function.	
	*/
}
