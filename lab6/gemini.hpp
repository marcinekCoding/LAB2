class Cargo {
public:
  Cargo(int id, double weight);
  int getId() const;
  double getWeight() const;

private:
  int id;
  double weight;
};

class Truck {
public:
  Truck(int id, double capacity);
  int getId() const;
  double getCapacity() const;
  double getCurrentLoad() const;
  bool loadCargo(const Cargo &cargo);
  bool unloadCargo(const Cargo &cargo);

private:
  int id;
  double capacity;
  double currentLoad;
};