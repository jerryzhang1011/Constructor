#include "RandomDice.h"

RandomDice::RandomDice(int index):index{index}{ }

int RandomDice::generate() {
    std::mt19937 rng;
    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
    rng.seed(seed);
    int min_value = 1;
    int max_value = 6;
    std::uniform_int_distribution<int> distribution(min_value, max_value);
    return distribution(rng) + distribution(rng);
}

RandomDice::~RandomDice(){ }

