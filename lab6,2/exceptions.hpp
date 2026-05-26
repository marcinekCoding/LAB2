#pragma once

#include <exception>
class LogisticsException : public std::exception {
public:
  virtual const char *what() const noexcept override = 0;
};

class InvalidShipment : public LogisticsException {
public:
  const char *what() const noexcept override { return "too low weight"; }
};
