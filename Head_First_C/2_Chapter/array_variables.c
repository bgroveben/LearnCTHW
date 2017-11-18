/*
* When you create an array, the array variable can be used as a pointer to the
* start of the array in memory.
* The computer will set aside space on the stack for each of the characters in
* the string, plus the \0 end character.
* C will also associate the address of the first character with the name of the
* variable.
* BTW, look up "pointer decay".
*/
#include <stdio.h>

int main()
{
    char quote[] = "Cookies make you sexy.";
    printf("The quote string is stored at : %p\n", quote);
    return 0;
}
