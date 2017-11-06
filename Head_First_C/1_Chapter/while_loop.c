/*
* This code has no main() method and will not compile.
*/

/*
* A while loop runs code repeatedly as long as some condition remains true.
* Or until your browser, system, or network crash.
*/

while (<some condition>) {
	... /* do something here */
	... /* if there is only one line, you don't need braces */
	... /* but we have three */
}

while (more_balls)
	keep_juggling();

/*
* There's another form of the while loop that checks the loop condition
* after the loop body is run.
* That means that the loop always executes at least once.
* Meet the do...while loop.
*/

do {
	... /* Buy lottery ticket. */
} while (have_not_won);

/*
* This is a while loop that counts from 1 to 10.
*/
int counter = 1;
while (counter < 11) {
	printf("%i green bottles, hanging on a wall\n", counter);
	// Don't forget to increment your counter, otherwise your loop won't stop.
	counter++;
}