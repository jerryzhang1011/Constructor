#ifndef VECTOR
#define VECTOR
#include <vector>
#include "abstractPlayer.h"
#include "abstractDisplay.h"
using namespace std;
class Subject {
    protected: 
        std::vector<AbstractPlayer*> p;
        int input;//All specific number input will be done through this parameter. 
        int getDigit(int num);
    public:     
        AbstractDisplay* d;
        void notifyPlayer(int target, int eventPara1, int eventPara2);
        void setInput(int in);
        void appendInput(int in);
        int getInput();
        void notifyDisplay(std::string cmd);
        void attachPlayer(AbstractPlayer *player);
        void start(size_t curr);
        //void attachDisplay(Display*) = 0;
        ~Subject();
};

#endif
