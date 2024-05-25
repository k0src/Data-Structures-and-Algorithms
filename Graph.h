#ifndef STRUCTURESALGOS_GRAPH_H
#define STRUCTURESALGOS_GRAPH_H

#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <stdexcept>

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
private:
    std::map<std::string, Node*> nodes;
    std::map<Node*, std::list<Node*>*> adjList;
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
        os << node.label;
        return os;
    }

    std::string label;
};

#endif //STRUCTURESALGOS_GRAPH_H