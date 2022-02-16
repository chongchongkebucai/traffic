#include "Simulator.h"
#include <unistd.h>

using namespace traffic;

int main() {
    Simulator simulator;

    int count = 0;
    while (1) {
        simulator.move();
        simulator.update_time();
        simulator.entry_crossing();
        simulator.display();
        simulator.leave_crossing();

        simulator.check();

        count++;
        if (count > 1000) {
            exit(0);
        }
        if (count >= 500) {
            simulator.write_date(count);
        }
    }

    return 0;
}