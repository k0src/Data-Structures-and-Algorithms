#include "Heapify.h"

void Heapify::heapify(int *array, int size) {
    int lastParentIndex = (size / 2 - 1);
    for (int i = lastParentIndex; i >= 0; i--) {
        heapify(array, size, i);
    }
}

void Heapify::heapify(int *array, int size, int index) {
    int largerIndex = index;

    int leftIndex = (index * 2) + 1;
    if (leftIndex < size && array[leftIndex] > array[largerIndex])
        largerIndex = leftIndex;

    int rightIndex = (index * 2) + 2;
    if (rightIndex < size && array[rightIndex] > array[largerIndex])
        largerIndex = rightIndex;

    if (index == largerIndex)
        return;

    swap(array, size, index, largerIndex);
    heapify(array, size, largerIndex);
}

void Heapify::swap(int *array, int size, int first, int second) {
    int temp = array[first];
    array[first] = array[second];
    array[second] = temp;
}
