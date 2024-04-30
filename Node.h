#ifndef STRUCTURESALGOS_NODE_H
#define STRUCTURESALGOS_NODE_H

// This class should be nested in LinkedList.
// I'm keeping it all separate to be easier to read.

class Node {
public:
    // Constructor
    Node();
    // Constructor with parameter
    explicit Node(int item);
    ~Node();
private:
    // Value of the current node
    int value;
    // Pointer to next node
    Node* next;
    // Friend of LinkedList - for private members
    friend class LinkedList;
};


#endif //STRUCTURESALGOS_NODE_H