/*
    Header file for the BILLIONAIRES problem.
    
    Do NOT change anything in this file!!!
*/

/* CONCENTRATE only on Lines 14 to 72; you need not be concerned with the other lines. */
#ifndef BILLIONAIRES_PROBLEM
   #define BILLIONAIRES_PROBLEM (1)
#endif

#define TEST_THIS_MAIN (1)

#define MAX 50

typedef char Str15[16];
typedef char Str30[31];

struct nameTag {
    Str15 first;  // first name
    Str15 last;   // last name
};

typedef struct nameTag nameType;

// struct data type corresponding to each row of Billionaire data
// refer to page 1 of the PDF file
struct bTag {
    nameType name;          // note: structure within a structure
    float net_worth2023;
    float net_worth2022;
    int age;
    Str15 country;
    Str30 source;
    Str30 industry;
};

typedef struct bTag BType;  // Billionaire Type


// this structure will be used in answering question Q4
struct cTag {
    nameType name;
    float difference;     // HINT: difference = net_worth2023 - net_worth22    
    float percentage;     // HINT: percentage = difference/net_worth2022 * 100

    // Note: If the difference and percentage values are negative, then the billionaire's fortune
    //         decreased from year 2022 to 2023. 
    //       If the difference and percentage values are positive, then the billionaire's fortune
    //         increased, i.e., the rich became richer.
};

typedef struct cTag CType;


/*
   The following are the function prototypes for the 5 functions that the student need to 
   define in the source file LASTNAME-BILLIONAIRES.c
*/ 
double Q1_SumNetWorth(int param_number, BType BILLIONAIRE[], int n);
void Q2_YoungestOldest(BType *ptrYoungest, BType *ptrOldest, BType BILLIONAIRE[], int n);
int Q3_BillionairesByCountry(BType TEMPLIST[], char *param_country, BType BILLIONAIRE[], int n);
void Q4_ChangeInNetWorth(CType CHANGE[], BType BILLIONAIRE[], int n);
void Q5_StructCopy(BType *ptrDest, BType *ptrSource);


/*
   The following are the function prototypes for the utility functions which were defined in main.c
*/ 
void PrintStruct(BType param);
int InputData(BType BILLIONAIRE[]);
void PrintData(BType LIST[], int n);

//--- THE END ---