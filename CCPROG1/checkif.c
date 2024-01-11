#include<stdio.h>

int CheckHp(int* nP1hp, int* nP2hp){
    int dead;
    
    if(*nP1hp == 0){
        printf("You lost!");
        dead = 1;
    }
    else if(*nP2hp == 0){
        printf("You win!");
        dead = 1;
    }
    else{
        dead = 0;
    }

    return dead;
}

int main(){
    int hell, nP1hp, nP2hp;

    nP1hp = 1;
    nP2hp = 0;
    CheckHp(&nP1hp, &nP2hp);


    return 0;
}