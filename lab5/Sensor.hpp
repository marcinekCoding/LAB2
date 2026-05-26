#pragma once
#include <iostream>
#include <string>
#include <variant>
#include <optional>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

template <typename T>
class Sensor
{
public:
    struct Identity
    {
        std::string hardwareID;
        std::string type;
        Identity(std::string one, std::string two) : hardwareID(one), type(two) {}
    };

private:
    std::string label;
    std::variant<Identity, std::string> source;
    std::optional<std::string> unit;
    std::vector<T> measurements;

public:
    Sensor(std::string nazwa, std::variant<Identity, std::string> source, std::optional<std::string> unit = std::nullopt)
        : label(nazwa), source(source), unit(unit) {}

    const std::string &getLabel() const { return label; }
    const std::variant<Identity, std::string> &getSource() const { return source; }
    const std::optional<std::string> &getUnit() const { return unit; }
    const std::vector<T> &getMeasurments() const { return measurements; }

    // etap 2
    T getRMS() const
    {
        if (getMeasurments().empty())
        {
            return T(0);
        }
        struct jak_dodawac
        {
            T operator()(T dane, T l) const
            {
                return dane + l * l;
            }
        };
        // z accumulate
        T dane = std::accumulate(getMeasurments().begin(), getMeasurments().end(),
                                 T(0), jak_dodawac());
        T srednia = dane / getMeasurments().size();
        return std::sqrt(srednia);
    }

    T getMin() const
    {
        if (getMeasurments().empty())
        {
            return T(0);
        }
        auto min = std::min_element(getMeasurments().begin(), getMeasurments().end());
        return *min;
    }

    bool operator>(const Sensor<T> &sen) const
    {
        if (label == sen.getLabel())
        {
            return measurements.size() > sen.getMeasurments().size();
        }
        else
        {
            return label > sen.getLabel();
        }
    }

    bool operator!=(const Sensor<T> &sen) const
    {
        return label != sen.getLabel();
    }

    Sensor<T>& operator<<(T pomiar)
    {
        measurements.push_back(pomiar);
        return *this;
    }

};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Sensor<T> &sen)
{
    os<<sen.getLabel();
    os<<"RMS: "<<sen.getRMS()<<", Min: "<<sen.getMin();
    if(sen.getUnit().has_value())
    {
        os<<"\nUnit: "<<sen.getUnit().value();
    }
    return os;
}