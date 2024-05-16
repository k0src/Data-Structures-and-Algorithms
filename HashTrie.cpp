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