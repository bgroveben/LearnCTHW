/*
These are just code fragments.
This file will not compile without a main method.
*/
/*
* There are three things you need to know in order to use pointers to read and
* write data.
*/

// 1. Get the address of the variable:
int *address_of_x = &x;
// 2. Read the contents of an address:
int value_stored = *address_of_x;
/*
* The * and & operators are opposites.
* The & operator takes a piece of data and tells you where it’s stored.
* The * operator takes an address and tells you what’s stored there.
* Because pointers are sometimes called references, the * operator is said to
* dereference a pointer.
*/
// 3. Change the contents of an address:
*address_of_x = 99;
// Just use the * operator again, but on the LEFT side of an assignment.
