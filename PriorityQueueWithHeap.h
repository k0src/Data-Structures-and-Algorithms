#ifndef STRUCTURESALGOS_PRIORITYQUEUEWITHHEAP_H
#define STRUCTURESALGOS_PRIORITYQUEUEWITHHEAP_H

// Wrapper around the heap class

#include "Heap.h"

class PriorityQueueWithHeap {
public:
    explicit PriorityQueueWithHeap(int length);
    ~PriorityQueueWithHeap();
    void enqueue(int item);
    int dequeue();
    bool isEmpty();
private:
    Heap* heap;
    int length;
};

#endif