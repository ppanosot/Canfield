/*********************************************************************
  Author:        Dana Vrajitoru, IUSB, CS
  Class:         C243 Data Structures
  File name:     List.cc
  Last updated:  September 3, 2019
  Description:   Implementation of a container class for a list.

**********************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

#include "general.h"
#include "List.h"

// Default constructor.
List::List()
    : head(NULL), tail(NULL), size(0) // empty list
{
} // List::List()

// Copy constructor. The target object should be assigned a hard copy
// of the list contained in the data object.
List::List(List &data)
    : head(NULL), tail(NULL), size(0) // start with an empty list
{
    *this = data; // then use the operator= form this class
} // List::List()

// Destructor. Deletes the entire list.
List::~List()
{
    // call the function makeEmpty instead so that we only have to
    // change things in one place
    makeEmpty();
} // List::~List()

// Assignment operator. It must also make a hard copy of the
// list. Make sure that the tail of the target object is also set
// correctly.
List &List::operator=(List &data)
{
    if (this != &data) // check that we're not assigning the object to itself
    {
        makeEmpty();
        size = data.size;
        head = data.head->copy(); // make a copy of the list instead of 
                                  // of assigning just the pointer 
        tail = head->lastNode();  // now we have to find the last node
                                  // because we've copied the list
    }

    return *this; 
} // List::operator=()

// Returns the size of the list.
int List::getSize()
{
    return size;
} // List::getSize()

// Inserts a new node with the number parameter stored as datum at the
// front of the list. It must make sure to update both the head and
// the tail of the list if need be.
void List::insertFront(int number)
{
    // create a node with the data and pointing towards the head
    ListNodePtr newNode = new ListNode(number, head);
    testAllocation(newNode);

    size++;             // we're adding a node

    head = newNode;     // this one becomes the head of the list

    if (size == 1)      // if it was the first one
        tail = newNode; // then it's also the tail
} // List::insertFront()

// Removes the node in the list that follows the one referenced by the
// iterator. If the iterator contains a NULL pointer, the front node
// is removed. It returns false if the list was empty and no node was
// removed and true otherwise.
bool List::removeNodeAfter(ListIterator iter)
{
    if (!iter) // current in iter is NULL
        return removeFront();
    else 
    {
        if (!iter.current->next) // iter is the last node
            return false;        // nothing to remove in this case
        else
        {
            ListNodePtr temp = iter.current->next; // the node to delete
            iter.current->next = iter.current->next->next; // adjust links
            delete temp;
            size--;
            if (!iter.current->next) // if the node we deleted was the last one
                tail = iter.current; // then we have a new tail.
            return true;
        }
    }
} // List::removeNodeAfter()

// Checks if the list is empty.
bool List::isEmpty()
{
    return (size == 0); // we can check the size or the pointers
} // List::isEmpty()

// Converts the list to Boolean. It returns true if the list is not
// empty, and false if it is.
List::operator bool()
{
    return !isEmpty(); // return true if the list is not empty
} // List::operator bool()

// Deletes the entire list and resets all the data.
void List::makeEmpty()
{
    if (size) // if the list is not empty
    {
        deleteList(head); // call the function from ListNode.cc
        head = NULL; // then reset the data
        tail = NULL;
        size = 0;
    }
} // List::makeEmpty()

// Difference operator - it must compare the content of the two lists
// and not just the pointers to them.
bool List::operator!=(List &data)
{
    return !(*this == data); // call the operator== on the object,
                             // not on the pointer
} // List::operator!=()

// Concatenates the data list to the one in the target object and
// empties the data list.
void List::concatenate(List &data)
{
    if (head != data.head) // if the two lists are not the same
    {
        if (head) // if the first list is not empty
        {
            // call the ListNode function to add the second list 
            // to the tail of the first
            tail->concatenate(data.head); 
            size += data.size; // we also have to update the size
            if (data.tail)     // and the tail
                tail = data.tail;
        }
        else // if the first list is empty
        {
            // move the list from the second one into it
            head = data.head;
            size = data.size;
            tail = data.tail;
        }
        if (data) // if the second list was not empty, unlink/empty it
        {
            data.size = 0;
            data.head=NULL;
            data.tail=NULL;
        }
    }
    else // error
        cout << "Attepmt to concatenate a list to itself. "
             << "Operation ignored." << endl;
} // List::concatenate()
  
// Prints the last node in the list: the tail.
void List::printLast()
{
    if (tail) // check that we have a last node
        cout << "The last node in the list contains " 
             << tail->datum << endl;
    else
        cout << "The list is empty, it has no last node" << endl;
} // List::printLast()

/*******************************************************************/
// Functions using list iterators.

