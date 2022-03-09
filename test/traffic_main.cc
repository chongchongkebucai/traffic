#include "Simulator.h"
#include <unistd.h>

#define START 200
#define END 700

using namespace traffic;

int main() {
    Simulator simulator;

    int start_car_conflict_num = 0;
    int start_person_coflict_num = 0;

    int count = 0;
    while (1) {
        simulator.move();
        simulator.update_time();
        simulator.entry_crossing();
        simulator.display();
        simulator.leave_crossing();

        simulator.check();

        count++;
        if (count > END) {
            std::cout << "The car conflict number are "
                      << simulator.get_car_conflict_num() - start_car_conflict_num << std::endl;
            std::cout << "The person conflict number are "
                      << simulator.get_person_conflict_num() - start_person_coflict_num
                      << std::endl;
            exit(0);
        }
        if (count >= START) {
            simulator.write_date(count);
        }
        if (count == START) {
            start_car_conflict_num = simulator.get_car_conflict_num();
            start_person_coflict_num = simulator.get_person_conflict_num();
        }
    }

    return 0;
}