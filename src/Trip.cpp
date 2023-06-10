#include "Trip.hpp"

Trip::Trip(Location *startLocation, Location *endLocation)
{
    this->startLocation = startLocation;
    this->endLocation = endLocation;
}

Trip::Trip(Location *startLocation, Location *endLocation, std::string modeOfTransport)
{
    this->startLocation = startLocation;
    this->endLocation = endLocation;
    this->modeOfTransport = modeOfTransport;
}

Trip::Trip(Location *startLocation, Location *endLocation, int distanceInKm, int timeInMinutes, int costInDollars)
{
    this->startLocation = startLocation;
    this->endLocation = endLocation;
    this->distanceInKm = distanceInKm;
    this->timeInMinutes = timeInMinutes;
    this->costInDollars = costInDollars;
}

Trip::Trip(Location *startLocation, Location *endLocation, int distanceInKm, int timeInMinutes, int costInDollars, std::string modeOfTransport)
{
    this->startLocation = startLocation;
    this->endLocation = endLocation;
    this->distanceInKm = distanceInKm;
    this->timeInMinutes = timeInMinutes;
    this->costInDollars = costInDollars;
    this->modeOfTransport = modeOfTransport;
}

Location *Trip::getStartLocation()
{
    return startLocation;
}

Location *Trip::getEndLocation()
{
    return endLocation;
}

int Trip::getDistanceInKm()
{
    return distanceInKm;
}

int Trip::getTimeInMinutes()
{
    return timeInMinutes;
}

int Trip::getCostInDollars()
{
    return costInDollars;
}

int Trip::getDistanceOnCondition(std::string condition)
{
    if (condition == "distance")
    {
        return distanceInKm;
    }
    else if (condition == "time")
    {
        return timeInMinutes;
    }
    else if (condition == "cost")
    {
        return costInDollars;
    }
    else
    {
        return 0;
    }
}

std::string Trip::getModeOfTransport()
{
    return modeOfTransport;
}

void Trip::setStartLocation(Location *startLocation)
{
    this->startLocation = startLocation;
}

void Trip::setEndLocation(Location *endLocation)
{
    this->endLocation = endLocation;
}

void Trip::setDistanceInKm(int distanceInKm)
{
    this->distanceInKm = distanceInKm;
}

void Trip::setTimeInMinutes(int timeInMinutes)
{
    this->timeInMinutes = timeInMinutes;
}

void Trip::setCostInDollars(int costInDollars)
{
    this->costInDollars = costInDollars;
}

void Trip::setModeOfTransport(std::string modeOfTransport)
{
    this->modeOfTransport = modeOfTransport;
}
