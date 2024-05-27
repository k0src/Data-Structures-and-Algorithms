#ifndef STRUCTURESALGOS_GRAPH_H
#define STRUCTURESALGOS_GRAPH_H

#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <stdexcept>
#include <set>
#include <stack>
#include <queue>

class Graph {
public:
    class Node;

    Graph();
    ~Graph();
    void addNode(const std::string& label);
    void removeNode(const std::string& label);
    void addEdge(const std::string& from, const std::string& to);
    void removeEdge(const std::string& from, const std::string& to);
    void print();
    void traverseDepthFirst(const std::string& root);
    void traverseDepthFirstIterative(const std::string& root);
    void traverseBreadthFirst(const std::string& root);
    std::vector<std::string> topologicalSort();
    bool hasCycle();
private:
    std::map<std::string, Node*> nodes;
    std::map<Node*, std::list<Node*>*> adjList;
    void traverseDepthFirst(Node* node, std::set<Node*>* visited);
    void topologicalSort(Node* node, std::set<Node*>& visited, std::stack<Node*>& stack);
    bool hasCycle(Node *node, std::set<Node*>& all, std::set<Node*>& visiting, std::set<Node*>& visited);
};

class Graph::Node {
public:
    explicit Node(const std::string& label) {
        this->label = label;
    }
    bool operator<(const Node& other) const {
        return label < other.label;
    }

    friend std::ostream& operator<<(std::ostream& os, const Node& node) {
        os << node.label << '\n';
        return os;
    }

    std::string label;
};

#endif //STRUCTURESALGOS_GRAPH_H