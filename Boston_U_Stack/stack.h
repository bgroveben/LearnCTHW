// Prototypes for each stack function go here

/*
File: stack.h
Author: Robert I. Pitts <rip@cs.bu.edu>
Last Modified: June 16, 2016 by Benjamin Grove
Topic: Stack - Array Implementation

This is the interface for a stack of characters
*/

#ifndef _STACK_H
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
