
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "display.h"

void Display::trading(int curr, int other_player, int give, int get) {
    std::vector<std::string> colours = {"Blue", "Red", "Orange", "Yellow"};
    std::vector<std::string> resource = {"BRICK", "ENERGY", "GLASS", "HEAT", "WIFI"};
    std::cout << colours[curr] << " offers " << colours[other_player] << " one " << resource[give] << " for one " << resource[get] << "." << std::endl;
    std::cout << "Does " << colours[other_player] << " accept this offer?" << std::endl;
}

void Display::geeseLose(int colour, int *r) {
    std::vector<std::string> colours = {"Blue", "Red", "Orange", "Yellow"};
    std::vector<std::string> resource = {"BRICK", "ENERGY", "GLASS", "HEAT", "WIFI"};
    int total_los = 0;
    for (int i = 0; i < 5; ++i) {
        total_los += r[i];
    }
    std::string colour_name = colours[colour];
    std::cout << "Builder " << colour_name << " loses " << total_los << " resources to the geese. They lose:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        if (r[i] != 0) {
            std::cout << r[i] << " " << resource[i] << std::endl;
        }
    }
}


std::string Display::input() {
    std::cout << ">";
    std::string s;
    std::cin>>s;
    std::cout << std::endl;
    return s;
}

int Display::readInt(){

    while(true){
        std::cout << ">>";
        std::string s;
        cin>>s;
        istringstream iss{s};
        int i = 0;
        if(iss>>i){
            return i;
        }
        invalid();
    }

}

void Display::invalid() {
    std::cout << "Invalid command." << std::endl;
}

void Display::buildFail() {
    std::cout << "You cannot build here." << std::endl;
}

void Display::insufficient() {

    std::cout << "You do not have enough resources." << std::endl;
}

void Display::begin(int builder) {
    std::vector<std::string> colours = {"Blue", "Red", "Orange", "Yellow"};
    std::cout << "Builder " << colours[builder] << ", where do you want to build a basement?" << std::endl;
}


void Display::end(int builder) {
    std::vector<std::string> colours = {"Blue", "Red", "Orange", "Yellow"};
    std::cout << "Builder " << colours[builder] << " is the winner." << std::endl;
}

void Display::loadedDice() {
    std::cout << "Input a roll between 2 and 12:" << std::endl;
}

void Display::invalidRoll() {
    std::cout << "Invalid roll." << std::endl;
}

void Display::turn(int builder) {
    std::vector<std::string> colours = {"Blue", "Red", "Orange", "Yellow"};
    std::cout << "Builder " << colours[builder] << "'s turn." << std::endl;
}
void Display::gain(std::vector <AbstractPlayer*> p, std::vector <int> num, std::string type) {
    std::vector<std::string> colours = {"Blue", "Red", "Orange", "Yellow"};
    for (size_t i = 0; i < p.size(); ++i) {
        std::cout << "Builder " << colours[p[i]->getIndex()] << " gained:" << std::endl;
        std::cout << num[i] << " " << type << std::endl;
    }
}


void Display::noGain() { // 7

    std::cout << "No builders gained resources." << std::endl;
}

void Display::geeseSteal(std::vector <AbstractPlayer*> p, 
                         std::vector <std::vector<std::pair<int, std::string>> > resourcesLost) {
    std::vector<std::string> colours = {"Blue", "Red", "Orange", "Yellow"};
    for (size_t i = 0; i < p.size(); ++i) {
        int totalResourcesLost = 0;
        for (auto resource : resourcesLost[i]) {
            totalResourcesLost += resource.first;
        }
        std::cout << "Builder " << colours[p[i]->getIndex()] << " loses "; 
        std::cout << totalResourcesLost << " resources to the geese. They lose:" << std::endl;
        for (auto resource : resourcesLost[i]) {
            std::cout << resource.first << " " << resource.second << std::endl;
        }
    }
}

void Display::placeGeese() { // 8

    std::cout << "Choose where to place the GEESE." << std::endl;
}

void Display::chooseSteal (int builder, std::vector<std::string> builders) {
    std::vector<std::string> colours = {"Blue", "Red", "Orange", "Yellow"};
    std::cout << "Builder " << colours[builder] << " can choose to steal from ";
    for (size_t i = 0; i < builders.size(); ++i) {
        std::cout << builders[i];
        if (i != builders.size() - 1) {
            std::cout << ' ';
        } else {
            std::cout << '.' << std::endl;
        }
    }
    std::cout << "0: Blue, 1: Red, 2: Orange, 3: Yellow" << std::endl;
    std::cout << "Choose a builder to steal from." << std::endl;
}

void Display::steal(int builder, std::string stolen, std::string resource) {
    std::vector<std::string> colours = {"Blue", "Red", "Orange", "Yellow"};
    std::cout << "Builder " << colours[builder] << " steals " << resource;
    std::cout << " from builder " << stolen << "." << std::endl;
}

void Display::noSteal(int builder) {
    std::vector<std::string> colours = {"Blue", "Red", "Orange", "Yellow"};
    std::cout << "Builder " << colours[builder] << " has no builders to steal from." << std::endl;
}


void Display::status(int builder, int points, int* resources) {
    std::vector<std::string> colours = {"Blue", "Red", "Orange", "Yellow"};
    std::vector<std::string> resourceTypes = {"brick", "energy", "glass", "heat", "WIFI"};
    std::cout << colours[builder] << " has " << points << " building points, ";
    for (size_t i = 0; i < resourceTypes.size(); ++i) {
        std::cout << resources[i] << " " << resourceTypes[i];
        if (i != resourceTypes.size() - 1) {
            std::cout << ", ";
        } else {
            std::cout << "." << std::endl;
        }
    }
}


