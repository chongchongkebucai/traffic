#pragma once

#include <algorithm>
#include <cassert>
#include <set>

#include "Config.h"
#include "Graph.h"
#include "Location.h"
#include "Rect.h"
#include "Transport.h"

namespace traffic {
using std::set;

class Map {
public:
    Map();
    explicit Map(Config *config);
    Map(const Map &map) = default;
    ~Map();

    // getter
    int      get_sidewalk_width() const { return _sidewalk->get_width(); }
    int      get_sidewalk_height() const { return _sidewalk->get_height(); }
    int      get_super_way_width() const { return _super_way->get_width(); }
    int      get_super_way_height() const { return _super_way->get_height(); }
    Location get_sidewalk_min_location() { return _sidewalk->get_min_location(); }
    Location get_sidewalk_max_location() { return _sidewalk->get_max_location(); }
    Location get_super_way_min_location() { return _super_way->get_min_location(); }
    Location get_super_way_max_location() { return _super_way->get_max_location(); }
    Rect     get_sidewalk() { return (*_sidewalk); }
    Rect     get_super_way() { return (*_super_way); }
    Graph *  get_graph() const { return _graph; }

    // setter
    void set_sidewalk_min_location(const Location &loc) { _sidewalk->set_min_location(loc); }
    void set_sidewalk_max_location(const Location &loc) { _sidewalk->set_max_location(loc); }
    void set_super_way_min_location(const Location &loc) { _super_way->set_min_location(loc); }
    void set_super_way_max_location(const Location &loc) { _super_way->set_min_location(loc); }

    // operator
    void        add_transport(Transport *transport);
    void        clear_transport(Transport *transport);
    vector<int> get_id(const Rect &rect) const;
    int         get_id(const Location &loc) const;
    bool        have_transport(const Rect &rect) const;
    bool        have_transport(const Location &loc) const;
    bool        within_boundary(const Location &loc) const;

private:
    void init_map();
    bool within_boundary(int row, int col) const;

private:
    Config *_config;
    Graph * _graph;
    Rect *  _sidewalk;
    Rect *  _super_way;
};

inline bool Map::within_boundary(const Location &loc) const {
    return _graph->within_boundary(loc.get_y(), loc.get_x());
}
inline bool Map::within_boundary(int row, int col) const {
    return _graph->within_boundary(row, col);
}

inline bool Map::have_transport(const Location &loc) const {
    return _graph->have_transport(loc.get_y(), loc.get_x());
}
inline int Map::get_id(const Location &loc) const {
    return _graph->get_value(loc.get_y(), loc.get_x());
}

} // namespace traffic