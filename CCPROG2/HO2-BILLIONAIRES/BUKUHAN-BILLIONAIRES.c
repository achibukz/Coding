/*
   Encode your LASTNAME, FIRSTNAME: Bukuhan, Abram Aki   SECTION: S17A
   
   1. First make sure to rename this file by replacing LASTNAME with your own last name. For example, 
      if your last name is SANTOS, then this file should be named as SANTOS-BILLIONAIRES.c.
   
   2. Encode your solution using this file.  This is the C source file that you should submit/upload
      via the Canvas submission page.
   
      Follow all instructions in the Problem Specifications (PDF file), and the instructions written
      as comments in this skeleton file. Non-compliance will result to a reduction in score/grade 
      for this exam.

   3. Compile your C source file in the command line as follows:

           prompt> gcc -Wall LASTNAME-BILLIONAIRES.c  (press Enter)

      This will produce a.exe file by default if there is no error.  If there is a warning or an error, 
      fix it first, and then re-compile.

      Make sure that there are NO warnings before your run the exe file.

   4. Run/test your a.exe file with input redirection in the command line as follows:

           prompt> a < INPUT.TXT  (press Enter)

      The data to be used in the program will come from the contents of the accompanying INPUT.TXT file.

   5. Compare the output of your program by comparing it with the contents of the accompanying EXPECTED.TXT.  
      It contains the expected results. They should be exactly the same -- even the spacing!  If they 
      are not the same, then there's a strong probability that there's a logical error in your 
      solution, or you did not follow some specifications.     
      
   6. Debug your C source code if there are logical errors.  Repeat from Step 3.   

   7. Submit this C source via the Canvas submission page.  

   8. To produce the output redirected LASTNAME-ACTUAL.TXT file, run a.exe in the command line 
      with I/O redirection as follows:
           
            prompt> a < INPUT.TXT > LASTNAME-ACTUAL.TXT  (press Enter)
      
      View/verify the contents of LASTNAME-ACTUAL.TXT using any text editor such as Notepad.

      Submit your LASTNAME-ACTUAL.TXT file via the Canvas submission page. 
*/

#include <stdio.h>
#include <string.h>

#include "billionaires.h"  // read and understand the contents of this header file


/* 
    Q1: What is the combined net worth of the top <param_number> billionaires?
*/
double Q1_SumNetWorth(int param_number, BType BILLIONAIRE[], int n)
{
    // Declare your own local variables.
    // You are NOT allowed to call printf() or scanf() inside this function.
    int total = 0;
    int i;

    for (i = 0; i < param_number; i++){
        total += BILLIONAIRE[i].net_worth2023;
    }
   
    return total;  // This return statement is just a place holder.
                // You should change the return statement as part of your solution to this exam.  
}


/*
    Q2: Who are the youngest and oldest billionaires?
    
    Assign to *ptrYoungest the structure containing the data for the youngest billionaire.
    Assign to *ptrOldest the structure containing the data for the oldest billionaire. 
*/
void Q2_YoungestOldest(BType *ptrYoungest, BType *ptrOldest, BType BILLIONAIRE[], int n)
{
    // Declare your own local variables.
    // You are NOT allowed to call printf() or scanf() inside this function.   

    int i;
    int new = BILLIONAIRE[0].age;
    int old = BILLIONAIRE[0].age;

    for (i = 0; i < n; i++){
        if (new > BILLIONAIRE[i].age){
            new = BILLIONAIRE[i].age;
            *ptrYoungest = BILLIONAIRE[i];
        }
    }

    for (i = 0; i < n; i++){
        if (old < BILLIONAIRE[i].age){
            old = BILLIONAIRE[i].age;
            *ptrOldest = BILLIONAIRE[i];
        }
    }
  
}


