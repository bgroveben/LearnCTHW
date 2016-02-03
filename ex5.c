#include <stdio.h>

/* This is a comment .*/
int main(int argc, char *argv[])
{
    int distance = 100;

    // this is also a comment
    printf("You are %d miles away.\n", distance);

    return 0;
}
/**/
/*
Breaking it Down

There's a few features of the C language in this code that you might have only slightly figured out while you were
typing code. Let's break this down line-by-line quickly, and then we can do exercises to understand each part better:

ex5.c:1
An include and it is the way to import contents of one file into this source file.
C has a convention of using .h extensions for header files, which contain lists of functions you can use in your program.

ex5.c:3
This is a multi-line comment and you can put as many lines of text between the opening and closing characters as you want.

ex5.c:4
A more complex version of the main function you've been using blindly so far.
How C programs work is the operating system loads your program, then runs the function named main.
For the function to be totally complete it needs to return an int and take two parameters:
-- an int for the argument count, and an array of char * strings for the arguments.
Did that just fly over your head? Not to worry, we'll cover this soon.

ex5.c:5
To start the body of any function you write a { character that indicates the beginning of a "block".
In Python you just did a : and indented.
In other languages you might have a begin of do word to start.

ex5.c:6
A variable declaration and assignment at the same time.
This is how you create a variable, with the syntax:
type name = value;
In C statements (except for logic) end in a semicolon ; character.

ex5.c:8
Single line comment, just like JavaScript.

ex5.c:9
A call to your old friend printf.
Like in many languages function calls work with the syntax
name(arg1, arg2);
and can have any number of arguments.
The printf function is actually kind of wierd and can take multiple arguments. We'll see that later.

ex5.c:11
A return from the main function which gives the OS your exit value.
You may not be familiar with how Unix software uses return codes, so we'll cover that as well.

ex5.c:12
Finally, we end the main function with a closing brace } character, and that's the end of the program.
*/
