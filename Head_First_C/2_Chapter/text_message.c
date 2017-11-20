/*
* Use the power of pointer arithmetic to mend a broken heart.
* This function will skip the first six characters of the text message.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *msg_from_amy = "Don't call me";
    skip(msg_from_amy);
    return 0;
}
int skip(char *msg)
{
    puts(msg + 6);
    return 0;
}
/*
* C Header files:
* http://en.cppreference.com/w/c/header
* The C Preprocessor:
* https://gcc.gnu.org/onlinedocs/gcc-3.0.2/cpp.html#SEC_Top
*/
