/*
* This code has no main() method and will not compile.
*/
/*
* Almost everything in C has a return value, and not just function calls.
* In fact, even things like assignments have return values.
* Now let's learn how to chain assignments together. 
*/
x = 4;
/*
* The assignment "x = 4" has the value 4.
* Next, we'll set y to 4 as well.
*/
y = (x = 4);
// You can shorten the code slightly by removing the parentheses:
y = x = 4;
/* 
* Chained assignments can often be found in code that needs to set 
* several variables at the same time.
*/
