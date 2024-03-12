/*
    This is the main.c file.  It contains the main() function for the WORD LIST SORTER AND REVERSER problem.
	
	DO the following to test your LASTNAME-WORDLIST.c solution: 
	
	1. Edit Line 39 below to include your own source file.
	2. Compile this main.c file to produce main.exe.  Make sure to use -Wall compiler directive!
	3. If there are no compilation errors and/or warnings, go to the Command Line Interface via CMD. 
	4. Run main.exe in the command line with I/O redirection as follows:
   
           	main < INPUT.txt > LASTNAME-ACTUAL.txt           	

	   where INPUT.txt is an accompanying sample text files that contain input data 
	   read via scanf() in the ReadWords() function.

       For example, if your lastname is SANTOS, you should run main.exe as:
	   
       		main < INPUT.txt > SANTOS-ACTUAL.txt
		      
    5. Using Notepad (or other text editors), open and compare your LASTNAME-ACTUAL.txt with the 
	   contents of the accompanying EXPECTED.TXT file. They should be exactly the same -- even the spacing!
	   If they are not the same, then there's a strong probability that there's a logical error in your 
	   solution, or you did not follow some specifications.  

	6. Debug and retry until you get the correct results.    
	   
	7. Devise your own tests. Do NOT simply depend on the sample INPUT and EXPECTED text files.
*/

/* Do NOT change  the #include below.  You are NOT allowed to include other files. */
#include <stdio.h>

#include "defs.h" /* Make sure you read/understand the contents of this header file. */

/*
    TO DO: change the #include below to your own file/solution. For example if your 
	lastname is SANTOS, then it should be changed to #include "SANTOS-WORDLIST.c".
*/
#include "BUKUHAN-WORDLIST.c"

/*
    This is the main() function for testing your solution.  
	
	You are not supposed to modify the contents and the logic of this function.
    
    If you need to experiment, i.e. you'd like to edit/introduce new codes, then it is suggested that you
	copy this file, and make changes on your copy.
	
	Note that the teacher-in-charge of checking your solution may use another set of input data 
	and a different main() function.  
	
	Your functions should work correctly even with a different set of input data and a different main() function.
*/

void displayList(String20 words[], int count)
{
	int i;
	
	for(i = 0; i < count; i++)
		printf("%s\n", words[i]);
}

void displayRotate(String20 words[], int count, int m)
{
	int i;
	
	printf("\nWord list AFTER rotate left %d times:\n", m);
	for(i = 0; i < count; i++)
		printf("[%s]", words[i]);	
}

int main()
{    
    String20 words[MAX] = {}; //Array for inputWords function
    String20 arrSorting[5] = {"Watch", "Pencil", "Computer", "Notebook", "Abstract"}; //Array for testing sorting function
    String20 arrReverse[4] = {"Xerox", "Apple", "Samsung", "Sony"}; //Array for testing reverse function
    String20 arrRotate[7] = {"Frieren", "Stark", "Fern", "Eisen", "Himmel", "Heiter", "Sein"}; //Array for testing rotateLeft function
	String20 arrDupe[3] = {"Apple", "Orange", "Strawberry"}; //Array for testing checkDuplicate function
	int count, total;
    
    printf("How many items do you wish to add to the list? ");
    scanf("%d", &count);
    
    total = inputWords(words, count);
    
    printf("\nThe words inputted:\n");
    displayList(words, total);
    
    printf("\n---TEST CHECKDUPLICATE(Note: 1 = TRUE, 0 = FALSE)---\n");
    printf("Expected: 1 | Actual : %d\n", checkDuplicate(arrDupe, "Orange", 3));
    printf("Expected: 0 | Actual : %d\n", checkDuplicate(arrDupe, "Banana", 3));
    printf("Expected: 1 | Actual : %d\n", checkDuplicate(arrDupe, "Strawberry", 3));
    printf("Expected: 0 | Actual : %d\n", checkDuplicate(arrDupe, "orange", 3));
    

    printf("\n---REVERSING WORDS---\n");
    printf("\nBefore Reversing:\n");
    displayList(arrReverse, 4);
    reverseWords(arrReverse, 4);
    printf("\nAfter Reversing:\n");
    displayList(arrReverse, 4);
	
	printf("\n---SORTING WORDS---\n");
    printf("\nWords before sorting:\n");
    displayList(arrSorting, 5);
	    
	printf("\nWords in Ascending order:\n");
	sortItems(arrSorting, 5, 1);
    displayList(arrSorting, 5);
 
	printf("\nWords in Descending order:\n");
    sortItems(arrSorting, 5, 2);
    displayList(arrSorting, 5);

    
    printf("\n---ROTATING WORDS---\n");
    
	rotateLeft(arrRotate, 7, 0);
    displayRotate(arrRotate, 7, 0);
    printf("\n");
    rotateLeft(arrRotate, 7, 2);
	displayRotate(arrRotate, 7, 2);

    printf("\n\n---ROTATING WORDS USING A SIZE LESS THAN THE NUMBER OF ELEMENTS---\n");
	printf("\nUsing a size value of 3 (only the first 3 elements will move)\n");	
    rotateLeft(arrRotate, 3, 5);
	displayRotate(arrRotate, 7, 5);
	
	printf("\n\nUsing a size value of 5 (only the first 5 elements will move)\n");
    rotateLeft(arrRotate, 5, 6);
	displayRotate(arrRotate, 7, 6);
    
    return 0;
}
