/*
 * Program to count cards in a blackjack game.
 * https://en.wikipedia.org/wiki/Card_counting
 *
 * Released under the DGAF Public License.
 * (c)2017 Ben's Blackjack Team.
 * 
 * The recipe:
 * Evaluate the card.
 * Is it between 3 and 6 (inclusive)?
 *     Increase count by 1.
 * Otherwise...
 *     Decrease count by 1.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char card_name[3];
	puts("Enter the card name: ");
	scanf("%2s", card_name);
	int val = 0;
	if (card_name[0] == 'K') {
		val = 10;
	} else if (card_name[0] == 'Q') {
		val = 10;
	} else if (card_name[0] == 'J') {
		val = 10;
	} else if (card_name[0] == 'A') {
		val = 11;
	} else {
		val = atoi(card_name);
	}
	printf("The card value is: %i\n", val);
	return 0;
}