#include "gameBoard.h"
#include <iostream>
#include <string>


void GameBoard::processCommand(int target,int eventPara1, int eventPara2) {
    if(eventPara1 == 0){
        if(eventPara2 == 0){
            delete dice;
            dice = new LoadedDice{this,target};
        }
        else if(eventPara2 == 1){
            delete dice;
            dice = new RandomDice{target};
        }
        else if(eventPara2 == 2){
            diceRoll = dice->generate();
            std::cout<<"dice rolled"<<std::endl;
            processDice(target);
            delete(dice);
            dice = nullptr;
        }
    }
    else if(eventPara1 == CONSTANTS::ROADCOMMAND){
        constructRoad(target,eventPara2);
    }
    else if(eventPara1 == CONSTANTS::BASEMENTCOMMAND){
        build_residence(target,eventPara2, false);
    }
    else if(eventPara1 == CONSTANTS::IMPROVECOMMAND){
        improve_residence(eventPara2);
    }
    else if(eventPara1 <= CONSTANTS::TRADECOMMAND){
        processTrade(target, eventPara1/CONSTANTS::TRADECOMMAND,eventPara2);
    }
}


int GameBoard::name_to_index(std::string player_name) {
    // Blue Red, Orange Yellow
    if (player_name == "B") {
        return 0;
    } else if (player_name == "R") {
        return 1;
    } else if (player_name == "O") {
        return 2;
    } else {
        return 3;
    }
}
std::string GameBoard::index_to_name(int player_index) {
    std::string out;
    if (player_index == 0) {
        out = "B";
    } else if (player_index == 1) {
        out = "R";
    } else if (player_index == 2) {
        out = 'O';
    } else {
        out = "Y";
    }
    return out;
}



std::string GameBoard::convert_short_to_full_name(std::string sh) {
    std::string result;
    if (sh == "B") {
        result = "Blue";
    } else if (sh == "O") {
        result =  "Orange";
    } else if (sh == "R") {
        result = "Red";
    } else {
        result = "Yellow";
    }
    return result;
}

void GameBoard::player_get_resource () {
    //Order: BRICK, ENERGY,GLASS, HEAT, WIFI.
    // set resource
    for (int i = 0; i < 19; ++i) {
        if (tiles[i]->getVal() == diceRoll) {
            if (tiles[i]->getGoose()) continue;
            std::string item = tiles[i]->getType();
            int code = CONSTANTS::get_resource_code(item);
            for (auto vertex : tiles[i]->getNeighbourVertex()) {
                if (vertices[vertex]->own()) {
                    int player_num = name_to_index(vertices[vertex]->getOwner());
                    // notify(target (player code), eventPara1 100~104, eventPara2 1~3): recieve resources (call when giving player resources)
                    // give player index 0 / 1 item of / item 0

                    if (vertices[vertex]->getLevel() == "B") {
                        notifyPlayer(player_num,code , 1);
                    } else if (vertices[vertex]->getLevel() == "H") {
                        notifyPlayer(player_num,code , 2);
                    } else {
                        notifyPlayer(player_num,code , 3);
                    }
                }
            }
        }
    }
}

