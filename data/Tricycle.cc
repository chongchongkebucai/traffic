#include "Tricycle.h"

namespace traffic {

Tricycle::Tricycle() {
    _width = 5;
    _height = 3;
    _max_speed = 14;
}

Tricycle::Tricycle(int id) : Tricycle() { _id = id; }

void Tricycle::update_next_loc() {}

} // namespace traffic