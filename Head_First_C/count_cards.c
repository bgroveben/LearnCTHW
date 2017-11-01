/*
* Program to calculate the number of cards in the shoe.
* This code is released under Ben's Vegas Public License.
* (c) 2017, Ben's Blackjack Squad.
*/

/* The stdio library contains code that allows you to read and write data
* from and to the terminal: */
#include <stdio.h>

/* The main() function is the starting point for all of the code 
* in your program. */
int main()
{ 
	int decks;
	puts("Enter a number of decks.");
	scanf("%i", &decks);
	if (decks < 1) {
		puts("That is not a valid number of decks.");
		return 1;
	}
	printf("There are %i cards\n", (decks * 52));
	return 0;
}
