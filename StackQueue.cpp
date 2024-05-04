#include "StackQueue.h"
#include <stdexcept>

void StackQueue::enqueue(int item) {
    stack1.push(item);
}

int StackQueue::dequeue() {
    if (isEmpty()) {
        throw std::invalid_argument("Queue is empty.");
    }
    // Dequeue from the second stack by default.
    // If the second stack is empty, move all items from the
    // first stack to the second stack, effectively reversing it
    if (stack2.empty()) { // O(n)
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
    int top = stack2.top();
    stack2.pop();
    return top;
}

int StackQueue::peek() {
    if (isEmpty()) {
        throw std::invalid_argument("Queue is empty.");
    }
    if (stack2.empty()) {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
    return stack2.top();
}

bool StackQueue::isEmpty() const {
    return stack2.empty() && stack1.empty();
}
