#pragma once

#include <cassert>
#include <iostream>
#include <vector>

#include "Location.h"

namespace traffic {
using std::vector;

class Graph {
public:
    Graph();
    Graph(int row_num, int col_num);
    Graph(const Graph &graph) = default;
    ~Graph() = default;

    // getter
    int get_row_num() const { return _rows; }
    int get_col_num() const { return _cols; }
    int get_value(int row, int col) const;

    // setter
    void set_row_num(int row_num) { _rows = row_num; }
    void set_col_num(int col_num) { _cols = col_num; }
    void set_value(int row, int col, int value);

    // operator
    bool is_empty(int row, int col) const;
    bool have_transport(int row, int col) const;
    bool within_boundary(int row, int col) const;

private:
    vector<vector<int>> _grids; // barrier: -1, empty: 0, id: >1.
    int                 _rows;
    int                 _cols;
};

inline bool Graph::have_transport(int row, int col) const { return _grids[row][col] > 0; }

inline bool Graph::is_empty(int row, int col) const { return _grids[row][col] == 0; }

inline bool Graph::within_boundary(int row, int col) const {
    return (0 <= row && row < _rows) && (0 <= col && col < _cols);
}

} // namespace traffic