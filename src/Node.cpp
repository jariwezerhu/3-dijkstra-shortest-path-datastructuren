#include "Node.hpp"

Node::Node(Location *location)
{
    this->location = location;
}

void Node::addNeighbour(Node *neighbour, Trip *trip)
{
    if (tripsToNeighbours.find(neighbour) == tripsToNeighbours.end())
    {
        tripsToNeighbours[neighbour] = std::vector<Trip *>();
    }
    tripsToNeighbours[neighbour].push_back(trip);
}

std::vector<Node *> Node::getNeighbours()
{
    std::vector<Node *> neighbours;
    for (auto &neighbour : tripsToNeighbours)
    {
        neighbours.push_back(neighbour.first);
    }
    return neighbours;
}

std::string Node::getLocationName()
{
    return location->getLocationName();
}

void Node::sortTrips(std::function<bool(Trip *, Trip *)> compareFunction)
{
    for (auto &neighbour : tripsToNeighbours)
    {
        std::sort(neighbour.second.begin(), neighbour.second.end(), compareFunction);
    }
}

std::vector<Trip *> Node::getTripsToNeighbour(Node *neighbour)
{
    if (tripsToNeighbours.find(neighbour) == tripsToNeighbours.end())
    {
        return std::vector<Trip *>();
    }
    return tripsToNeighbours[neighbour];
}
