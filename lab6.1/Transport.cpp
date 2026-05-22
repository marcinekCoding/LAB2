#include "TransportVessels.hpp"

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
    if (currentLoad >= this->getMaxCapacity())
    {
        std::cout << this->getID() << "cannot load" << cargo->getDescription() << "Exceeds capacity of" << this->getMaxCapacity() << "units\n";
        return false;
    }
    lista.push_back(cargo);
    currentLoad++;
    return true;
}

bool ScoutShip::loadCargo(Cargo *cargo)
{
    if (currentLoad >= this->getMaxCapacity() || cargo->getWeight()>200)
    {
        std::cout << this->getID() << "cannot load" << cargo->getDescription() << "Exceeds capacity of" << this->getMaxCapacity() << "units\n";
        return false;
    }
    lista.push_back(cargo);
    currentLoad++;
    return true;
}
