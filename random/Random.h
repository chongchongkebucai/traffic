#pragma once

#include <random>
#include <vector>

namespace traffic {
using std::vector;

class Random {
public:
    typedef std::discrete_distribution<int>::param_type    discrete_param_type;
    typedef std::uniform_int_distribution<int>::param_type uniform_param_type;
    typedef std::bernoulli_distribution::param_type        bernoulli_param_type;

    Random();
    Random(const Random &) = default;
    ~Random() = default;

    int  discrete_distribution(const vector<int> &weights);
    void set_discrete_distr_param(const vector<int> &weights);
    int  discrete_distribution();

    bool bernoulli_distribution(double p);
    void set_bernoulli_distr_param(double p);
    bool bernoulli_distribution();

    int  uniform_distribution(int a, int b);
    void set_uniform_distr_param(int a, int b);
    int  uniform_distribution();

private:
    std::random_device                 _produce_seed;
    std::default_random_engine         _random_engine;
    std::bernoulli_distribution        _bernoulli_distr;
    std::discrete_distribution<int>    _discrete_distr;
    std::uniform_int_distribution<int> _uniform_distr;
};

} // namespace traffic