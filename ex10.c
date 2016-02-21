#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    // go through each string in argv
    // why are we skipping argv[0]? -- The program's name (./ex10) is at 0, with the rest coming after it.
    for(i = 1; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }

    // let's make our own array of strings
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };
    int num_states = 4;

    for(i = 0; i < num_states; i++) {
        printf("state %d: %s\n", i, states[i]);
    }

    return 0;
}
/* Set num_states wrong so that it's a higher value and see what it does:
http://blog.regehr.org/archives/213  "A Guide to Undefined Behavior in C and C++, Part 1" (of 3).
The C FAQ defines “undefined behavior” like this:
Anything at all can happen; the Standard imposes no requirements. The program may fail to compile, or it may execute incorrectly (either crashing or silently generating incorrect results), or it may fortuitously do exactly what the programmer intended.
*/

// Figure out what kinds of code you can put into the parts of a for-loop:
/* Uncomment this to make it run
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    // let's make our own array of strings
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };

    int num_states = 4;

    for (; ;) {
        if (i >= num_states) {
            break;
        }

        printf("state %d: %s\n", i, states[i]);

        i++;
    }

    return 0;
}
*/
