/*
	Header file for WORD LIST SORTER AND REVERSER problem.
	
	DO NOT change this file.
	
	Concentrate only on Lines 10 - 28. You do not need to be concerned with the other lines.
*/

/* DO NOT change the four #defines below */
#define MAX (1000)
#define EXIT ("0")
#define FALSE (0)
#define TRUE (!FALSE)

/* DO NOT change the two typedef below */
typedef int Boolean;
typedef char String20[21];

/* Function prototypes for the functions that the student need to define in the source file LASTNAME-WORDLIST.c */
void sortItems(String20 words[], int size, int sortOrder);
int checkDuplicate(String20 words[], String20 word, int size);
int inputWords(String20 words[], int size);
void reverseWords(String20 words[], int size);
void rotateLeft(String20 words[], int size, int m);

/* The definitions for the following functions are already provided in the LASTNAME-WORDLIST.c file */
void displayList(String20 words[], int count);
void displayRotate(String20 words[], int count, int m);
