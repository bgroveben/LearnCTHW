/*
* Pretty much all functions in C follow the same format.
* This is a program with a custom function that gets called by main().
*/
#include <stdio.h>

int larger(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int main()
{
	int greatest = larger(100, 1000);
	printf("%i is the greatest!\n", greatest);
	return 0;
}