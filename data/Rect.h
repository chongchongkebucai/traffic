#pragma once

#include "Location.h"

namespace traffic {

class Rect {
public:
    Rect() : _min_loc(0, 0), _max_loc(0, 0) {}
    Rect(const Location &min_loc, const Location &max_loc) : _min_loc(min_loc), _max_loc(max_loc) {}
    Rect(const Rect &rect) = default;
    ~Rect() = default;

    // setter
    Location get_min_location() const { return _min_loc; }
    Location get_max_location() const { return _max_loc; }
    int      get_min_x() const { return _min_loc.get_x(); }
    int      get_min_y() const { return _min_loc.get_y(); }
    int      get_max_x() const { return _max_loc.get_x(); }
    int      get_max_y() const { return _max_loc.get_y(); }
    int      get_width() const { return _max_loc.get_x() - _min_loc.get_x(); }
    int      get_height() const { return _max_loc.get_y() - _min_loc.get_y(); }

    // getter
    void set_min_location(const Location &loc) { _min_loc = loc; }
    void set_max_location(const Location &loc) { _max_loc = loc; }

    // operator
    bool contains(const Location &loc) const;
    bool contains(const Rect &rect) const;
    bool contains_x(const Rect &rect) const;
    bool contains_y(const Rect &rect) const;

private:
    Location _min_loc;
    Location _max_loc;
};

inline bool Rect::contains(const Location &loc) const {
    int x = loc.get_x();
    int y = loc.get_y();
    return (_min_loc.get_x() <= x && x <= _max_loc.get_x()) &&
           (_min_loc.get_y() <= y && y <= _max_loc.get_y());
}

inline bool Rect::contains_x(const Rect &rect) const {
    return _min_loc.get_x() <= rect.get_min_x() && rect.get_max_x() <= _max_loc.get_x();
}
inline bool Rect::contains_y(const Rect &rect) const {
    return _min_loc.get_y() <= rect.get_min_y() && rect.get_max_y() <= _max_loc.get_y();
}

inline bool Rect::contains(const Rect &rect) const { return contains_x(rect) && contains_y(rect); }

} // namespace traffic