void Display::residence(int builder, std::vector <int> basement, std::vector <int> house, std::vector <int> tower) {

    std::vector <std::string> colours = {"Blue", "Red", "Orange", "Yellow"};
    std::cout << colours[builder] << " has built: " << std::endl;
    if (!basement.empty()) {
        for (auto Basement : basement) {
            std::cout << Basement << ' ';
        }
        std::cout << 'B' << std::endl;
    } 
    if (!house.empty()) {
        for (auto House : house) {
            std::cout << House << ' ';
        }
        std::cout << 'T' << std::endl;
    } 
    if (!tower.empty()) {
        for (auto Tower : tower) {
            std::cout << Tower << ' ';
        }
        std::cout << 'H' << std::endl;
    }  
}

void Display::trade(int builder, std::string colour, std::string give, std::string take) {
    std::vector <std::string> colours = {"Blue", "Red", "Orange", "Yellow"};
    std::string Builder = colours[builder];
    std::cout << Builder << " offers " << colour << " one ";
    std::cout << give << " for one " << take << "." << std::endl;
    std::cout << "Does " << colour << " accept this offer? (yes: 1, no: 2)" << std::endl;
}


void Display::save(int builder, std::vector <AbstractPlayer*> p, std::vector <Tile*> tiles, std::ofstream& oss) {

    std::vector<std::string> colours = {"Blue", "Red", "Orange", "Yellow"};
    std::string curTurn = colours[builder];
    int geese; // Must be a number from 0 - 18.

    // prints line 1: <curTurn>
    oss << curTurn << std::endl;

    // prints line 2 - 5: <builder0Data> <builder1Data> <builder2Data> <builder3Data>
    for (int i = 0; i < 4; ++i) {
        int* resources = p.at(i)->getResources();
        for (int j = 0; j < 5; ++j) {
            oss << resources[j] << ' ';
        }

        oss << 'r' << ' ';
        for (auto road : p.at(i)->getRoad()) {
            oss << road << ' ';
        }

        oss << 'h' << ' ';

        std::vector<std::pair<int, char>> residences;

        for (auto basement : p.at(i)->getBasement()) {
            residences.push_back({basement, 'B'});
        }
        for (auto house : p.at(i)->getHouse()) {
            residences.push_back({house, 'H'});
        }
        for (auto tower : p.at(i)->getTower()) {
            residences.push_back({tower, 'T'});
        }

        std::sort(residences.begin(), residences.end()); // Sort residences in ascending order

        for (auto residence : residences) {
            oss << residence.first << ' ' << residence.second << ' ';
        }

        oss << std::endl;
    }

    // prints line 6: <board>
    for (int i = 0; i < 19; ++i) {
        if (tiles.at(i)->getGoose()) geese = i;
        if (tiles.at(i)->getType() == "BRICK") {
            oss << "0 ";
        } else if (tiles.at(i)->getType() == "ENERGY") {
            oss << "1 ";
        } else if (tiles.at(i)->getType() == "GLASS") {
            oss << "2 ";
        } else if (tiles.at(i)->getType() == "HEAT") {
            oss << "3 ";
        } else if (tiles.at(i)->getType() == "WIFI") {
            oss << "4 ";
        } else {
            oss << "5 ";
        }
        oss << tiles.at(i)->getVal();
        oss << " ";
    }
    oss << std::endl;
    
    // prints line 7: <geese>
    oss << geese << std::endl;
}

void Display::help() {  // 9
    std::cout << "Valid commands:" << std::endl;
    std::cout << "board" << std::endl;
    std::cout << "status" << std::endl;
    std::cout << "residences" << std::endl;
    std::cout << "build-road <edge#>" << std::endl;
    std::cout << "build-res <housing#>" << std::endl;
    std::cout << "improve <housing#>" << std::endl;
    std::cout << "trade <colour> <give> <take>" << std::endl;
    std::cout << "next" << std::endl;
    std::cout << "isave <file>" << std::endl;
    std::cout << "help" << std::endl;
}

