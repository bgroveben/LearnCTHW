// Exercise 15: Pointers Dreaded Pointers
/*
In computer science, a pointer is a programming language object, whose value refers (points) to another value
stored elsewhere in the computer memory using its memory address.
A pointer references a location in memory, and obtaining the value stored at that location is known as
dereferencing the pointer.
A page number in a book's index is a pointer to the corresponding page.
You are dereferencing the pointer when you actually go to the page with the given page number.
https://en.wikipedia.org/wiki/Pointer_(computer_programming)
*/
// Here is a frivolous program that prints a group of people's ages in three different ways:

#include <stdio.h>

int main(int argc, char *argv[])
{
    // create two arrays we care about
    int ages[] = {23, 43, 12, 89, 2};
    char *names[] = {
        "Alan", "Frank", "Mary", "John", "Lisa"
    };

    // safely get the size of ages
    int count = sizeof(ages) / sizeof(int);
    int i = 0;

    // first way using indexing
    for(i = 0; i < count; i++) {
        printf("%s has %d years alive.\n", names[i], ages[i]);
    }

    printf("---\n");

    // setup the pointers to the start of the arrays
    int *cur_age = ages;
    char **cur_name = names;  // since names is 2-dimensional (an array of strings)
    // you need char ** for a 'pointer to (a pointer to char)' type

    // second way using pointers
    for(i = 0; i < count; i++) {
        printf("%s is %d years old.\n", *(cur_name+i), *(cur_age+i));
        // *(cur_name+i) is the same as name[i]
        // the value of (pointer cur_name plus i)
    }

    printf("---\n");

    // third way, pointers are just arrays
    for(i = 0; i < count; i++) {
        printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
    }

    printf("---\n");

    // fourth way with pointers in a stupid complex way using various pointer arithmetic methods
    for(cur_name = names, cur_age = ages; // initialize
            (cur_age - ages) < count; // test portion -- compare distance of the pointer from the start of ages
            cur_name++, cur_age++) // increment -- point at the next element of the name and age arrays 
    {
        printf("%s lived %d years so far.\n", *cur_name, *cur_age);
    }

    return 0;
}
