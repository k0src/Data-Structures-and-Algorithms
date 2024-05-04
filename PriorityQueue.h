#ifndef STRUCTURESALGOS_PRIORITYQUEUE_H
#define STRUCTURESALGOS_PRIORITYQUEUE_H

#include <ostream>

class PriorityQueue {
public:
    PriorityQueue(int length);
    void add(int item);
    int remove();
    int size() const;
    int* toArray() const;
    bool isEmpty() const;
private:
    int* array;
    int length;
    int count = 0;
    int shiftItems(int item);
};

std::ostream &operator<<(std::ostream& stream, const PriorityQueue& priorityQueue);

#endif //STRUCTURESALGOS_PRIORITYQUEUE_H