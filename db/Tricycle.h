#pragma once

#include "Car.h"
#include "Location.h"

namespace traffic {

class Tricycle : public Car {
public:
    Tricycle();
    explicit Tricycle(int id);
    Tricycle(const Tricycle &Tricycle) = default;
    virtual ~Tricycle() = default;

    virtual void update_next_loc();
};

} // namespace traffic