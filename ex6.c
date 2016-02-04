/*
You should be getting a grasp of how a simple C program is structured, so let's explore some different types of variables.
*/
#include <stdio.h>

int main(int argc, char *argv[])
{
    int distance = 100;
    float power = 2.345f;
    double super_power = 56789.4532;
    char initial = 'A';
    char first_name[] = "Zed";
    char last_name[] = "Shaw";

    printf("You are %d miles away.\n", distance);
    printf("You have %f levels of power.\n", power);
    printf("You have %f awesome super powers.\n", super_power);
    printf("I have an initial %c.\n", initial);
    printf("I have a first name %s.\n", first_name);
    printf("I have a last name %s.\n", last_name);
    printf("My whole name is not really %s %c. %s.\n", first_name, initial, last_name);

    return 0;
}
/*
In this program we're declaring variables of different types and then
printing them with different printf format strings.

Here's the breakdown of how they match up:
Integers:
You declare integers with the int keyword and print them using %d.
Floating Point:
Declared with float or double depending on how big they need to be, and printed with %f.
Character:
Declared with char, written with a single quote '' around the character, and printed with a %c.
String(Array of Characters):
Declared with char name[], written with double quotes "" around the characters, and printed with %s.

Note that C makes a distinction between single-quotes for char and double-quote for char[] or strings
*/
