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

    bool validate();
private:
    TreeNode* root = nullptr;
    // Traversal methods
    void traversePreOrder(TreeNode* node);
    void traverseInOrder(TreeNode* node);
    void traversePostOrder(TreeNode* node);

    int min(TreeNode* node);
    int height(TreeNode* node);

    bool equals(TreeNode* first, TreeNode* second);

    bool validate(TreeNode* node, int min, int max);
};


#endif //STRUCTURESALGOS_TREE_H