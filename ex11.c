// In C, there isn't really a 'boolean' type.
// Instead, any integer that is a 0 is 'false', otherwise it is 'true'.
// To a computer, truth values are just integers, after all.

// This is a while loop that does the same thing as the for loop in ex10.c.
// Compare and contrast.

#include <stdio.h>

int main(int argc, char *argv[])
{
    // go through each string in argv

    int i = 0;
    while(i < argc) {
        printf("arg %d: %s\n", i, argv[i]);
        i++;
    }
    // let's make our own array of strings
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };

    int num_states = 4;
    i = 0; // watch for this
    while(i < num_states) {
        printf("state %d: %s\n", i, states[i]);
        i++;
    }

    return 0;
}
