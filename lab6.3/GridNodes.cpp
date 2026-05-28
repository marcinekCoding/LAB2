#include "GridNodes.hpp"
#include "Energies.hpp"
#include <stdexcept>

double GridNode::getCurrentLoad() const {
  double output = 0;
  for (auto &it : connectedSources) {
    output += it->calculateOutput();
  }
  return output;
}

void StandardDistributor::injectEnergy(EnergySource *source) {
  if (getSources().size() + source->calculateOutput() > getMaxLoadMW() ||
      typeid(source) == typeid(VolatileDarkEnergy)) {
    delete source;
    throw std::runtime_error("overloading");
  } else {
    // czemu to nie dziala getSources().push_back(source);
  }
}
