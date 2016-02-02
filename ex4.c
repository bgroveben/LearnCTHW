/*
Here is a deliberately broken version of the ex3.c code to build.
This file will be used to test and experiment with valgrind
*/
#include <stdio.h>

int main()
{
    int age = 10;
    int height;

    printf("I am %d years old.\n");
    printf("I am %d inches tall.\n", height);

    return 0;
}
