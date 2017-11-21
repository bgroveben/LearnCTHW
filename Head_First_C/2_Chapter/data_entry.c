/*
* Let's get the user to enter a string from the keyboard.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[40];
    printf("Enter your name, buddy: ");
    // Tell scanf to read up to 39 characters plus the string terminator \0.
    scanf("%39s", name);
    printf("Name: %39s\n", name);
    // Notice that when it prints out, you get the space for all 39 characters.

    /*
    * You can enter data into a numeric field by passing a pointer to a
    * number variable.
    */
    int age;
    printf("Enter your age, if you dare: ");
    // Use the & operator to get the address of the int.
    scanf("%i", &age);
    printf("Age: %i\n", age);

    /*
    * You can even use scanf() to enter more than one piece of information
    * at a time.
    */
    char first_name[20];
    char last_name[20];
    printf("Enter first and last name: ");
    // The first and last names are stored in separate arrays.
    scanf("%19s %19s", first_name, last_name);
    printf("First: %s   Last: %s\n", first_name, last_name);

    return 0;
}
