#include "Log.h"

namespace traffic {

Log::Log() {
    _config = new Config();
    string file_name = _config->get_file_name();
    _out.open(file_name, std::ios::out | std::ios::trunc);
}

Log::Log(Config *config) {
    _config = config;
    string file_name = _config->get_file_name();
    _out.open(file_name, std::ios::out | std::ios::trunc);
}

void Log::write(int time, const list<Transport *> &transports) {
    _out << time << "; ";

    for (auto trans : transports) {
        if (dynamic_cast<Person *>(trans) != nullptr) {
            write(trans);
            _out << " ";
        }
    }

    _out << "; ";

    for (auto trans : transports) {
        if (dynamic_cast<Car *>(trans) != nullptr) {
            write(trans);
            _out << " ";
        }
    }

    _out << "\n";
}

void Log::write(Transport *trans) {
    if (dynamic_cast<Person *>(trans) != nullptr) {
        _out << trans->get_cur_loc().get_y();
    } else if (dynamic_cast<Car *>(trans) != nullptr) {
        _out << trans->get_cur_loc().get_x();
    } else {
        assert(0);
    }
}

} // namespace traffic
