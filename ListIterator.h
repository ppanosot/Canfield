/*********************************************************************
  Author:        Dana Vrajitoru, IUSB, CS
  Class:         C243 Data Structures
  File name:     ListIterator.h
  Last updated:  September 3, 2019
  Description:   Definition of the list iterator class.
**********************************************************************/

#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H

#include "ListNode.h"

class ListIterator {

private:
    ListNode *current;

public:
    // Default constructor. We need to make sure the pointer current is
    // initialized to NULL.
    ListIterator();

    // Constructor from a ListNode pointer.
    ListIterator(ListNode *link);

    // Assignment operator with a ListNode pointer
    ListNode *operator=(ListNode *link);

    // Comparison operator.
    bool operator==(ListIterator &data);

    // Operator to advance the pointer.
    ListIterator &operator++();

    // Operator to access the content of the node. If the pointer is null, 
    // it exits the program with an error message.
    int &operator*();

    // Operator to check if the pointer is not null.
    operator bool();

    // Operator to convert to a ListNodePtr.
    operator ListNodePtr();

    // Swaps the content of the target object with the other iterator if
    // they are both not null. If one of them is null the function
    // returns false, otherwise true.
    bool swap(ListIterator &other);

    // Functions to be implemented by the student.

    // Locates the minimum in the list starting from the target object
    // and returns a list iterator containing a pointer to this node.
    ListIterator min();

    // This operator should move the iterator forward by a number of
    // nodes indicated by the parameter. If there are not enough nodes
    // to skip that many steps forward, the current pointer should be
    // made NULL.
    ListIterator &moveForward(int steps);

    friend class List;
};

#endif
