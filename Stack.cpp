#include "Stack.h"
#include <stdexcept>
#include <limits>

Stack::Stack() {
    array = new int[length]; //default size
}

Stack::~Stack(){
    delete[] array;
}

void Stack::push(int item) {
    if (length == count) {
        int* copy = new int[count * 2]; // Create a new array, double the size.
        for (int i = 0; i < count; i++) { // Loop over the array, and copy every item over.
            copy[i] = array[i];
        }
        delete[] array; // Delete the old array to avoid memory leaks.
        array = copy;
        length *= 2; // Update the length to the new size.
    }

    // Make item min value if no items
    if (count == 0)
        minValue = item;

    // Update min value
    if (item < minValue)
        minValue = item;

    // Add element at the end of the array
    array[count++] = item;
}

int Stack::peek() {
    if (count == 0)
        throw std::invalid_argument("Cannot peek an empty stack!");
    return array[count - 1];
}

// Decrement and return
int Stack::pop() {
    if (count == 0)
        throw std::invalid_argument("Cannot pop an empty stack!");

    int poppedValue = array[--count];

    // Check if the popped element is the current minimum value
    if (poppedValue == minValue) {
        // Reset minValue to the maximum possible integer value
        minValue = std::numeric_limits<int>::max();

        // Traverse the elements in the stack to find the new minimum value
        for (int i = 0; i < count; ++i) {
            if (array[i] < minValue) {
                minValue = array[i];
            }
        }
    }
    return poppedValue;
}

bool Stack::isEmpty() {
    return (count == 0);
}

int Stack::min() {
    if (count == 0)
        throw std::invalid_argument("Cannot get minimum value from an empty stack!");
    return minValue;
}