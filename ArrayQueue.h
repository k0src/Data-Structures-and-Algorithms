#ifndef STRUCTURESALGOS_ARRAYQUEUE_H
#define STRUCTURESALGOS_ARRAYQUEUE_H
#include <ostream>

class ArrayQueue {
public:
    ArrayQueue(int length);
    ~ArrayQueue();
    void enqueue(int item);
    int dequeue();
    int peek();
    bool isEmpty() const;
    bool isFull() const;
    int* toArray() const;
    int size() const;
private:
    int length;
    int count = 0;
    int* array;
    int front = 0;
    int back = 0;
};

std::ostream &operator<<(std::ostream& stream, const ArrayQueue& arrayQueue);

#endif //STRUCTURESALGOS_ARRAYQUEUE_H