/*
* You know how to pass simple values as arguments to functions, but what if you
* want to send something more complex to a function, like a string?
* If you remember from the last chapter, strings in C are actually arrays of
* characters.
* That means if you want to pass a string to a function, you can do it like this:
*/

#include <stdio.h>
// The function will be passed a char array:
void fortune_cookie(char msg[])
{
    printf("Message reads: %s\n", msg);
    printf("The variable named msg occupies %i bytes\n", sizeof(msg));
}

int main()
{
    char quote[] = "C has an operator called sizeof that can tell you how many bytes of space something takes in memory. You can either call it with a data type or with a piece of data.";
    fortune_cookie(quote);
    return 0;
}
