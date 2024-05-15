#include "Trie.h"

Trie::Trie() {
    root = new TrieNode(' ');
}

void Trie::insert(std::string word) {
    TrieNode* current = root;

    for (char c: word) {
        int index = c - 'a';
        if (current->children[index] == nullptr)
            current->children[index] = new TrieNode(c);
        current = current->children[index];
    }
    current->isEndOfWord = true;
}
