#pragma once

namespace traffic {

enum class Direction { kUp, kDown, kLeft, kRight };

inline bool same_directin(Direction a, Direction b) { return a == b; }
inline bool opposite_direction(Direction a, Direction b) {
    return (a == Direction::kUp && b == Direction::kDown) ||
           (a == Direction::kDown && b == Direction::kUp) ||
           (a == Direction::kLeft && b == Direction::kRight) ||
           (a == Direction::kRight && b == Direction::kLeft);
}

enum class Road { kLeft, kMiddle, kRight };

} // namespace traffic