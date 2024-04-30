#include "LinkedList.h"
#include "Node.h"
#include <stdexcept>
#include <iostream>

// Initialize the first and last nodes to nullptr
LinkedList::LinkedList() {
    first = nullptr;
    last = nullptr;
    count = 0;
}

void LinkedList::addLast(int item) {
    // First, we "wrap" the integer inside a node object
    Node* node = new Node(item);

    // If the list is empty, make first and last = the new node.
    if (isEmpty()) {
        first = node;
        last = node;
    }
    // If not, make last.next (previous last) = the new node, and last = the new node
    else {
        last->next = node;
        last = node;
    }
    count++;
}

void LinkedList::addFirst(int item) {
    // First, make new node.
    Node* node = new Node(item);

    // Check if list is empty.
    if (isEmpty()) {
        first = node;
        last = node;
    }
    // The new node should POINT to the current first node.
    else {
        node->next = first;
        // make new node the first
        first = node;
    }
    count++;
}

void LinkedList::insertAt(int index, int item) {
    // Check if index is valid
    if (index < 0 || index > count)
        throw std::invalid_argument("Index out of bounds!");

    // If index is 0 use addFirst
    if (index == 0)
        addFirst(item);
    // If index is at the end, use addLast
    else if (index == count)
        addLast(item);
    // Else, find the node at the previous index
    else {
        // Start from beginning of list
        Node* current = first;
        // Move current to the node just before the desired index
        for (int i = 0; i < index - 2; i++)
            current = current->next;
        // Create new node with the item
        Node* node = new Node(item);
        // Insert the nde between current and current->next
        node->next = current->next;
        current->next = node;
        count++;
    }
}

bool LinkedList::isEmpty() {
    return (first == nullptr);
}

int LinkedList::indexOf(int item) {
    // Traverse list until we get to the item.
    // Since we don't have indices, we will use an index variable to store the index.
    int index = 0;
    // Set temp variable equal to the first node
    Node* current = first;
    // While current does not = nullptr, so the end of the list...
    while (current != nullptr) {
        // If the value of the current node = item, return the index
        if (current->value == item) return index;
        // Increment the current node, by setting it equal to current->next
        current = current->next;
        index++;
    }
    return -1;
}

bool LinkedList::contains(int item) {
    // Use exiting logic to see if item is in list
    return (indexOf(item) != -1);
}

void LinkedList::removeFirst() {
    // First, check if list is empty. If so, throw exception.
    if (isEmpty()) {
        throw std::out_of_range("Cannot delete element from an empty list.");
    }
    // Also, check if there is only ONE element in the list - then just set both to null.
    if (first == last) {
        first = nullptr;
        last = nullptr;
    }
    else {
        // second - pointer to the second element
        Node* second = first->next;
        // Remove link from first to second
        first->next = nullptr;
        // Make "second" the first item
        first = second;
    }
    count--;
}

// extracted logic for getting prev node
Node* LinkedList::getPrev(Node* node) {
    // First, we traverse the list to find the SECOND TO LAST NODE
    Node* current = first;
    while(current != nullptr) {
        // If current IS the second to last node, break.
        if (current->next == node)
            return current;
        // Otherwise, increment current
        current = current->next;
    }
    // if no previous - return null
    return nullptr;
}

void LinkedList::removeLast() {
    // Check if one item or empty
    if (isEmpty()) {
        throw std::out_of_range("Cannot delete element from an empty list.");
    }
    if (first == last) {
        first = nullptr;
        last = nullptr;
    }
    else {
        // First, get the second to last node using getPrev, passing in last
        Node* prev = getPrev(last);
        last = prev;
        // Remove the link between the last node and previous last node
        last->next = nullptr;
    }
    count--;
}

int LinkedList::size() const {
    return count;
}

// A vector can be used here to
int* LinkedList::toArray() {
    int* array = new int[count];

    Node* current = first;
    int index = 0;
    while (current != nullptr) {
        array[index] = current->value;
        current = current->next;
        index++;
    }
    return array;
}

void LinkedList::reverse() {
    // Check if the list is empty or has only one node
    if (isEmpty() || first == last)
        return;

    // Initialize pointers to keep track of nodes during reversal
    Node* prev = first;           // Points to the first node initially
    Node* current = first->next;  // Points to the second node initially

    // Traverse the list and reverse the links between nodes
    while (current != nullptr) {
        Node* next = current->next; // Store the next node before modifying the link
        current->next = prev;       // Reverse the link to point to the previous node
        prev = current;             // Move the prev pointer forward
        current = next;             // Move the current pointer forward
    }
    // Update the last pointer to point to the previous first node,
    // as it will be the last node after reversal
    last = first;
    last->next = nullptr;         // Ensure it is the last node after reversal
    // Update the first pointer to point to the last node,
    // which is now the first node after reversal
    first = prev;
}

int LinkedList::kthFromEnd(int k) {
    // Check if empty
    if (isEmpty())
        throw std::invalid_argument("Cannot get kth node in an empty list.");

    // Create two pointers. Set them both to the head
    Node* p1= first;
    Node* p2 = first;

    // Loop thru the list, until p2 is k-1 nodes away from p1
    for (int i = 0; i < k; i++) {
        p2 = p2->next;
        if (p2 == nullptr)
            throw std::invalid_argument("K is too large.");
    }

    // Move both pointers down the list, until p2 is at the end.
    while (p2 != nullptr) {
        p2 = p2->next;
        p1 = p1->next;
    }
    // return the value at p2
    return p1->value;
}

int LinkedList::middle() {
    if (isEmpty())
        throw std::invalid_argument("Cannot get middle of an empty list.");
    Node* p1 = first;
    Node* p2 = first;

    while (p1 != nullptr && p1->next != nullptr) {
        p1 = p1->next->next;
        p2 = p2->next;
    }
    return p2->value;
}