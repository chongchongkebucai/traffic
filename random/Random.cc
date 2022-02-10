#include "Random.h"

namespace traffic {
Random::Random() : _random_engine(_produce_seed()) {}

int Random::discrete_distribution(const vector<int> &weights) {
    set_discrete_distr_param(weights);
    return discrete_distribution();
}
void Random::set_discrete_distr_param(const vector<int> &weights) {
    discrete_param_type param(weights.begin(), weights.end());
    _discrete_distr.param(param);
}
int Random::discrete_distribution() { return _discrete_distr(_random_engine); }

bool Random::bernoulli_distribution(double p) {
    set_bernoulli_distr_param(p);
    return bernoulli_distribution();
}
void Random::set_bernoulli_distr_param(double p) {
    _bernoulli_distr.param(bernoulli_param_type(p));
}
bool Random::bernoulli_distribution() { return _bernoulli_distr(_random_engine); }

int Random::uniform_distribution(int a, int b) {
    set_uniform_distr_param(a, b);
    return uniform_distribution();
}
void Random::set_uniform_distr_param(int a, int b) {
    _uniform_distr.param(uniform_param_type(a, b));
}
int Random::uniform_distribution() { return _uniform_distr(_random_engine); }
} // namespace traffic