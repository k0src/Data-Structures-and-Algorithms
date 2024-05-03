#include "ArrayQueue.h"
#include <stdexcept>

// Constructor: Initializes the circular array queue with a given length
ArrayQueue::ArrayQueue(int length) {
    array = new int[length];  // Dynamically allocating memory for the array
    this->length = length;    // Storing the length of the array
}

// Destructor: Frees the dynamically allocated memory for the array
ArrayQueue::~ArrayQueue() {
    delete[] array;  // Deallocating the memory
}

// Adds an item to the back of the queue
void ArrayQueue::enqueue(int item) {
    if (isFull())  // Checking if the queue is full
        throw std::invalid_argument("Queue is full!");  // Throwing an exception if the queue is full
    array[back] = item;            // Adding the item to the back of the queue
    back = (back + 1) % length;    // Updating the back index to the next position in a circular manner
    count++;                       // Increasing the count of elements in the queue
}

// Removes and returns the front item from the queue
int ArrayQueue::dequeue() {
    int item = array[front];        // Storing the front item
    array[front] = 0;               // Removing the front item (optional)
    front = (front + 1) % length;   // Updating the front index to the next position in a circular manner
    count--;                        // Decreasing the count of elements in the queue
    return item;                    // Returning the removed item
}

// Returns the front item of the queue without removing it
int ArrayQueue::peek() {
    return array[front];  // Returning the front item of the queue
}

// Checks if the queue is empty
bool ArrayQueue::isEmpty() const {
    return back == 0;  // Returns true if the back index is at the initial position
}

// Checks if the queue is full
bool ArrayQueue::isFull() const {
    return count == length;  // Returns true if the count of elements is equal to the length of the array
}

// To array
int* ArrayQueue::toArray() const {
    int* arr = new int[count];  // Create a new array of size 'count'
    int j = front;
    for (int i = 0; i < count; ++i) {
        arr[i] = array[j];
        j = (j + 1) % length;
    }
    return arr;
}

int ArrayQueue::size() const {
    return count;
}

// Overloading << operator
std::ostream &operator<<(std::ostream& stream, const ArrayQueue& arrayQueue) {
    int* q = arrayQueue.toArray();
    stream << "[";

    if (arrayQueue.size() > 0) {
        stream << q[0];

        for (int i = 1; i < arrayQueue.size(); i++) {
            stream << ", " << q[i];
        }
    }
    stream << "]" << std::endl;
    delete[] q;
    return stream;
}