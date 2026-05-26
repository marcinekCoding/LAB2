#include "routing.hpp"
#include "exceptions.hpp"
#include <algorithm>
#include <iostream>

void DeliveryCenter::processALL() {
  for (auto &it : shipments) {
    if (!it->isdelivered()) {
      std::cout << "paczka: " << it->getID() << "poprawnie obsluzona\n";
      it->markDelivered();
      revenue += it->shippingCost();
    }
  }
}

void DeliveryCenter::printPending() const {
  std::cout << "Paczki niedostarczone" << std::endl;
  for (auto &it : shipments) {
    if (!it->isdelivered()) {
      std::cout << "paczka id:" << it->getID() << " do miejsca"
                << it->getWeight() << "\n";
    }
  }
}

void DeliveryCenter::printDelivered() const {
  std::cout << "Paczki dostarczone" << std::endl;
  for (auto &it : shipments) {
    if (it->isdelivered()) {
      std::cout << "paczka id:" << it->getID() << " do miejsca"
                << it->getWeight() << "\n";
    }
  }
}

void DeliveryCenter::addShipment(std::unique_ptr<Shipment> s) {
  if (s->getWeight() <= 0) {
    InvalidShipment blad;
    throw blad;
  }
  shipments.push_back(s);
}

int DeliveryCenter::countByCity(const std::string &city) const {
  struct miasto {
    bool operator()(std::unique_ptr<Shipment> s, std::string &miasto) {
      return s->getCity() == miasto;
    }
  };
  int wynik = static_cast<int>(
      std::count_if(shipments.begin(), shipments.end(), miasto()));
  return wynik;
}