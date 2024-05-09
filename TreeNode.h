#ifndef STRUCTURESALGOS_TREENODE_H
#define STRUCTURESALGOS_TREENODE_H


class TreeNode {
public:
    TreeNode(int value);
private:
    TreeNode* leftChild;
    TreeNode* rightChild;
    int value;
    friend class Tree;
};


#endif //STRUCTURESALGOS_TREENODE_H