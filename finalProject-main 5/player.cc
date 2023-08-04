#include "player.h"
#include "display.h"
using namespace std;
//replace all iostream with functions in display and notify display

int rng(int start, int end){
    std::mt19937 rng;
    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
    rng.seed(seed);
    std::uniform_int_distribution<int> distribution(start, end);
    return distribution(rng);
}

bool Player::addScore(){
    score++;
    if(score == 10){
        return true;
    }
    else{
        return false;
    }
}

void Player::turn(){
    //Set dice


    //cout<<"Builder "<<index<<"'s turn"<<endl;
    gb->d->turn(index);

    diceRoll();
    action();
}
// handles diceRolling
void Player::diceRoll(){
    while(true){
        string command = gb->d->input();
        if(cin.eof()) gb->end_of_input(index);
        if(command == "load"){
            gb->processCommand(index,0,0);
        }
        else if(command == "fair"){
            gb->processCommand(index,0,1);
        }
        else if(command == "roll"){
            gb->processCommand(index,0,2);
            break;
        }
    }
}

int Player::action(){
    while(true){
        string command = gb->d->input();
        //Display can handle info output commands on its own or by directly consult player
        //this function will not cover those commands
        if(cin.eof()) gb->end_of_input(index);
        if(score == 10){
            gb->d->end(index);
            throw(index);
        }
        if(command == "road"){
            int position;
            cin>>position;
            if(cin.eof()) gb->end_of_input(index);
            roadConstruct(position);
        }
        else if(command == "trade"){
            int target;
            int resourceTypeGiven;
            int resourceTypeDemanded;
            cin>>target>>resourceTypeGiven>>resourceTypeDemanded;
            if(cin.eof()) gb->end_of_input(index);
            resourceTypeDemanded++;
            resourceTypeGiven++;
            tradeRequest(target,resourceTypeGiven,resourceTypeDemanded);
        }
        else if(command == "build-res"){
            int target;
            cin>>target;
            if(cin.eof()) gb->end_of_input(index);
            houseConstruct(target);
        }
        else if (command == "build-road") {
            int target;
            cin>>target;
            if(cin.eof()) gb->end_of_input(index);
            roadConstruct(target);
        }
        else if(command == "improve"){
            int target;
            cin>>target;
            if(cin.eof()) gb->end_of_input(index);
            improve(target);
        }
        else if(command == "next"){
            break;        
        }
        else if(command == "resources"){
            cout<<resource[0]<<" "<<resource[1]<<" "<<resource[2]<<" "<<resource[3]<<" "<<resource[4]<<" "<<endl;
        }
        else if(command == "board") {
            gb->display_board();
        }
        else if(command == "status") {
            gb->print_all_player();
        }
        else if(command == "residences") {
            gb->d->residence(index, basement, house, tower);
        }
        else if (command == "help") {
            gb->d->help();
        }
        else if (command == "save") {
            std::string file_name;
            cin >> file_name;
            std::ofstream  oss {file_name};
            gb->save_game(oss, index);
            throw -1;
        }
        else if (command == "next") {
            break;
        }
        else {
            continue;
        }
    }
    return 0;
}

//strong guarantee
void Player::roadConstruct(int position){
    for(int i = 0; i<RESOURCETYPE;i++){
        if(resource[i]<CONSTANTS::ROADCOST[i]){
            gb->d->insufficient();
            return;
        }
    }
    try{
        gb->processCommand(index,CONSTANTS::ROADCOMMAND,position);
        for(int i = 0; i<RESOURCETYPE;i++){
            resource[i]-=CONSTANTS::ROADCOST[i];
        }
    }catch(const char*s){
        cout<<s<<endl;
    }
}

//string guarantee
void Player::houseConstruct(int position){
    for(int i = 0; i<RESOURCETYPE;i++){
        if(resource[i]<CONSTANTS::BASEMENTCOST[i]){
            gb->d->insufficient();
            return;
        }
    }
    try{
        gb->processCommand(index,CONSTANTS::BASEMENTCOMMAND,position);
        for(int i = 0; i<RESOURCETYPE;i++){
            resource[i]-=CONSTANTS::BASEMENTCOST[i];
        }
        basement.emplace_back(position);
        addScore();
    }catch(const char*s){
        cout<<s<<endl;
    }
}

void Player::tradeRequest(int target, int resourceTypeGiven, int resourceTypeDemanded, int amountGiven, int amountDemanded){
    if(resource[resourceTypeGiven-1]<amountGiven){

        // cout<<"not possible, not enough resource"<<endl;
        gb->d->insufficient();
        return;
    }
    gb->setInput(resourceTypeDemanded);
    try{
        gb->processCommand(index,CONSTANTS::TRADECOMMAND*(target+1),resourceTypeGiven);
        resource[resourceTypeGiven-1]-=amountGiven;
        resource[resourceTypeDemanded-1]+=amountDemanded;
    }catch(const char*s){
        cout<<s<<endl;
    }
}

void Player::tradeResponse(int target, int resourceTypeGiven, int resourceTypeDemanded, int amountGiven, int amountDemanded) {
    gb->d->trade(target,CONSTANTS::get_Player_string(index),CONSTANTS::get_resource_name(resourceTypeDemanded),CONSTANTS::get_resource_name(resourceTypeGiven));
    while(true){
        int response = gb->d->readInt();
        std::cout<<response<<std::endl;
        if( response==1){
            std::cout<<"recieved"<<std::endl;
            resource[resourceTypeGiven] -= 1;
            resource[resourceTypeDemanded] += 1;
            break;
        }
        else if(response == 2){
            throw "denied";
        }
    }

}

