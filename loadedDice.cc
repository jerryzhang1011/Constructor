#include "loadedDice.h"
LoadedDice::LoadedDice(Subject* s,int index):s{s},index{index}{ }
int LoadedDice::generate(){
    s->notifyPlayer(index,-1,-1);
    return s->getInput();
}
LoadedDice::~LoadedDice() { }
