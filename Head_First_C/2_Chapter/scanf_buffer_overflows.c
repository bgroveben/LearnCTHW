/*
* The scanf() function may cause buffer overflows.
* If you forget to limit the length of the string that you read with scanf(),
* then any user can enter far more data than the program has space to store.
* The extra data then gets written into memory that has not been properly
* allocated by the computer.
* Now, you might get lucky and the data will simply be stored and not cause any
* problems.
* But it’s very likely that buffer overflows will cause bugs.
* It might be called a segmentation fault or an abort trap, but whatever the
* error message that appears, the result will be a crash.
* For example, if you just use %s in scanf(), there can be a problem if someone
* gets a little type-happy.
*/
#include <stdio.h>
#include <stdlib.h>

/*
int main()
{
    char name;
    char card_name;
    printf("Enter a name: \n");
    scanf("%39c\n", name);
    printf("%c", name);
    printf("Enter a card name: \n");
    scanf("%2c", card_name);
    printf("%c", card_name);
    return 0;
}
>>> Enter a name:
name
[1]    1883 segmentation fault  ./scanf_buffer_overflows
*/

int main()
{
    char food[5];
    printf("Enter a favorite food: ");
    scanf("%s", food);
    printf("Favorite food: %s\n", food);
    printf("%lu\n", sizeof(food));
    return 0;
}
