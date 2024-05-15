#include "Node.h"
#include "Trie.h"


Node::Node() {
    // Initialize value to 0, and next to nullptr
    this->value = 0;
    this->next = nullptr;
}

Node::Node(int item) {
    // Initialize the node with a value.
    this->value = item;
    this->next= nullptr;
}

// Deallocate memory for the deleted nodes
Node::~Node() {
    // Dont delete a random address
    if (next != nullptr)
    {
        delete next;
        next = nullptr;
    }
}