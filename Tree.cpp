#include "Tree.h"
#include <iostream>
#include <cmath>

Tree::Tree() {
}

Tree::~Tree() {
    // delete all nodes
}

void Tree::add(int item) {
    TreeNode* node = new TreeNode(item);
    if (root == nullptr) {
        root = node; // If tree is empty, set the new node as the root
    } else {
        TreeNode* current = root;

        while (true) {
            if (item < current->value) {
                // If left child is null, we found a parent.
                if (current->leftChild == nullptr) {
                    current->leftChild = node;
                    break;
                }
                // If left child is not null, keep moving down the tree
                current = current->leftChild;
            }
            else {
                // if right child is null, we found parent for this node
                if (current->rightChild == nullptr) {
                    current->rightChild = node;
                    break;
                }
                // otherwise, keep moving down the tree
                current = current->rightChild;
            }
        }
    }
}

bool Tree::has(int item) {
    TreeNode* current = root;

    // while current isn't nullptr
    // if tree is empty, current is nullptr
    // if we reach end of tree, current is nullptr
    while (current != nullptr) {
        // return true if current value = item
        if (current->value == item) {
            return true;
        }
        // if item less than current value, move down tree to left
        else if (item < current->value) {
            current = current->leftChild;
        }
        // if item greater than current value, move down tree to right
        else {
            current = current->rightChild;
        }
    }
    return false;
}

// Overloaded w/ no parameter as a public method
void Tree::traversePreOrder() {
    traversePreOrder(root);
}

// Pre order traversal
void Tree::traversePreOrder(TreeNode* rootNode) {
    // Base case
    if (rootNode == nullptr)
        return;
    // Root -> Left -> Right
    std::cout << rootNode->value << std::endl;
    traversePreOrder(rootNode->leftChild);
    traversePreOrder(rootNode->rightChild);
}

void Tree::traverseInOrder() {
    traverseInOrder(root);
}

// In order traversal
void Tree::traverseInOrder(TreeNode* rootNode) {
    if (rootNode == nullptr)
        return;

    traverseInOrder(rootNode->leftChild);
    std::cout << rootNode->value << std::endl;
    traverseInOrder(rootNode->rightChild);
}

void Tree::traversePostOrder() {
    traversePostOrder(root);
}

// Post order traversal
void Tree::traversePostOrder(TreeNode* rootNode) {
    if (rootNode == nullptr)
        return;

    traversePostOrder(rootNode->leftChild);
    traversePostOrder(rootNode->rightChild);
    std::cout << rootNode->value << std::endl;
}

int Tree::height() {
    height(root);
}

// Finding height value using post order traversal
int Tree::height(TreeNode* rootNode) {
    if (root == nullptr)
        return -1;
    // Base case
    if ((rootNode->leftChild == nullptr) && (rootNode->rightChild == nullptr))
        return 0;

    // Calculate heights of left and right
    int left = height(rootNode->leftChild);
    int right = height(rootNode->rightChild);

    return (1 + std::max(left, right));
}

// Finding min value using post order traversal
int Tree::min() {
    min(root);
}

int Tree::min(TreeNode* rootNode) {
    if (root == nullptr)
        return -1;
    // Base case
    if ((rootNode->leftChild == nullptr) && (rootNode->rightChild == nullptr))
        return rootNode->value;
    // Find min in left subtree
    int left = min(rootNode->leftChild);
    // Find min in right subtree
    int right = min(rootNode->rightChild);
    // Compare with root, return min value of the 3
    return std::min(std::min(left, right), rootNode->value);
}