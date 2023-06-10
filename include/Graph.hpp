#pragma once
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
#include "Node.hpp"
#include "Trip.hpp"

class Graph
{
public:
    Graph();
    void addNode(Node *node);
    std::vector<Node *> getNodes();
    void addTripsToNodes(std::vector<Trip *> trips);
    void sortNodesOnCondition(std::string condition);
    std::vector<Trip *> getShortestPath(Node *startNode, Node *endNode, std::string condition, bool print);
    void printGraph(std::vector<Trip *> trips, int totalDistance, int totalTime, int totalCost, std::string condition);

private:
    std::vector<Node *> nodes;
};