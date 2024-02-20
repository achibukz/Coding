#include <stdio.h>
#include <string.h>

void func(char str[]){
    int i = 0;
    int j;

    while (i < strlen(str)){
        if (str[i] == ' '){
            j = i+1;
            while (str[j] != '\0'){
                str[j-1] = str[j];
                j++;
            }
            str[j-1] = '\0';
        }
        else
            i++;
    }
}

int main(){
    char message[101] = "let them cook";

    func(message);
    printf("%s", message);


    return 0;
}