#pragma once

#include <ostream>

namespace traffic {

class Location {
public:
    Location() : _x(0), _y(0) {}
    Location(int x, int y) : _x(x), _y(y) {}
    Location(const Location &Location) = default;
    ~Location() = default;

    int get_x() const { return _x; }
    int get_y() const { return _y; }

    void set_x(int x) { _x = x; }
    void set_y(int y) { _y = y; }

    bool operator<(const Location &rhs) const {
        return _y < rhs.get_y() || (_y == rhs.get_y() && _x < rhs.get_x());
    }
    bool operator==(const Location &rhs) const { return _x == rhs.get_x() && _y == rhs.get_y(); }
    bool operator!=(const Location &rhs) const { return !(operator==(rhs)); }

private:
    int _x;
    int _y;
};

inline std::ostream &operator<<(std::ostream &os, const Location &Location) {
    return os << "(" << Location.get_x() << ", " << Location.get_y() << ")";
}

} // namespace traffic
