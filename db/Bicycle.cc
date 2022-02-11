#include "Bicycle.h"

namespace traffic {

Bicycle::Bicycle() {
    _width = 4;
    _height = 2;
    _max_speed = 12;
    _acc_speed = 1;
}

Bicycle::Bicycle(int id) : Bicycle() { _id = id; }

void Bicycle::update_next_loc() {}

} // namespace traffic