/* This isn't part of 'Learn C the Hard Way', but I just have to try it.
I found this on Rosetta Code:
https://www.rosettacode.org/wiki/FizzBuzz#C*/
#include <stdio.h>

int main (void)
{
    int i;
    for (i = 1; i <= 100; i++)
    {
        if (!(i % 15))
            printf ("FizzBuzz");
        else if (!(i % 3))
            printf ("Fizz");
        else if (!(i % 5))
            printf ("Buzz");
        else
            printf ("%d", i);

        printf("\n");
    }
    return 0;
}

/* Don't forget to run 'make fizzbuzz' and './fizzbuzz' in your terminal */
