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

void StackDestroy(stackT *stackP) // this function only needs the stack to operate on
{
    // get rid of the array
    free(stackP->contents);
    // reset/free up the pointers
    stackP->contents = NULL;
    stackP->MaxSize = 0;
    stackP->top = -1;
}

int StackIsEmpty(stackT *stackP)
{
    // the top field is -1 when the stack is empty
    return stackP->top < 0;
}

int StackIsFull(stackT *stackP)
{
    // when the top is equal to the maximum size minus 1, then the stack is full 
    return stackP->top >= stackP->maxSize - 1;
}
