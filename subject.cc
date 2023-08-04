#include "subject.h"
using namespace std;
void Subject::notifyPlayer(int target, int eventPara1,int eventPara2){
    for(size_t i = 0; i<p.size(); i++){
        (p.at(i))->notify(target, eventPara1, eventPara2);
    }
}
void Subject::setInput(int input){this->input = input;}
int Subject::getInput(){return input;}
void Subject::start(size_t curr){
    while(true){
        for(size_t i = curr; i<p.size();i++){
            try{notifyPlayer(i,0,0);}
            catch(int){return;}
        }
    }
}
void Subject::attachPlayer(AbstractPlayer* player){
    p.emplace_back(player);
}

void Subject::notifyDisplay(std::string regular_cmd) {
    return;
}

Subject::~Subject(){
    for(int i = 0; i<p.size(); i++){
        delete(p.at(i));
    }
    delete d;
}
int Subject::getDigit(int num){
    int d = 0;
    while(num/10 != 0){
        num = num/10;
        d++;
    }
    return d;
}
void Subject::appendInput(int num){
    int i = getDigit(input);
    for(int k = 0; k<i;k++){
        this->input*=10;
    }
    this->input += input;
}
