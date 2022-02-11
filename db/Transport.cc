#include "Transport.h"

namespace traffic {

Transport::Transport() {
    _id = -1;
    _width = 0;
    _height = 0;
    _dir = Direction::kRight;
    _max_speed = 0;
    _acc_speed = 0;
}

void Transport::update_next_loc() { std::cout << "你还没有实现这个方法哦！" << std::endl; }

} // namespace traffic