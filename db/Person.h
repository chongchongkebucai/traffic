#pragma once

#include "Location.h"
#include "Transport.h"

namespace traffic {

class Person : public Transport {
public:
    Person();
    explicit Person(int id);
    Person(const Person &person) = default;
    virtual ~Person() = default;

    int  get_normal_speed() const { return _normal_speed; }
    bool get_once_crossing() const { return _once_crossing; }

    void set_normal_speed(int speed) { _normal_speed = speed; }
    void set_once_crossing(bool once_crossing) { _once_crossing = once_crossing; }

    virtual void update_next_loc();

private:
    int  _normal_speed;
    bool _once_crossing;
};

} // namespace traffic