#pragma once
#include <string>
#include "Cargoes.hpp"
#include <vector>

class TransportVessel
{
public:
    std::string nazwa;
    std::vector<Cargo *> lista;
    double currentLoad;

    TransportVessel(std::string id) : nazwa(id), currentLoad(0) {}
    double getCurrentLoad() { return currentLoad; }
    const std::string &getID() { return nazwa; }
    const std::vector<Cargo *> &getLoadedCargo() { return lista; }

    double getMaxCapacity();
    virtual bool loadCargo(Cargo *cargo) = 0;

    virtual ~TransportVessel() = default;
};

class Freighter : public TransportVessel
{
public:
    double capacity;
    Freighter(std::string id, double capacity) : TransportVessel(id), capacity(capacity) {}
    bool loadCargo(Cargo *cargo) override;
};
class ScoutShip : public TransportVessel
{
public:
    double capacity;
    ScoutShip(std::string id, double capacity) : TransportVessel(id), capacity(capacity) {}
    bool loadCargo(Cargo *cargo) override;
};