#include <stdio.h>
#include <stdlib.h>

/*
* Three-card Monte – also known as find the lady and three-card trick – is a
* confidence game in which the victim, or "mark", is tricked into betting a sum
* of money, on the assumption that they can find the "money card" among three
* face-down playing cards.
* -- https://en.wikipedia.org/wiki/Three-card_Monte
*/

int main()
{
    // The code is designed to shuffle the letters in the three-letter
    // string “JQK.”
    /*
    * A variable that points to a string literal can’t be used to change the
    * contents of the string:
    * char *cards = "JQK";      <-- This variable can't modify this string.
    * But if you create an array from a string literal, then you can modify it:
    */
    char cards[] = "JQK";
    char a_card = cards[2];
    cards[2] = cards[1];
    cards[1] = cards[0];
    cards[0] = cards[2];
    cards[2] = cards[1];
    cards[1] = a_card;
    puts(cards);
    return 0;
    // The players place their bets on where they think the “Q” letter will be,
    // and then the code is compiled and run.
}
