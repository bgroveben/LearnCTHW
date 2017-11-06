/*
* Most functions in C have a return value, but sometimes you
* might want to create a function that has nothing useful to return. It might
* just do stuff rather than calculate stuff. Normally, functions always have 
* to contain a return statement, but not if you give your function the return
* type void:
*/
void complain()
{
	puts("I'm feeling unfulfilled.");
	// No need for a return statement here,
	// it's a void function!
}
