/*
* This code has no main() method and will not compile.
*/

/*
* The break statement is used to escape from a loop before it finishes.
* You can also use break to break out of switch statements.
*/
while(feeling hungry) {
	eat_cookies();
	if (feeling_queasy) {
		/* Break out of the while loop. */
		break;
	}
	drink_coffee();
}

/*
* The continue statement can be used to skip the rest of the loop body
* and go back to the start of the loop.
*/
while(feeling_hungry) {
	if (not_lunch_yet) {
		/* Go back to the loop condition. */
		continue;
	}
	eat_cookies();
}