void Display::board(std::vector <Tile*> tiles, std::vector <Vertex*> vertices, std::vector <Edge*> edges) { 
    // print line 1.
    std::cout << std::string(20, ' ');
    std::cout << '|';
    if (vertices.at(0)->own()) {
        vertices.at(0)->printOwner();
        vertices.at(0)->printLevel();
    } else {
        vertices.at(0)->printNum();
    }
    std::cout << "|--";
    if (edges.at(0)->own()) {
        edges.at(0)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(0)->printNum();
    }
    std::cout << "--|";
    if (vertices.at(1)->own()) {
        vertices.at(1)->printOwner();
        vertices.at(1)->printLevel();
    } else {
        vertices.at(1)->printNum();
    }
    std::cout << '|' << std::endl;

    // prints line 2.
    std::cout << std::string(22, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|' << std::endl;

    // prints line 3.
    std::cout << std::string(21, ' ');
    if (edges.at(1)->own()) {
        edges.at(1)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(1)->printNum();
    }
    std::cout << std::string(3, ' ');
    tiles.at(0)->printNum();
    std::cout << std::string(3, ' ');
    if (edges.at(2)->own()) {
        edges.at(2)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(2)->printNum();
    }
    std::cout << std::endl;

    // prints line 4.
    std::cout << std::string(22, ' ');
    std::cout << '|';
    std::cout << std::string(2, ' ');
    tiles.at(0)->printType();
    std::cout << std::string(7 - tiles.at(0)->getLength(), ' ');
    std::cout << '|' << std::endl;

    // prints line 5.
    std::cout << std::string(10, ' ');  
    std::cout << '|';
    if (vertices.at(2)->own()) {
        vertices.at(2)->printOwner();
        vertices.at(2)->printLevel();
    } else {
        vertices.at(2)->printNum();
    }
    std::cout << "|--";
    if (edges.at(3)->own()) {
        edges.at(3)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(3)->printNum();
    }
    std::cout << "--|";
    if (vertices.at(3)->own()) {
        vertices.at(3)->printOwner();
        vertices.at(3)->printLevel();
    } else {
        vertices.at(3)->printNum();
    }
    std::cout << '|';
    if (tiles.at(0)->getType() != "PARK") {
        std::cout << std::string(2, ' ');
        if (tiles.at(0)->getVal() < 10) std::cout << ' ';
        tiles.at(0)->printVal();
        std::cout << std::string(2, ' ');
    } else {
        std::cout << std::string(6, ' ');
    }
    std::cout << '|';
    if (vertices.at(4)->own()) {
        vertices.at(4)->printOwner();
        vertices.at(4)->printLevel();
    } else {
        vertices.at(4)->printNum();
    }
    std::cout << "|--";
    if (edges.at(4)->own()) {
        edges.at(4)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(4)->printNum();
    }
    std::cout << "--|";
    if (vertices.at(5)->own()) {
        vertices.at(5)->printOwner();
        vertices.at(5)->printLevel();
    } else {
        vertices.at(5)->printNum();
    }
    std::cout << '|' << std::endl;

    // prints line 6.
    std::cout << std::string(12, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|' << std::endl;

    // prints line 7.
    std::cout << std::string(11, ' ');
    if (edges.at(5)->own()) {
        edges.at(5)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(5)->printNum();
    }
    std::cout << std::string(3, ' ');
    tiles.at(1)->printNum();
    std::cout << std::string(3, ' ');
    if (edges.at(6)->own()) {
        edges.at(6)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(6)->printNum();
    }
    std::cout << std::string(8, ' ');
    if (edges.at(7)->own()) {
        edges.at(7)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(7)->printNum();
    }
    std::cout << std::string(3, ' ');
    tiles.at(2)->printNum();
    std::cout << std::string(3, ' ');
    if (edges.at(8)->own()) {
        edges.at(8)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(8)->printNum();
    }
    std::cout << std::endl;

    // prints line 8.
    std::cout << std::string(12, ' ');
    std::cout << '|';
    std::cout << std::string(2, ' ');
    tiles.at(1)->printType();
    std::cout << std::string(7 - tiles.at(1)->getLength(), ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(2, ' ');
    tiles.at(2)->printType();
    std::cout << std::string(7 - tiles.at(2)->getLength(), ' ');
    std::cout << '|' << std::endl;

    // prints line 9.
    std::cout << '|';
    if (vertices.at(6)->own()) {
        vertices.at(6)->printOwner();
        vertices.at(6)->printLevel();
    } else {
        vertices.at(6)->printNum();
    }
    std::cout << "|--";
    if (edges.at(9)->own()) {
        edges.at(9)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(9)->printNum();
    }
    std::cout << "--|";
    if (vertices.at(7)->own()) {
        vertices.at(7)->printOwner();
        vertices.at(7)->printLevel();
    } else {
        vertices.at(7)->printNum();
    }
    std::cout << '|';
    if (tiles.at(1)->getType() != "PARK") {
        std::cout << std::string(2, ' ');
        if (tiles.at(1)->getVal() < 10) std::cout << ' ';
        tiles.at(1)->printVal();
        std::cout << std::string(2, ' ');
    } else {
        std::cout << std::string(6, ' ');
    }
    std::cout << '|';
    if (vertices.at(8)->own()) {
        vertices.at(8)->printOwner();
        vertices.at(8)->printLevel();
    } else {
        vertices.at(8)->printNum();
    }
    std::cout << "|--";
    if (edges.at(10)->own()) {
        edges.at(10)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(10)->printNum();
    }
    std::cout << "--|";
    if (vertices.at(9)->own()) {
        vertices.at(9)->printOwner();
        vertices.at(9)->printLevel();
    } else {
        vertices.at(9)->printNum();
    }
    std::cout << '|';
    if (tiles.at(2)->getType() != "PARK") {
        std::cout << std::string(2, ' ');
        if (tiles.at(2)->getVal() < 10) std::cout << ' ';
        tiles.at(2)->printVal();
        std::cout << std::string(2, ' ');
    } else {
        std::cout << std::string(6, ' ');
    }
    std::cout << '|';
    if (vertices.at(10)->own()) {
        vertices.at(10)->printOwner();
        vertices.at(10)->printLevel();
    } else {
        vertices.at(10)->printNum();
    }
    std::cout << "|--";
    if (edges.at(11)->own()) {
        edges.at(11)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(11)->printNum();
    }
    std::cout << "--|";
    if (vertices.at(11)->own()) {
        vertices.at(11)->printOwner();
        vertices.at(11)->printLevel();
    } else {
        vertices.at(11)->printNum();
    }
    std::cout << '|' << std::endl;

    // prints line 10.
    std::cout << std::string(2, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|' << std::endl;

    // prints line 11.
    std::cout << ' ';
    if (edges.at(12)->own()) {
        edges.at(12)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(12)->printNum();
    }
    std::cout << std::string(3, ' ');
    tiles.at(3)->printNum();
    std::cout << std::string(3, ' ');
    if (edges.at(13)->own()) {
        edges.at(13)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(13)->printNum();
    }
    std::cout << std::string(8, ' ');
    if (edges.at(14)->own()) {
        edges.at(14)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(14)->printNum();
    }
    std::cout << std::string(3, ' ');
    tiles.at(4)->printNum();
    std::cout << std::string(3, ' ');
    if (edges.at(15)->own()) {
        edges.at(15)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(15)->printNum();
    }
    std::cout << std::string(8, ' ');
    if (edges.at(16)->own()) {
        edges.at(16)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(16)->printNum();
    }
    std::cout << std::string(3, ' ');
    tiles.at(5)->printNum();
    std::cout << std::string(3, ' ');
    if (edges.at(17)->own()) {
        edges.at(17)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(17)->printNum();
    }
    std::cout << std::endl;

    // prints line 12.
    std::cout << std::string(2, ' ');
    std::cout << '|';
    std::cout << std::string(2, ' ');
    tiles.at(3)->printType();
    std::cout << std::string(7 - tiles.at(3)->getLength(), ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(2, ' ');
    tiles.at(4)->printType();
    std::cout << std::string(7 - tiles.at(4)->getLength(), ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(2, ' ');
    tiles.at(5)->printType();
    std::cout << std::string(7 - tiles.at(5)->getLength(), ' ');
    std::cout << '|' << std::endl;

    // prints line 13.
    std::cout << '|';
    if (vertices.at(12)->own()) {
        vertices.at(12)->printOwner();
        vertices.at(12)->printLevel();
    } else {
        vertices.at(12)->printNum();
    }
    std::cout << '|';
    if (tiles.at(3)->getType() != "PARK") {
        std::cout << std::string(2, ' ');
        if (tiles.at(3)->getVal() < 10) std::cout << ' ';
        tiles.at(3)->printVal();
        std::cout << std::string(2, ' ');
    } else {
        std::cout << std::string(6, ' ');
    }
    std::cout << '|';
    if (vertices.at(13)->own()) {
        vertices.at(13)->printOwner();
        vertices.at(13)->printLevel();
    } else {
        vertices.at(13)->printNum();
    }
    std::cout << "|--";
    if (edges.at(18)->own()) {
        edges.at(18)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(18)->printNum();
    }
    std::cout << "--|";
    if (vertices.at(14)->own()) {
        vertices.at(14)->printOwner();
        vertices.at(14)->printLevel();
    } else {
        vertices.at(14)->printNum();
    }
    std::cout << '|';
    if (tiles.at(4)->getType() != "PARK") {
        std::cout << std::string(2, ' ');
        if (tiles.at(4)->getVal() < 10) std::cout << ' ';
        tiles.at(4)->printVal();
        std::cout << std::string(2, ' ');
    } else {
        std::cout << std::string(6, ' ');
    }
    std::cout << '|';
    if (vertices.at(15)->own()) {
        vertices.at(15)->printOwner();
        vertices.at(15)->printLevel();
    } else {
        vertices.at(15)->printNum();
    }
    std::cout << "|--";
    if (edges.at(19)->own()) {
        edges.at(19)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(19)->printNum();
    }
    std::cout << "--|";
    if (vertices.at(16)->own()) {
        vertices.at(16)->printOwner();
        vertices.at(16)->printLevel();
    } else {
        vertices.at(16)->printNum();
    }
    std::cout << '|';
    if (tiles.at(5)->getType() != "PARK") {
        std::cout << std::string(2, ' ');
        if (tiles.at(5)->getVal() < 10) std::cout << ' ';
        tiles.at(5)->printVal();
        std::cout << std::string(2, ' ');
    } else {
        std::cout << std::string(6, ' ');
    }
    std::cout << '|';
    if (vertices.at(17)->own()) {
        vertices.at(17)->printOwner();
        vertices.at(17)->printLevel();
    } else {
        vertices.at(17)->printNum();
    }
    std::cout << '|' << std::endl;

    // prints line 14.
    std::cout << std::string(2, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|' << std::endl;

    // prints line 15.
    std::cout << ' ';
    if (edges.at(20)->own()) {
        edges.at(20)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(20)->printNum();
    }
    std::cout << std::string(8, ' ');
    if (edges.at(21)->own()) {
        edges.at(21)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(21)->printNum();
    }
    std::cout << std::string(3, ' ');
    tiles.at(6)->printNum();
    std::cout << std::string(3, ' ');
    if (edges.at(22)->own()) {
        edges.at(22)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(22)->printNum();
    }
    std::cout << std::string(8, ' ');
    if (edges.at(23)->own()) {
        edges.at(23)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(23)->printNum();
    }
    std::cout << std::string(3, ' ');
    tiles.at(7)->printNum();
    std::cout << std::string(3, ' ');
    if (edges.at(24)->own()) {
        edges.at(24)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(24)->printNum();
    }
    std::cout << std::string(8, ' ');
    if (edges.at(25)->own()) {
        edges.at(25)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(25)->printNum();
    }
    std::cout << std::endl;

    // prints line 16.
    std::cout << std::string(2, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(2, ' ');
    tiles.at(6)->printType();
    std::cout << std::string(7 - tiles.at(6)->getLength(), ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(2, ' ');
    tiles.at(7)->printType();
    std::cout << std::string(7 - tiles.at(7)->getLength(), ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|' << std::endl;

    // prints line 17.
    std::cout << '|';
    if (vertices.at(18)->own()) {
        vertices.at(18)->printOwner();
        vertices.at(18)->printLevel();
    } else {
        vertices.at(18)->printNum();
    }
    std::cout << "|--";
    if (edges.at(26)->own()) {
        edges.at(26)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(26)->printNum();
    }
    std::cout << "--|";
    if (vertices.at(19)->own()) {
        vertices.at(19)->printOwner();
        vertices.at(19)->printLevel();
    } else {
        vertices.at(19)->printNum();
    }
    std::cout << '|';
    if (tiles.at(6)->getType() != "PARK") {
        std::cout << std::string(2, ' ');
        if (tiles.at(6)->getVal() < 10) std::cout << ' ';
        tiles.at(6)->printVal();
        std::cout << std::string(2, ' ');
    } else {
        std::cout << std::string(6, ' ');
    }
    std::cout << '|';
    if (vertices.at(20)->own()) {
        vertices.at(20)->printOwner();
        vertices.at(20)->printLevel();
    } else {
        vertices.at(20)->printNum();
    }
    std::cout << "|--";
    if (edges.at(27)->own()) {
        edges.at(27)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(27)->printNum();
    }
    std::cout << "--|";
    if (vertices.at(21)->own()) {
        vertices.at(21)->printOwner();
        vertices.at(21)->printLevel();
    } else {
        vertices.at(21)->printNum();
    }
    std::cout << '|';
    if (tiles.at(7)->getType() != "PARK") {
        std::cout << std::string(2, ' ');
        if (tiles.at(7)->getVal() < 10) std::cout << ' ';
        tiles.at(7)->printVal();
        std::cout << std::string(2, ' ');
    } else {
        std::cout << std::string(6, ' ');
    }
    std::cout << '|';
    if (vertices.at(22)->own()) {
        vertices.at(22)->printOwner();
        vertices.at(22)->printLevel();
    } else {
        vertices.at(22)->printNum();
    }
    std::cout << "|--";
    if (edges.at(28)->own()) {
        edges.at(28)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(28)->printNum();
    }
    std::cout << "--|";
    if (vertices.at(23)->own()) {
        vertices.at(23)->printOwner();
        vertices.at(23)->printLevel();
    } else {
        vertices.at(23)->printNum();
    }
    std::cout << '|' << std::endl;

    // prints line 18.
    std::cout << std::string(2, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|' << std::endl;

    // prints line 19.
    std::cout << ' ';
    if (edges.at(29)->own()) {
        edges.at(29)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(29)->printNum();
    }
    std::cout << std::string(3, ' ');
    tiles.at(8)->printNum();
    std::cout << std::string(3, ' ');
    if (edges.at(30)->own()) {
        edges.at(30)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(30)->printNum();
    }
    std::cout << std::string(8, ' ');
    if (edges.at(31)->own()) {
        edges.at(31)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(31)->printNum();
    }
    std::cout << std::string(3, ' ');
    tiles.at(9)->printNum();
    std::cout << std::string(3, ' ');
    if (edges.at(32)->own()) {
        edges.at(32)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(32)->printNum();
    }
    std::cout << std::string(8, ' ');
    if (edges.at(33)->own()) {
        edges.at(33)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(33)->printNum();
    }
    std::cout << std::string(3, ' ');
    tiles.at(10)->printNum();
    std::cout << std::string(3, ' ');
    if (edges.at(34)->own()) {
        edges.at(34)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(34)->printNum();
    }
    std::cout << std::endl;

    // prints line 20.
    std::cout << std::string(2, ' ');
    std::cout << '|';
    std::cout << std::string(2, ' ');
    tiles.at(8)->printType();
    std::cout << std::string(7 - tiles.at(8)->getLength(), ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(2, ' ');
    tiles.at(9)->printType();
    std::cout << std::string(7 - tiles.at(9)->getLength(), ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(2, ' ');
    tiles.at(10)->printType();
    std::cout << std::string(7 - tiles.at(10)->getLength(), ' ');
    std::cout << '|' << std::endl;

    // prints line 21.
    std::cout << '|';
    if (vertices.at(24)->own()) {
        vertices.at(24)->printOwner();
        vertices.at(24)->printLevel();
    } else {
        vertices.at(24)->printNum();
    }
    std::cout << '|';
    if (tiles.at(8)->getType() != "PARK") {
        std::cout << std::string(2, ' ');
        if (tiles.at(8)->getVal() < 10) std::cout << ' ';
        tiles.at(8)->printVal();
        std::cout << std::string(2, ' ');
    } else {
        std::cout << std::string(6, ' ');
    }
    std::cout << '|';
    if (vertices.at(25)->own()) {
        vertices.at(25)->printOwner();
        vertices.at(25)->printLevel();
    } else {
        vertices.at(25)->printNum();
    }
    std::cout << "|--";
    if (edges.at(35)->own()) {
        edges.at(35)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(35)->printNum();
    }
    std::cout << "--|";
    if (vertices.at(26)->own()) {
        vertices.at(26)->printOwner();
        vertices.at(26)->printLevel();
    } else {
        vertices.at(26)->printNum();
    }
    std::cout << '|';
    if (tiles.at(9)->getType() != "PARK") {
        std::cout << std::string(2, ' ');
        if (tiles.at(9)->getVal() < 10) std::cout << ' ';
        tiles.at(9)->printVal();
        std::cout << std::string(2, ' ');
    } else {
        std::cout << std::string(6, ' ');
    }
    std::cout << '|';
    if (vertices.at(27)->own()) {
        vertices.at(27)->printOwner();
        vertices.at(27)->printLevel();
    } else {
        vertices.at(27)->printNum();
    }
    std::cout << "|--";
    if (edges.at(36)->own()) {
        edges.at(36)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(36)->printNum();
    }
    std::cout << "--|";
    if (vertices.at(28)->own()) {
        vertices.at(28)->printOwner();
        vertices.at(28)->printLevel();
    } else {
        vertices.at(28)->printNum();
    }
    std::cout << '|';
    if (tiles.at(10)->getType() != "PARK") {
        std::cout << std::string(2, ' ');
        if (tiles.at(10)->getVal() < 10) std::cout << ' ';
        tiles.at(10)->printVal();
        std::cout << std::string(2, ' ');
    } else {
        std::cout << std::string(6, ' ');
    }
    std::cout << '|';
    if (vertices.at(29)->own()) {
        vertices.at(29)->printOwner();
        vertices.at(29)->printLevel();
    } else {
        vertices.at(29)->printNum();
    }
    std::cout << '|' << std::endl;

    // prints line 22.
    std::cout << std::string(2, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|' << std::endl;

     // prints line 23.
    std::cout << ' ';
    if (edges.at(37)->own()) {
        edges.at(37)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(37)->printNum();
    }
    std::cout << std::string(8, ' ');
    if (edges.at(38)->own()) {
        edges.at(38)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(38)->printNum();
    }
    std::cout << std::string(3, ' ');
    tiles.at(11)->printNum();
    std::cout << std::string(3, ' ');
    if (edges.at(39)->own()) {
        edges.at(39)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(39)->printNum();
    }
    std::cout << std::string(8, ' ');
    if (edges.at(40)->own()) {
        edges.at(40)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(40)->printNum();
    }
    std::cout << std::string(3, ' ');
    tiles.at(12)->printNum();
    std::cout << std::string(3, ' ');
    if (edges.at(41)->own()) {
        edges.at(41)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(41)->printNum();
    }
    std::cout << std::string(8, ' ');
    if (edges.at(42)->own()) {
        edges.at(42)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(42)->printNum();
    }
    std::cout << std::endl;

    // prints line 24.
    std::cout << std::string(2, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(2, ' ');
    tiles.at(11)->printType();
    std::cout << std::string(7 - tiles.at(11)->getLength(), ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(2, ' ');
    tiles.at(12)->printType();
    std::cout << std::string(7 - tiles.at(12)->getLength(), ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|' << std::endl;

    // prints line 25.
    std::cout << '|';
    if (vertices.at(30)->own()) {
        vertices.at(30)->printOwner();
        vertices.at(30)->printLevel();
    } else {
        vertices.at(30)->printNum();
    }
    std::cout << "|--";
    if (edges.at(43)->own()) {
        edges.at(43)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(43)->printNum();
    }
    std::cout << "--|";
    if (vertices.at(31)->own()) {
        vertices.at(31)->printOwner();
        vertices.at(31)->printLevel();
    } else {
        vertices.at(31)->printNum();
    }
    std::cout << '|';
    if (tiles.at(11)->getType() != "PARK") {
        std::cout << std::string(2, ' ');
        if (tiles.at(11)->getVal() < 10) std::cout << ' ';
        tiles.at(11)->printVal();
        std::cout << std::string(2, ' ');
    } else {
        std::cout << std::string(6, ' ');
    }
    std::cout << '|';
    if (vertices.at(32)->own()) {
        vertices.at(32)->printOwner();
        vertices.at(32)->printLevel();
    } else {
        vertices.at(32)->printNum();
    }
    std::cout << "|--";
    if (edges.at(44)->own()) {
        edges.at(44)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(44)->printNum();
    }
    std::cout << "--|";
    if (vertices.at(33)->own()) {
        vertices.at(33)->printOwner();
        vertices.at(33)->printLevel();
    } else {
        vertices.at(33)->printNum();
    }
    std::cout << '|';
    if (tiles.at(12)->getType() != "PARK") {
        std::cout << std::string(2, ' ');
        if (tiles.at(12)->getVal() < 10) std::cout << ' ';
        tiles.at(12)->printVal();
        std::cout << std::string(2, ' ');
    } else {
        std::cout << std::string(6, ' ');
    }
    std::cout << '|';
    if (vertices.at(34)->own()) {
        vertices.at(34)->printOwner();
        vertices.at(34)->printLevel();
    } else {
        vertices.at(34)->printNum();
    }
    std::cout << "|--";
    if (edges.at(45)->own()) {
        edges.at(45)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(45)->printNum();
    }
    std::cout << "--|";
    if (vertices.at(35)->own()) {
        vertices.at(35)->printOwner();
        vertices.at(35)->printLevel();
    } else {
        vertices.at(35)->printNum();
    }
    std::cout << '|' << std::endl;

    // prints line 26.
    std::cout << std::string(2, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|' << std::endl;

    // prints line 27.
    std::cout << ' ';
    if (edges.at(46)->own()) {
        edges.at(46)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(46)->printNum();
    }
    std::cout << std::string(3, ' ');
    tiles.at(13)->printNum();
    std::cout << std::string(3, ' ');
    if (edges.at(47)->own()) {
        edges.at(47)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(47)->printNum();
    }
    std::cout << std::string(8, ' ');
    if (edges.at(48)->own()) {
        edges.at(48)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(48)->printNum();
    }
    std::cout << std::string(3, ' ');
    tiles.at(14)->printNum();
    std::cout << std::string(3, ' ');
    if (edges.at(49)->own()) {
        edges.at(49)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(49)->printNum();
    }
    std::cout << std::string(8, ' ');
    if (edges.at(50)->own()) {
        edges.at(50)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(50)->printNum();
    }
    std::cout << std::string(3, ' ');
    tiles.at(15)->printNum();
    std::cout << std::string(3, ' ');
    if (edges.at(51)->own()) {
        edges.at(51)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(51)->printNum();
    }
    std::cout << std::endl;

    // prints line 28.
    std::cout << std::string(2, ' ');
    std::cout << '|';
    std::cout << std::string(2, ' ');
    tiles.at(13)->printType();
    std::cout << std::string(7 - tiles.at(13)->getLength(), ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(2, ' ');
    tiles.at(14)->printType();
    std::cout << std::string(7 - tiles.at(14)->getLength(), ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(2, ' ');
    tiles.at(15)->printType();
    std::cout << std::string(7 - tiles.at(15)->getLength(), ' ');
    std::cout << '|' << std::endl;

    // prints line 29.
    std::cout << '|';
    if (vertices.at(36)->own()) {
        vertices.at(36)->printOwner();
        vertices.at(36)->printLevel();
    } else {
        vertices.at(36)->printNum();
    }
    std::cout << '|';
    if (tiles.at(13)->getType() != "PARK") {
        std::cout << std::string(2, ' ');
        if (tiles.at(13)->getVal() < 10) std::cout << ' ';
        tiles.at(13)->printVal();
        std::cout << std::string(2, ' ');
    } else {
        std::cout << std::string(6, ' ');
    }
    std::cout << '|';
    if (vertices.at(37)->own()) {
        vertices.at(37)->printOwner();
        vertices.at(37)->printLevel();
    } else {
        vertices.at(37)->printNum();
    }
    std::cout << "|--";
    if (edges.at(52)->own()) {
        edges.at(52)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(52)->printNum();
    }
    std::cout << "--|";
    if (vertices.at(38)->own()) {
        vertices.at(38)->printOwner();
        vertices.at(38)->printLevel();
    } else {
        vertices.at(38)->printNum();
    }
    std::cout << '|';
    if (tiles.at(14)->getType() != "PARK") {
        std::cout << std::string(2, ' ');
        if (tiles.at(14)->getVal() < 10) std::cout << ' ';
        tiles.at(14)->printVal();
        std::cout << std::string(2, ' ');
    } else {
        std::cout << std::string(6, ' ');
    }
    std::cout << '|';
    if (vertices.at(39)->own()) {
        vertices.at(39)->printOwner();
        vertices.at(39)->printLevel();
    } else {
        vertices.at(39)->printNum();
    }
    std::cout << "|--";
    if (edges.at(53)->own()) {
        edges.at(53)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(53)->printNum();
    }
    std::cout << "--|";
    if (vertices.at(40)->own()) {
        vertices.at(40)->printOwner();
        vertices.at(40)->printLevel();
    } else {
        vertices.at(40)->printNum();
    }
    std::cout << '|';
    if (tiles.at(15)->getType() != "PARK") {
        std::cout << std::string(2, ' ');
        if (tiles.at(15)->getVal() < 10) std::cout << ' ';
        tiles.at(15)->printVal();
        std::cout << std::string(2, ' ');
    } else {
        std::cout << std::string(6, ' ');
    }
    std::cout << '|';
    if (vertices.at(41)->own()) {
        vertices.at(41)->printOwner();
        vertices.at(41)->printLevel();
    } else {
        vertices.at(41)->printNum();
    }
    std::cout << '|' << std::endl;

    // prints line 30.
    std::cout << std::string(2, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|' << std::endl;

    // prints line 31.
    std::cout << ' ';
    if (edges.at(54)->own()) {
        edges.at(54)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(54)->printNum();
    }
    std::cout << std::string(8, ' ');
    if (edges.at(55)->own()) {
        edges.at(55)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(55)->printNum();
    }
    std::cout << std::string(3, ' ');
    tiles.at(16)->printNum();
    std::cout << std::string(3, ' ');
    if (edges.at(56)->own()) {
        edges.at(56)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(56)->printNum();
    }
    std::cout << std::string(8, ' ');
    if (edges.at(57)->own()) {
        edges.at(57)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(57)->printNum();
    }
    std::cout << std::string(3, ' ');
    tiles.at(17)->printNum();
    std::cout << std::string(3, ' ');
    if (edges.at(58)->own()) {
        edges.at(58)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(58)->printNum();
    }
    std::cout << std::string(8, ' ');
    if (edges.at(59)->own()) {
        edges.at(59)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(59)->printNum();
    }
    std::cout << std::endl;

    // prints line 32.
    std::cout << std::string(2, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(2, ' ');
    tiles.at(16)->printType();
    std::cout << std::string(7 - tiles.at(16)->getLength(), ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(2, ' ');
    tiles.at(17)->printType();
    std::cout << std::string(7 - tiles.at(17)->getLength(), ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|' << std::endl;

    // prints line 33.
    std::cout << '|';
    if (vertices.at(42)->own()) {
        vertices.at(42)->printOwner();
        vertices.at(42)->printLevel();
    } else {
        vertices.at(42)->printNum();
    }
    std::cout << "|--";
    if (edges.at(60)->own()) {
        edges.at(60)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(60)->printNum();
    }
    std::cout << "--|";
    if (vertices.at(43)->own()) {
        vertices.at(43)->printOwner();
        vertices.at(43)->printLevel();
    } else {
        vertices.at(43)->printNum();
    }
    std::cout << '|';
    if (tiles.at(16)->getType() != "PARK") {
        std::cout << std::string(2, ' ');
        if (tiles.at(16)->getVal() < 10) std::cout << ' ';
        tiles.at(16)->printVal();
        std::cout << std::string(2, ' ');
    } else {
        std::cout << std::string(6, ' ');
    }
    std::cout << '|';
    if (vertices.at(44)->own()) {
        vertices.at(44)->printOwner();
        vertices.at(44)->printLevel();
    } else {
        vertices.at(44)->printNum();
    }
    std::cout << "|--";
    if (edges.at(61)->own()) {
        edges.at(61)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(61)->printNum();
    }
    std::cout << "--|";
    if (vertices.at(45)->own()) {
        vertices.at(45)->printOwner();
        vertices.at(45)->printLevel();
    } else {
        vertices.at(45)->printNum();
    }
    std::cout << '|';
    if (tiles.at(17)->getType() != "PARK") {
        std::cout << std::string(2, ' ');
        if (tiles.at(17)->getVal() < 10) std::cout << ' ';
        tiles.at(17)->printVal();
        std::cout << std::string(2, ' ');
    } else {
        std::cout << std::string(6, ' ');
    }
    std::cout << '|';
    if (vertices.at(46)->own()) {
        vertices.at(46)->printOwner();
        vertices.at(46)->printLevel();
    } else {
        vertices.at(46)->printNum();
    }
    std::cout << "|--";
    if (edges.at(62)->own()) {
        edges.at(62)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(62)->printNum();
    }
    std::cout << "--|";
    if (vertices.at(47)->own()) {
        vertices.at(47)->printOwner();
        vertices.at(47)->printLevel();
    } else {
        vertices.at(47)->printNum();
    }
    std::cout << '|' << std::endl;

    // prints line 34.
    std::cout << std::string(12, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|' << std::endl;

    // prints line 35.
    std::cout << std::string(11, ' ');
    if (edges.at(63)->own()) {
        edges.at(63)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(63)->printNum();
    }
    std::cout << std::string(8, ' ');
    if (edges.at(64)->own()) {
        edges.at(64)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(64)->printNum();
    }
    std::cout << std::string(3, ' ');
    tiles.at(18)->printNum();
    std::cout << std::string(3, ' ');
    if (edges.at(65)->own()) {
        edges.at(65)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(65)->printNum();
    }
    std::cout << std::string(8, ' ');
    if (edges.at(66)->own()) {
        edges.at(66)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(66)->printNum();
    }
    std::cout << std::endl;

    // prints line 36.
    std::cout << std::string(12, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|';
    std::cout << std::string(2, ' ');
    tiles.at(18)->printType();
    std::cout << std::string(7 - tiles.at(18)->getLength(), ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|' << std::endl;

    // prints line 37.
    std::cout << std::string(10, ' ');  
    std::cout << '|';
    if (vertices.at(48)->own()) {
        vertices.at(48)->printOwner();
        vertices.at(48)->printLevel();
    } else {
        vertices.at(48)->printNum();
    }
    std::cout << "|--";
    if (edges.at(67)->own()) {
        edges.at(67)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(67)->printNum();
    }
    std::cout << "--|";
    if (vertices.at(49)->own()) {
        vertices.at(49)->printOwner();
        vertices.at(49)->printLevel();
    } else {
        vertices.at(49)->printNum();
    }
    std::cout << '|';
    if (tiles.at(18)->getType() != "PARK") {
        std::cout << std::string(2, ' ');
        if (tiles.at(18)->getVal() < 10) std::cout << ' ';
        tiles.at(18)->printVal();
        std::cout << std::string(2, ' ');
    } else {
        std::cout << std::string(6, ' ');
    }
    std::cout << '|';
    if (vertices.at(50)->own()) {
        vertices.at(50)->printOwner();
        vertices.at(50)->printLevel();
    } else {
        vertices.at(50)->printNum();
    }
    std::cout << "|--";
    if (edges.at(68)->own()) {
        edges.at(68)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(68)->printNum();
    }
    std::cout << "--|";
    if (vertices.at(51)->own()) {
        vertices.at(51)->printOwner();
        vertices.at(51)->printLevel();
    } else {
        vertices.at(51)->printNum();
    }
    std::cout << '|' << std::endl;

    // prints line 38.
    std::cout << std::string(22, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|' << std::endl;

    // prints line 39.
    std::cout << std::string(21, ' ');
    if (edges.at(69)->own()) {
        edges.at(69)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(69)->printNum();
    }
    std::cout << std::string(8, ' ');
    if (edges.at(70)->own()) {
        edges.at(70)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(70)->printNum();
    }
    std::cout << std::endl;

    // prints line 40.
    std::cout << std::string(22, ' ');
    std::cout << '|';
    std::cout << std::string(9, ' ');
    std::cout << '|' << std::endl;

    // prints line 41.
    std::cout << std::string(20, ' ');
    std::cout << '|';
    if (vertices.at(52)->own()) {
        vertices.at(52)->printOwner();
        vertices.at(52)->printLevel();
    } else {
        vertices.at(52)->printNum();
    }
    std::cout << "|--";
    if (edges.at(71)->own()) {
        edges.at(71)->printOwner();
        std::cout << 'R';
    } else {
        edges.at(71)->printNum();
    }
    std::cout << "--|";
    if (vertices.at(53)->own()) {
        vertices.at(53)->printOwner();
        vertices.at(53)->printLevel();
    } else {
        vertices.at(53)->printNum();
    }
    std::cout << '|' << std::endl;
}


Display::~Display(){}
