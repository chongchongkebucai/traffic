#pragma once

#include <cassert>
#include <fstream>
#include <list>

#include "Car.h"
#include "Config.h"
#include "Person.h"
#include "Transport.h"
#include "Bicycle.h"
#include "Tricycle.h"
#include "Electrocar.h"

namespace traffic {
using std::list;
using std::ofstream;

class Log {
public:
    Log();
    Log(Config *config);
    Log(const Log &) = default;
    ~Log() { _out.close(); }

    void write(int time, const list<Transport *> &transports);
    void write(Transport *trans);

private:
    Config * _config;
    ofstream _out;
};

} // namespace traffic