void GameBoard::processGeese(int tileIndex, int index, std::string activePlayer) {
    std::string s;
    Tile* dest = tiles[tileIndex];
    dest->setStatus(true);
    std::vector <std::string> builders;
    for (auto vertex : dest->getNeighbourVertex()) {
        if (vertices[vertex]->own()) {
            std::string name = vertices[vertex]->getOwner();
            notifyPlayer(CONSTANTS::get_Player_code(name),1,1);
            
            if (name == activePlayer)continue;
            if(input>0){
                name = convert_short_to_full_name(name);
                builders.emplace_back(name);}
        }
    }
    if (builders.empty()) {
        d->noSteal(index);
        return;
    }
    // std::cout << "Builder " << index << " can choose to steal from:";
    // for (auto i : builders) {
    //     std::cout << " " << i;
    // }
    // std::cout << "." << std::endl;
    
////////////// keep asking
    bool found = false;
    int steal_index;
    while(!found) {
        d->chooseSteal(index, builders);
        notifyPlayer(index,-1,-1);   // get input
        //check if target is available
        for (auto i : dest->getNeighbourVertex()) {
            if (name_to_index(vertices[i]->getOwner()) == input) {
                found = true;
                steal_index = i;
                break;
            }
        }
    }
////////////// end of asking
    int stolenPlayer = input;
    int active_player_index = name_to_index(activePlayer);
    std::string r_name;         // resource name
    notifyPlayer(stolenPlayer,1,2);
    notifyPlayer(active_player_index,100+input,1);
    r_name = CONSTANTS::get_resource_name(input);
    // std::cout << "Builder " << curr_player_name << " steals " << r_name << " from builder ";
    // vertices[steal_index]->printOwner();
    // std::cout << "." << std::endl;

    d->steal(index, convert_short_to_full_name(index_to_name(stolenPlayer)), r_name);
}

void GameBoard::processTrade(int index, int target, int given){
    //input = resourceTypeDemanded*100+amountDemanded
    int demanded = input;
    notifyPlayer(target-1,CONSTANTS::TRADECOMMAND*(index+1),given*10+demanded);
}

void GameBoard::processDice(int index){
    if(diceRoll == 7){
        notifyPlayer(-1,1,0);
        notifyPlayer(index,-1,-1);
        processGeese(input,index,index_to_name(index));
        notifyPlayer(index,100+input,1);
    }
    else{
        player_get_resource();
    }
}

void GameBoard::constructRoad(int player_id, int edgeIndex) {
    if (edges[edgeIndex]->own()) {
        throw "Already build";
        return;
    }
    bool found = false;
    // check edge
    for (auto i : edges[edgeIndex]->getNeighbourEdge()) {
        int edge_player_id = name_to_index(edges[i]->getOwner());
        if (edges[i]->own() && edge_player_id == player_id) {
            found = true;
            break;
        }
    }
    
    // now check vertex
    for (auto i : edges[edgeIndex]->getNeighbourVertex()) {
        int vertex_player_id = name_to_index(vertices[i]->getOwner());
        if (vertices[i]->own() && vertex_player_id == player_id) {
            found = true;
            break;
        }
    }
    // check if found
    if (found) {
        edges[edgeIndex]->setStatus(true);
        edges[edgeIndex]->setOwner(index_to_name(player_id));
    } else {
        throw "No neighbour";
    }
    return;
}

void GameBoard::build_residence(int player_id, int vertexIndex, bool start) {
    if (vertexIndex > 53 || vertexIndex < 0) {
        throw "Invalid command";
        return;
    }
    if (vertices.at(vertexIndex)->own()) {
        throw "Already build";
        return;
    }
    // check adjacent vertex
    for (auto i : vertices[vertexIndex]->getNeighbourVertex()) {
        if (vertices[i]->own()) {
            throw "adjacent to a existing residence";
            return;
        }
    }
    //if this is during setup phase, we don't need road adjacency.
    if (start) {
        vertices[vertexIndex]->setStatus(true);
        vertices[vertexIndex]->setOwner(index_to_name(player_id));
        vertices[vertexIndex]->build(index_to_name(player_id));
        return;
    }

    // now check if exist an adjacent road
    for (auto i : vertices[vertexIndex]->getNeighbourEdge()) {
        if (edges[i]->own() && player_id == name_to_index(edges[i]->getOwner())) {
            vertices[vertexIndex]->setStatus(true);
            vertices[vertexIndex]->setOwner(index_to_name(player_id));
            //vertices[vertexIndex]->build(index_to_name(player_id));
            return;
        }
    }
    throw "No adjacent road";
    return;
}

void GameBoard::improve_residence(int vertexIndex) {
    vertices[vertexIndex]->improve();
    return;
}