// Begining of the list returned as a list iterator.
ListIterator List::begin()
{
    return ListIterator(head); 
} // 

// End of the list returned as a list iterator.
ListIterator List::end()
{
    return ListIterator(tail);
} // List::end()

// Prints the list to the console. It also outputs the number of nodes
// and whether the list is empty.  The function is writen using list
// iterators.
void List::print()
{
    // print the count first
    cout << "The list has " << size << " nodes." << endl;

    if (size)   // if the list is not empty
    {
        // print all the nodes using an iterator
        cout << "Here are the nodes of the list:" << endl;
        ListIterator iter(head); //start from the head
        while (iter) // while we haven't reached the end
        {
            cout << *iter << ' '; // print the datum
            ++iter; // move to the next node
        }
        cout << endl;
    }
} // List::print()

// Searches for the parameter number in the list and returns a list
// iterator referencing the node containing this number. If the number
// is not in the list, it returns an iterator where the pointer
// current is NULL.
ListIterator List::locate(int number)
{
    ListIterator locator = begin(); // start form the head
    while (locator && *locator != number) // while we haven't reached the end
                                          // nor found the target
        ++locator; // move to the next node
    return locator; // return the iterator containing the target
                    // or containing NULL if it wasn't there
} // List::locate()

// Returns the element i of the list in the form of a list iterator,
// where index=0 returns the first node of the list. If the list has
// less than index+1 nodes, then it should return a null iterator.
ListIterator List::nodeAtIndex(int index)
{
    // This should work once you implement moveForward.
    ListIterator start = begin();
    start.moveForward(index);
    return start;
} // List::nodeAtPosition()

// The bubble sort implemented on the list using list iterators.
void List::bubbleSort()
{
    if (head) // if the list is not empty
    {
        bool ordered = false;
        ListIterator iter1, iter2; // need two iterators
        while (!ordered) // while the list is not sorted
        {
            ordered = true; // we'll assume it is sorted
            iter1 = head;   // start form the head with one
            iter2 = head->next; // and the next with the other
            while (iter2) 
            {
                if (*iter1 > *iter2) // if two nodes are out of order
                {
                    iter1.swap(iter2); // swap their datums
                    ordered = false;   // and set the flag
                }
                ++iter1; // move both iterators at the same time
                ++iter2; // so they will allways be adjacent nodes
            }
        }
    }
} // List::bubbleSort()

/*******************************************************************/
// Functions to be written by the student. 

// search the list for the parameter number, if finds the number,
// update index parameter to the position of node with number
// and return true, else return false
bool List::findIndex(int number, int & index)
{
    index = 0;
    ListIterator locator = begin(); // start form the head
    while (locator) // while we haven't reached the end
    {				// nor found the target
        if (*locator == number) // find match
        {
            return true;
        }
        ++locator; // move to the next node
        ++index;
    }
    index = 0; // reset just in case
    return false; // return 
} // List::refindIndex()

// Comparison operator - it must compare the content of the two
// lists and not just the pointers to them.
bool List::operator==(List &data)
{
    if (size == data.size)
    {
    ListIterator iter1, iter2;
    iter1 = head;
    iter2 = data.head;

    while (iter1) // checking only one is sufficient 
    {             // since the two lists have the same size
        if (*iter1 != *iter2)
        {
            return false;
        }
            ++iter1; // move both iterator to the next node
            ++iter2;
        }
    }
    else
    {
        return false;
    }
    return true;
} // List::operator==()


// Inserts a new node with the specified content at the back of the
// list. Could be calling another class method if appropriate. The
// code must be supplied by the student.
void List::insertBack(int number)
{
    // create a node with the data and pointing towards the tail
    ListNodePtr newNode = new ListNode(number);
    testAllocation(newNode);

    if (head)                   // if list is not empty
    {
        tail->setNext(newNode); // point the next pointer of the previous tail to
                                // the new node
    }
    size++;             // update new size				  
    tail = newNode;     // update tail of the list

    if (size == 1)      // if it was the first one
        head = newNode; // then it's also the head
} // List::insertBack()

