#pragma once
#include "Energies.hpp"
#include <string>
#include <vector>

class GridNode {
protected:
  std::string nodeName;
  double maxLoadMW;
  std::vector<EnergySource *> connectedSources;

public:
  GridNode(const std::string &name, double maxLoad)
      : nodeName(name), maxLoadMW(maxLoad) {}
  virtual ~GridNode() = default;

  std::string getNodeName() const { return nodeName; }
  double getMaxLoadMW() const { return maxLoadMW; }
  const std::vector<EnergySource *> &getSources() const {
    return connectedSources;
  }
  double getCurrentLoad() const;
  virtual void injectEnergy(EnergySource *source) = 0;
};

class StandardDistributor : public GridNode {
public:
  StandardDistributor(const std::string &name, double maxLoad)
      : GridNode(name, maxLoad) {}

  void injectEnergy(EnergySource *source) override;
};