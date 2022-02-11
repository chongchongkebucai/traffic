#include "Simulator.h"
#include <unistd.h>

using namespace traffic;

int main() {
    Simulator simulator;

    int count = 0;
    while (1) {
        simulator.move();
        simulator.entry_crossing();
        simulator.display();
        simulator.leave_crossing();

        count++;
        if (count > 10000) {
            exit(0);
        }
        if (500 <= count && count <= 1000) {
            simulator.write_date(count);
        }
    }

    return 0;
}