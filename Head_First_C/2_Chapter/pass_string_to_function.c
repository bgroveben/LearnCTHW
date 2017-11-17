/*
* You know how to pass simple values as arguments to functions, but what if you
* want to send something more complex to a function, like a string?
* If you remember from the last chapter, strings in C are actually arrays of
* characters.
* That means if you want to pass a string to a function, you can do it like this:
*/

// The function will be passed a char array:
void fortune_cookie(char msg[])
{
    printf("Message reads: %s\n", msg);
    printf("msg occupies %i bytes\n", sizeof(msg));
}

char quote[] = "Cookies make you sexy";
fortune_cookie(quote);
