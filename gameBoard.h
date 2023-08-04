#ifndef GBOARD
#define GBOARD
#include <vector>
#include <string>
#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
#include <string>
#include <sstream>
#include "dice.h"
#include "subject.h"
#include "board.h"
//#include "abstractPlayer.h"
#include "loadedDice.h"
#include "RandomDice.h"
#include "const.h"
#include "abstractDisplay.h"
#include "display.h"

class GameBoard: public Subject{
    protected:
        Dice* dice;
        int diceRoll;//the result of dice roll
        std::vector <Tile*> tiles;
        std::vector <Vertex*> vertices;
        std::vector <Edge*> edges;
        void player_get_resource ();                 // get val from diceRoll
        int name_to_index(std::string player_name);  // convert name to index EX) R -> 0
        int get_resource_code(std::string s);        // convert resource s to code, ex) brick -> 100           
    public:
        void processCommand(int target,int eventPara1, int eventPara2);
        void initialize(int seed);
        int GEESELIMIT = 7;
        GameBoard();
        GameBoard(std::vector <Tile*> t, std::vector <Vertex*> v, std::vector <Edge*> e);
        void processGeese(int tileIndex, int index, std::string activePlayer); // notifyPlayer(player_index, -1, 0)
        void processTrade(int index, int target, int process);  
        void processDice(int index);
        void processGeese(int tileIndex,int index);//place geese at position tileIndex:: To do
        //call notifyPlayer(index,-1,0)(choosing steal target)
        //response in input
        //call notifyPlayer(targetindex,1,2)(target index is in int input)
        void player_get_resource(std::string player_name);

        void constructRoad(int player_id, int edgeIndex);
        //May throw error (string: )
        //throw "Already build";
        //throw "No neighbour";
        // have to garantee player has sufficient money
        
        void build_residence(int player_id, int vertexIndex, bool start);
        void improve_residence(int vertexIndex);
        void print_all_player();
        void display_board();
        ////////////////////////////////////////////////
        std::string index_to_name(int player_index); // convert index to name ex) 0 -> R
        std::string convert_short_to_full_name(std::string sh);        // ex) R -> Red


        ~GameBoard(); 

        void players_choose_start_index();     // 4 player each choose 2 residence 
        void save_game(std::ofstream& oss, int index);
        void end_of_input(int index);
        void read_board_info(std::ifstream &iss);
        void read_load_info(std::ifstream &ifs, size_t& curTurn);
};

#endif
