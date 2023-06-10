#pragma once
#include <string>

class Location
{
public:
    Location(std::string name);

    std::string getLocationName() const;

private:
    std::string name;
};