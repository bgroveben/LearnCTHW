#include <stdio.h>

int main(int argc, char *argv[])
{
    int areas[] = {10, 12, 13, 14, 20};
    char name[] = "Zed";
    char full_name[] = {
        'Z', 'e', 'd',
        ' ', 'A', '.', ' ',
        'S', 'h', 'a', 'w', '\0'
    };

    // WARNING: On some systems you may have to change the
    // %ld in this code to a %u since it will use unsigned ints
    printf("The size of an int: %ld\n", sizeof(int));
    printf("The size of areas (int[]): %ld\n",
            sizeof(areas));
    printf("The number of ints in areas: %ld\n",
            sizeof(areas) / sizeof(int));
    printf("The first area is %d, the 2nd %d.\n",
            areas[0], areas[1]);

    printf("The size of a char: %ld\n", sizeof(char));
    printf("The size of name (char[]): %ld\n",
            sizeof(name));
    printf("The number of chars: %ld\n",
            sizeof(name) / sizeof(char));

    printf("The size of full_name (char[]): %ld\n",
            sizeof(full_name));
    printf("The number of chars: %ld\n",
            sizeof(full_name) / sizeof(char));

    printf("name=\"%s\" and full_name=\"%s\"\n",
            name, full_name);

    return 0;
}

/*
Now, let's go through the output of these different printf calls.
5
My computer thinks an int is 4 bytes in size. Your computer might use a different size if it's 32 vs 64 bits.

6
The areas array has 5 integers in it, so it makes sense that my computer requires 20 bytes to store it.

7
If we divide the size of areas by size of an int then we get 5 elements.
Looking at the code, this matches what we put in the initializer.

8
We then did an array access to get areas[0] and areas[1], which means C is zero-indexed like Python and Ruby.

9-11
We repeat this for the name array, but notice something odd about the size of the array?
It says it is 4 bytes long, but we only typed "Zed" for 3 characters.
Where's the 4th one coming from? I believe it is for a null character '\0' appended after 'd'.

12-13
We do the same thing with full_name and notice that it gets this correct.

13 Finally, we just print out the name and full_name to prove that they actually are "strings" according to printf.
*/
