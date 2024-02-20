#include <stdio.h>

int whoWonTicTacToe(char arr[][3]){
    int i, j;
    int countO = 0;
    int countX = 0;
    int win = 0;

// Horizontal
    for(i = 0; i < 3; i++){
        if(countO < 3){
            countO = 0;
        }
        if(countX < 3){
            countX = 0;
        }
        for(j = 0; j < 3; j++){
            if(arr[i][j] == 'O'){
                countO++;
            }
            if(arr[i][j] == 'X'){
                countX++;
            }
        }
        
        if(countO == 3){
            break;
        }
        if(countX == 3){
            break;
        }
    }

// Vertical
    for(i = 0; i < 3; i++){
        if(countO < 3){
            countO = 0;
        }
        if(countX < 3){
            countX = 0;
        }
        for(j = 0; j < 3; j++){
            if(arr[j][i] == 'O'){
                countO++;
            }
            if(arr[j][i] == 'X'){
                countX++;
            }
        }
        
        if(countO == 3){
            break;
        }
        if(countX == 3){
            break;
        }
    }

    if(countO == 3){
        win = 1;
    }
    if(countX == 3){
        win = 2;
    }

    return win;
}


int main(){
    int win;
    char arr[3][3] = {{'X','O','O'}, {'X', 'O', 'X' }, {'O', 'O','.'}};

    win = whoWonTicTacToe(arr);
    
    if(win == 0){
        printf("It is a draw");
    }
    if(win == 1){
        printf("O Won");
    }
    if(win == 2){
        printf("X Won");
    }

    return 0;
}