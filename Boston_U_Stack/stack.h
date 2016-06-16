/* Stack types and prototypes for each stack function go here. */

/*
File: stack.h
Author: Robert I. Pitts <rip@cs.bu.edu>
Last Modified: June 16, 2016 by Benjamin Grove
Topic: Stack - Array Implementation

This is the interface for a stack of characters
*/

#ifndef _STACK_H  /* #ifndef - Returns true if this macro is not defined */
#define _STACK_H

/*
Type: stackElementT
This is the type of the objects entered in the stack.
Edit it to change the type of things to be placed in the stack.
*/
typedef char stackElementT;

/*
Type: stackElementT
This is the type for a stack, i.e., it is a type that holds the information necessary to keep track of a stack.
It has a pointer 'contents' to a dynamically-allocated array (used to hold the contents of the stack),
an integer 'maxSize' that holds the size of this array (i.e., the maximum number of things that can be held in the stack),
and another integer 'top', which stores the array index of the element at the top of the stack.
*/
typedef struct {
    stackElementT *contents;
    int maxSize;
    int top;
}   stackT;

/*
Function: StackInit
Usage: StackInit(&stack, maxSize);
A new stack variable is initialized.
The initialized stack is empty.
MaxSize is used to determine the maximum number of characters that can be held in the stack.
*/
void StackInit(stackT *stackP, int maxSize);

/*
Function: StackDestroy
Usage: StackDestroy(&stack);
This function cleans up a stack when we are done with it.
It should get rid of any dynamically-allocated memory and set the stack to some reasonable state.
This function frees all memory associated with the stack (to prevent memory leaks).
The 'stack' variable may not be used again unless StackInit(&stack, maxSize) is first called on the stack.
*/
void StackDestroy(stackT *stackP);


/*
Functions: StackIsEmpty, StackIsFull
Usage: if(StackIsEmpty(&stack));
       if(StackIsFull(&stack));
These functions return a true value if the stack is empty or full.
It is not necessary to pass a stack by reference (with a pointer) to these functions because they do not change the stack.
However, then some of the stack functions would use pointers, and some would not.
It is more consistent to just pass stacks by reference (with a pointer) all the time.
*/
int StackIsEmpty(stackT *stackP);
int StackIsFull(stackT *stackP);

/*
Functions: StackPush, StackPop
Usage: StackPush(&stack, element);
       element = StackPop(&stack);
These are the fundamental stack operations that add an element to the top of the stack
and remove an element from the top of the stack.
A call to StackPop on an empty stack or to StackPush on a full stack will throw an error.
Use StackIsFull and StackIsEmpty to avoid those errors.
*/
void StackPush(stackT *stackP, stackElementT element);
stackElementT StackPop(stackT *stackP);

#endif  /* not defined _STACK_H */
