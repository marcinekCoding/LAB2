#include "Cargoes.hpp"
#include <ostream>
#include <string>
#include <sstream>

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