void Player::improve(int position){
    for(size_t i = 0; i<basement.size(); i++){
        if(basement.at(i) == position){
            for(int k = 0; k<RESOURCETYPE;k++){
                if(resource[k]<CONSTANTS::HOUSECOST[k]){
                    gb->d->insufficient();
                    return;
                }
            }
            gb->processCommand(index,CONSTANTS::IMPROVECOMMAND,position);
            for(int k = 0; k<RESOURCETYPE;k++){
                resource[k]-=CONSTANTS::HOUSECOST[k];
            }
            addScore();
            basement.erase(basement.begin()+i);
            house.emplace_back(position);
            return;   
        }
    }
    for(size_t i = 0; i<house.size(); i++){
        if(house.at(i) == position){
            for(int k = 0; k<RESOURCETYPE;k++){
                if(resource[k]<CONSTANTS::TOWERCOST[k]){
                    gb->d->insufficient();
                    return;
                }
            }
            gb->processCommand(index,CONSTANTS::IMPROVECOMMAND,position);
            for(int k = 0; k<RESOURCETYPE;k++){
                resource[k]-=CONSTANTS::TOWERCOST[k];
            }
            addScore();
            house.erase(house.begin()+i);
            tower.emplace_back(position);
            return;   
        }
    }
    gb->d->buildFail();
}

//returns array of length 5
int* Player::robberRandomLoss(int* a){
    int total = resource[0]+resource[1]+resource[2]+resource[3]+resource[4];
    if(total>=gb->GEESELIMIT){
        int lost = total/2;
        for(int i = lost; i>0; i--){
            int k = randomLoss();
            a[k]++;
        }
    }
    return a;

}

int Player::randomLoss(){
    int total = resource[0]+resource[1]+resource[2]+resource[3]+resource[4];
    if(total <1){
        return -1;
    }
    int r = rng(1,total);
    if(r<=resource[0]){
        resource[0]-=1;
        return 0;
    }
    else if(r<=resource[0]+resource[1]){
        resource[1]-=1;
        return 1;
    }
    else if(r<=resource[0]+resource[1]+resource[2]){
        resource[2]-=1;
        return 2;
    }
    else if(r<=resource[0]+resource[1]+resource[2]+resource[3]){
        resource[3]-=1;
        return 3;
    }
    else{
        resource[4] -= 1;
        return 4;
    }
}

int Player::notify(int target, int eventPara1, int eventPara2){
    if(target == index || target == -1){
        if(eventPara1 == -1){
            if(eventPara2 == -1){
                int input = gb->d->readInt();
                if(cin.eof()) gb->end_of_input(index);
                gb->setInput(input);
            }
            else{
                gb->setInput(eventPara2);
            }
        }
        else if(eventPara1 == 0){//turn start
            turn();
        }
        else if(eventPara1-100 >= 0 && eventPara1-100<=RESOURCETYPE){//gain resource from dice
            resource[eventPara1-100] += eventPara2;
        }
        else if(eventPara1 == 1 && eventPara2 == 0){//loss resource to geese
            int a[5] = {0,0,0,0,0}; 
            robberRandomLoss(a);
            gb->d->geeseLose(index,a);
            gb->d->status(index,score,resource);
        }
        else if(eventPara1 == 1){//geese stealing
            if(eventPara2 == 1){
                gb->setInput(resource[0]+resource[1]+resource[2]+resource[3]+resource[4]);
            }
            else if(eventPara2 == 2){//lose resource
                gb->setInput(randomLoss());
            }
        }
        else if(eventPara1 == 6){
            basement.push_back(eventPara2);
            score++;
        }
        else if (eventPara1 == 7) {
            house.push_back(eventPara2);
            score += 2;
        }
        else if (eventPara1 == 8) {
            tower.push_back(eventPara2);
            score += 3;
        }
        else if (eventPara1 == 9) {
            roads.push_back(eventPara2);
        }
        else if(eventPara1 <= CONSTANTS::TRADECOMMAND){
            int proposer = (eventPara1/CONSTANTS::TRADECOMMAND)-1;
            std::cout<<eventPara2<<std::endl;
            int resourceOffered,resourceDemanded;
            resourceOffered = (eventPara2/10)-1;
            resourceDemanded = eventPara2%10 -1;
            tradeResponse(proposer,resourceDemanded,resourceOffered,1,1);
        }
    }
    return 0;
}

Player::Player(int index,GameBoard *gb): gb {gb}, display{new Display()}, index {index}{
    for (int i = 0; i < RESOURCETYPE; ++i) {
        resource[i] = 5;
    }
    score = 0;
}

void Player::player_print() {
    // order: BRICK, ENERGY, GLASS, HEAT, then WIFI.
    // <colour> has <numPoints> building points, <numBrick> brick, <numEnergy> energy,
    // <numGlass> glass, <numHeat> heat, and <numWiFi> WiFi.
    gb->d->status(index, score, resource);
//     int i = 0;
//     std::cout << gb->convert_short_to_full_name(gb->index_to_name(index)) << " has " << numPoints << " building points, " << resource[i++] << " brick, " <<  resource[i++] << " energy," << std::endl;
//     std::cout << resource[i++] << " glass, " << resource[i++] << " heat, and " << resource[i++] << " WiFi." << std::endl;
}

Player::~Player(){}

int* Player::getResources() { return resource; }

std::vector <int> Player::getRoad() { return roads; }

std::vector <int> Player::getBasement() { return basement; }

std::vector <int> Player::getHouse() { return house; }

std::vector <int> Player::getTower() { return tower; }
