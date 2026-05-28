#pragma once
#include <string>

#include <cstdint>
class EnergySource {
private:
  uint64_t id;
  std::string gridZone;

public:
  virtual ~EnergySource() = default;
  static int number;
  uint64_t getID() const { return id; }
  std::string getGridZone() const { return gridZone; }
  virtual std::string getSpecs() const = 0;
  virtual double calculateOutput() const = 0;
  virtual EnergySource *clone() const = 0;

  EnergySource(const std::string &zone) : gridZone(zone), id(number) {
    number++;
  }
};

class PlasmaEnergy : public EnergySource {
public:
  double coreTemperature;
  double magnetic;

  PlasmaEnergy(const std::string &zone, double temp, double stability)
      : EnergySource(zone), coreTemperature(temp), magnetic(stability) {}
  double calculateOutput() const override;
  std::string getSpecs() const override;
  EnergySource *clone() const override;
};

class MatterAnimatterEnergy : public EnergySource {
private:
  double antimatterMass;
  double efficiencyFactor;

public:
  MatterAnimatterEnergy(const std::string &zone, double temp, double stability)
      : EnergySource(zone), antimatterMass(temp), efficiencyFactor(stability) {}
  double calculateOutput() const override;
  std::string getSpecs() const override;
  EnergySource *clone() const override;
};

enum class RadiationRisk {
  SAFE = 0,
  CHRONO_DISPLACEMENT = 1,
  THERMONUCLEAR_MELTDOWN = 2
};

class VolatileDarkEnergy : public EnergySource {
private:
  RadiationRisk risk;
  double darkMass;
  VolatileDarkEnergy(const std::string &zone, RadiationRisk riskLevel,
                     double mass)
      : EnergySource(zone), risk(riskLevel), darkMass(mass) {}

  double calculateOutput() const override;
  std::string getSpecs() const override;
  EnergySource *clone() const override;
};