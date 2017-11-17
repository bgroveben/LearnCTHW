/*
* We have a classic trio of bachelors ready to play The Dating Game today.
* Tonight’s lucky lady is going to pick one of these fine contestants.
* Who will she choose?
*/
#include <stdio.h>

int main()
{
    // Initialize contestants:
    int contestants[] = {1, 2, 3};
    // Make choice the address of the contestants array:
    int *choice = contestants;
    contestants[0] = 2;
    contestants[1] = contestants[2];
    contestants[2] = *choice;
    printf("I'm going to pick contestant number %i\n", contestants[2]);
    return 0;
}
/* Run the code to see which suitor she chooses.
* Try to keep track of which values the items in the
* contestants array refer to.
*/
