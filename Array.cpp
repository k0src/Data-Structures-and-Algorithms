//
// Created by clips on 4/28/2024.
//

#include "Array.h"
#include <iostream>
#include <exception>

// Constructor - initialize make the items pointer point to a new int array, with size length.
Array::Array(int length) {
    items = new int[length];
    this->length = length;
}

// Destructor - free memory
Array::~Array() {
    delete[] items;
}

void Array::print() {
    for (int i = 0; i < count; i++){
        std::cout << items[i] << std::endl;
    }
}

void Array::insert(int item) {
    // If array is full, we need to resize it
    if (length == count) {
        int* copy = new int[count * 2]; // Create a new array, double the size.
        for (int i = 0; i < count; i++) { // Loop over the array, and copy every item over.
            copy[i] = items[i];
        }
        delete[] items; // Delete the old array to avoid memory leaks.
        items = copy;
        length *= 2; // Update the length to the new size.
    }
    // Add element at the end of the array
    items[count++] = item; // Count is the current index, then we increment count.
}

void Array::removeAt(int index) {
    // First, validate the index.
    if (index < 0 || index >= count) {
        throw std::invalid_argument("index");
    }
    // Shift the items to the left, to fill the hole.
    for (int i = index; i < count - 1; i++) {
        items[i] = items[i + 1];
    }
    count--; // Decrement the amount of numbers in the array.
}

// Loop over array until we find the item.
int Array::indexOf(int item) const {
    for (int i = 0; i < count; i++) {
        if (items[i] == item) {
            return i;
        }
    }
    return -1;
}

int Array::max() const {
    int max = 0;
    for (int i = 0; i < count; i++) {
        if (items[i] > max)
            max = items[i];
    }
    return max;
}

void Array::reverse() {
    int* reverse = new int[count];
    for (int i = 0; i < count; i++) {
        // Start from the end - 1
        reverse[i] = items[count - i -1];
    }
    delete[] items;
    items = reverse;
}