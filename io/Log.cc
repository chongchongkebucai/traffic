#include "Log.h"

namespace traffic {

Log::Log() {
    _config = new Config();
    string time_space_file = _config->get_time_space_file();
    _time_space_out.open(time_space_file, std::ios::out | std::ios::trunc);
    string delay_file = _config->get_delay_file();
    _delay_out.open(delay_file);
}

Log::Log(Config *config) {
    _config = config;
    string time_space_file = _config->get_time_space_file();
    _time_space_out.open(time_space_file, std::ios::out | std::ios::trunc);
    string delay_file = _config->get_delay_file();
    _delay_out.open(delay_file);
}

Log::~Log() {
    _time_space_out.close();
    _delay_out.close();
}

void Log::write_coord(int time, const list<Transport *> &transports) {
    _time_space_out << time << " ; ";

    for (auto trans : transports) {
        if (dynamic_cast<Person *>(trans) != nullptr) {
            write_coord(trans);
            _time_space_out << ": ";
        }
    }
    _time_space_out << "; ";

    for (auto trans : transports) {
        if (dynamic_cast<Car *>(trans) != nullptr) {
            write_coord(trans);
            _time_space_out << ": ";
        }
    }
    _time_space_out << std::endl;
}

void Log::write_coord(Transport *trans) {
    if (dynamic_cast<Person *>(trans) != nullptr) {
        auto dir = trans->get_direction();
        _time_space_out << (dir == Direction::kUp ? 0 : 1) << " ";
        _time_space_out << trans->get_cur_loc().get_y();
    } else if (dynamic_cast<Car *>(trans) != nullptr) {
        if (dynamic_cast<Bicycle *>(trans) != nullptr) {
            _time_space_out << 1 << " ";
        } else if (dynamic_cast<Electrocar *>(trans) != nullptr) {
            _time_space_out << 2 << " ";
        } else if (dynamic_cast<Tricycle *>(trans) != nullptr) {
            _time_space_out << 3 << " ";
        }
        _time_space_out << trans->get_cur_loc().get_x();
    } else {
        assert(0);
    }
}

void Log::write_delay(Transport *trans) {
    int type;
    if (dynamic_cast<Person *>(trans) != nullptr) {
        type = 1;
    } else if (dynamic_cast<Car *>(trans) != nullptr) {
        type = 2;
    }
    int time = trans->get_time();
    _delay_out << type << " " << time << std::endl;
}

} // namespace traffic
