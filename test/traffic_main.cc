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
    }

    return 0;
}