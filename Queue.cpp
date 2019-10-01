/*********************************************************************
  Author:        Patarut Panosot, Dana Vrajitoru, IUSB, CS
  Class:         C243 Data Structures
  File name:     Queue.cc
  Last updated:  September 18, 2019
  Description:   Implementation of a class queue derived from a list.
**********************************************************************/

#include <iostream>
#include <cstdlib>
using namespace std;

#include "Queue.h"

// Default constructor: create an empty queue.
Queue::Queue() : List()
{
} //Queue::Queue()


// Insert an object into the queue.
void Queue::enqueue(int data)
{
	insertBack(data);
} // Queue::enqueque()

// Remove the front object and return its value.
int Queue::dequeue()
{
	int result = front();
	removeFront();
	return result;
} // Queue::dequeue()

// Inspect the value of the front object.
int Queue::front()
{
	if (!isEmpty())
		return *begin();
	else
	{
		cout << "attempt to access the top of an empty stack" << endl;
		exit(1);
	}
} // Queue::front()

// Delete all the objects in the queue.
void Queue::makeEmpty()
{
	List::makeEmpty();
} // Queue::makeEmpty()

// Test if the queue is empty.
bool Queue::isEmpty()
{
	return List::isEmpty();
} // Queue::isEmpty()

// Concatenate two queues.
void Queue::concatenate(Queue &other)
{
	List::concatenate(other);
} // Queue::concatenate()

// The number of objects in the queue.
int Queue::stored()
{
	return getSize();
} // Queue::stored()