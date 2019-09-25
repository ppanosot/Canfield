
/*********************************************************************
  Author:        Dana Vrajitoru, IUSB, CS
  Class:         C243 Data Structures
  File name:     Stack.cc
  Last updated:  September 2019
  Description:   Implementation of a class stack derived from a list.
**********************************************************************/

#include <iostream>
#include <cstdlib>
using namespace std;

#include "Stack.h"

// Default constructor: create an empty stack.
Stack::Stack() : List() 
{
} //Stack::Stack()

// Insert an object into the stack.
void Stack::push(int data)
{
    insertFront(data);
} // Stack::push()

// Remove the top object and return its value.
int Stack::pop()
{
    int result = top();
    removeFront();
    return result;
} // Stack::pop() 

// Inspect the value of the top object.
int Stack::top()
{ 
    if (!isEmpty()) 
        return *begin();
    else 
    {
        cout << "attempt to access the top of an empty stack" << endl;
        exit(1);
    }  
} // Stack::top()

// Inspect the bottom object of the stack. Unorthodox function for a
// stack but necessary in the game.
int Stack::bottom()
{
    if (!isEmpty())
        return *end();
    else 
    {
        cout << "attempt to find the bottom of an empty stack" << endl;
        exit(1);
    }
} // Stack::bottom()

// Delete all the objects in the stack.
void Stack::makeEmpty()
{ 
    List::makeEmpty(); 
}// Stack::makeEmpty()

// Test if the stack is empty.
bool Stack::isEmpty()
{ 
    // return !(List)(*this); 
    return List::isEmpty();
} // Stack::isEmpty()

// Concatenate the stack "other" to the target object.
void Stack::concatenate(Stack &other)
{
    List::concatenate(other);
} // Stack::concatenate()

// Very simple display of the stack for the purpose of the game.
void Stack::print()
{
    display();
} // Stack::print()

// The number of objects in the stack.
int Stack::stored()
{
    return getSize();
} // Stack::stored()
