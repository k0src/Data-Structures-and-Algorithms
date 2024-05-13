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

}