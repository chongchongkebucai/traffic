#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace traffic {
using std::string;
using std::vector;

class Config {
public:
    Config() = default;
    explicit Config(const string &config_file) { std::cout << "Too lazy to achieve!" << std::endl; }
    Config(const Config &config) = default;
    ~Config() = default;

    string       get_file_name() const { return _file_name; }
    int          get_row_num() const { return _row_num; }
    int          get_col_num() const { return _col_num; }
    int          get_grid_width() const { return _grid_width; }
    int          get_grid_height() const { return _grid_height; }
    int          get_super_way_width() const { return _super_way_width; }
    int          get_super_way_height() const { return _super_way_height; }
    int          get_sidewalk_width() const { return _sidewalk_width; }
    int          get_sidewalk_height() const { return _sidewalk_height; }
    int          get_person_width() const { return _person_width; }
    int          get_person_height() const { return _person_height; }
    int          get_bicycle_width() const { return _bicycle_width; }
    int          get_bicycle_height() const { return _bicycle_height; }
    int          get_electrocar_width() const { return _electrocar_width; }
    int          get_electrocar_height() const { return _electrocar_height; }
    int          get_tricycle_width() const { return _tricycle_width; }
    int          get_tricycle_height() const { return _tricycle_height; }
    double       get_downward_person_arrival_rate() const { return _downward_person_arrival_rate; }
    double       get_upward_person_arrival_rate() const { return _upward_person_arrival_rate; }
    double       get_car_arrival_rate() const { return _car_arrival_rate; }
    double       get_moderating_rate() const { return _moderating_rate; }
    double       get_once_crossing_rate() const { return _once_crossing_rate; }
    int          get_upper_bound_time() const { return _upper_bound_time; }
    int          get_lower_bound_time() const { return _lower_bound_time; }
    int          get_upper_bound_dist() const { return _upper_bound_dist; }
    int          get_lower_bound_dist() const { return _lower_bound_dist; }
    double       get_downward_person_pass_rate() const { return _downward_person_pass_rate; }
    double       get_upward_person_pass_rate() const { return _upward_person_pass_rate; }
    int          get_person_normal_speed() const { return _person_normal_speed; }
    int          get_person_max_speed() const { return _person_max_speed; }
    int          get_electrocar_max_speed() const { return _electrocar_max_speed; }
    int          get_bicycle_max_speed() const { return _bicycle_max_speed; }
    int          get_tricycle_max_speed() const { return _tricycle_max_speed; }
    int          get_accelerated_speed() const { return _accelerated_speed; }
    int          get_safe_dist() const { return _safe_dist; }
    int          get_lane_width() const { return _lane_width; }
    vector<int> &get_car_ratio() { return _car_ratio; }

    void set_file_name(const string &name) { _file_name = name; }
    void set_row_num(int row_num) { _row_num = row_num; }
    void set_col_num(int col_num) { _col_num = col_num; }
    void set_grid_width(int grid_width) { _grid_width = grid_width; }
    void set_grid_height(int grid_height) { _grid_height = grid_height; }
    void set_super_way_width(int super_way_width) { _super_way_width = super_way_width; }
    void set_super_way_height(int super_way_height) { _super_way_height = super_way_height; }
    void set_sidewalk_width(int sidewalk_width) { _sidewalk_width = sidewalk_width; }
    void set_sidewalk_height(int sidewalk_height) { _sidewalk_height = sidewalk_height; }
    void set_person_width(int width) { _person_width = width; }
    void set_person_height(int height) { _person_height = height; }
    void set_bicycle_width(int bicycle_width) { _bicycle_width = bicycle_width; }
    void set_bicycle_height(int bicycle_height) { _bicycle_height = bicycle_height; }
    void set_electrocar_width(int electrocar_width) { _electrocar_width = electrocar_width; }
    void set_electrocar_height(int electrocar_height) { _electrocar_height = electrocar_height; }
    void set_tricycle_width(int tricycle_width) { _tricycle_width = tricycle_width; }
    void set_tricycle_height(int tricycle_height) { _tricycle_height = tricycle_height; }
    void set_once_crossing_rate(double rate) { _once_crossing_rate = rate; }
    void set_downward_person_arrival_rate(double arrival_rate) {
        _downward_person_arrival_rate = arrival_rate;
    }
    void set_upward_person_arrival_rate(double arrival_rate) {
        _upward_person_arrival_rate = arrival_rate;
    }
    void set_upper_bound_time(int time) { _upper_bound_time = time; }
    void set_lower_bound_time(int time) { _lower_bound_time = time; }
    void set_upper_bound_dist(int dist) { _upper_bound_dist = dist; }
    void set_lower_bound_dist(int dist) { _lower_bound_dist = dist; }
    void set_car_arrival_rate(double car_arrival_rate) { _car_arrival_rate = car_arrival_rate; }
    void set_moderating_rate(double moderating_rate) { _moderating_rate = moderating_rate; }
    void set_car_ratio(vector<int> car_ratio) { _car_ratio = car_ratio; }
    void set_person_normal_speed(int speed) { _person_normal_speed = speed; }
    void set_person_max_speed(int max_speed) { _person_max_speed = max_speed; }
    void set_electrocar_max_speed(int max_speed) { _electrocar_max_speed = max_speed; }
    void set_bicycle_max_speed(int max_speed) { _bicycle_max_speed = max_speed; }
    void set_tricycle_max_speed(int max_speed) { _tricycle_max_speed = max_speed; }
    void set_accelerated_speed(int accelerated_speed) { _accelerated_speed = accelerated_speed; }
    void set_safe_dist(int dist) { _safe_dist = dist; }

private:
    string _file_name = "/home/congxiang/work/TrafficSimulator/data/traffic_data.txt";

    int _row_num = 8;
    int _col_num = 200;
    int _grid_width = 0.5;
    int _grid_height = 0.5;
    int _super_way_width = 100;
    int _super_way_height = 8;
    int _sidewalk_width = 50;
    int _sidewalk_height = 16;

    int _person_width = 1;
    int _person_height = 1;
    int _bicycle_width = 4;
    int _bicycle_height = 2;
    int _electrocar_width = 4;
    int _electrocar_height = 2;
    int _tricycle_width = 5;
    int _tricycle_height = 2;

    double      _downward_person_arrival_rate = 0.5;
    double      _upward_person_arrival_rate = 0.5;
    double      _car_arrival_rate = 0.5;
    double      _moderating_rate = 0.3;
    vector<int> _car_ratio = {14, 5, 1};

    double _once_crossing_rate = 0.4;
    int    _upper_bound_time = 5;
    int    _lower_bound_time = 4;
    int    _upper_bound_dist = 15;
    int    _lower_bound_dist = 13;
    double _downward_person_pass_rate = 0.2;
    double _upward_person_pass_rate = 0.1;

    int _person_normal_speed = 3;
    int _person_max_speed = 4;
    int _electrocar_max_speed = 16;
    int _bicycle_max_speed = 12;
    int _tricycle_max_speed = 14;
    int _accelerated_speed = 1;

    int _safe_dist = 80;
    int _lane_width = 2;
};
} // namespace traffic