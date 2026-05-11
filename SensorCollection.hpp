#pragma once
#include <iostream>
#include <optional>
#include "Sensor.hpp"
#include <unordered_map>
#include <list>

class SensorCollection
{
public:
    std::unordered_map<std::string, std::list<Sensor<double>>> sensorsByType;

    void addSensor(const std::string &type, const Sensor<double> &sensor);
    auto &getSensorsByType() { return sensorsByType; }
    std::list<Sensor<double>> getAllSensors();
    //etap 4
    void reverseSensors();
    void removeShortSensors(const std::string& type, std::size_t minCount);
    double getTotalMinSum();
    std::vector<Sensor<double>> getSensorsContaining(const std::string& keyword);
    std::optional<Sensor<double>> findHighestRMS();
};
inline std::ostream &operator<<(std::ostream &os, SensorCollection &czujniki)
{
    for (auto &it : czujniki.getSensorsByType())
    {
        os << "=== "<<it.first <<" ==="<< std::endl;
        for (auto &ai : it.second)
        {
            os << ai;
        }
        os<<std::endl;
    }
    return os;
}
