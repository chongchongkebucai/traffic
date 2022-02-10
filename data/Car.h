#pragma once

#include "Location.h"
#include "Transport.h"

namespace traffic {

class Car : public Transport {
public:
    Car() {
        _acc_speed = 1;
        _speed = 5;
    }
    Car(const Car &car) = default;
    virtual ~Car() = default;

    virtual void update_next_loc() {}
};

} // namespace traffic