#include "Graph.hpp"
#include <iostream>

Graph::Graph()
{
}

void Graph::addNode(Node *node)
{
    nodes.push_back(node);
}

std::vector<Node *> Graph::getNodes()
{
    return nodes;
}

void Graph::addTripsToNodes(std::vector<Trip *> trips)
{
    for (auto &trip : trips)
    {
        Node *startNode;
        Node *endNode;
        for (auto &node : nodes)
        {
            if (node->getLocationName() == trip->getStartLocation()->getLocationName())
            {
                startNode = node;
            }
            else if (node->getLocationName() == trip->getEndLocation()->getLocationName())
            {
                endNode = node;
            }
        }
        startNode->addNeighbour(endNode, trip);
    }
}

void Graph::sortNodesOnCondition(std::string condition)
{
    // Maak een map van functies die twee trips vergelijken op basis van de gegeven conditie
    std::unordered_map<std::string, std::function<bool(Trip *, Trip *)>> comparisonFunctions = {
        {"distance", [](Trip *a, Trip *b)
         { return a->getDistanceInKm() < b->getDistanceInKm(); }},
        {"time", [](Trip *a, Trip *b)
         { return a->getTimeInMinutes() < b->getTimeInMinutes(); }},
        {"cost", [](Trip *a, Trip *b)
         { return a->getCostInDollars() < b->getCostInDollars(); }}};

    // Zoek de functie die hoort bij de gegeven conditie
    auto comparisonFunction = comparisonFunctions.find(condition);
    if (comparisonFunction == comparisonFunctions.end())
    {
        return;
    }

    // Sorteer de trips van elke node op basis van de gegeven conditie
    for (auto &node : nodes)
    {
        node->sortTrips(comparisonFunction->second);
    }
}

std::vector<Trip *> Graph::getShortestPath(Node *startNode, Node *endNode, std::string condition, bool print)
{
    // Sorteer de nodes op basis van de gegeven conditie
    sortNodesOnCondition(condition);

    std::vector<Trip *> shortestPath;
    std::vector<Node *> visitedNodes;
    std::vector<Node *> unvisitedNodes;
    std::unordered_map<Node *, int> distanceToNode;
    std::unordered_map<Node *, Node *> previousNode;
    Node *currentNode;
    int totalDistance = 0;
    int totalTime = 0;
    int totalCost = 0;

    // Initialiseer de afstand tot elke node als oneindig, behalve de startnode
    for (auto &node : nodes)
    {
        if (node == startNode)
        {
            distanceToNode[node] = 0;
        }
        else
        {
            distanceToNode[node] = INT_MAX;
        }
        unvisitedNodes.push_back(node);
    }

    // Blijf zoeken naar het kortste pad totdat alle nodes bezocht zijn
    while (unvisitedNodes.size() > 0)
    {
        // Sorteer de onbezochte nodes op basis van de afstand tot de startnode
        std::sort(unvisitedNodes.begin(), unvisitedNodes.end(), [&distanceToNode](Node *a, Node *b)
                  { return distanceToNode[a] < distanceToNode[b]; });
        currentNode = unvisitedNodes[0];
        unvisitedNodes.erase(unvisitedNodes.begin());

        // Als de eindnode bereikt is, bouw het kortste pad op en geef het terug
        if (currentNode == endNode)
        {
            while (currentNode != startNode)
            {
                shortestPath.insert(shortestPath.begin(), previousNode[currentNode]->getTripsToNeighbour(currentNode)[0]);
                currentNode = previousNode[currentNode];
                totalDistance += shortestPath[0]->getDistanceInKm();
                totalTime += shortestPath[0]->getTimeInMinutes();
                totalCost += shortestPath[0]->getCostInDollars();
            }
            if (print)
                printGraph(shortestPath, totalDistance, totalTime, totalCost, condition);
            return shortestPath;
        }

        // Update de afstand tot de buren van de huidige node
        for (auto &neighbour : currentNode->getNeighbours())
        {
            if (std::find(visitedNodes.begin(), visitedNodes.end(), neighbour) != visitedNodes.end())
            {
                continue;
            }
            int distance = distanceToNode[currentNode] + currentNode->getTripsToNeighbour(neighbour)[0]->getDistanceOnCondition(condition);
            if (distance < distanceToNode[neighbour])
            {
                distanceToNode[neighbour] = distance;
                previousNode[neighbour] = currentNode;
            }
        }

        visitedNodes.push_back(currentNode);
    }
}

void Graph::printGraph(std::vector<Trip *> trips, int totalDistance, int totalTime, int totalCost, std::string condition)
{
    std::cout << "Shortest path on " << condition << ":" << std::endl;
    for (auto &trip : trips)
    {
        std::cout << trip->getStartLocation()->getLocationName() << " -> " << trip->getEndLocation()->getLocationName() << " by " << trip->getModeOfTransport() << ": " << trip->getDistanceInKm() << "km, " << trip->getTimeInMinutes() << "min, $" << trip->getCostInDollars() << std::endl;
    }
    std::cout << "Total distance: " << totalDistance << "km" << std::endl;
    std::cout << "Total time: " << totalTime << "min" << std::endl;
    std::cout << "Total cost: $" << totalCost << std::endl;
}