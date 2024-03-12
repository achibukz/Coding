/**
  * Problem: Sets
  *
  * Name: BUKUHAN, Abram Aki R.
  * Section: S17A
  *
  */

#include "sets.h"   // Do NOT edit or delete this line
  
/* To Do: (1) Implement Search() to return the index where
          key was first found in A.  If not found, return -1.
   @param key - string to search for in A 
   @param A - array of strings 
   @param nElem - number of elements in A
*/   
int
Search(String key, String A[], int nElem)
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

/* To Do: (2) Implement setUnion() that will produce the
           union of unique values from the array A and array B.
           In math, union of sets will be the elements from both
		   sets. Do not assume that the arrays have same number 
		   of elements. The function returns the number of 
		   elements in C.
	
   Reminder: 1. Do NOT use array indexing notation for this function.
    
	         2. You are required to to meaningfully use Search()
  			    as part of the solution for this function.
			  
		Refer to pdf file for the details and complete 
		list of restrictions.	

   @param A first array of strings
   @param B second array of strings
   @param C resulting array to contain the union of A and B
   @param nElemA number of elements in array A
   @param nElemB number of elements in array B
*/
int 
setUnion(String *A, String *B, String *C, int nElemA, int nElemB)
{
   int i,j;
   int cmp;
   int cnt = 0;

   for (i = 0; i < nElemA; i++){
      strcpy(*(C + i), *(A + i));
      cnt++;
   }

   for (i = 0; i < cnt; i++){
      for (j = 0; j < nElemB; j++){
         cmp = strcmp(*(C + i), *(B + j));
         if (cmp != 0){
            strcpy(*(C + cnt), *(B + j));
            cnt++;
         }
      }
   }
   

	return cnt;  //remember to update the return statement
}

/* To Do: (3) Implement setDiff() that will generate contents of 
           array C to contain unique elements from array A that are not in
		   array B. The function returns the number of 
		   elements in C.

   Reminder: You are required to to meaningfully use Search()
  			 as part of the solution for this function.
			  
		Refer to pdf file for the details and complete 
		list of restrictions.	
		   
   @param A first array of strings
   @param B second array of strings
   @param C resulting array to contain elements in A but not in B
   @param nElemA number of elements in array A
   @param nElemB number of elements in array B
   @return number of elements in array C
*/
int
setDiff(String A[], String B[], String C[], int nElemA, int nElemB)
{
   int srch;
   int cnt = 0;
   int i,j;
   String null = "";

   for (i = 0; i < nElemA; i++){
      strcpy(C[i], A[i]);
      cnt++;
   }

   cnt++;

   for (j = 0; j < nElemB; j++){
     srch = Search(B[i], C, cnt);

     if (srch != -1){
      strcpy(C[srch], null);
      cnt--;

     } 
   }
	
	return cnt - 1;  //remember to update the return statement
}

/* To Do: (4) Implement intersect() that will produce the
           intersection of unique values from the array A and array B.
           In math, intersection of sets will be the common elements only
		   from both sets. Do not assume that the arrays have same number 
		   of elements. The function returns the number of 
		   elements in C.

   Reminder: You are required to to meaningfully use Search()
  			 as part of the solution for this function.
			  
		Refer to pdf file for the details and complete 
		list of restrictions.	
		   
   @param A first array of strings
   @param B second array of strings
   @param C resulting array to contain the intersection of A and B
   @param nElemA number of elements in array A
   @param nElemB number of elements in array B
*/
int
intersect(String A[], String B[], String C[], int nElemA, int nElemB)
{
	int srch;
   int cnt = 0;
   int i,j;
   String null = "";

   for (i = 0; i < nElemA; i++){
      strcpy(C[i], A[i]);
      cnt++;
   }


   for (j = 0; j < nElemB; j++){
     srch = Search(B[i], C, cnt);

     if (srch == -1){
      strcpy(C[srch], null);
      cnt--;

     } 
   }

	return cnt;  //remember to update the return statement
}

/* To Do: (5) Implement substringList() that will produce the collection
           of words from the 1D array B that has substrings equivalent to
		   the string key. The function returns the number of 
		   elements in C.
		   
	Reminder: You are only allowed to use strlen(), strcmp(), strcat(),
  	          and strcpy() from string.h.  No other functions from 
			  string.h can be used.
			  
			  Refer to pdf file for the details and complete 
			  list of restrictions.
		   
   @param key - string to search for within strings in B 
   @param B array of strings
   @param C resulting array to contain strings that have key as substrings
   @param nElemB number of elements in array B
   @return number of elements in array C
*/
int
substringList(String key, String B[], String C[], int nElemB)
{
   int indC = 0;
   int i;
   int cmp;

   for (i = 0; i < nElemB; i++){
      cmp = strcmp(key, B[i]);

      if (cmp == 0){
         strcpy(C[i], B[i]);
         indC++;
      }
   }
   


	return indC;  //remember to update the return statement
}