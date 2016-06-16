// Function definitions (bodies) go here

/*
File: stack.h
Author: Robert I. Pitts <rip@cs.bu.edu>
Last Modified: June 16, 2016 by Benjamin Grove
Topic: Stack - Array Implementation

This is an array implementation of a character stack.
*/

#include <stdio.h>
#include <stdlib.h>  // for dynamic allocation
#include "stack.h"

/*  Function Definitions  */

void StackInit(stackT *stackP, int maxSize)
{
    stackElementT *newContents;
    // allocate a new array to hold the contents
    newContents = (stackElementT *)malloc(sizeof(stackElementT) * maxSize);
    // make sure that space is allocated by testing the pointer against NULL
    if (newContents == NULL) {
        fprintf(stderr, "Insufficient memory to initilaize stack.\n");
        exit(1);
    }
    // Initialize an empty stack, -1 points at the top element
    stackP->contents = newContents; // allocate space for the contents
    stackP->maxSize = maxSize; // set max size for checking fullness
    stackP->top = -1; // set up the top
}
