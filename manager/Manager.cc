#include "Manager.h"

namespace traffic {

Manager::Manager() {
    this->_id = 0;
    this->_config = new Config();
}

Manager::Manager(Config *config, int id /* = 0 */) {
    this->_id = id;
    this->_config = config;
}

Person *Manager::create_person() {
    int     id = get_id();
    Person *person = new Person(id);

    person->set_accelerated_speed(_config->get_accelerated_speed());
    person->set_width(_config->get_person_width());
    person->set_height(_config->get_person_height());
    person->set_max_speed(_config->get_person_max_speed());
    person->set_normal_speed(_config->get_person_normal_speed());
    person->set_once_crossing(_random.bernoulli_distribution(_config->get_once_crossing_rate()));

    return person;
}

Car *Manager::create_car() {
    Car *car = nullptr;
    int  id = get_id();

    auto &car_ratio = _config->get_car_ratio();
    int   index = _random.discrete_distribution(car_ratio);
    if (index == 0) {
        car = new Electrocar(id);
        car->set_width(_config->get_electrocar_width());
        car->set_height(_config->get_electrocar_height());
        car->set_max_speed(_config->get_electrocar_max_speed());
    } else if (index == 1) {
        car = new Bicycle(id);
        car->set_width(_config->get_bicycle_width());
        car->set_height(_config->get_bicycle_height());
        car->set_max_speed(_config->get_bicycle_max_speed());
    } else if (index == 2) {
        car = new Tricycle(id);
        car->set_width(_config->get_tricycle_width());
        car->set_height(_config->get_tricycle_height());
        car->set_max_speed(_config->get_tricycle_max_speed());
    } else {
        std::cout << "应该不会进入这里吧！不会吧不会吧" << std::endl;
    }
    car->set_direction(Direction::kRight);
    car->set_accelerated_speed(_config->get_accelerated_speed());
    return car;
}

int Manager::get_id() {
    int id = 0;
    _mutex.lock();
    if (_id == 0) {
        _id++;
    }
    id = _id++;
    _mutex.unlock();
    return id;
}

} // namespace traffic