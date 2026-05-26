#pragma once
#include <string>

class Shipment {

private:
  std::string id;
  double weight;
  std::string destinationCity;
  bool delivered;

public:
  Shipment(std::string id, double waga, std::string City,
           bool delivered = false)
      : id(id), weight(waga), destinationCity(City), delivered(delivered) {}

  // gettery
  const std::string &getID() { return id; }
  const std::string &getCity() { return destinationCity; }
  const double getWeight() const { return weight; }
  bool isdelivered() { return delivered; }

  void markDelivered() { delivered = true; }
  virtual double shippingCost() const = 0;
  virtual std::string typeName() const = 0;
};

class StandardShipment : public Shipment {
public:
  StandardShipment(std::string id, double waga, std::string City,
                   bool delivered = false)
      : Shipment(id, waga, City, delivered) {}

  double shippingCost() const override { return 8 + 2.5 * getWeight(); }
};

class ExpressShipment : public Shipment {
public:
  ExpressShipment(std::string id, double waga, std::string City,
                  bool delivered = false)
      : Shipment(id, waga, City, delivered) {}

  double shippingCost() const override { return 15 + 4.0 * getWeight(); }
};

class FragileShipment : public Shipment {
public:
  FragileShipment(std::string id, double waga, std::string City,
                  bool delivered = false)
      : Shipment(id, waga, City, delivered) {}

  double shippingCost() const override { return 12 + 3.0 * getWeight() + 10; }
};