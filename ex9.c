#include <stdio.h>

int main(int argc, char *argv[])
{
    int numbers[4] = {2};
    char name[4] = {'a', 'b', 'c', '\0'};  // This is one way, but not the preferred way, to make a string

    // first, print them out raw
    printf("numbers: %d %d %d %d\n",
            numbers[0], numbers[1],
            numbers[2], numbers[3]);

    printf("name each: %c %c %c %c\n",
            name[0], name[1],
            name[2], name[3]);

    printf("name: %s\n", name);

    // set up the numbers
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    numbers[3] = 4;

    // set up the name
    name[0] = 90;   // 'Z'
    name[1] = 101;  // 'e'
    name[2] = 100;  // 'd'
    name[3] = '\0'; // null character for last bit  www.ascii-code.com

    // then print them out initialized
    printf("numbers: %d %d %d %d\n",
            numbers[0], numbers[1],
            numbers[2], numbers[3]);

    printf("name each: %c %c %c %c\n",
            name[0], name[1],
            name[2], name[3]);

    // print the name like a string
    printf("name: %s\n", name);

    // another way to use name
    char *another = "Zed";  // This is another, preferred way to make a string

    printf("another: %s\n", another);

    printf("another each: %c %c %c %c\n",
            another[0], another[1],
            another[2], another[3]);

    return 0;
}

// In the C language, there is no difference between a string and an array of characters.
// To paraphrase, a string and an array of bytes are the same thing.