std::vector<int> generateNumbers(int seed) {
    // Create a vector with the exact counts of each number
    std::vector<int> numbers = {2, 3, 3, 4, 4, 5, 5, 6, 6, 8, 8, 9, 9, 10, 10, 11, 11, 12};

    // Create a random generator
    std::mt19937 rng;

    if (seed == -1) {
        // Use random_device to generate a seed for the random number generator
        rng = std::mt19937(std::random_device{}());
    } else {
        // Use the provided seed for reproducibility
        rng = std::mt19937(seed);
    }

    // Shuffle the vector to randomize the order of the numbers
    std::shuffle(numbers.begin(), numbers.end(), rng);

    return numbers;
}

std::vector<std::string> generateStrings(int seed) {
    // Create a vector with the exact counts of each string
    std::vector<std::string> strings = {"PARK", "BRICK", "BRICK", "BRICK", "BRICK", 
                                        "ENERGY", "ENERGY", "ENERGY", "ENERGY",
                                        "GLASS", "GLASS", "GLASS", "GLASS",
                                        "HEAT", "HEAT", "HEAT",
                                        "WIFI", "WIFI", "WIFI"};

    std::mt19937 rng;
    if (seed == -1) {
        // Create a random generator using a hardware random device
        rng.seed(std::random_device{}());
    } else {
        // Use the given seed
        rng.seed(seed);
    }

    // Shuffle the vector to randomize the order of the strings
    std::shuffle(strings.begin(), strings.end(), rng);

    return strings;
}

void GameBoard::initialize(int seed) {
    const int goose = 7;
    const int tileNum = 19;
    const int vertexNum = 54;
    const int edgeNum = 72;
    std::vector<int> randomNumber = generateNumbers(seed);
    std::vector<std::string> randomString = generateStrings(seed);
    for (int i = 0; i < tileNum; ++i) {
        tiles.at(i)->setNum(i);
        tiles.at(i)->setType(randomString.back());
        if (randomString.back() == "PARK") {
            randomString.pop_back();
            tiles.at(i)->setVal(goose);
            tiles.at(i)->setStatus(true);
        } else {
            randomString.pop_back();
            tiles.at(i)->setVal(randomNumber.back());
            randomNumber.pop_back();
            tiles.at(i)->setStatus(false);
        }
        tiles.at(i)->setVertex(i);
        tiles.at(i)->setEdge(i);
    }
    for (int i = 0; i < vertexNum; ++i) {
        vertices.at(i)->setNum(i);
        vertices.at(i)->setStatus(false);
        vertices.at(i)->setOwner("");
        vertices.at(i)->setVertex(i);
        vertices.at(i)->setEdge(i);
    }
    for (int i = 0; i < edgeNum; ++i) {
        edges.at(i)->setNum(i);
        edges.at(i)->setStatus(false);
        edges.at(i)->setOwner("");
        edges.at(i)->setVertex(i);
        edges.at(i)->setEdge(i);
    }
}


GameBoard::GameBoard():dice{new RandomDice(0)}{
    d = new Display();

    // tiles
    for (int i = 0; i < 19; ++i) {
        Tile *t1 = new Tile {};
        tiles.emplace_back(t1);
    }
    //vertex
    for (int i = 0; i < 54; ++i) {
        Vertex *v1 = new Vertex {};
        vertices.emplace_back(v1);
    }
    //edges
    for (int i = 0; i < 72; ++i) {
        Edge *e1 = new Edge {};
        edges.emplace_back(e1);
    }
}
GameBoard::GameBoard(std::vector <Tile*> t, std::vector <Vertex*> v, std::vector <Edge*> e):dice{new RandomDice(0)},
            tiles{t}, vertices{v},edges{e} { }



void GameBoard::print_all_player() {
    for (auto i : p) {
        i->player_print();
    }
}

void GameBoard::display_board() {
    d->board(tiles, vertices, edges);
}

