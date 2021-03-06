#include "Simulator.h"

namespace traffic {

Simulator::Simulator() {
    _config = new Config();
    _manager = new Manager(this->_config);
    _random = new Random();
    _map = new Map(this->_config);
    _log = new Log(this->_config);
}
Simulator::Simulator(const string &confige_file) {
    this->_config = new Config(confige_file);
    this->_manager = new Manager(this->_config);
    this->_random = new Random();
    this->_map = new Map(this->_config);
    this->_log = new Log(this->_config);
    this->_car_conflict_num = 0;
    this->_person_conflict_num = 0;
}

Simulator::~Simulator() {
    for (auto *transport : _transports) {
        if (transport) {
            delete transport;
        }
    }
    if (this->_config) {
        delete this->_config;
    }
    if (this->_map) {
        delete this->_map;
    }
    if (this->_manager) {
        delete _manager;
    }
    if (this->_random) {
        delete _random;
    }
    if (this->_log) {
        delete _log;
    }
}

void Simulator::move() {
    calc_speed();
    update_loc();
}
void Simulator::calc_speed() {
    for (auto *transport : _transports) {
        if (is_person(transport)) {
            Person *person = dynamic_cast<Person *>(transport);
            calc_speed(person);
            revise_speed(person);
        } else if (is_car(transport)) {
            calc_speed(dynamic_cast<Car *>(transport));
        } else {
            std::cout << "haunted!" << std::endl;
        }
    }
}
void Simulator::calc_speed(Person *person) {
    auto loc = person->get_cur_loc();
    int  width = person->get_width();

    person->set_cur_loc(loc.get_x() - width, loc.get_y());
    int left_gap = calc_gap(person);
    person->set_cur_loc(loc.get_x() + width, loc.get_y());
    int right_gap = calc_gap(person);
    person->set_cur_loc(loc);
    int cur_gap = calc_gap(person);

    Road road = select_road(left_gap, cur_gap, right_gap, person);
    person->set_next_road(road);

    Transport *front_trans = front_transport(person);
    if (road != Road::kMiddle) {
        if (dynamic_cast<Car *>(front_trans) != nullptr) {
            person->set_conflict(true);
        }
    }

    auto gap = std::max(cur_gap, std::max(left_gap, right_gap));
    auto normal_speed = person->get_normal_speed();
    auto next_speed = std::min(normal_speed, gap);
    person->set_next_speed(next_speed);

    if (next_speed != normal_speed && dynamic_cast<Car *>(front_trans) != nullptr) {
        person->set_conflict(true);
    }
}
void Simulator::revise_speed(Person *person) {
    // ??????????????????
    if (person->get_next_speed() == 0) {
        return;
    }
    Transport *car1 = left_front_nearest_car(person);
    Transport *car2 = right_front_nearest_car(person);
    Transport *car = nullptr;
    if (!car1 && !car2) {
        return;
    } else if (!car1 && car2) {
        car = car2;
    } else if (car1 && !car2) {
        car = car1;
    } else {
        auto time1 =
            distance(car1, person) / (car1->get_next_speed() == 0 ? 1 : car1->get_next_speed());
        auto time2 =
            distance(car2, person) / (car2->get_next_speed() == 0 ? 1 : car2->get_next_speed());
        if (time1 < time2) {
            car = car1;
        } else {
            car = car2;
        }
    }

    // ????????????
    bool is_once_crossing = person->get_once_crossing();
    if (is_once_crossing) {
        once_cross(person, car);
    } else {
        no_once_cross(person, car);
    }
}

void Simulator::once_cross(Person *person, Transport *car) {
    auto   dir = person->get_direction();
    auto   dist = distance(car, person);
    auto   speed = car->get_next_speed();
    double time = speed == 0 ? INT_MAX : dist / speed;

    auto upward_pass_rate = _config->get_upward_person_pass_rate();
    auto downward_pass_rate = _config->get_downward_person_pass_rate();
    auto low_bound_time = _config->get_lower_bound_time();
    auto up_bound_time = _config->get_upper_bound_time();

    if (time >= up_bound_time) {
        return;
    } else if (low_bound_time <= time && time < up_bound_time) {
        if ((dir == Direction::kUp && _random->bernoulli_distribution(upward_pass_rate)) ||
            (dir == Direction::kDown && _random->bernoulli_distribution(downward_pass_rate))) {
            person->set_next_speed(person->get_max_speed());
        } else {
            person->set_next_speed(0);
            person->set_conflict(true);
        }
    } else {
        person->set_conflict(true);
        person->set_next_speed(0);
    }
}

void Simulator::no_once_cross(Person *person, Transport *car) {
    auto dist = distance(car, person);
    auto dir = person->get_direction();

    auto upward_pass_rate = _config->get_upward_person_pass_rate();
    auto downward_pass_rate = _config->get_downward_person_pass_rate();
    auto low_bound_dist = _config->get_lower_bound_dist();
    auto up_bound_dist = _config->get_upper_bound_dist();

    if (dist >= up_bound_dist) {
        return;
    } else if ((low_bound_dist <= dist && dist < up_bound_dist)) {
        if ((dir == Direction::kUp && _random->bernoulli_distribution(upward_pass_rate)) ||
            (dir == Direction::kDown && _random->bernoulli_distribution(downward_pass_rate))) {
            person->set_next_speed(person->get_max_speed());
        } else {
            person->set_next_speed(0);
            person->set_conflict(true);
        }
    } else {
        person->set_conflict(true);
        person->set_next_speed(0);
    }
}

void Simulator::calc_speed(Car *car) {
    auto loc = car->get_cur_loc();
    auto dir = car->get_direction();
    auto car_box = car->get_bounding_box();
    auto width = _config->get_lane_width();
    auto speed = car->get_speed();
    speed = std::min(speed + _config->get_accelerated_speed(), car->get_max_speed());

    // ???????????????????????????????????????
    if (!_map->get_super_way().contains_x(car_box)) {
        car->set_next_road(Road::kMiddle);
        car->set_next_speed(car_box.get_width() + 1);
    } else {
        car->set_cur_loc(loc.get_x(), loc.get_y() + width);
        int left_gap = calc_gap(car);
        car->set_cur_loc(loc.get_x(), loc.get_y() - width);
        int right_gap = calc_gap(car);
        car->set_cur_loc(loc);
        int cur_gap = calc_gap(car);

        Transport *trans = front_transport(car);
        if (trans && dynamic_cast<Car *>(trans) != nullptr &&
            opposite_direction(trans->get_direction(), car->get_direction()) &&
            distance(car, trans) < 45) {
            auto dist = distance(car, trans);
            if (15 <= dist && dist < 45) {
                if (dir == Direction::kRight) {
                    left_gap = 0;
                } else if (dir == Direction::kLeft) {
                    right_gap = 0;
                }
                Road road = select_road(left_gap, cur_gap, right_gap, car);
                car->set_next_road(road);
                if (road != Road::kMiddle && dynamic_cast<Person *>(trans) != nullptr) {
                    car->set_conflict(true);
                }

                int gap = cur_gap;
                if (road == Road::kLeft) {
                    gap = left_gap;
                } else if (road == Road::kRight) {
                    gap = right_gap;
                }

                car->set_next_speed(std::min(speed, gap));
                if (car->get_conflict() == false && speed != gap &&
                    dynamic_cast<Person *>(trans) != nullptr) {
                    car->set_conflict(true);
                }
            } else {
                if ((dir == Direction::kRight && right_gap == 0) ||
                    (dir == Direction::kLeft && left_gap == 0)) {
                    car->set_next_road(Road::kMiddle);
                    car->set_next_speed(0);
                } else {
                    car->set_next_road(dir == Direction::kRight ? Road::kRight : Road::kLeft);
                    car->set_next_speed(
                        std::min(speed, dir == Direction::kRight ? right_gap : left_gap));
                }

                if (dynamic_cast<Person *>(trans) != nullptr) {
                    car->set_conflict(true);
                }
            }
        } else {
            Road road = select_road(left_gap, cur_gap, right_gap, car);
            car->set_next_road(road);

            Transport *front_trans = front_transport(car);
            if (road != Road::kMiddle && dynamic_cast<Person *>(front_trans) != nullptr) {
                car->set_conflict(true);
            }

            int gap = cur_gap;
            if (road == Road::kLeft) {
                gap = left_gap;
            } else if (road == Road::kRight) {
                gap = right_gap;
            }
            car->set_next_speed(std::min(speed, gap));
            if (car->get_conflict() == false && speed != gap &&
                dynamic_cast<Person *>(trans) != nullptr) {
                car->set_conflict(true);
            }
        }
    }

    if (_random->bernoulli_distribution(_config->get_moderating_rate())) {
        auto next_speed = car->get_next_speed() - 1;
        next_speed = next_speed < 0 ? 0 : next_speed;
        car->set_next_speed(next_speed);
    }
}
void Simulator::update_loc() {
    for (auto *trans : _transports) {
        if (dynamic_cast<Car *>(trans) != nullptr) {
            update_loc(trans);
        }
    }
    for (auto *trans : _transports) {
        if (dynamic_cast<Person *>(trans) != nullptr) {
            update_loc(trans);
        }
    }

    for (auto *trans : _transports) {
        if (dynamic_cast<Car *>(trans) != nullptr) {
            if (trans->get_conflict() == true) {
                _car_conflict_num++;
            }
        } else if (dynamic_cast<Person *>(trans) != nullptr) {
            if (trans->get_conflict() == true) {
                _person_conflict_num++;
            }
        }

        trans->set_conflict(false);
    }
}
void Simulator::update_loc(Transport *trans) {
    auto     loc = calc_next_loc(trans);
    Location max_loc(loc.get_x() + trans->get_width() - 1, loc.get_y() + trans->get_height() - 1);
    Rect     rect(loc, max_loc);

    if (placeable(rect, trans->get_id())) {
        trans->set_speed(trans->get_next_speed());
        _map->clear_transport(trans);
        trans->set_cur_loc(loc);
        _map->add_transport(trans);
    } else {
        trans->set_next_speed(0);

        auto       ids = _map->get_id(rect);
        Transport *next_trans = find_transport(ids);
        if (dynamic_cast<Person *>(trans) != nullptr &&
                dynamic_cast<Car *>(next_trans) != nullptr ||
            dynamic_cast<Car *>(trans) != nullptr &&
                dynamic_cast<Person *>(next_trans) != nullptr) {
            trans->set_conflict(true);
        }
    }
}

Transport *Simulator::find_transport(const vector<int> &ids) const {
    for (auto cur_id : ids) {
        auto *trans = find_transport(cur_id);
        if (trans) {
            return trans;
        }
    }
    return nullptr;
}

bool Simulator::placeable(const Rect &rect, int id) const {
    auto ids = _map->get_id(rect);
    for (auto cur_id : ids) {
        if (cur_id == -1 || (cur_id > 0 && cur_id != id)) {
            return false;
        }
    }
    return true;
}

Location Simulator::calc_next_loc(Transport *transport) const {
    auto      loc = transport->get_cur_loc();
    Direction dir = transport->get_direction();
    auto      speed = transport->get_next_speed();
    Road      road = transport->get_next_road();
    auto      trans_width = transport->get_width();
    auto      trans_height = transport->get_height();

    if (is_person(transport)) {
        if ((dir == Direction::kUp && road == Road::kLeft) ||
            (dir == Direction::kDown && road == Road::kRight)) {
            displacement(loc, Direction::kLeft, trans_width);
        } else if ((dir == Direction::kUp && road == Road::kRight) ||
                   (dir == Direction::kDown && road == Road::kLeft)) {
            displacement(loc, Direction::kRight, trans_width);
        }
    } else {
        if (dir == Direction::kRight && road == Road::kLeft) {
            displacement(loc, Direction::kUp, trans_height);
        } else if (dir == Direction::kRight && road == Road::kRight) {
            displacement(loc, Direction::kDown, trans_height);
        } else if (dir == Direction::kLeft && road == Road::kLeft) {
            displacement(loc, Direction::kUp, trans_height);
        } else if (dir == Direction::kLeft && road == Road::kRight) {
            displacement(loc, Direction::kDown, trans_height);
        }
    }

    displacement(loc, dir, speed);
    return loc;
}

Road Simulator::select_road(int left_gap, int cur_gap, int right_gap, Transport *trans) const {
    auto dir = trans->get_direction();
    auto loc = trans->get_cur_loc();
    auto rect = trans->get_bounding_box();
    auto height = trans->get_height();

    if (cur_gap >= std::max(left_gap, right_gap)) {
        return Road::kMiddle;
    }

    auto sidewalk_rect = _map->get_sidewalk();
    auto superway_rect = _map->get_super_way();
    if (dir == Direction::kUp) {
        displacement(loc, Direction::kLeft, 1);
        if (false == sidewalk_rect.contains(loc)) {
            return Road::kRight;
        }
        displacement(loc, Direction::kRight, 2);
        if (false == sidewalk_rect.contains(loc)) {
            return Road::kLeft;
        }
    } else if (dir == Direction::kDown) {
        displacement(loc, Direction::kLeft, 1);
        if (false == sidewalk_rect.contains(loc)) {
            return Road::kLeft;
        }
        displacement(loc, Direction::kRight, 2);
        if (false == sidewalk_rect.contains(loc)) {
            return Road::kRight;
        }
    } else if (dir == Direction::kRight) {
        displacement(loc, Direction::kUp, height);
        if (false == superway_rect.contains(trans->get_bounding_box().move_y(height))) {
            return Road::kRight;
        }
        displacement(loc, Direction::kDown, trans->get_height() * 2);
        if (false == superway_rect.contains(trans->get_bounding_box().move_y(-1 * height))) {
            return Road::kLeft;
        }
    } else if (dir == Direction::kLeft) {
        displacement(loc, Direction::kUp, trans->get_height());
        if (false == superway_rect.contains(rect.move_y(height))) {
            return Road::kRight;
        }
        displacement(loc, Direction::kDown, trans->get_height() * 2);
        if (false == superway_rect.contains(rect.move_y(-2 * height))) {
            return Road::kLeft;
        }
    }

    if (left_gap == right_gap) {
        if (dir == Direction::kRight) {
            return Road::kRight;
        } else if (dir == Direction::kLeft) {
            return Road::kLeft;
        } else if (dir == Direction::kUp) {
            return Road::kRight;
        } else if (dir == Direction::kDown) {
            return Road::kLeft;
        }
    } else {
        if (left_gap > right_gap) {
            return Road::kLeft;
            // if (dir == Direction::kUp) {
            //     return Road::kLeft;
            // } else if (dir == Direction::kDown) {
            //     return Road::kRight;
            // } else if (dir == Direction::kRight) {
            //     return Road::kLeft;
            // } else {
            //     return Road::kRight;
            // }
        } else {
            return Road::kRight;
            // if (dir == Direction::kUp) {
            //     return Road::kRight;
            // } else if (dir == Direction::kDown) {
            //     return Road::kLeft;
            // } else if (dir == Direction::kRight) {
            //     return Road::kRight;
            // } else {
            //     return Road::kLeft;
            // }
        }
    }
}
// only calculate dead ahead
int Simulator::calc_gap(Transport *transport) const {
    auto      loc = transport->get_cur_loc();
    Direction dir = transport->get_direction();
    auto      trans_box = transport->get_bounding_box();
    auto      sidewalk_box = _map->get_sidewalk();
    auto      superway_box = _map->get_super_way();

    // ??????????????????????????????
    if (dir == Direction::kUp || dir == Direction::kDown) {
        if (!sidewalk_box.contains_x(trans_box)) {
            return 0;
        }
    } else {
        if (!superway_box.contains_y(trans_box)) {
            return 0;
        }
    }
    // ???????????????????????????????????????
    auto ids = _map->get_id(trans_box);
    for (auto id : ids) {
        if (id != 0 && id != transport->get_id()) {
            return 0;
        }
    }

    // ????????????????????????????????????
    auto *front_trans = front_transport(transport);
    if (front_trans == nullptr) {
        return INT_MAX;
    }

    int dist = distance(transport, front_trans);

    if (opposite_direction(dir, front_trans->get_direction())) {
        return dist / 2;
    } else {
        return dist;
    }
}

int Simulator::distance(Transport *from, Transport *to) const {
    auto dir = from->get_direction();
    auto from_loc = from->get_cur_loc();
    auto to_loc = to->get_cur_loc();

    if (dir == Direction::kUp || dir == Direction::kDown) {
        return std::abs(from_loc.get_y() - to_loc.get_y()) - from->get_height();
    } else {
        if (dynamic_cast<Car *>(from) != nullptr && dynamic_cast<Person *>(to) != nullptr &&
            from->get_direction() == Direction::kLeft) {
            auto dist = std::abs(to_loc.get_x() - from_loc.get_x());
            if (dist < 0) {
                return 0;
            }
            return dist;
        }
        auto dist = std::abs(to_loc.get_x() - from_loc.get_x()) - from->get_width();
        if (dist < 0) {
            return 0;
        }
        return dist;
    }
}

Transport *Simulator::front_transport(Transport *transport) const {
    auto cur_id = transport->get_id();
    auto dir = transport->get_direction();
    auto loc = transport->get_cur_loc();
    auto width = transport->get_width();
    auto height = transport->get_height();

    auto is_trans = [](int id) { return id <= 0; };

    do {
        displacement(loc, dir);
        if (!_map->within_boundary(loc)) {
            return nullptr;
        }
        Rect rect(loc, Location(loc.get_x() + width - 1, loc.get_y() + height - 1));
        auto ids = _map->get_id(rect);
        ids.erase(std::remove_if(ids.begin(), ids.end(), is_trans), ids.end());
        if (ids.size() > 1 || (ids.size() == 1 && ids[0] != cur_id)) {
            Transport *near_trans = nullptr;
            int        min_dist = INT_MAX;
            for (auto id : ids) {
                auto *trans = find_transport(id);
                if (transport == trans) {
                    continue;
                }
                auto dist = distance(transport, trans);
                if (dist < min_dist) {
                    near_trans = trans;
                    min_dist = dist;
                }
            }
            return near_trans;
        }
    } while (true);
}

void Simulator::displacement(Location &loc, Direction dir, int dist /* = 1 */) const {
    while (dist--) {
        if (dir == Direction::kLeft) {
            loc.set_x(loc.get_x() - 1);
        } else if (dir == Direction::kRight) {
            loc.set_x(loc.get_x() + 1);
        } else if (dir == Direction::kUp) {
            loc.set_y(loc.get_y() + 1);
        } else if (dir == Direction::kDown) {
            loc.set_y(loc.get_y() - 1);
        }
    }
}

Transport *Simulator::left_front_nearest_car(Transport *transport) const {
    auto      loc = transport->get_cur_loc();
    Direction dir = transport->get_direction();
    int       width = _config->get_safe_dist();
    int       height = transport->get_next_speed();

    Location min_loc;
    Location max_loc;
    if (dir == Direction::kUp) {
        min_loc.set_x(loc.get_x() - width);
        min_loc.set_y(loc.get_y() + 1);
        max_loc.set_x(loc.get_x() - 1);
        max_loc.set_y(loc.get_y() + height);
    } else {
        min_loc.set_x(loc.get_x() - width);
        min_loc.set_y(loc.get_y() - height);
        max_loc.set_x(loc.get_x() - 1);
        max_loc.set_y(loc.get_y() - 1);
    }
    Rect rect(min_loc, max_loc);

    vector<int> ids = _map->get_id(rect);

    Transport *near_car = nullptr;
    int        min_time = INT_MAX;
    for (auto id : ids) {
        Transport *near_trans = find_transport(id);
        if (is_car(near_trans) && is_front(transport, near_trans)) {
            int    dist = std::abs(near_trans->get_cur_loc().get_x() - loc.get_x());
            int    speed = near_trans->get_speed();
            double time = 1.0 * dist / speed;
            if (time < min_time) {
                min_time = time;
                near_car = near_trans;
            }
        }
    }
    return near_car;
}

Transport *Simulator::right_front_nearest_car(Transport *transport) const {
    auto      loc = transport->get_cur_loc();
    Direction dir = transport->get_direction();
    int       width = _config->get_safe_dist();
    int       height = transport->get_next_speed();

    Location min_loc;
    Location max_loc;
    if (dir == Direction::kUp) {
        min_loc.set_x(loc.get_x() + 1);
        min_loc.set_y(loc.get_y() + 1);
        max_loc.set_x(loc.get_x() + width);
        max_loc.set_y(loc.get_y() + height);
    } else {
        min_loc.set_x(loc.get_x() + 1);
        min_loc.set_y(loc.get_y() - height);
        max_loc.set_x(loc.get_x() + width);
        max_loc.set_y(loc.get_y() - 1);
    }
    Rect rect(min_loc, max_loc);

    vector<int> ids = _map->get_id(rect);

    Transport *near_car = nullptr;
    int        min_time = INT_MAX;
    for (auto id : ids) {
        Transport *near_trans = find_transport(id);
        if (is_car(near_trans) && is_front(transport, near_trans)) {
            int    dist = std::abs(near_trans->get_cur_loc().get_x() - loc.get_x());
            int    speed = near_trans->get_speed();
            double time = 1.0 * dist / speed;
            if (time < min_time) {
                min_time = time;
                near_car = near_trans;
            }
        }
    }
    return near_car;
}

bool Simulator::is_front(Transport *cur_trans, Transport *front_trans) const {
    auto cur_box = cur_trans->get_bounding_box();
    auto front_box = front_trans->get_bounding_box();
    auto dir = cur_trans->get_direction();

    if (dir == Direction::kUp) {
        return front_box.get_max_x() < cur_box.get_min_x() &&
               front_box.get_min_y() > cur_box.get_max_y();
    } else if (dir == Direction::kDown) {
        return cur_box.get_min_y() > front_box.get_max_y() &&
               cur_box.get_min_x() > front_box.get_max_x();
    } else {
        assert(0);
    }
}

bool Simulator::region_change(Transport *transport) const {
    auto loc = transport->get_cur_loc();
    auto next_loc = loc;
    auto rect = _map->get_super_way();

    auto speed = transport->get_next_speed();
    auto dir = transport->get_direction();
    if (dir == Direction::kUp) {
        next_loc.set_y(loc.get_y() + speed);
    } else {
        next_loc.set_y(loc.get_y() - speed);
    }

    return !rect.contains(loc) && rect.contains(next_loc);
}

Transport *Simulator::find_transport(int id) const {
    for (auto *transport : _transports) {
        if (transport->get_id() == id) {
            return transport;
        }
    }
    return nullptr;
}

void Simulator::entry_crossing() {
    person_enter_crossing();
    car_enter_crossing();
}
void Simulator::person_enter_crossing() {
    int  coord_x = 0;
    int  coord_y = 0;
    auto min_loc = _map->get_sidewalk_min_location();
    auto max_loc = _map->get_sidewalk_max_location();
    int  width = _map->get_sidewalk_width();

    auto person_downward_arrival_rate = _config->get_downward_person_arrival_rate();
    if (true == _random->bernoulli_distribution(person_downward_arrival_rate)) {
        Person *person = _manager->create_person();
        person->set_direction(Direction::kDown);

        int count = 0;
        do {
            coord_x = _random->uniform_distribution(0, width - 1) + min_loc.get_x();
            coord_y = max_loc.get_y();
            person->set_cur_loc(Location(coord_x, coord_y));
            if (count++ > 100) {
                delete person;
                person = nullptr;
                break;
            }
        } while (_map->have_transport(person->get_cur_loc()));
        if (person) {
            _transports.emplace_back(person);
            _map->add_transport(person);
        }
    }

    auto person_upward_arrvial_rate = _config->get_upward_person_arrival_rate();
    if (true == _random->bernoulli_distribution(person_upward_arrvial_rate)) {
        Person *person = _manager->create_person();
        person->set_direction(Direction::kUp);

        int count = 0;
        do {
            coord_x = _random->uniform_distribution(0, width - 1) + min_loc.get_x();
            coord_y = 0;
            person->set_cur_loc(Location(coord_x, coord_y));
            if (count++ > 100) {
                delete person;
                person = nullptr;
                break;
            }
        } while (_map->have_transport(person->get_cur_loc()));
        if (person) {
            _transports.emplace_back(person);
            _map->add_transport(person);
        }
    }
}
void Simulator::car_enter_crossing() {
    auto super_way_min_loc = _map->get_super_way_min_location();
    int  super_way_height = _map->get_super_way_height();

    auto left_car_arrival_rate = _config->get_left_car_arrival_rate();
    auto right_car_arrival_rate = _config->get_right_car_arrival_rate();
    if (true == _random->bernoulli_distribution(left_car_arrival_rate)) {
        Car *car = _manager->create_car(Direction::kRight);
        Rect bounding_box;
        int  count = 1;

        do {
            int coord_x = 0;
            int coord_y =
                _random->uniform_distribution(0, super_way_height - 3) + super_way_min_loc.get_y();
            if (coord_y % 2 == 1) {
                coord_y--;
            }
            car->set_cur_loc(Location(coord_x, coord_y));
            bounding_box = car->get_bounding_box();

            if (count++ > 1000) {
                delete car;
                car = nullptr;
                break;
            }
        } while (_map->have_transport(bounding_box));

        if (car) {
            _transports.emplace_back(car);
            _map->add_transport(car);
        }
    }

    if (true == _random->bernoulli_distribution(right_car_arrival_rate)) {
        Car *car = _manager->create_car(Direction::kLeft);
        Rect bounding_box;
        int  count = 1;

        do {
            int coord_x = _config->get_super_way_width() - car->get_width() - 1;
            int coord_y =
                _random->uniform_distribution(0, super_way_height - 3) + super_way_min_loc.get_y();
            if (coord_y % 2 == 1) {
                coord_y--;
            }
            car->set_cur_loc(Location(coord_x, coord_y));
            bounding_box = car->get_bounding_box();

            if (count++ > 1000) {
                delete car;
                car = nullptr;
                break;
            }
        } while (_map->have_transport(bounding_box));

        if (car) {
            _transports.emplace_back(car);
            _map->add_transport(car);
        }
    }
}

void Simulator::leave_crossing() {
    for (auto iter = _transports.begin(); iter != _transports.end();) {
        auto loc = (*iter)->get_cur_loc();

        if (_map->within_boundary(loc) == false) {
            auto *trans = *iter;
            _log->write_delay(trans);
            _map->clear_transport(trans);
            _manager->destroy_transport(trans);
            iter = _transports.erase(iter);
        } else {
            ++iter;
        }
    }
}

void Simulator::display() {
    auto *graph = _map->get_graph();
    auto  row_num = graph->get_row_num();
    auto  col_num = graph->get_col_num();

    for (int row = row_num - 1; row >= 0; --row) {
        for (int col = 0; col < col_num; ++col) {
            int val = graph->get_value(row, col);
            if (val == -1) {
                std::cout << "#";
            } else if (val == 0) {
                std::cout << " ";
            } else {
                int   msg = val % 10;
                auto *trans = find_transport(val);
                auto  dir = trans->get_direction();
                if (dynamic_cast<Person *>(trans) != nullptr) {
                    if (dir == Direction::kUp) {
                        std::cout << GREEN << msg << RESET;
                    } else if (dir == Direction::kDown) {
                        std::cout << BLUE << msg << RESET;
                    }
                } else if (dynamic_cast<Car *>(trans) != nullptr) {
                    if (dir == Direction::kRight) {
                        std::cout << RED << msg << RESET;
                    } else if (dir == Direction::kLeft) {
                        std::cout << PURPLE << msg << RESET;
                    }
                }
            }
        }
        std::cout << std::endl;
    }

    std::cout << "\n" << std::endl;
    int num = _config->get_super_way_width();
    for (int i = 0; i < num; i++) {
        std::cout << "-";
    }
    std::cout << "\n" << std::endl;
}

void Simulator::update_time() {
    for (auto *trans : _transports) {
        trans->set_time(trans->get_time() + 1);
    }
}

bool Simulator::check() const {
    for (auto *trans : _transports) {
        auto loc = trans->get_cur_loc();
        int  id = _map->get_id(loc);
        if (trans->get_id() != id) {
            return false;
        }
    }
    return true;
}

} // namespace traffic