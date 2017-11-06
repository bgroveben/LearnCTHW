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
	/* Assign a value to each card: */
	int val = 0;
	switch(card_name[0]){
	case 'K':
	case 'Q'):
	case 'J'):
		val = 10;
		break;
	case 'A':
		val = 11;
		break;
	default:
		val = atoi(card_name);
	}

	/* Check if the value is 3 to 6: */
	if ((val > 2) && (val < 7))
		puts("Count has gone up.");
	/* Otherwise check if the card was 10, J, Q, or K: */
	else if (val == 10)
		puts("Count has gone down.");
	return 0;
}