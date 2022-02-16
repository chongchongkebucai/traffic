#pragma once

#include <cassert>
#include <fstream>
#include <list>

#include "Bicycle.h"
#include "Car.h"
#include "Config.h"
#include "Electrocar.h"
#include "Person.h"
#include "Transport.h"
#include "Tricycle.h"

namespace traffic {
using std::list;
using std::ofstream;

class Log {
public:
    Log();
    Log(Config *config);
    Log(const Log &) = default;
    ~Log();

    void write_coord(int time, const list<Transport *> &transports);
    void write_coord(Transport *trans);

    void write_delay(Transport *trans);

private:
    Config * _config;
    ofstream _time_space_out;
    ofstream _delay_out;
};

} // namespace traffic