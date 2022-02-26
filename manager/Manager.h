#pragma once

#include <mutex>
#include <iostream>

#include "Bicycle.h"
#include "Config.h"
#include "Person.h"
#include "Random.h"
#include "Transport.h"
#include "Car.h"
#include "Electrocar.h"
#include "Bicycle.h"
#include "Tricycle.h"
#include "Enum.h"

namespace traffic {

class Manager {
public:
    Manager();
    Manager(Config *config, int id = 0);
    Manager(const Manager &) = default;
    ~Manager() = default;

    Person *create_person();
    Car *   create_car(Direction dir);
    void    destroy_transport(Transport *transport) const;

private:
    int get_id();

private:
    long long  _id;
    Config *   _config;
    Random     _random;
    std::mutex _mutex;
};

inline void Manager::destroy_transport(Transport *transport) const { delete transport; }

} // namespace traffic