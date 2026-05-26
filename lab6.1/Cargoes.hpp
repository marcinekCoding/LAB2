#pragma once
#include <iostream>

enum class DangerLevel
{
    LOW = 0,
    MEDIUM = 1,
    HIGH = 2,
    CRITICAL = 3,
};
class Cargo
{
public:
    size_t id;
    std::string nazwa;
    static size_t idx;

    Cargo(size_t id, std::string name) : id(id), nazwa(name) { id++; }
    size_t getID() { return id; }
    std::string getName() { return nazwa; }
    virtual std::string getDescription() = 0;
    virtual double getWeight() = 0;

   virtual ~Cargo() = default;
};

class RawMaterialCargo : public Cargo
{
public:
    double purityPercentage;
    double weight;
    RawMaterialCargo(std::string name, double waga, double purity)
        : Cargo(idx, name), weight(waga), purityPercentage(purity) {}

    std::string getDescription() override;
    double getWeight() override { return weight; }
};

class ManufacturedGoodsCargo : public Cargo
{
public:
    unsigned int unitCount;
    double weightPerUnit;

    ManufacturedGoodsCargo(std::string name, unsigned int count, double weightPU)
        : Cargo(idx, name), unitCount(count), weightPerUnit(weightPU) {}
    std::string getDescription() override;

    double getWeight() override { return (weightPerUnit * unitCount); }
};

class HazardousWasteCargo : public Cargo
{
public:
    DangerLevel dangerlevel;
    double weight;

    HazardousWasteCargo(std::string name, double weight, DangerLevel danger)
    : Cargo(idx,name), weight(weight) , dangerlevel(danger) {}

    std::string getDescription() override;
    std::string en_to_string(DangerLevel& lvl);
    double getWeight()override{return weight;}

};