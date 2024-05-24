#ifndef STRUCTURESALGOS_HASHTRIE_H
#define STRUCTURESALGOS_HASHTRIE_H

#include <string>
#include <map>
#include <iostream>
#include <vector>

class HashTrie {
public:
    class TrieNode;
    HashTrie();
    void insert(const std::string& word);
    bool contains(const std::string& word) const;
    void traverse();
    void remove(const std::string& word);
private:
    TrieNode* root;
    void traverse(TrieNode* node);
    void remove(TrieNode* node, const std::string& word, int index);
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
    bool isEndOfWord = false;
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
    std::vector<TrieNode*> getChildren() {
        std::vector<TrieNode*> childrenV;

        for (const auto& pair : children) {
            childrenV.push_back(pair.second);
        }
        return childrenV;
    }
    bool hasChildren() {
        return !children.empty();
    }
    void removeChild(char c) {
        auto it = children.find(c);
        if (it != children.end()) {
            delete it->second;
            children.erase(it);
        }
    }
};


#endif //STRUCTURESALGOS_HASHTRIE_H
