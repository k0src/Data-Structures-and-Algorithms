#include "WeightedGraph.h"

void WeightedGraph::addNode(const std::string &label) {
    Node* node = new Node(label);
    auto* list = new std::list<Edge*>;

    nodes.insert(std::make_pair(label, node));
    adjList.insert(std::make_pair(node, list));
}

void WeightedGraph::addEdge(const std::string &from, const std::string &to, int weight) {
    auto fromNodeIt = nodes.find(from);
    if (fromNodeIt == nodes.end())
        throw std::invalid_argument("Invalid 'from' node");

    auto toNodeIt = nodes.find(to);
    if (toNodeIt == nodes.end())
        throw std::invalid_argument("Invalid 'to' node");

    Node* fromNode = fromNodeIt->second;
    Node* toNode = toNodeIt->second;

    adjList[fromNode]->push_back(new Edge(fromNode, toNode, weight));
    adjList[toNode]->push_back(new Edge(toNode, fromNode, weight));
}

void WeightedGraph::print() {
    for (const auto& sourcePair : adjList) {
        Node* source = sourcePair.first;
        auto targets = sourcePair.second;

        if (!targets->empty()) {
            std::cout << *source << " is connected to {";
            bool first = true;
            for (const auto& target : *targets) {
                if (!first) {
                    std::cout << ", ";
                }
                std::cout << *target;
                first = false;
            }
            std::cout << "}" << std::endl;
        }
    }
}