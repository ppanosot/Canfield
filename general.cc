/*********************************************************************
  Author:        Dana Vrajitoru, IUSB, CS
                 W. Knight, IUSB, CS
  Class:         C243 Data Structures
  File name:     general.cc
  Last updated:  September 2019
  Description:   Some useful general purpose functions.
**********************************************************************/

#include <iostream>
using namespace std;

#include <cstdlib>

#include "general.h"

/*********************  T E S T   A L L O C A T I O N  ********************

This utility function accepts as an argument a pointer of any type whatsoever.
It tests the pointer "p" to see whether it is NULL, and if it is, the function
terminates the program with an error message saying "dynamic allocation
failed."  If "p" is not NULL, the function does nothing.  This function is NOT 
a member of a class.  Documented and coded by W. Knight.  */

void testAllocation(void *p)
{
    if (!p)
    {
        cout << "Dynamic allocation failed.  Program being terminated."
             << endl;
        exit(1);
    }
} // testAllocation()


// Reads a number between 0 and the limit. If the user enters
// something outside the limit, they are asked to enter the number
// again.
void getNumber(int &n, int limit)
{
    cin >> n;
    while (!cin.good() || n < 0 || n >= limit) 
    {
        if (!cin.good()) 
        {
            cin.clear();
            cin.ignore(100,'\n');
        }
        cout << "Please enter a number between 0 and " << limit << endl;
        cin >> n;
    }
} // getNumber()

// Swap two integers
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
} // swap

// Clears the terminal screen.
void clearScreen()
{
    for (int i=0; i<24; i++)
        cout << endl;
} // clearScreen()
