#include <gtest/gtest.h>

#include <iostream>
#include <vector>

#include "Random.h"

using namespace traffic;
using std::cout;
using std::endl;
using std::vector;

TEST(gtest, discrete_random) {
    vector<int> rate = {14, 5, 1};
    vector<int> count_discrete = {0, 0, 0};
    vector<int> count_bernolli = {0, 0};

    Random rand;

    for (int i = 0; i < 2000; i++) {
        int index = rand.discrete_distribution(rate);
        count_discrete[index]++;
        index = rand.bernoulli_distribution();
        count_bernolli[index]++;
    }

    int count_size = count_discrete.size();
    for (int i = 0; i < count_size; i++) {
        cout << count_discrete[i] << endl;
    }
    cout << endl;
    count_size = count_bernolli.size();
    for (int i = 0; i < count_size; i++) {
        cout << count_bernolli[i] << endl;
    }
    count_size = 10;
    for (int i = 0; i < count_size; i++) {
        cout << rand.uniform_distribution(0, 8 - 1) << endl;
    }
}