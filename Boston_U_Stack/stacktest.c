/* This program tests the 'stack of characters' module. */

/*
File: stacktest.c
Author: Robert I. Pitts <rip@cs.bu.edu>
Last Modified: June 16, 2016 by Benjamin Grove
Topic: Stack - Array Implementation
*/

#include <stdio.h>
#include <string.h> /* for strlen() */
#include "stack.h"

int main(void)
{
    stackT stack;     /* A stack to hold characters */
    char str[101];    /* String entered by user */
    char *traverse;   /* Pointer used to traverse the string */
    /* Get a string of 100 characters or less from the user */
    printf("Enter a string of 100 characters or less: ");
    fgets(str, sizeof(str), stdin);  /* Read line, discard newline */
    /* Initialize the stack, making it large enough to hold the string that is read in */
    StackInit(&stack, strlen(str));
    /* Traverse the string and put each character on the stack. */
    for (traverse = str; *traverse != '\0'; traverse++) {
        StackPush(&stack, *traverse);
    }
    /* Pop each of the characters off of the stack and print them out */
    printf("\nPopped characters are: ");
    while (!StackIsEmpty(&stack)) {
        printf("%c", StackPop(&stack));
    }
    printf("\n");
    StackDestroy(&stack);
    return 0;
}
