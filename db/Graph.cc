#include "Graph.h"

namespace traffic {

Graph::Graph() : _rows(0), _cols(0) {}

Graph::Graph(int row_num, int col_num) : _grids(row_num, vector<int>(col_num, 0)) {
    _rows = row_num;
    _cols = col_num;
}

int Graph::get_value(int row, int col) const {
    if (!within_boundary(row, col)) {
        std::cout << "超出地图的边界了！错误稍微有点严重哦" << std::endl;
        assert(0);
    }
    return _grids[row][col];
}

void Graph::set_value(int row, int col, int value) {
    if (!within_boundary(row, col)) {
        std::cout << "超出地图的边界了！很严重的错误哦" << std::endl;
        assert(0);
    }
    _grids[row][col] = value;
}

} // namespace traffic