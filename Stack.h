/*********************************************************************
  Author:        Dana Vrajitoru, IUSB, CS
  Class:         C243 Data Structures
  File name:     Stack.h
  Last updated:  September 2019
  Description:   Definition of a class stack derived from a list.
**********************************************************************/

#ifndef STACK_H
#define STACK_H

#include "List.h"

// A class stack containing integers derived from the class List.
class Stack: protected List {
public:
    // Default constructor: create an empty stack.
    Stack(); 
    
    // Insert an object into the stack.
    void push(int data);

    // Remove the top object and return its value.
    int pop();

    // Inspect the value of the top object.
    int top();    

    // Inspect the bottom object of the stack. Unorthodox function for a
    // stack but necessary in the game.
    int bottom();
    
    // Delete all the objects in the stack.
    void makeEmpty();

    // Test if the stack is empty.
    bool isEmpty();

    // Concatenate the stack "other" to the target object.
    void concatenate(Stack &other);

    // Very simple display of the stack for the purpose of the game.
    void print();

    // The number of objects in the stack.
    int stored();
};

#endif
