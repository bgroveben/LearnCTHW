// Code for this program:
// http://www.tutorialspoint.com/data_structures_algorithms/stack_program_in_c.htm
// For a description of a stack data structure:
// http://www.tutorialspoint.com/data_structures_algorithms/stack_algorithm.htm

#include <stdio.h>

int MAXSIZE = 8;
int stack[8];
int top = -1;

int isempty() {

    if(top == -1)
        return 1;
    else
        return 0;
}

int isfull() {

    if(top == MAXSIZE)
        return 1;
    else
        return 0;
}

int peek() {
    return stack[top];
}

int pop() {
    int data;

    if(!isempty()) {
        data = stack[top];
        top = top - 1;
        return data;
    } else {
        printf("The Stack is empty, no data to retrieve.\n");
    }

    return 0;
}

int push(int data) {

    if(!isfull()) {
        top = top + 1;
        stack[top] = data;
    } else {
        printf("The Stack is full, no data can be inserted.\n");
    }

    return 0;
}

int main() {
    // push some stuff onto the stack
    push(3);
    push(5);
    push(9);
    push(1);
    push(12);
    push(15);

    printf("Element at the top of the stack: %d\n", peek());
    printf("Elements: \n");

    // print stack data
    while(!isempty()) {
        int data = pop();
        printf("%d\n", data);
    }

    printf("Stack full: %s\n", isfull()?"true":"false");
    printf("Stack empty: %s\n", isempty()?"true":"false");

    return 0;
}
