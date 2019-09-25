/*********************************************************************
  Author:        Dana Vrajitoru, IUSB, CS
  Class:         C243 Data Structures
  File name:     Queue.h
  Last updated:  September 2019
  Description:   Definition of a class queue derived from a list.
**********************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

#include "List.h"

// A class queue containing integers derived from the class List.
class Queue: protected List {
public: 
    // Default constructor: create an empty queue.
    Queue(); 

    // Insert an object into the queue.
    void enqueue(int data);

    // Remove the front object and return its value.
    int dequeue();

    // Inspect the value of the front object.
    int front();

    // Delete all the objects in the queue.
    void makeEmpty();

    // Test if the queue is empty.
    bool isEmpty();

    // Concatenate two queues.
    void concatenate(Queue &other);

    // The number of objects in the queue.
    int stored();
};

#endif
