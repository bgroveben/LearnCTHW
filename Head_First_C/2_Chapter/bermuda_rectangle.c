/*
The game will need to keep control of lots of things, like scores, lives and the current location of the players.
* You won’t want to write the game as one large piece of code; instead, you’ll create lots of smaller functions that will each do something useful in the game.
* A major part of the game is going to be navigating your ship around the Bermuda Rectangle, so let’s dive deeper into what the code will need to do in one of the navigation functions.
* The game will track the location of players using latitudes and longitudes.
*/

// FIRST -- figure out what this code will print out.

#include <stdio.h>

// Write a go_south_east() function that takes arguments for the latitude and longitude, which it will then increase and decrease:
void go_south_east(int lat, int lon)
{
    // Decrease the latitude:
    lat = lat -1;
    // Increase the longitude:
    lon = lon + 1;
}

int main()
{
    int latitude = 32;
    int longitude = -64;
    go_south_east(latitude, longitude);
    printf("Avast! Now at: [%i, %i]\n", latitude, longitude);
    return 0;
}
