#ifndef ABSTRACTPLAYER
#define ABSTRACTPLAYER
#include <vector>
class AbstractPlayer{
    public:
        virtual int notify (int target, int eventPara1, int eventPara2)=0;//see eventNumber.txt for representations
        virtual void player_print()=0;
        virtual int* getResources()=0;
        virtual int getIndex() = 0;
        virtual int getNumPoints() = 0;
        virtual std::vector <int> getRoad() = 0;
        virtual std::vector <int> getBasement() = 0;
        virtual std::vector <int> getHouse() = 0;
        virtual std::vector <int> getTower() = 0;
        
};
#endif
