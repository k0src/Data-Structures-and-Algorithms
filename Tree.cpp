#include "Tree.h"

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
