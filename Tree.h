#ifndef STRUCTURESALGOS_TREE_H
#define STRUCTURESALGOS_TREE_H

#include "TreeNode.h"

class Tree {
public:
    Tree();
    ~Tree();
    void add(int item);
    bool has(int item);
    // Traversal methods
    void traversePreOrder();
    void traverseInOrder();
    void traversePostOrder();

    int min();
    int height();

    bool equals(Tree* other);
private:
    TreeNode* root = nullptr;
    // Traversal methods
    void traversePreOrder(TreeNode* rootNode);
    void traverseInOrder(TreeNode* rootNode);
    void traversePostOrder(TreeNode* rootNode);

    int min(TreeNode* rootNode);
    int height(TreeNode* rootNode);

    bool equals(TreeNode* first, TreeNode* second);
};


#endif //STRUCTURESALGOS_TREE_H