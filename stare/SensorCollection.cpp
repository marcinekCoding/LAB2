#include "SensorCollection.hpp"
#include <algorithm>
#include <numeric>
#include <iostream>

void SensorCollection::addSensor(const std::string &type, const Sensor<double> &sensor)
{
    sensorsByType[type].push_back(sensor);
}
std::list<Sensor<double>> SensorCollection::getAllSensors()
{
    std::list<Sensor<double>> wszytkie;
    for (auto &it : sensorsByType)
    {
        for (auto &ai : it.second)
        {
            wszytkie.push_back(ai);
        }
    }
    return wszytkie;
}

void SensorCollection::reverseSensors()
{
    for (auto &it : sensorsByType)
    {
        it.second.reverse();
    }
}

void SensorCollection::removeShortSensors(const std::string &type, std::size_t minCount)
{
    struct instrukcja
    {
        std::size_t minCount;
        instrukcja(std::size_t size) : minCount(size) {}

        bool operator()(Sensor<double> &sensor) const
        {
            if (sensor.getMeasurments().size() < minCount)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    };
    auto it = sensorsByType.find(type);
    if (it != sensorsByType.end())
    {
        it->second.remove_if(instrukcja(minCount));
    }
}

double SensorCollection::getTotalMinSum()
{
    double sum = 0.0;
    struct instruction
    {
        double operator()(double sum, const Sensor<double> &sensor) const
        {
            return sensor.getMin()+sum;
        }
    };
    for (auto &it : sensorsByType)
    {
        sum = std::accumulate(it.second.begin(), it.second.end(), 0.0, instruction());
    }
    return sum;
}
std::vector<Sensor<double>> SensorCollection::getSensorsContaining(const std::string &keyword)
{
    std::list<Sensor<double>> wszystkie = getAllSensors();
    std::vector<Sensor<double>> zwracane;
    auto instrukcja = [&keyword](const auto &sensor)
    {
        return sensor.getLabel().find(keyword) != std::string::npos;
    };

    std::copy_if(wszystkie.begin(), wszystkie.end(),
                 std::back_inserter(zwracane), instrukcja);
    return zwracane;
}

std::optional<Sensor<double>> SensorCollection::findHighestRMS()
{
    std::optional<Sensor<double>> endpoint;
    std::list<Sensor<double>> wszystkie = getAllSensors();
    if(wszystkie.empty())
    {
        endpoint = std::nullopt;
        return endpoint;
    }

    auto it = std::max_element(wszystkie.begin(), wszystkie.end(), 
        [](const auto& a, const auto& b) {
            return a.getRMS() < b.getRMS();
        });
        endpoint = *it;
        return endpoint;
}
