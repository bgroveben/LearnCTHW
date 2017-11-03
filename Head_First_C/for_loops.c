/*
* This code has no main() method and will not compile.
*/

/*
* There is a simple counting program in while_loop.c.
* This program does the same thing, but uses a for loop.
*/
int counter;
/* Here:
 * The variable is initialized,
 * The text condition is checked before the loop runs each time,
 * The counter is incremented after each loop.
*/
for (counter = 1; counter < 11; counter++) {
	printf("%i green bottles, hanging on a wall\n", counter);
} /* Since there's only one line in the loop body,
   * the braces aren't necessary.
   */