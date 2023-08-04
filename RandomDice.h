#ifndef RANDOMDICE
#define RANDOMDICE

#include "dice.h"
#include <random>
#include <chrono>

class RandomDice: public Dice {
    int index;
    public:
        int generate() override;
        RandomDice(int index);
        ~RandomDice();
};

#endif
