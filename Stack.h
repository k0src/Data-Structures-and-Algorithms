#ifndef STRUCTURESALGOS_STACK_H
#define STRUCTURESALGOS_STACK_H


class Stack {
public:
    Stack();
    ~Stack();
    void push(int item);
    int pop();
    int peek();
    bool isEmpty();
    int min();
private:
    int* array;
    int count = 0;
    int length = 5;
    int minValue;
};

#endif //STRUCTURESALGOS_STACK_H