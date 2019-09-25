/*********************************************************************
  Author:        Dana Vrajitoru, IUSB, CS
  Class:         C243 Data Structures
  File name:     ListNode.h
  Last updated:  September 3, 2019
  Description:   Definition of a class that implements a list node 
                 containing an integer.
**********************************************************************/

#ifndef LIST_NODE_H
#define LIST_NODE_H

class ListNode {

private:
    int datum;
    ListNode *next;

public:

    // Constructor with the number only; it can be used as a default
    // too.
    ListNode(int number=0);

    // Constructor with both the number and the next pointer.
    ListNode(int number, ListNode *link);

    // Destructor. We don't delete the entire list here because we may
    // want to be able to delete individual nodes without deleting the
    // entire list attached to them.
    ~ListNode();

    // Copy constructor. It makes a soft copy of the node - the list
    // starting from the pointer next is not copied. The next pointer in
    // the target object will contain the same value as the pointer next
    // in the data object, meaning that this node points into the list
    // starting with data.
    ListNode(ListNode &data);

    // Set and get for the private attributes.
    int getDatum();
    void setDatum(int number = 0);
    ListNode *getNext();
    void setNext(ListNode *link);

    // Assignment operator. It makes a soft copy of the node - the next
    // pointer is not copied.
    ListNode &operator=(ListNode &data);

    // Hard copy of a list starting from the target object.
    ListNode *copy();
  
    // Concatenate a whole list at the end of the list starting with the
    // target object.
    void concatenate(ListNode *link);

    // Returns the last node in the list starting from the target object.
    ListNode *lastNode();

    // Deletes the entire list starting with the target object.
    friend void deleteList(ListNode *head);

    friend class List;
    friend class ListIterator;
}; // class ListNode

typedef ListNode *ListNodePtr;

#endif
