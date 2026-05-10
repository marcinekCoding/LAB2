#pragma once
#include <iostream>
#include <string>
#include <variant>
#include <optional>
#include <vector>

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

    const std::string& getLabel() const { return label; } 
    const std::variant<Identity, std::string>& getSource() const { return source;}
    const std::optional<std::string>& getUnit()const  { return unit; }
    const std::vector<T>& getMeasurments()const  { return measurements; }

    //etap 2 
    <T> getRMS()
    {
        //z accumulate
        T dane = std::accum

    }
};