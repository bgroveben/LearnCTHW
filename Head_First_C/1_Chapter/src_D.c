/*
* Read the code in this file and decide if it will compile or not.
*/

#include <stdio.h>

int main()
{
	int card = 1;
	if (card > 1) {
		card = card - 1;
		if (card < 7)
			puts("Small card");
	else
		puts("Ace!");
	
	return 0;
}

/*
* This code will not compile because the braces aren't matched.
* See if you can fix it.
*/