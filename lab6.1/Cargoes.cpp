#include "Cargoes.hpp"
#include <ostream>
#include <string>
#include <sstream>

size_t Cargo::idx = 1;

std::string RawMaterialCargo::getDescription()
{
    std::stringstream os;
    os << "{" << nazwa << "} (ID:" << id << " - Raw Material: Purity {" << purityPercentage << "%";
    return os.str();
}

std::string ManufacturedGoodsCargo::getDescription()
{
    std::stringstream os;
    os << "{" << nazwa << "} (ID:" << id << " - Manufactured Goods:  {" << unitCount << " units";
    return os.str();
}

std::string HazardousWasteCargo::getDescription()
{
    std::stringstream os;
    os << "{" << nazwa << "} (ID:" << id << " - Hazardous Waste: Danger level  {" << en_to_string(dangerlevel) << "\n";
    return os.str();
}

std::string HazardousWasteCargo::en_to_string(DangerLevel &lvl)
{
    switch (static_cast<int>(lvl))
    {
    case 0:
        return "LOW";
        break;
    case 1:
        return "MEDIUM";
        break;
    case 2:
        return "HIGH";
        break;
    case 3:
        return "CRITICAL";
        break;

    default:
    return "gowno";
        break;
    }
}
