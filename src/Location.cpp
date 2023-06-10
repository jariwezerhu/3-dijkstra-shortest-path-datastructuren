#include "Location.hpp"

Location::Location(std::string locationName)
{
    this->name = locationName;
}

std::string Location::getLocationName() const
{
    return name;
}
