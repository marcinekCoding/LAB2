#pragma once
#include "Energies.hpp"
#include "GridNodes.hpp"
#include <typeinfo>

class GridAuditor {
  std::vector<EnergySource *> backup;

  void performEmergencyBackup(const std::vector<GridNode *> &network,
                              std::vector<EnergySource *> &backupStorage) {
    for (auto &it : network) {

      if (typeid(it) == typeid(StandardDistributor)) {

        StandardDistributor *temp = dynamic_cast<StandardDistributor *>(it);
        for (auto &i2 : temp->getSources()) {

          if (PlasmaEnergy *elo = dynamic_cast<PlasmaEnergy *>(i2)) {
            EnergySource *nowy = elo->clone();
            backupStorage.push_back(nowy);
          }
        }
      }
    }
  }
};
