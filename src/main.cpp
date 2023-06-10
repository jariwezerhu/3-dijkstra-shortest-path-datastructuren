#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <iostream>
#include "Location.hpp"
#include "Trip.hpp"
#include "Node.hpp"
#include "Graph.hpp"

int main()
{
    // Maak locaties aan
    Location *amsterdam = new Location("Amsterdam");
    Location *denHaag = new Location("Den Haag");
    Location *brussel = new Location("Brussel");
    Location *antwerpen = new Location("Antwerpen");
    Location *parijs = new Location("Parijs");

    // Maak nodes aan voor de locaties
    Node *amsterdamNode = new Node(amsterdam);
    Node *denHaagNode = new Node(denHaag);
    Node *brusselNode = new Node(brussel);
    Node *antwerpenNode = new Node(antwerpen);
    Node *parijsNode = new Node(parijs);

    // Maak trips aan tussen de locaties
    Trip *carTrip1 = new Trip(amsterdam, denHaag, 75, 55, 10, "car");
    Trip *carTrip2 = new Trip(denHaag, brussel, 180, 115, 30, "car");
    Trip *carTrip3 = new Trip(brussel, antwerpen, 45, 50, 15, "car");
    Trip *carTrip4 = new Trip(antwerpen, parijs, 340, 180, 50, "car");
    Trip *carTrip5 = new Trip(amsterdam, brussel, 220, 135, 25, "car");
    Trip *carTrip6 = new Trip(denHaag, antwerpen, 125, 85, 20, "car");

    Trip *trainTrip1 = new Trip(amsterdam, denHaag, 70, 45, 15, "train");
    Trip *trainTrip2 = new Trip(denHaag, brussel, 160, 210, 25, "train");
    Trip *trainTrip3 = new Trip(brussel, antwerpen, 35, 40, 20, "train");
    Trip *trainTrip4 = new Trip(antwerpen, parijs, 300, 120, 40, "train");
    Trip *trainTrip5 = new Trip(amsterdam, brussel, 200, 240, 30, "train");
    Trip *trainTrip6 = new Trip(denHaag, antwerpen, 100, 170, 25, "train");

    Trip *planeTrip1 = new Trip(amsterdam, brussel, 400, 40, 360, "plane");
    Trip *planeTrip2 = new Trip(brussel, parijs, 500, 90, 550, "plane");
    Trip *planeTrip3 = new Trip(amsterdam, parijs, 600, 120, 600, "plane");
    Trip *planeTrip4 = new Trip(denHaag, antwerpen, 700, 45, 350, "plane");

    // Voeg alle trips toe aan een vector
    std::vector<Trip *> trips = {carTrip1, carTrip2, carTrip3, carTrip4, carTrip5, carTrip6, trainTrip1, trainTrip2, trainTrip3, trainTrip4, trainTrip5, trainTrip6, planeTrip1, planeTrip2, planeTrip3, planeTrip4};

    // Maak een nieuwe graph aan
    Graph *graph = new Graph();

    // Voeg alle nodes toe aan de graph
    graph->addNode(amsterdamNode);
    graph->addNode(denHaagNode);
    graph->addNode(brusselNode);
    graph->addNode(antwerpenNode);
    graph->addNode(parijsNode);

    // Voeg alle trips toe aan de nodes
    graph->addTripsToNodes(trips);

    // Bereken de kortste paden tussen Amsterdam en Parijs op basis van afstand, tijd en kosten
    std::vector<Trip *> shortestPath = graph->getShortestPath(amsterdamNode, parijsNode, "distance", true);
    std::cout << std::endl;
    std::vector<Trip *> fastestPath = graph->getShortestPath(amsterdamNode, parijsNode, "time", true);
    std::cout << std::endl;
    std::vector<Trip *> cheapestPath = graph->getShortestPath(amsterdamNode, parijsNode, "cost", true);
    std::cout << std::endl;

    // Druk enter om het programma af te sluiten
    std::cout << "Press enter to exit the program...";
    std::cin.get();
}