// Inserts a node after the node pointed to by current in the
// iterator. We assume that the existing node is part of the list. If
// current in the iterator is NULL, then the function should insert
// the new node at the front of the list. The function should update
// head, tail, and size properly.
void List::insertAfter(ListIterator iter, int number)
{
    if (iter.current == NULL) // if no list, insert to front
    {
        insertFront(number);
    }
    else
    {
        ListNodePtr newNode = new ListNode(number);
		testAllocation(newNode);
        newNode->next = iter.current->next; // insert newNode into the linked list
        iter.current->next = newNode;
        if (!newNode->next) // if newNode is last node
        {
            tail = newNode;
        }
        size++;	            // update size
    }
} // List::insertAfter()

// same as insertAfter but takes an int index parameter instead of iterator.
// calls insertAfter to do the actual insert.
// if index >= size, insert at back.
// if index negative, insert at front.
void List::insertAfterIndex(int index, int number)
{
    if (index < 0)
    {
        insertFront(number);
    }
    else if (index >= (size-1))
    {
        insertBack(number);
    }
    else
    {
        ListIterator iter = begin();
        int counter = 0;
        while (counter != index)
        {
            ++iter;
            ++counter;
        }
        insertAfter(iter, number);
    }
} // List::insertAfterIndex()

// Removes the front node from the list and deletes the memory of the
// node to be removed. The function should return true if a node was
// removed, and false if the list was already empty. The head, tail
// (!), and size of the list should be updated correctly.
// THIS DOES NOT NEED TO USE ITERATORS.
bool List::removeFront()
{
    if (head) // check if list exists
    {
        if (size == 1) // if only one node
        {
            delete head;
            head = NULL;
            tail = NULL;
            size = 0;
            return true;
        }
        else
        {
            ListNodePtr temp = head;
            head = head->next; // move head to 2nd node
            delete temp;      // delete first node
            --size;
            return true;
        }
    }
    return false; // did not remove any node;
} // List::removeFront()

// Checks if the list is in ascending order.
bool List::isOrdered()
{
    ListIterator iter1, iter2;
    iter1 = head;
    if (iter1) // at list has at least 1 node
    {
        iter2 = iter1.current->next;
    }
    else 
    {
        iter2 = iter1;  //skip loop
    }
    while (iter2)        // iter1 not pointing to last node
    {
        if (*iter1 > *iter2)
        {
            return false;
        }
        ++iter1;
        ++iter2;
    }
    return true;
} // List::isOrdered()

// Counts the number of negative values in the list. If the list is
// empty, just return 0.
int List::countNegative()
{
    ListIterator iter = head;
    int counter = 0;
    while (iter) // while pointing to some nodes
    {
        if (*iter < 0)   // if datum is negative
        {
            ++counter;   // increment counter
        }
        ++iter;
    }

    return counter;
} // List::countNegative()

// This function computes the sum of all the numbers stored in the
// list. It should be implemented using list iterators.
int List::sum()
{
    ListIterator iter = head;
    int sum = 0;
    while (iter)
    {
        sum += *iter;
        ++iter;
    }

    return sum;
} // List::sum()

// This function should implement the selection sort on a list using
// list iterators. It should have an iterator scanning the list but
// stopping before the last node. For every position in the list, it
// would have to find the location of the minimal number in the list
// using a call to the appropriate function from the ListIterator
// class. Then if the location of the minimum is not the same as the
// current node, swap the value of the current node with the minimum.
void List::selectionSort()
{
    if (size < 2) // cant sort
    {
        return;
    }

    ListIterator iter1, iter2;
    iter1 = head;
    while (iter1.current->next) // iter1 not pointing to last node
    {
        iter2 = iter1.min();
        iter1.swap(iter2);
        ++iter1;
    }
    // Should do the following in a loop, followed by a swap.
    // iter2 = iter1.min();
} // List::selectionSort()

// Very simple display of the List with no other messages.
void List::display()
{
    if (size) 
    {
        ListIterator iter(head);
        while (iter) 
        {
            cout << setw(2) << *iter << ' ';
            ++iter;
        }
    }
} // List::display()
