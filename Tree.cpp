#include "Tree.h"
#include <iostream>
#include <cmath>
#include <limits>

Tree::Tree() = default;

Tree::~Tree() {
    deleteTree(root);
}

void Tree::deleteTree(TreeNode* node) {
    if (node == nullptr)
        return;

    deleteTree(node->leftChild);
    deleteTree(node->rightChild);

    delete node;
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
void Tree::traversePreOrder(TreeNode* node) {
    // Base case
    if (node == nullptr)
        return;
    // Root -> Left -> Right
    std::cout << node->value << std::endl;
    traversePreOrder(node->leftChild);
    traversePreOrder(node->rightChild);
}

void Tree::traverseInOrder() {
    traverseInOrder(root);
}

// In order traversal
void Tree::traverseInOrder(TreeNode* node) {
    if (node == nullptr)
        return;

    traverseInOrder(node->leftChild);
    std::cout << node->value << std::endl;
    traverseInOrder(node->rightChild);
}

void Tree::traversePostOrder() {
    traversePostOrder(root);
}

// Post order traversal
void Tree::traversePostOrder(TreeNode* node) {
    if (node == nullptr)
        return;

    traversePostOrder(node->leftChild);
    traversePostOrder(node->rightChild);
    std::cout << node->value << std::endl;
}

int Tree::height() {
    return height(root);
}

// Finding height value using post order traversal
int Tree::height(TreeNode* node) {
    if (root == nullptr)
        return -1;
    // Base case
    if ((node->leftChild == nullptr) && (node->rightChild == nullptr))
        return 0;

    // Calculate heights of left and right
    int left = height(node->leftChild);
    int right = height(node->rightChild);

    return (1 + std::max(left, right));
}

// Finding min value using post order traversal
int Tree::min() {
    return min(root);
}

int Tree::min(TreeNode* node) {
    if (root == nullptr)
        return -1;
    // Base case
    if ((node->leftChild == nullptr) && (node->rightChild == nullptr))
        return node->value;
    // Find min in left subtree
    int left = min(node->leftChild);
    // Find min in right subtree
    int right = min(node->rightChild);
    // Compare with root, return min value of the 3
    return std::min(std::min(left, right), node->value);
}

// check equality using pre-order traversal
bool Tree::equals(Tree* other) {
    if (other == nullptr) {
        return false;
    }

    return equals(root, other->root);
}

bool Tree::equals(TreeNode *first, TreeNode *second) {
    if (first == nullptr && second == nullptr)
        return true;
    if (first != nullptr && second != nullptr)
        return first->value == second->value
                && equals(first->leftChild, second->leftChild)
                && equals(first->rightChild, second->rightChild);

    return false;
}

bool Tree::validate() {
    return validate(root, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}

bool Tree::validate(TreeNode* node, int min, int max) {
    if (node == nullptr)
        return true;

    if (node->value > max || node->value < min)
        return false;

    return validate(node->leftChild, min, node->value - 1) &&
           validate(node->rightChild, node->value + 1, max);
}

void Tree::printNodesAtDistance(int k) {
    printNodesAtDistance(root, k);
}

void Tree::printNodesAtDistance(TreeNode *node, int k) {
    if (node == nullptr)
        return;

    if (k == 0)
        std::cout << node->value << '\n';

    printNodesAtDistance(node->leftChild, k - 1);
    printNodesAtDistance(node->rightChild, k - 1);
}

std::vector<int> Tree::nodesAtDistance(int k) {
    std::vector<int> list;
    nodesAtDistance(root, k, list);
    return list;
}

void Tree::nodesAtDistance(TreeNode *node, int k, std::vector<int>& list) {
    if (node == nullptr)
        return;

    if (k == 0)
        list.push_back(node->value);

    nodesAtDistance(node->leftChild, k - 1, list);
    nodesAtDistance(node->rightChild, k - 1, list);
}

void Tree::traverseLevelOrder() {
    for (int i = 0; i <= height(root); i++) {
        for (auto n: nodesAtDistance(i))
            std::cout << n << '\n';
    }
}
