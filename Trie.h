#ifndef STRUCTURESALGOS_TRIE_H
#define STRUCTURESALGOS_TRIE_H

#include <iostream>

#define ALPHABET_SIZE 26

class Trie {
public:
    class TrieNode;
    Trie();
    void insert(std::string word);
private:
    TrieNode* root;
};

class Trie::TrieNode {
public:
    TrieNode(char value) {
        this->value = value;
        for (auto& i : children) {
            i = nullptr;
        }
        isEndOfWord = false;
    }
    void print() {
        std::cout << "value=" << value << std::endl;
    }
    char value;
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
};

#endif