#ifndef STRUCTURESALGOS_WEIGHTEDGRAPH_H
#define STRUCTURESALGOS_WEIGHTEDGRAPH_H

#include <ostream>
#include <map>
#include <list>
#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <climits>
#include <vector>
#include <functional>

class WeightedGraph {
public:
    class Node;
    class Edge;
    void addNode(const std::string& label);
    void addEdge(const std::string& from, const std::string& to, int weight);
    void print();
    int getShortestDistance(const std::string& startLabel, const std::string& endLabel);

private:
    std::map<std::string, Node*> nodes;
    std::map<Node*, std::list<Edge*>*> adjList;
};

class WeightedGraph::Node {
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

class WeightedGraph::Edge {
public:
    Edge(Node* from, Node* to, int weight) : from(from), to(to), weight(weight) {}
    Node* from;
    Node* to;
    int weight;

    friend std::ostream& operator<<(std::ostream& os, const Edge& edge) {
        os << *edge.from << "->" << *edge.to << " (weight: " << edge.weight << ")";
        return os;
    }
};

#endif