void GameBoard::players_choose_start_index() {
    for (int i = 0; i < 4; ++i) {
        d->begin(i);
        notifyPlayer(i, -1, -1);
        int in = this->getInput();
        try {
            this->build_residence(i, in, true);
            notifyPlayer(i,6,in);
            /*notifyPlayer(i,-1,-1);
            int in = this->getInput();
            this->constructRoad(i,in);*/
        }
        catch(const char* a) {
            --i;
            d->buildFail();
        }
    }
    for (int i = 0; i < 4; ++i) {
        d->begin(i);
        notifyPlayer(i, -1, -1);
        int in = this->getInput();
        try {
            this->build_residence(i, in, true);
            notifyPlayer(i,6,in);
            /*notifyPlayer(i,-1,-1);
            int in = this->getInput();
            this->constructRoad(i,in);*/
        }
        catch(const char* a) {
            --i;
            d->buildFail();
        }
    }
}



GameBoard::~GameBoard(){
    for(int i = 0; i<tiles.size(); i++){
        delete(tiles.at(i));
    }
    for(int i = 0; i<vertices.size(); i++){
        delete(vertices.at(i));
    }
    for(int i = 0; i<edges.size(); i++){
        delete(edges.at(i));
    }
}

void GameBoard::save_game(std::ofstream& oss, int index) {
    this->d->save(index, p, tiles, oss);
    return;
}

void GameBoard::end_of_input(int index) {
    std::ofstream oss {"backup.sv"};
    this->save_game(oss, index);
    throw -1;
}


void GameBoard::read_board_info(std::ifstream &iss) {
    for (int i = 0; i < 19; ++i) {
        int resource_name;
        int value;
        std::string type;
        iss >> resource_name;
        iss >> value;
        if (resource_name == 0) {
            type = "BRICK";
        }
        else if (resource_name == 1) {
            type = "ENERGY";
        }
        else if (resource_name == 2) {
            type = "GLASS";
        }
        else if (resource_name == 3) {
            type = "HEAT";
        }
        else if (resource_name == 4) {
            type = "WIFI";
        }
        else {
            type = "PARK";
        } 

        tiles[i]->setVal(value);
        tiles[i]->setType(type);
    }
}


