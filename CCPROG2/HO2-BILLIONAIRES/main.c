/* 
   main.c (for BILLIONAIRES problem)
   
   DO NOT CHANGE/EDIT THE FUNCTIONS DEFINED IN THIS C SOURCE FILE!!!
*/


/*
    Print the values of the members of param structure.
*/
void PrintStruct(BType param)
{
    printf("%s %s %.2f %.2f %d %s %s %s\n", param.name.first, param.name.last, param.net_worth2023,
            param.net_worth2022, param.age, param.country, param.source, param.industry);
}    

/*
    Print the values of the elements of a 1D array of structure
    accessed indirectly via LIST.  The are n structures with values.
*/
void PrintData(BType  LIST[], int n)
{
    for (int i = 0; i < n; i++)
        PrintStruct(LIST[i]);
}

/*
   This function will initialize the contents of BILLIONAIRE[] array of structure.
   It will return the number of rows of data that were stored in the array.
   
   Read billionares.h header file for the details of BType.
*/
int InputData(BType BILLIONAIRE[]) 
{
    BType temp;
    int ctr = 0;   // counter for the number of rows of data
     
    while ( scanf("%s %s %f %f %d %s %s %s", temp.name.first, temp.name.last, &temp.net_worth2023, 
                  &temp.net_worth2022, &temp.age, temp.country, temp.source, temp.industry) == 8 ) {
        // PrintStruct(temp);
        BILLIONAIRE[ctr] = temp;   // structure to structure assignment
        ctr++;
    }

    return ctr;
}


/*
    This is the main() function for testing your solution.  
	
    You are not supposed to modify the contents and the logic of this function.
    
    If you need to experiment, i.e. you'd like to edit/introduce new codes, then it is suggested that you
	copy this file, and make changes on your copy.
	
	Note that the teacher-in-charge of checking your solution may use another set of input data 
	and a different main() function.  
	
	Your functions should work correctly even with a different set of input data and a different main() function.
*/	

// Do NOT change/edit/delete the #if in the next line.  You need not be concerned about #if #else #endif lines.
#if TEST_THIS_MAIN

int main()
{
    // Read about the BType typedef alias in billionaires.h
    BType BILLIONAIRE[MAX];  // 1D array of structures (stores data about the billionaires)
    int nB;      // number of billionaires; used together with BILLIONAIRE[] array
    
    // the next variable is used only for testing the answer for Q1
    double sum;  
    
    // the next two variables will be used only for testing the answer for Q2
    BType youngestB;  // data for the youngest billionaire
    BType oldestB;    // data for the oldest billionaire

    // the next three variables will be used only for testing the answer for Q3
    BType TEMPLIST[MAX];     // 1D array of structures for storing result
    int nTemp;               // used together iwth TEMPLIST[] array
    Str15 COUNTRIES[4] = { "FRANCE", "JAPAN", "INDIA", "USA"};  // test cases for Q3 
    // the next variable is used only for testing the answer for Q1
    
    // the next variable will be used only for testing the answer for Q4
    CType CHANGE[MAX];  // Read about the CType typedef alias in billionaires.h
      
    // the next variable will be used only for testing the answer for Q5
    BType temp_struct; 
    

    nB = InputData(BILLIONAIRE);  // first step requires input of data on billionaires (see INPUT.TXT)
    PrintData(BILLIONAIRE, nB);   // print the array contents to verify what was read via input redirection
    printf("\n");

    // Test if the functions for answering questions Q1 to Q5 work or not.
    printf("----TEST-Q1_SumNetWorth()-----\n");
    sum = Q1_SumNetWorth(5,  BILLIONAIRE, nB);
    printf("%.2lf BILLION US DOLLARS\n", sum);
    printf("\n");


    printf("----TEST-Q2_YoungestOldest()-----\n");
    Q2_YoungestOldest(&youngestB, &oldestB, BILLIONAIRE, nB); 
    printf("YOUNGEST: %s %s AGE %d\n", youngestB.name.first, youngestB.name.last, youngestB.age);
    printf("OLDEST: %s %s AGE %d\n", oldestB.name.first, oldestB.name.last, oldestB.age);
    printf("\n");


    printf("----TEST-Q3_BillionairesByCountry()-----\n");
    for (int i = 0; i < 3; i++) {
        nTemp = Q3_BillionairesByCountry(TEMPLIST, COUNTRIES[i], BILLIONAIRE, nB);
        printf("%d %s BILLIONAIRES\n", nTemp, COUNTRIES[i]);
        for (int j = 0; j < nTemp; j++)
            printf("%s %s\n", TEMPLIST[j].name.first, TEMPLIST[j].name.last);
        printf("\n");
    }
    

    printf("----TEST-Q4_ChangeInNetWorth()-----\n");
    Q4_ChangeInNetWorth(CHANGE, BILLIONAIRE, nB);
    for (int i = 0; i < nB; i++)
        printf("%s %s %.2f %.2f\n", CHANGE[i].name.first, CHANGE[i].name.last, 
                CHANGE[i].difference, CHANGE[i].percentage);
    printf("\n");


    printf("----TEST-Q5_StructCopy()-----\n");
    Q5_StructCopy(&temp_struct, &BILLIONAIRE[0]);
    PrintStruct(temp_struct);
    printf("\n");

    return 0;
}

// Do NOT change/edit/delete the #else in the next line.
#else

    /*
      There's no need for you to be concerned about the #else and #endif lines.  
   */

// Do NOT change/edit/delete the #endif in the next line.
#endif