#include <stdio.h>

int main(int argc, char *argv[])
{
    int bugs = 100;
    double bug_rate = 1.2;

    printf("You have %d bugs at the imaginary rate of %f.\n",
            bugs, bug_rate);

    long universe_of_defects = 1L * 1024L * 1024L * 1024L;
    printf("The entire universe has %ld bugs.\n",
            universe_of_defects);

    double expected_bugs = bugs * bug_rate;
    printf("You are expected to have %f bugs.\n",
            expected_bugs);

    double part_of_universe = expected_bugs / universe_of_defects;
    printf("That is only a %e portion of the universe.\n",
            part_of_universe);

    // this makes no sense, just a demo of something weird
    char nul_byte = '\0';
    int care_percentage = bugs * nul_byte;
    printf("Which means you should care %d%%.\n",
            care_percentage);

    return 0;
}

/*
Here's what is going on in this little bit of nonsense:

ex7.c:1-4
The usual start of a C program.

ex7.c:5-6
Declare an int and a double for some fake bug data.

ex7.c:8-9
Print out those two, so nothing new here.

ex7.c:11
Declare a huge number using a new type long for storing big numbers.

ex7.c:12-13
Print out that huge number using %ld, which adds a modifier to the usual %d.
Adding 'l' (the letter ell) means "print this as a long decimal".

ex7.c15-17
Just more math and printing.

ex7.c:19-21
Craft up a depiction of your bug rate compared to the bugs in the universe which is completely inaccurate.
It is so small, though, that we have to use %e to print it in scientific notation.

ex7.c:24
Make a character with a special syntax '\0' which creates a 'nul byte' character.
This is effectively the number 0.
For more info on NUL vs. null: https://en.wikipedia.org/wiki/C_string_handling.

ex7.c:25
Multiply bugs by this character, which produces 0 for how much you care.
This demonstrates an ugly hack you find sometimes.

ex7.c:26-27
Print that out, and notice you have two percent characters (%%), sou you can print a '%' (percent) character.

ex7.c:28-30
The end of the main function.
*/

/*
This bit of source is entirely just an exercise and demonstrates how some math works.
At the end, it also demonstrats something that you see in C, but not in many other languages.
To C, a 'character' is just an integer -- a really small integer, but that's all it is.
The last part of the code (lines 22-24, I think) is a glance at how C gives you direct access to the machine.
*/
