/* 
These are just code fragments.
This file will not compile without a main method.
It might not compile with a main method, who knows?
The idea behind this exercise is to examine each code fragment 
and figure out what the code does.
*/

/* Create an integer variable and set it to 11: */
int card_count = 11;
/* Is the count more than 10?: */
if (card_count > 10)
	/* If so, display a message (a string) in the terminal: */
	puts("The deck is hot. Increase bet.");


/* The curly braces define a block statement. */
/* Create an integer variable and set it to 10: */ 
int c = 10;
/* As long as the value is positive,
display a message and decrease the count: */
while (c > 0) {
	puts("I must not write code in class.");
	c = c - 1;
}
/* Here is the end of the code that should be repeated.*/

/* Assume a name that is shorter than 20 characters. */
/* Create an array of 20 characters: */
char ex[20];
/* Display a message on the screen: */
puts("Enter girlfriend's name: ");
/* Store everything the user types into the ex array: */
scanf("%19s", ex);
/* Display a message that includes the text entered: */
printf("Dear %s. \n\n\tYou're history.\n", ex)

/* Create a character variable; store the letter H: */
char suit = 'H';
/* A switch statement checks a single variable for different values. */
/* Look at the value of the variable: */
switch(suit) {
/* Is it 'C'?: */
case 'C':
/* If so, display the word "Clubs": */
	puts("Clubs");
	/* Then skip past the other checks: */
	break;
/* Is it 'D'?: */
case 'D':
/* If so, display the word "Diamonds": */
	puts("Diamonds");
	/* Then skip past the other checks: */
	break;
/* Is it 'H'?: */
case 'H':
/* If so, display the word "Hearts": */
	puts("Hearts");
	/* Then skip past the other checks: */
	break;
/* Otherwise: */
default:
/* If so, display the word "Spades": */
	puts("Spades");
}
/* Here is the end of the tests. */

