# Canfield
A simplified C++ console version of the game Canfield.
This repository contains all the files needed to compile and run the game. this include the main game playing interface, class definition and implementation files for linked list, stack, and queue, used to implement the game playing mechanism like card stackings, dealings, etc.

To compile: copy all the files into the same directory. In linux, in the terminal, simply nevigate to the directory and run the Makefile with the command "make". To run the program, enter the command "canfield".
In Windows, use an ide like visual studio, add all the source files, compile and run the game.

Rules: This is a simplified version of the game. There are no suits, so tableau and foundations are built by ranks only (foundations must start with a ace (1)). Face cards are represented by number 11-13. Cards are dealt to the waste one by one and can be redealt forever. This game is really easy to pick up, especially in this watered down version. The game gives warnings for illegal moves and have text guide for every move. Also winning is gauranteed.
