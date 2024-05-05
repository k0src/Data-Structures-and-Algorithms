#ifndef STRUCTURESALGOS_QUEUESTACK_H
#define STRUCTURESALGOS_QUEUESTACK_H

#include <queue>

class QueueStack {
public:
    void push(int item);
    int pop();
    int peek() const;
    int size() const;
    bool isEmpty() const;
private:
    std::queue<int> queue1;
    std::queue<int> queue2;
};

#endif //STRUCTURESALGOS_QUEUESTACK_H