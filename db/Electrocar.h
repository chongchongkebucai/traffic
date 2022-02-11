#pragma once

#include "Car.h"
#include "Location.h"

namespace traffic {

class Electrocar : public Car {
public:
    Electrocar();
    explicit Electrocar(int id);
    Electrocar(const Electrocar &Electrocar) = default;
    virtual ~Electrocar() = default;

    virtual void update_next_loc();
};

} // namespace traffic