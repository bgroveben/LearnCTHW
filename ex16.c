// Exercise 16: Structs and Pointers To Them

/*
In this exercise we are going to learn how to make a 'struct', point a pointer at them, and use them to make sense of internal memory structures.
We will also apply the knowledge of pointers from ex15 so we can build these structures from raw memory using 'malloc'.
*/

// Now that we are including more and different header files, it is time to do a bit of research on them and what they do.

/* A good list of header files for the C language can be found at:
http://www.tutorialspoint.com/c_standard_library/index.htm
http://www.cplusplus.com/reference/clibrary/
http://en.cppreference.com/w/c/header
*/
#include <stdio.h>
/* The <stdio.h> header provides generic file operation support and supplies functions with narrow character input/ouput capabilities.
http://en.cppreference.com/w/c/io
https://en.wikipedia.org/wiki/C_file_input/output
https://en.wikibooks.org/wiki/C_Programming/C_Reference/stdio.h
*/
#include <assert.h>
/* The <assert.h> header defines the assert() macro used for diagnostics/testing/error handling.
http://pubs.opengroup.org/onlinepubs/9699919799/
https://en.wikipedia.org/wiki/Assert.h
http://en.cppreference.com/w/c/error/assert
*/
#include <stdlib.h>
/* <stdlib.h> is the header of the general purpose standard library.
It includes functions involving memory allocation, process control, conversions, and others.
https://en.wikibooks.org/wiki/C_Programming/C_Reference/stdlib.h
http://www.techonthenet.com/c_language/standard_library_functions/stdlib_h/
http://pubs.opengroup.org/onlinepubs/009695399/basedefs/stdlib.h.html
*/
#include <string.h>
/* <string.h> deals with string handling functions including comparison, concatenation, copying, search, and others.
https://en.wikibooks.org/wiki/C_Programming/Strings#The_.3Cstring.h.3E_Standard_Header
https://www.cs.cf.ac.uk/Dave/C/node19.html#SECTION001910000000000000000
http://www.cplusplus.com/reference/cstring/
*/

struct Person {
    char *name;
    int age;
    int height;
    int weight;
};
/*
A struct is a complex data type declaration that defines a physically grouped list of variables to be placed
under one name in a block of memory, allowing the different variables to be accessed via a single pointer,
or the struct declared name which returns the same address.
https://en.wikipedia.org/wiki/Struct_(C_programming_language)
*/

struct Person *Person_create(char *name, int age, int height, int weight)
{
    struct Person *who = malloc(sizeof(struct Person));
    assert(who != NULL);

    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight = weight;

    return who;
}

void Person_destroy(struct Person *who)
{
    assert(who != NULL);

    free(who->name);
    free(who);
}

void Person_print(struct Person *who)
{
    printf("Name: %s\n", who->name);
    printf("\tAge: %d\n", who->age);
    printf("\tHeight: %d\n", who->height);
    printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
    // make two people structures
    struct Person *joe = Person_create(
        "Joe Alex", 32, 64, 140);

    struct Person *frank = Person_create(
        "Frank Blank", 20, 72, 180);

    // print them out and where they are in memory
    printf("Joe is at memory location %p:\n", joe);
    Person_print(joe);

    printf("Frank is at memory location %p:\n", frank);
    Person_print(frank);

    // make everyone age 20 years and print them again
    joe->age += 20;
    joe->height -= 2;
    joe->weight += 40;
    Person_print(joe);

    frank->age += 20;
    frank->weight += 20;
    Person_print(frank);

    // destroy them both so we clean up
    Person_destroy(joe);
    Person_destroy(frank);

    return 0;
}
