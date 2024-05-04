#include "PriorityQueue.h"
#include <stdexcept>

PriorityQueue::PriorityQueue(int length) {
    this->length = length;
    array = new int[length];
}

int PriorityQueue::shiftItems(int item) {
    int i;
    for (i = count - 1; i >= 0; i--) {
        if (array[i] > item) {
            array[i + 1] = array[i];
        }
        else
            break;
    }
    return i + 1;
}

void PriorityQueue::add(int item) {
    // if array is full resize
    if (count == length) {
        int* copy = new int[count * 2];
        for (int i = 0; i < count; i++) {
            copy[i] = array[i];
        }
        delete[] array;
        array = copy;
        length *= 2;
    }
    // Shifting items to insert new ite,
    int i = shiftItems(item);
    array[i] = item;
    count++;
}

bool PriorityQueue::isEmpty() const {
    return (count == 0);
}

int PriorityQueue::remove() {
    if (isEmpty()) {
        throw std::invalid_argument("Queue is empty!");
    }
    return array[--count];
}

int* PriorityQueue::toArray() const {
    return array;
}

int PriorityQueue::size() const {
    return count;
}

std::ostream &operator<<(std::ostream& stream, const PriorityQueue& priorityQueue) {
    int* q = priorityQueue.toArray();
    stream << "[";

    if (priorityQueue.size() > 0) {
        stream << q[0];

        for (int i = 1; i < priorityQueue.size(); i++) {
            stream << ", " << q[i];
        }
    }
    stream << "]" << std::endl;
    delete[] q;
    return stream;
}