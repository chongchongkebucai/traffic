#pragma once

#include <algorithm>
#include <climits>
#include <list>
#include <string>

#include "Color.h"
#include "Config.h"
#include "Enum.h"
#include "Log.h"
#include "Manager.h"
#include "Map.h"
#include "Random.h"
#include "Transport.h"

namespace traffic {
using std::list;

class Simulator {
public:
    Simulator();
    explicit Simulator(const string &config_file);
    Simulator(const Simulator &) = delete;
    ~Simulator();

    void entry_crossing();
    void move();
    void leave_crossing();
    void display();

    bool check() const;

    void write_date(int time) const { _log->write(time, _transports); }

private:
    void person_enter_crossing();
    void car_enter_crossing();

    void calc_speed();
    void calc_speed(Person *person);
    void calc_speed(Car *car);
    void revise_speed(Person *person);
    void once_cross(Person *person, Transport *car);
    void no_once_cross(Person *person, Transport *car);
    void calc_loc();
    void update_loc();
    void update_loc(Transport *trans);

    Road       select_road(int left_gap, int cur_gap, int right_gap, Transport *trans) const;
    int        calc_gap(Transport *transport) const;
    Transport *left_front_nearest_car(Transport *transport) const;
    bool       is_front(Transport *cur_trans, Transport *front_trans) const;
    bool       region_change(Transport *transport) const;
    int        distance(Transport *from, Transport *to) const;

    Transport *find_transport(int id) const;
    Transport *front_transport(Transport *transport) const;
    bool       is_person(Transport *transport) const;
    bool       is_car(Transport *transport) const;
    void       displacement(Location &loc, Direction dir, int dist = 1) const;
    Location   calc_next_loc(Transport *trans) const;
    bool       placeable(const Rect &rect, int id) const;

private:
    Config *          _config;
    Manager *         _manager;
    Random *          _random;
    Map *             _map;
    list<Transport *> _transports;
    Log *             _log;
};

inline bool Simulator::is_person(Transport *transport) const {
    return typeid(*transport) == typeid(Person);
}
inline bool Simulator::is_car(Transport *transport) const {
    return dynamic_cast<Car *>(transport) != nullptr;
}

} // namespace traffic