void GameBoard::read_load_info(std::ifstream &ifs, size_t& curTurn) {
    std::string line, str, type;
    int element, value;
    for (int i = 0; i < 7; ++i) {
        std::getline(ifs, line);
        std::istringstream iss(line);
        if (i == 0) {
            if (line == "Blue") {
                curTurn = 0;
            }
            else if (line == "Red") {
                curTurn = 1;
            }
            else if (line == "Orange") {
                curTurn = 2;
            }
            else {
                curTurn = 3;
            }
        } else if (i == 1) {
            for (int j = 0; j < 5; ++j) {
                iss >> element;
                notifyPlayer(i-1, 100 + j, element);
            }
            iss >> str;
            while (iss >> element) {
                //p.at(i - 1).roads.push_back(element);
                notifyPlayer(i -1, 9, element);
            }
            iss.clear();
            iss.ignore();
            while (iss >> element >> str) {
                if (str == "B") {
                    vertices.at(element)->setStatus(true);
                    vertices.at(element)->setOwner("B");
                    vertices.at(element)->setLevel("B");
                    //p.at(i - 1).basement.push_back(element);
                    notifyPlayer(i - 1, 6, element);
                } else if (str == "H") {
                    vertices.at(element)->setStatus(true);
                    vertices.at(element)->setOwner("B");
                    vertices.at(element)->setLevel("H");
                    //p.at(i - 1).house.push_back(element);
                    notifyPlayer(i - 1, 7, element);
                } else {
                    vertices.at(element)->setStatus(true);
                    vertices.at(element)->setOwner("B");
                    vertices.at(element)->setLevel("T");
                    //p.at(i - 1).tower.push_back(element);
                    notifyPlayer(i - 1, 8, element);
                }
            }
        } else if (i == 2) {
            for (int j = 0; j < 5; ++j) {
                iss >> element;
                //p.at(i - 1).resource[j] = element;
                notifyPlayer(i - 1, j + 100, element);
            }
            iss >> str;
            while (iss >> element) {
                //p.at(i - 1).roads.push_back(element);
                notifyPlayer(i - 1, 9, element);
            }
            iss.clear();
            iss.ignore();
            while (iss >> element >> str) {
                if (str == "B") {
                    vertices.at(element)->setStatus(true);
                    vertices.at(element)->setOwner("R");
                    vertices.at(element)->setLevel("B");
                    notifyPlayer(i - 1, 6, element);
                } else if (str == "H") {
                    vertices.at(element)->setStatus(true);
                    vertices.at(element)->setOwner("R");
                    vertices.at(element)->setLevel("H");
                    notifyPlayer(i - 1, 7, element);
                } else {
                    vertices.at(element)->setStatus(true);
                    vertices.at(element)->setOwner("R");
                    vertices.at(element)->setLevel("T");
                    notifyPlayer(i - 1, 8, element);
                }
            }
        } else if (i == 3) {
            for (int j = 0; j < 5; ++j) {
                iss >> element;
                notifyPlayer(i - 1, j + 100, element);
            }
            iss >> str;
            while (iss >> element) {
                notifyPlayer(i - 1, 9, element);
            }
            iss.clear();
            iss.ignore();
            while (iss >> element >> str) {
                if (str == "B") {
                    vertices.at(element)->setStatus(true);
                    vertices.at(element)->setOwner("O");
                    vertices.at(element)->setLevel("B");
                    notifyPlayer(i - 1, 6, element);
                } else if (str == "H") {
                    vertices.at(element)->setStatus(true);
                    vertices.at(element)->setOwner("O");
                    vertices.at(element)->setLevel("H");
                    notifyPlayer(i - 1, 7, element);
                } else {
                    vertices.at(element)->setStatus(true);
                    vertices.at(element)->setOwner("O");
                    vertices.at(element)->setLevel("T");
                    notifyPlayer(i - 1, 8, element);
                }
            }
        } else if (i == 4) {
            for (int j = 0; j < 5; ++j) {
                iss >> element;
                notifyPlayer(i - 1, j + 100, element);
            }
            iss >> str;
            while (iss >> element) {
                notifyPlayer(i - 1, 9, element);
            }
            iss.clear();
            iss.ignore();
            while (iss >> element >> str) {
                if (str == "B") {
                    vertices.at(element)->setStatus(true);
                    vertices.at(element)->setOwner("Y");
                    vertices.at(element)->setLevel("B");
                    notifyPlayer(i - 1, 6, element);
                } else if (str == "H") {
                    vertices.at(element)->setStatus(true);
                    vertices.at(element)->setOwner("Y");
                    vertices.at(element)->setLevel("H");
                    notifyPlayer(i - 1, 7, element);
                } else {
                    vertices.at(element)->setStatus(true);
                    vertices.at(element)->setOwner("Y");
                    vertices.at(element)->setLevel("T");
                    notifyPlayer(i - 1, 8, element);
                }
            }
        } else if (i == 5) {
            for (int k = 0; k < 19; ++k) {
                iss >> element >> value;
                if (element == 0) {
                    type = "BRICK";
                }
                else if (element == 1) {
                    type = "ENERGY";
                }
                else if (element == 2) {
                    type = "GLASS";
                }
                else if (element == 3) {
                    type = "HEAT";
                }
                else if (element == 4) {
                    type = "WIFI";
                }
                else {
                    type = "PARK";
                } 
                tiles[k]->setVal(value);
                tiles[k]->setType(type);
            }
        } else {
            std::stringstream iss {line};
            iss >> element;
            tiles.at(element)->setStatus(true);
        }
    }
}
