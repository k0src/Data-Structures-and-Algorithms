#ifndef STRUCTURESALGOS_LINKEDLIST_H
#define STRUCTURESALGOS_LINKEDLIST_H

#include "Node.h"
#include <ostream>

class LinkedList {
public:
    LinkedList();
    void addLast(int item);
    void addFirst(int item);
    int indexOf(int item);
    bool contains(int item);
    void removeFirst();
    void removeLast();
    int size() const;
    int* toArray();
    void reverse();
    int kthFromEnd(int k);
    int middle();
    void insertAt(int index, int item);
private:
    // Head and tail
    Node* first;
    Node* last;
    // For checking if list is empty
    bool isEmpty();
    int count;
    Node* getPrev(Node* node);
};

#endif //STRUCTURESALGOS_LINKEDLIST_H