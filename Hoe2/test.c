#include<stdio.h>

int main() {
	int base, pow, power;
    power = 1;
    base = 2;
    pow = 4;
    do{
        power *= base;
        pow--;
    }
    while(pow != 0);

    printf("%d", power);


	return 0;
}
