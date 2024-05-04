#ifndef STRUCTURESALGOS_STACKQUEUE_H
#define STRUCTURESALGOS_STACKQUEUE_H

#include <stack>

class StackQueue {
public:
    void enqueue(int item);
    int dequeue();
    bool isEmpty() const;
    int peek();
private:
    std::stack<int> stack1;
    std::stack<int> stack2;
};

#endif //STRUCTURESALGOS_STACKQUEUE_H