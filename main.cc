/*********************************************************************
  Author:        Dana Vrajitoru, IUSB, CS
  Class:         C243  Data Structures
  File name:     main.cc
  Last updated:  September 2019
  Description:   Main function for the program implementing the card 
                 game of Canfield using stacks and queues.
**********************************************************************/

#include "Canfield.h"
#include <ctime>
#include <cstdlib>

int main()
{
    Canfield game;
    //srand(time(NULL));
    game.play();
    return 0;
} // main()
