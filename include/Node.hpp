#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include "Location.hpp"
#include "Trip.hpp"

class Node
{
public:
    Node(Location *location);
    void addNeighbour(Node *neighbour, Trip *trip);
    std::vector<Node *> getNeighbours();
    std::string getLocationName();
    void sortTrips(std::function<bool(Trip *, Trip *)> compareFunction);
    std::vector<Trip *> getTripsToNeighbour(Node *neighbour);

private:
    Location *location;
    std::map<Node *, std::vector<Trip *>> tripsToNeighbours;
};