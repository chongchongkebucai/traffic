#include "Electrocar.h"

namespace traffic {

Electrocar::Electrocar() {
    _width = 4;
    _height = 2;
    _max_speed = 16;
    _acc_speed = 1;
}

Electrocar::Electrocar(int id) : Electrocar() { _id = id; }

void Electrocar::update_next_loc() {}

} // namespace traffic