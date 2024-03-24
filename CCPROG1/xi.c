#include <stdio.h>

int cCol(int player){

    int n, leave;
    char col;

    do
    {   
        n = 1;
        printf("(Singular digits are only accepted, EXAMPLE: '1', '2', so on)\n");    
        printf("Player %d Pick a column 1, 2, 3, 4 or 5?\n\n", player);
        scanf(" %c", &col);

        switch (col)
        {
        case '1':
            leave = 1;
            n = 0;
            break;
        case '2':
            leave = 2;
            n = 0;
            break;
        case '3':
            leave = 3;
            n = 0;
            break;
        case '4':
            leave = 4;
            n = 0;
            break;
        case '5':
            leave = 5;
            n = 0;
            break;
        default:
        system("cls");
        printf("Invalid input. Try again\n");
            break;
        }    
    }while (n == 1);
    return leave;
}

void cInput(int *r1, int *r2, int *r3, int *r4, int *r5, int player){

    int n, k = 0;
    char row;

    do
    {   
        n = 1;

        printf("Player %d Pick a row: A, B, C, D or E?\n", player);
        printf("Lowercase letters are not valid\n\n");        
        scanf(" %c", &row);
        
        k = cCol(player);

        switch (row)
        {
        case 'A':
            if (getDigit(k, *r1) == 0)
            {   
                *r1 += (expo(k) * player);
                n = 0;
            }else{
                printf("Space %c%d is occupied by Player %d\n", row, k, getDigit(k, *r1));
            }
            
            break;
        case 'B':
            if (getDigit(k, *r2) == 0)
            {
                *r2 += (expo(k) * player);
                n = 0;
            }else{
                printf("Space %c%d is occupied by Player %d\n", row, k, getDigit(k, *r2));
            }
            break;
        case 'C':
            if (getDigit(k, *r3) == 0)
            {
                *r3 += (expo(k) * player);
                n = 0;
            }else{
                printf("Space %c%d is occupied by Player %d\n", row, k, getDigit(k, *r3));
            }
            break;
        case 'D':
            if (getDigit(k, *r4) == 0)
            {
                *r4 += (expo(k) * player);
                n = 0;
            }else{
                printf("Space %c%d is occupied by Player %d\n", row, k, getDigit(k, getDigit(k, *r4)));
            }
            break;
        case 'E':
            if (getDigit(k, *r5) == 0)
            {
                *r5 += (expo(k) * player);
                n = 0;
            }else{
                printf("Space %c%d is occupied by Player %d\n", row, k, getDigit(k, *r5));
            }
            break;
        default:
            system("cls");
            printGrid(*r1, *r2, *r3, *r4, *r5);
            printf("Invalid input. Try Again.\n");
            break;
        }
    }while (n == 1);
    system("cls");
}