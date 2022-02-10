#include "Person.h"

namespace traffic {

Person::Person() {
    _width = 1;
    _height = 1;
    _normal_speed = 3;
    _max_speed = 4;
    _acc_speed = 1;
}

Person::Person(int id) : Person() { _id = id; }

void Person::update_next_loc() {}

} // namespace traffic