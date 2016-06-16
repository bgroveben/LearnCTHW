Notes for this stack implementation exercise come from here:  
https://www.cs.bu.edu/teaching/c/stack/array/

Highlights:

It is usually convenient to put a data structure in its own module, so we will create the files stack.h and stack.c.  
There are 2 main parts to a C data structure:  
1. The data types needed to keep track of a stack.  
2. The functions needed to implement stack operations.
We are going to put the prototypes for each stack function in stack.h and the put the function definitions (bodies) in stack.c.  
The main method is in the stacktest.c program, which will be used to get our output (reversing a string).

To run this program:
=> make stacktest  
=> ./stacktest
