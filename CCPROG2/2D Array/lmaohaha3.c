#include <stdio.h>
#include <string.h>

void myst(char msg[]){
    int len = strlen(msg);
    int i = 0;
    int j = strlen(msg);

    for (i = 0; i < len; i++){
        msg[j] = msg[i];
        j++;
    }

    msg[j] = '\0';
}