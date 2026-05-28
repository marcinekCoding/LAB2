#include "Energies.hpp"
#include <string>

int EnergySource::number = 1000;

double PlasmaEnergy::calculateOutput() const { return magnetic * 0.005; }

std::string PlasmaEnergy::getSpecs() const {
  return "[PLASMA] Zone: " + getGridZone() +
         ", Temp: " + std::to_string(coreTemperature) +
         "K, Stability: " + std::to_string(magnetic * 100) + "%";
}
EnergySource *PlasmaEnergy::clone() const {
  PlasmaEnergy *nowe = new PlasmaEnergy(*this);
  return nowe;
}

double MatterAnimatterEnergy::calculateOutput() const {
  return antimatterMass * efficiencyFactor * 90;
}
std::string MatterAnimatterEnergy::getSpecs() const {
  return "[Anitimatter] Zone: " + getGridZone() +
         ", Mass: " + std::to_string(antimatterMass) +
         "g, Eff: " + std::to_string(efficiencyFactor);
}
EnergySource *MatterAnimatterEnergy::clone() const {
  return new MatterAnimatterEnergy(*this);
}