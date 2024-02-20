#include <stdio.h>
#include <string.h>

int main(){
    char s1[21] = "red";
    char s2[21] = "blue";
    char s3[21] = "green";

    strcat(s1, s2);
    strcpy(s2, s3);
    strcpy(s3, s1);

    printf("%d\n", strcmp(s1, s2));
    printf("%d\n", strcmp(s2, s3));
    printf("%d\n", strcmp(s3, s1));



    return 0;
}