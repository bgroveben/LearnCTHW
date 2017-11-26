/*
* This is a variant of the three_card_monte.c file.
* Let's see what happens if we construct a new array.
*/
#include <stdio.h>

int main()
{
    char cards[] = "JQK";
    char a_card = cards[2];
    cards[2] = cards[1];
    cards[1] = cards[0];
    cards[0] = cards[2];
    cards[2] = cards[1];
    cards[1] = a_card;
    puts(cards);
    return 0;
}
/*
* The code works!
* Your cards variable now points to a string in an unprotected section of
* memory, so we are free to modify its contents.
*/
