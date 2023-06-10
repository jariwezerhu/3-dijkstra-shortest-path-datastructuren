#pragma once
#include "Location.hpp"

class Trip
{
public:
    Trip(Location *startLocation, Location *endLocation);
    Trip(Location *startLocation, Location *endLocation, std::string modeOfTransport);
    Trip(Location *startLocation, Location *endLocation, int distanceInKm, int timeInMinutes, int costInDollars);
    Trip(Location *startLocation, Location *endLocation, int distanceInKm, int timeInMinutes, int costInDollars, std::string modeOfTransport);
    Location *getStartLocation();
    Location *getEndLocation();
    int getDistanceInKm();
    int getTimeInMinutes();
    int getCostInDollars();
    int getDistanceOnCondition(std::string condition);
    std::string getModeOfTransport();
    void setStartLocation(Location *startLocation);
    void setEndLocation(Location *endLocation);
    void setDistanceInKm(int distanceInKm);
    void setTimeInMinutes(int timeInMinutes);
    void setCostInDollars(int costInDollars);
    void setModeOfTransport(std::string modeOfTransport);

private:
    Location *startLocation;
    Location *endLocation;
    int distanceInKm;
    int timeInMinutes;
    int costInDollars;
    std::string modeOfTransport;
};