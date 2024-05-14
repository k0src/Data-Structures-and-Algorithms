#include "PriorityQueueWithHeap.h"

PriorityQueueWithHeap::PriorityQueueWithHeap(int length) {
    this->length = length;
    heap = new Heap(length);
}

PriorityQueueWithHeap::~PriorityQueueWithHeap() {
    delete heap;
}

int PriorityQueueWithHeap::dequeue() {
    int top = heap->root();
    heap->remove();
    return top;
}

void PriorityQueueWithHeap::enqueue(int item) {
    heap->insert(item);
}

bool PriorityQueueWithHeap::isEmpty() {
    return heap->isEmpty();
}