/*
* Read the code in this file and decide if it will compile or not.
*/

#include <stdio.h>

int main()
{
	int card = 1;
	if (card > 1) {
		card  = card - 1;
		if (card < 7)
			puts("Small card");
	else
		puts("Ace!");
	}
	return 0;
}

/*
* This code compiles, but it is not really working properly.
* The program displays nothing and the else is matched to the wrong if.
*/
