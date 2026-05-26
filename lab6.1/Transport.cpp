#include "TransportVessels.hpp"
#include "Cargoes.hpp"

double TransportVessel::getMaxCapacity()
{
    if (typeid(*this) == typeid(Freighter))
    {
        Freighter *nowy = dynamic_cast<Freighter *>(this);
        return nowy->capacity;
    }
    else if (typeid(*this) == typeid(ScoutShip))
    {
        ScoutShip *nowy = dynamic_cast<ScoutShip *>(this);
        return nowy->capacity;
    }
    else
    {
        return -1;
    }
}

bool Freighter::loadCargo(Cargo *cargo)
{
    if (currentLoad + cargo->getWeight() > this->getMaxCapacity())
    {
        std::cout << this->getID() << "cannot load" << cargo->getDescription() << "Exceeds capacity of" << this->getMaxCapacity() << "units\n";
        return false;
    }
    if (auto hazard = dynamic_cast<HazardousWasteCargo *>(cargo))
    {
        std::cout << "WARNING: hazardous waste cargo (" << cargo->getID() << "), Danger LEVVEL" << hazard->en_to_string(hazard->dangerlevel) << " loaded!\n";
    }
    lista.push_back(cargo);
    currentLoad += cargo->getWeight();
    return true;
}

bool ScoutShip::loadCargo(Cargo *cargo)
{
    if (currentLoad >= this->getMaxCapacity() || cargo->getWeight() > 200)
    {
        std::cout << this->getID() << "cannot load" << cargo->getDescription() << "Exceeds capacity of" << this->getMaxCapacity() << "units\n";
        return false;
    }
    if (auto hazard = dynamic_cast<HazardousWasteCargo *>(cargo))
    {
        if (static_cast<int>(hazard->dangerlevel) >= 1)
        {
            return false;
        }
        else
        {
            std::cout << "WARNING: hazardous waste cargo (" << cargo->getID() << "), Danger LEVVEL" << hazard->en_to_string(hazard->dangerlevel) << " loaded!\n";
        }
    }
    lista.push_back(cargo);
    currentLoad += cargo->getWeight();
    return true;
}
