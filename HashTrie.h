#ifndef STRUCTURESALGOS_HASHTRIE_H
#define STRUCTURESALGOS_HASHTRIE_H

#include <string>
#include <map>

class HashTrie {
public:
    class TrieNode;
    HashTrie();
    void insert(const std::string& word);
private:
    TrieNode* root;
};

class HashTrie::TrieNode {
public:
    TrieNode(char value) {
        this->value = value;
    }
    ~TrieNode() {
        for (auto i : children) {
            delete i.second;
        }
    }
    char value;
    bool isEndOfWord;
    std::map<char, TrieNode*> children;
    bool hasChild(char c) {
        return children.find(c) != children.end();
    }
    void addChild(char c) {
        children[c] = new TrieNode(c);
    }
    TrieNode* getChild(char c) {
        return children[c];
    }
};


#endif //STRUCTURESALGOS_HASHTRIE_H
