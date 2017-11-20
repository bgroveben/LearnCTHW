/*
* If pointers are just addresses, then why do pointer variables have types?
* Why can’t you just store all pointers in some sort of general pointer
* variable?
* The reason is that pointer arithmetic is sneaky.
* If you add 1 to a char pointer, the pointer will point to the very next
* memory address.
* But that’s just because a char occupies 1 byte of memory.
* What if you have an int pointer?
* ints usually take 4 bytes of space, so if you add 1 to an int pointer, the
* compiled code will actually add 4 to the memory address.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nums[] = {1, 2, 3};
    printf("nums is at %p\n", nums);
    printf("nums + 1 is at %p\n", nums + 1);
    return 0;
}
/*
* If you run this code, the two memory addresses will be more than one byte
* apart.
* So pointer types exist so that the compiler knows how much to adjust the
* pointer arithmetic.
*/
