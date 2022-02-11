#pragma once

#include "Car.h"
#include "Location.h"

namespace traffic {

class Bicycle : public Car {
public:
    Bicycle();
    explicit Bicycle(int id);
    Bicycle(const Bicycle &Bicycle) = default;
    virtual ~Bicycle() = default;

    virtual void update_next_loc();
};

} // namespace traffic