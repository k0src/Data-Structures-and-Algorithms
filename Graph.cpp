#include "Graph.h"

Graph::Graph() {

}

Graph::~Graph() {

}

void Graph::addNode(const std::string &label) {
    Node* node = new Node(label);
    auto* list = new std::list<Node*>;

    nodes.insert(std::make_pair(label, node));
    adjList.insert(std::make_pair(node, list));
}


void Graph::removeNode(const std::string &label) {
    auto it = nodes.find(label);
    if (it == nodes.end())
        return;

    Node* node = it->second;

    for (auto& pair : adjList) {
        pair.second->remove(node);
    }

    auto adjIt = adjList.find(node);
    if (adjIt != adjList.end()) {
        delete adjIt->second;
        adjList.erase(adjIt);
    }

    nodes.erase(it);
    delete node;
}

void Graph::addEdge(const std::string &from, const std::string &to) {
    auto fromNodeIt = nodes.find(from);
    if (fromNodeIt == nodes.end())
        throw std::invalid_argument("Invalid 'from' node");

    auto toNodeIt = nodes.find(to);
    if (toNodeIt == nodes.end())
        throw std::invalid_argument("Invalid 'to' node");

    Node* fromNode = fromNodeIt->second;
    Node* toNode = toNodeIt->second;

    adjList[fromNode]->push_back(toNode);
}

void Graph::removeEdge(const std::string &from, const std::string &to) {
    auto fromNodeIt = nodes.find(from);
    auto toNodeIt = nodes.find(to);
    if (fromNodeIt == nodes.end() || toNodeIt == nodes.end())
        return;

    adjList[fromNodeIt->second]->remove(toNodeIt->second);
}

void Graph::print() {
    for (const auto& sourcePair : adjList) {
        Node* source = sourcePair.first;
        std::list<Node*>* targets = sourcePair.second;

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