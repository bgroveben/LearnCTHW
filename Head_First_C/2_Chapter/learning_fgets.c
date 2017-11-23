#include <stdio.h>
#include <stdlib.h>

/*
* There’s another function you can use to enter text data: fgets().
* Just like the scanf() function, it takes a char pointer, but unlike the
* scanf() function, the fgets() function must be given a maximum length:
*/

int main()
{
    char food[5];
    printf("Enter the name of a food: ");
    // First, fgets() takes a pointer to a buffer.
    // Next, it takes a max size of the string ('\0' included).
    // Last, stdin means data will be coming from the keyboard.
    fgets(food, sizeof(food), stdin);
    /*
    * Note: if food was a pointer, you would give an explicit length instead of
    * using sizeof, like so:
    * fgets(food, 5, stdin);
    */
    return 0;
}