/*
    Q3: Who are the billionaires from <param_country>?  

    Store in TEMPLIST[] the list of billionaires from <param_country>.
    Return as the result of the function the number of billionaires from <param_country>. 
*/
int Q3_BillionairesByCountry(BType TEMPLIST[], char *param_country, BType BILLIONAIRE[], int n)
{
    int mems = 0;
    // Declare your own local variables.
    // You are NOT allowed to call printf() or scanf() inside this function.
    int i;

    for (i = 0; i < n; i++){
        if (strcmp(BILLIONAIRE[i].country, param_country) == 0){
            TEMPLIST[mems] = BILLIONAIRE[i];
            mems++;
        }
    }

   
    return mems;  // This return statement is just a place holder.
                // You should change the return statement as part of your solution to this exam.  
}


/*
    Q4: By how much and by how many percent did the billionaires' net worth change 
        in 2023 compared to 2022?

    The CHANGE[] array should store the name, the difference and the percentage member values.   
    
    Refer to the PDF file on how to compute the difference and percentage member values.
*/
void Q4_ChangeInNetWorth(CType CHANGE[], BType BILLIONAIRE[], int n)
{
    // Declare your own local variables.
    // You are NOT allowed to call printf() or scanf() inside this function. 
    int i;

    for (i = 0; i < n; i++){
        CHANGE[i].name = BILLIONAIRE[i].name;
        CHANGE[i].difference = BILLIONAIRE[i].net_worth2023 - BILLIONAIRE[i].net_worth2022;
        CHANGE[i].percentage = CHANGE[i].difference / BILLIONAIRE[i].net_worth2022 * 100; 
    }

    
}


/*
    Q5: How do you copy the value of a source structure variable to a destination structure 
        variable with the following restrictions?

    a.  Copying must be done ONE MEMBER at a time (i.e., dest  = source is NOT allowed).
    b.  The structure members must be accessed indirectly via a structure pointer variable
        using the following operators:
            *   (dereference or indirection operation)
            .   (structure member access operator)
            ->  (structure pointer member access operator)

    HINT: Recall the two ways to access a structure member indirectly via a structure pointer variable.
            1st way:  (*pointer_variable_name).member_name
            2nd way:  pointer_variable_name->member_name   

    To use ALL the three operators mentioned above to copy a structure member to a member of 
    another structure, you can do something like
    
        (*some_ptr_var_name).member_name = another_ptr_variable_name->member_name;
    or
        some_ptr_var_name->member_name = (*another_ptr_variable_name).member_name;         
*/
void Q5_StructCopy(BType *ptrDest, BType *ptrSource)
{
    // Note that there is NO need for you to declare any local variable in this function.

    /*------------------------------------------------------------------------------------- 
        Write 8 statements that will copy the source to dest ONE MEMBER at a time
        following the guide written below numbered as #1 to #8; one statement per number. 
    --------------------------------------------------------------------------------------*/
     
    // #1. copy the first name; you ARE REQUIRED TO USE ->, * and . operators
    strcpy(ptrDest -> name.first, ptrSource -> name.first);

    // #2. copy the last name; you ARE REQUIRED TO USE  ->, * and . operators
    strcpy(ptrDest -> name.last, ptrSource -> name.last);

    // #3. copy the net worth in 2023; you ARE REQUIRED TO USE ->, * and . operators
    ptrDest -> net_worth2023 = ptrSource -> net_worth2023;
    
    // #4. copy the net worth in 2022; you ARE REQUIRED TO USE ->, * and . operators
    ptrDest -> net_worth2022 = ptrSource -> net_worth2022;

    // #5. copy the age; you ARE REQUIRED TO USE ->, * and . operators
    ptrDest -> age = ptrSource -> age;

    // #6. copy the country; you ARE REQUIRED TO USE ->, * and . operators
    strcpy(ptrDest -> country, ptrSource -> country);

    // #7. copy the source of fortune; you ARE REQUIRED TO USE ->, * and . operators
    strcpy(ptrDest -> source, ptrSource -> source);

    // #8. copy the industry; you ARE REQUIRED TO USE ->, * and . operators
    strcpy(ptrDest -> industry, ptrSource -> industry);

}


/*-------------------------------------------------------------------

   DO NOT EDIT/CHANGE ANYTHING BELOW THIS COMMENT!!! 

   The main.c file contains other codes for testing your solution.  

--------------------------------------------------------------------*/
#include "main.c"

//  --- THE END ---
