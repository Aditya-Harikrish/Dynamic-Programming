#ifndef RANDOM_H
#define RANDOM_H

#include <random>

std::random_device rd;

namespace Random {
int Int(int min, int max) {
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(min, max);
    return uni(rng);
}
}  // namespace Random

#endif