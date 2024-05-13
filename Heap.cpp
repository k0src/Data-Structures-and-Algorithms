#include "Heap.h"

Heap::Heap(int length) {
    // Initial capacity
    array = new int[length];
    this->length = length;
}

Heap::~Heap() {

}

void Heap::insert(int value) {
    if (isFull())
        throw std::invalid_argument("Too many items.");
    array[size++] = value;
    bubbleUp();
}

void Heap::bubbleUp() {
    int index = size - 1;
    // if value at current index if greater than parent, bubble up
    while (index > 0 && array[index] > array[parent(index)]) {
        swap(index, parent(index));
        // Set index to parent
        index = parent(index);
    }
}

int Heap::parent(int index) {
    return (index - 1) / 2;
}

void Heap::swap(int first, int second) {
    int temp = array[first];
    array[first] = array[second];
    array[second] = temp;
}

bool Heap::isEmpty() {
    return (size == 0);
}

bool Heap::isFull() {
    return size == length;
}

void Heap::remove() {
    if (isEmpty())
        throw std::invalid_argument("Heap is empty");
    // move last node to root
    array[0] = array[--size];

    // while root is less than children, bubble down
    int index = 0;
    while(index <= size && !isValidParent(index)) {
        int lci = largerChildIndex(index);
        swap(index, lci);
        index = lci;
    }

}

int Heap::leftChildIndex(int index) {
    return index * 2 + 1;
}

int Heap::rightChildIndex(int index) {
    return index * 2 + 2;
}

int Heap::leftChild(int index) {
    return array[leftChildIndex(index)];
}

int Heap::rightChild(int index) {
    return array[rightChildIndex(index)];
}

bool Heap::isValidParent(int index) {
    if (!hasLeftChild(index))
        return true;

    bool isValid = array[index] >= leftChildIndex(index);

    if (!hasRightChild(index))
        isValid &= array[index] >= rightChildIndex(index);

    return isValid;
}

int Heap::largerChildIndex(int index) {
    if (!hasLeftChild(index))
        return index;

    if (!hasRightChild(index))
        return leftChildIndex(index);

    return (leftChild(index) > rightChild(index)) ?
            leftChildIndex(index) : rightChildIndex(index);
}

bool Heap::hasLeftChild(int index) {
    return leftChildIndex(index) <= size;
}

bool Heap::hasRightChild(int index) {
    return rightChildIndex(index) <= size;
}