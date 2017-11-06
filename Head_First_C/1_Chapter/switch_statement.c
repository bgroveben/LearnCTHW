/*
* This code has no main() method and will not compile.
*/
/*
* The switch statment is kind of like an if statement, except it
* can test for multiple values.
*/

switch(train) {
case 37:
	winnings = winnings + 50;
	break;
case 65:
	puts("Jackpot!");
	winnings = winnings + 80;
case 12:
	winnings = winnings + 20;
	break
default:
	winnings = 0;
}