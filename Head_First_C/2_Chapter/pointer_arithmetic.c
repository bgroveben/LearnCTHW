/*
* An array variable can be used as a pointer to the first element in an array.
* That means you can read the first element of the array either by using the
* brackets notation or using the * operator like this:
*/
#include <stdio.h>

int main() {
    int drinks[] = {4, 2, 3};
    printf("1st order: %i drinks\n", drinks[0]);
    printf("1st order: %i drinks\n", *drinks);
    printf("\n");
    /*
    * But because an address is just a number, that means you can do pointer
    * arithmetic and actually add values to a pointer value and find the next
    * address.
    */
    printf("3rd order: %i drinks\n", drinks[2]);
    printf("3rd order: %i drinks\n", *(drinks + 2));
    return 0;
}
/*
* In general, the two expressions drinks[i] and *(drinks + i) are equivalent.
* That’s why arrays begin with index 0.
* The index is just the number that’s added to the pointer to find the location
* of the element.
*/
