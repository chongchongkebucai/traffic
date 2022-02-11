#pragma once

#include <fstream>
#include <cassert>
#include <list>

#include "Car.h"
#include "Config.h"
#include "Person.h"
#include "Transport.h"

namespace traffic {
using std::list;
using std::ofstream;

class Log {
public:
    Log();
    Log(Config *config);
    Log(const Log &) = default;
    ~Log() = default;

    void write(int time, const list<Transport *> &transports);
    void write(Transport *trans);

private:
    Config  *_config;
    ofstream _out;
};

} // namespace traffic