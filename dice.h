#ifndef DICE
#define DICE
class Dice{
    public:
        virtual int generate()=0;
        //Dice(GameBoard* gb,int index):gb{gb},index{index}{}
        virtual ~Dice() = default;
};
#endif
