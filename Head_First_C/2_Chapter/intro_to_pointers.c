/*
* A pointer is the address of a piece of data in memory.
* Instead of passing around a whole copy of the data, you can just pass
* a pointer.
* You might want two pieces of code to work on the same piece of data rather
* than a separate copy.
* If you’re not careful, you can quickly get lost chasing pointers through
* memory.
*/

// Variable y is stored in the globals section of memory:
int y = 1;
int main()
{
    // Variable x will live in the stack:
    int x = 4;
    return 0;
}
