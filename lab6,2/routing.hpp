#pragma once
#include "Shipment.hpp"
#include <memory>
#include <string>
#include <vector>

class IRoutingStrategy {
public:
  virtual std::string chooseRoute(const Shipment &shipment) const = 0;
  void CheapRoute();
  void FastRoute();
  void BalanceRoute();
};

class DeliveryCenter {
private:
  std::vector<std::unique_ptr<Shipment>> shipments;
  std::unique_ptr<IRoutingStrategy> strategy;
  double revenue;

public:
  void addShipment(std::unique_ptr<Shipment> s);
  void processALL();
  double getRevenue() const { return revenue; }
  void printPending() const;
  void printDelivered() const;

  int countByCity(const std::string &city) const;
};