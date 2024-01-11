#include <stdio.h>
#define NUMONE 8
#define NUMTWO 0

int D (int a, int b)
{
	return a * b + b / a; // (a*b) + (b/a)
}

int C (int a)
{
	return -1 * a; // -a
}

int B ()
{
	return 5 * (4 + 1) / 7; // 25/7 = 3
}

int A ()
{
	return 10 - 3 % 2; // 9
}

int main ()
{
	int nOne, nTwo, nThree, nFour, nFive;
	
	nOne   = A() + B() % 12 - NUMTWO; // 9 + 3 % 12 - 0 = 12
	nTwo   = C(A()) / B() + C(-1); // -9 / 3 + 1 = -2
	nThree = C(6) + A() != B(); // -6 + 9 != 3 -> 0
	nFour  = D(A(), C(-3)) == (B() - A()); // (2*3)+(3/2) == (3 - 9) -> 0
	nFive  = !((C(NUMONE) <= NUMTWO + D(2, 3)) == (A() - B()));
	
	printf("%d %d %d %d %d", nOne, nTwo, nThree, nFour, nFive);
	return 0;
}