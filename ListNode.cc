/*********************************************************************
  Author:        Dana Vrajitoru, IUSB, CS
  Class:         C243 Data Structures
  File name:     ListNode.cc
  Last updated:  September, 2019
  Description:   Implementation of a class that implements a list node 
                 containing an integer.
**********************************************************************/

#include <iostream>
using namespace std;
#include <cstdlib>

#include "ListNode.h"

// Constructor with the number only; it can be used as a default too.
ListNode::ListNode(int number) 
    :datum(number), next(NULL)
{
} // ListNode::ListNode()

// Constructor with both the number and the next pointer.
ListNode::ListNode(int number, ListNode *link)
    :datum(number), next(link)
{
} // ListNode::ListNode()

// Destructor.  We don't delete the entire list here because we may
// want to be able to delete individual nodes without deleting the
// entire list attached to them.
ListNode::~ListNode()
{
} // ListNode::~ListNode()

// Copy constructor. It makes a soft copy of the node - the list
// starting from the pointer next is not copied. The next pointer in
// the target object will contain the same value as the pointer next
// in the data object, meaning that this node points into the list
// starting with data.
ListNode::ListNode(ListNode &data)
    :datum(data.datum), next(data.next)
{
} //ListNode::ListNode()

// Set and get the private attributes.
// Get the value of the datum. Accessor method.
int ListNode::getDatum()
{
    if (this) // check if we even have a target object
        return datum;
    else        
    {
        cerr << "Accessing a NULL pointer. Terminating program now." << endl;
        exit(1);
    }
} // ListNode::getDatum()

// Set the value of the datum.
void ListNode::setDatum(int number)
{
    if (this) // check if we even have a target object
        datum = number;
    else        
    {
        cerr << "Accessing a NULL pointer. Terminating program now." << endl;
        exit(1);
    }
} // ListNode::setDatum()

// Get the value of next. Accessor method.
ListNode *ListNode::getNext()
{
    if (this) // check if we even have a target object
        return next;
    else        
    {
        cerr << "Accessing a NULL pointer. Terminating program now." << endl;
        exit(1);
    }
} // ListNode::getNext()

// Set the value of next.
void ListNode::setNext(ListNode *link)
{
    if (this) // check if we even have a target object
        next = link;
    else        
    {
        cerr << "Accessing a NULL pointer. Terminating program now." << endl;
        exit(1);
    }
} // ListNode::setNext()

// Assignment operator. It makes a soft copy of the node - the next
// pointer is not copied.
ListNode &ListNode::operator=(ListNode &data)
{
    // check that we're not assigning the object to itself
    if (&data != this) 
    {
        datum = data.datum;
        next = data.next;
    }
    return *this;
} // ListNode::operator=()

// Hard copy of a list starting from the target object.
/* Alternative recursive version
   ListNode *ListNode::copy() 
   {
   ListNode *new_node = new ListNode(*this);
   if (next)
   new_node->next = next->copy();
   return new_node;
   }
*/
// copy the list starting with this node and following up to the end
ListNode *ListNode::copy() 
{
    ListNode *p, *temp, *tail=NULL, *head = NULL;

    // start from this node
    p = this; 
    while (p) 
    {
        // create a new node containing the same datum as p
        temp = new ListNode(p->datum);

        // if it's not the first, add it to the back of the new list
        if (head) 
        { 
            tail->next = temp; 
            tail = temp;
        }
        else // otherwise make it both first and last
            head = tail = temp;

        p = p->next; // move to the next node to copy
    }
    return head;
} // ListNode::copy() 

// Concatenate a whole list at the end of the list starting from the
// target object.
/* Alternative recursive version
   void ListNode::concatenate(ListNode *link)
   {
   if (!next) // this is the last node in the list
   next = link;
   else
   next->concatenate(link);
   }
*/
void ListNode::concatenate(ListNode *link)
{
    // check if we're trying to concatenate a list to itself
    if (this == link) 
    {
        cout << "Attempt to concatenate a list to itself; operation aborted."
             << endl;
        return;
    }
    // go to the end of this list
    ListNode *p = lastNode(); // calling this from the target object.
    if (p) // add the node here if the current list is not empty
        p->next = link;
} // ListNode::concatenate()

// Delete the entire list starting from the target object.
void deleteList(ListNode *head)
{
    ListNode *temp;
    while (head) // we still have nodes to delete
    {
        temp = head;       // store the current node
        head = head->next; // move the head to the next
        delete temp;       // now we can delete it
    }
} // deleteList()

// Returns the last node in a list starting from the target object.
ListNode *ListNode::lastNode()
{
    ListNode *p = this;  // start from the current node
    while (p && p->next) // while we are not at the last node
        p = p->next;     // move forward
    return p;            // return the last node
} // ListNode::lastNode()
