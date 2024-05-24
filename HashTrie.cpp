#include "HashTrie.h"

HashTrie::HashTrie() {
    root = new TrieNode(' ');
}

void HashTrie::insert(const std::string& word) {
    TrieNode* current = root;
    for (char c : word) {
        if (!current->hasChild(c))
            current->addChild(c);
        current = current->getChild(c);
    }
    current->isEndOfWord = true;
}

bool HashTrie::contains(const std::string &word) const {
    TrieNode* current = root;
    for (char c : word) {
        if (!current->hasChild(c))
            return false;
        current = current->getChild(c);
    }
    return current->isEndOfWord;
}

void HashTrie::traverse() {
    traverse(root);
}

void HashTrie::traverse(HashTrie::TrieNode *node) {
    // Preorder traversal
    std::cout << node->value << std::endl;

    for (auto child : node->getChildren())
        traverse(child);
}

void HashTrie::remove(const std::string &word) {
    remove(root, word, 0);
}

void HashTrie::remove(HashTrie::TrieNode *node, const std::string &word, int index) {
    if (index == word.length()) {
        node->isEndOfWord = false;
        return;
    }

    char c = word[index];
    TrieNode* child = node->getChild(c);
    if (child == nullptr)
        return;
    remove(child, word, index + 1);

    if (child->hasChildren() && !child->isEndOfWord)
        node->removeChild(c);
}