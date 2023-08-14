#ifndef LOADEDDICE
#define LOADEDDICE
#include "dice.h"
#include "subject.h"

class LoadedDice:public Dice{
    int index;
    Subject *s;
    public:
        int generate() override;
        LoadedDice(Subject* s,int index);
        ~LoadedDice();
};

#endif
