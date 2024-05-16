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