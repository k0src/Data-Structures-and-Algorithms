#ifndef STRUCTURESALGOS_HEAP_H
#define STRUCTURESALGOS_HEAP_H

#include <stdexcept>
#include <iostream>

class Heap {
public:
    explicit Heap(int length);
    ~Heap();
    void insert(int value);
    void remove();
    bool isEmpty();
    bool isFull();
private:
    void swap(int first, int second);
    int parent(int index);
    void bubbleUp();
    int leftChildIndex(int index);
    int rightChildIndex(int index);
    int leftChild(int index);
    int rightChild(int index);
    bool isValidParent(int index);
    int largerChildIndex(int index);
    bool hasLeftChild(int index);
    bool hasRightChild(int index);

    int* array;
    int size = 0;
    int length;
};

#endif