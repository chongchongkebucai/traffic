#include "Map.h"

namespace traffic {

Map::Map() : _config(nullptr), _graph(nullptr) {}

Map::Map(Config *config) {
    this->_config = config;
    init_map();
}

Map::~Map() {
    if (this->_graph) {
        delete this->_graph;
        this->_graph = nullptr;
    }
    if (this->_super_way) {
        delete this->_super_way;
        this->_super_way = nullptr;
    }
    if (this->_sidewalk) {
        delete this->_sidewalk;
        this->_sidewalk = nullptr;
    }
}

void Map::init_map() {
    int super_way_width = _config->get_super_way_width();
    int super_way_height = _config->get_super_way_height();
    int sidewalk_width = _config->get_sidewalk_width();
    int sidewalk_height = _config->get_sidewalk_height();
    if (super_way_width < sidewalk_width) {
        std::cout << "非机动车道也太短了吧! 请自觉加长。" << std::endl;
        assert(0);
    }
    if (sidewalk_height < super_way_height) {
        std::cout << "人行道也太短了吧！请自觉加长。" << std::endl;
    }

    int row_num = std::max(super_way_height, sidewalk_height);
    int col_num = std::max(super_way_width, sidewalk_width);
    _graph = new Graph(row_num, col_num);

    int min_coord_x = 0;
    int min_coord_y = (sidewalk_height - super_way_height) / 2;
    _super_way =
        new Rect(Location(min_coord_x, min_coord_y),
                 Location(min_coord_x + super_way_width - 1, min_coord_y + super_way_height - 1));

    min_coord_x = (super_way_width - sidewalk_width) / 2;
    min_coord_y = 0;
    _sidewalk =
        new Rect(Location(min_coord_x, min_coord_y),
                 Location(min_coord_x + sidewalk_width - 1, min_coord_y + sidewalk_height - 1));

    for (int i = 0; i < row_num; ++i) {
        for (int j = 0; j < col_num; ++j) {
            Location loc(j, i);
            if (!_sidewalk->contains(loc) && !_super_way->contains(loc)) {
                _graph->set_value(i, j, -1);
            }
        }
    }
}

void Map::add_transport(Transport *transport) {
    int   id = transport->get_id();
    auto &loc = transport->get_cur_loc();
    int   row = loc.get_y();
    int   col = loc.get_x();
    int   width = transport->get_width();
    int   height = transport->get_height();

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            int cur_row = row + i;
            int cur_col = col + j;
            if (_graph->within_boundary(cur_row, cur_col)) {
                _graph->set_value(cur_row, cur_col, id);
            }
        }
    }
}

void Map::clear_transport(Transport *transport) {
    auto loc = transport->get_cur_loc();
    int  row = loc.get_y();
    int  col = loc.get_x();
    int  width = transport->get_width();
    int  height = transport->get_height();

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            int cur_row = row + i;
            int cur_col = col + j;
            if (_graph->within_boundary(cur_row, cur_col)) {
                _graph->set_value(cur_row, cur_col, 0);
            }
        }
    }
}

vector<int> Map::get_id(const Rect &rect) const {
    auto loc = rect.get_min_location();
    int  row = loc.get_y();
    int  col = loc.get_x();
    auto width = rect.get_width();
    auto height = rect.get_height();

    set<int> ids;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            int cur_row = row + i;
            int cur_col = col + j;

            if (within_boundary(Location(cur_col, cur_row))) {
                int id = _graph->get_value(cur_row, cur_col);
                if (id > 0) {
                    ids.insert(id);
                }
            }
        }
    }

    return vector(ids.begin(), ids.end());
}

bool Map::have_transport(const Rect &rect) const {
    auto loc = rect.get_min_location();
    auto width = rect.get_width();
    auto height = rect.get_height();

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            auto     x = loc.get_x() + i;
            auto     y = loc.get_y() + j;
            Location temp_loc(x, y);
            if (within_boundary(temp_loc) && have_transport(temp_loc)) {
                return true;
            }
        }
    }
    return false;
}

} // namespace traffic