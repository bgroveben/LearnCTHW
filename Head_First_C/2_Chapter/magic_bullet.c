/*
* The Case of the Magic Bullet.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char masked_raider[] = "Alive";
    char *jimmy = masked_raider;
    printf("Masked raider is %s, Jimmy is %s.\n", masked_raider, jimmy);
    masked_raider[0] = 'D';
    masked_raider[1] = 'E';
    masked_raider[2] = 'A';
    masked_raider[3] = 'D';
    masked_raider[4] = '!';
    printf("Masked raider is %s, Jimmy is %s.\n", masked_raider, jimmy);
    return 0;
}
/*
* So what gives?
* How come a single magic bullet killed Jimmy and the Masked Raider?
* What do you think happened?
* Well, jimmy and masked_raider are just aliases for the same memory address.
* They're pointing to the same place.
*/
