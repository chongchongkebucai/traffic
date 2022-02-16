#pragma once

#include <iostream>

#include "Enum.h"
#include "Location.h"
#include "Rect.h"

namespace traffic {

class Transport {
public:
    Transport();
    Transport(const Transport &transport) = default;
    virtual ~Transport() = default;

    // getter
    int       get_id() const { return _id; }
    Location &get_cur_loc() { return _cur_loc; }
    Location &get_next_loc() { return _next_loc; }
    int       get_width() const { return _width; }
    int       get_height() const { return _height; }
    Direction get_direction() const { return _dir; }
    int       get_speed() const { return _speed; }
    int       get_next_speed() const { return _next_speed; }
    int       get_max_speed() const { return _max_speed; }
    int       get_accelerated_speed() const { return _acc_speed; }
    Road      get_next_road() const { return _next_road; }
    int       get_time() const { return _time; }

    // setter
    void set_id(int id) { _id = id; }
    void set_next_loc(const Location &next_loc) { _next_loc = next_loc; }
    void set_cur_loc(const Location &cur_loc) { _cur_loc = cur_loc; }
    void set_cur_loc(int x, int y);
    void set_width(int width) { _width = width; }
    void set_height(int height) { _height = height; }
    void set_direction(Direction dir) { _dir = dir; }
    void set_speed(int speed) { _speed = speed; }
    void set_next_speed(int speed) { _next_speed = speed; }
    void set_max_speed(int max_speed) { _max_speed = max_speed; }
    void set_accelerated_speed(int acc_speed) { _acc_speed = acc_speed; }
    void set_next_road(Road road) { _next_road = road; }
    void set_time(int time) { _time = time; }

    // operator
    virtual void update_next_loc();
    Rect         get_bounding_box() const;

    bool operator<(const Transport &rhs) const { return _id < rhs.get_id(); }

protected:
    int       _id;
    Location  _cur_loc;
    Location  _next_loc;
    Road      _next_road;
    int       _width;
    int       _height;
    Direction _dir;
    int       _speed;
    int       _next_speed;
    int       _max_speed;
    int       _acc_speed;
    int       _time;
};

inline void Transport::set_cur_loc(int x, int y) {
    _cur_loc.set_x(x);
    _cur_loc.set_y(y);
};

inline Rect Transport::get_bounding_box() const {
    return Rect(_cur_loc, Location(_cur_loc.get_x() + _width - 1, _cur_loc.get_y() + _height - 1));
}

} // namespace traffic