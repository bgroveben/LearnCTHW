/*
 * Program to evaluate face values.
 * Released under the Yo Momma's House Public License.
 * (c) 2017 Ben's Blackjack Team
 */

/*
 * To compile and run this code from the command line:
 * => gcc cards.c -o cards && ./cards
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char card_name[3];
    int count = 0;
    while(card_name[0] != 'X')
    {
    	puts("Enter the card_name: ");
    	scanf("%2s", card_name);
    	int val = 0;
    	switch(card_name[0]) {
            case 'K':
            case 'Q':
            case 'J':
                val = 10;
                break;
            case 'A':
                val = 11;
                break;
            case 'X':
                // We're inside a switch statement,
                // so use continue instead of break.
                continue;
            default:
                val = atoi(card_name);
                if ((val < 1) || (val > 10)) {
                    puts("Invalid value");
                    continue;
                }
            }
            if ((val > 2) && (val < 7)) {
                count++;
            } else if (val == 10) {
                count--;
            }
            printf("The VALUE is: %i\n", val);
    	    printf("The COUNT is: %i\n", count);
    }
    return 0;
}
