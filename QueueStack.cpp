#include "QueueStack.h"
#include <stdexcept>

void QueueStack::push(int item) {
    queue1.push(item);
}

int QueueStack::pop() {
    if (isEmpty()) {
        throw std::invalid_argument("Stack is empty!");
    }

    // Move all but the last element from queue1 to queue2
    while (queue1.size() > 1) {
        queue2.push(queue1.front());
        queue1.pop();
    }

    // Extract the last element from queue1 (the top of the stack)
    int top = queue1.front();
    queue1.pop();

    // Move elements back from queue2 to queue1
    while (!queue2.empty()) {
        queue1.push(queue2.front());
        queue2.pop();
    }

    return top;
}

int QueueStack::peek() const {
    if (isEmpty()) {
        throw std::invalid_argument("Stack is empty!");
    }
    return queue1.back(); // Assuming queue1 is the queue holding stack elements
}

int QueueStack::size() const {
    return queue1.size();
}

bool QueueStack::isEmpty() const {
    return (queue1.empty() && queue2.empty());
}