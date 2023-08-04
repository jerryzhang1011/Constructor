#include <iostream>
#include <vector>
#include "board.h"
#include "gameBoard.h"
#include "player.h"
#include "subject.h"
#include "abstractPlayer.h"
#include <sstream>



int main (int argc, char* argv[]) {

    GameBoard gb = {};
    AbstractPlayer* p = new Player{0,&gb};
    gb.attachPlayer(p);
    AbstractPlayer* p1 = new Player{1,&gb};
    gb.attachPlayer(p1);
    AbstractPlayer* p2 = new Player{2,&gb};
    gb.attachPlayer(p2);
    AbstractPlayer* p3 = new Player{3,&gb};
    gb.attachPlayer(p3);


    std::string argument = "-random-board";
    std::string arg;

    for (int i = 1; i < argc; ++i) {
        std::string sb = argv[i];
        if (sb == "-load") {
            argument = "-load";
            arg = argv[i + 1];
            break;
        } else if (sb == "-board") {
            argument = "-board";
            arg = argv[i + 1];
            break;
        } else if (sb == "-seed") {
            argument = "-seed";
            arg = argv[i + 1];
        } else {
            continue;
        }
    }

    if (argument == "-random-board") {
        gb.initialize(-1);
        gb.display_board();
        gb.players_choose_start_index();
        gb.display_board();
        gb.start(0);
    }
    else if (argument == "-seed") {
        std::string seed = argv[2];
        std::stringstream oss {seed};
        int seed_num;
        oss >> seed_num;
        gb.initialize(seed_num);
        gb.display_board();
        gb.players_choose_start_index();
        gb.display_board();
        gb.start(0);  
    }
    else if (argument == "-load") {
        size_t curr = 0;
        gb.initialize(-1);
        std::string file_name = argv[2];
        std::ifstream iss {file_name};
        gb.read_load_info(iss, curr);
        gb.display_board();
        gb.start(curr);
    }
    else if (argument == "-board") {
        gb.initialize(-1);
        std::string file_name = argv[2];
        std::ifstream iss {file_name};
        gb.read_board_info(iss);
        gb.display_board();
        gb.players_choose_start_index();
        gb.display_board();
        gb.start(0);
    } else {
        std::cerr << "Invalid command line." << std::endl;
        return 0;
    }

    while (1) {
        std::cout << "Would you like play again?" << std::endl;
        std::string response;
        std::cin >> response;
        if (response == "yes") {
            gb.initialize(-1);
            gb.display_board();
            gb.players_choose_start_index();
            gb.display_board();
            gb.start(0);
        } else if (response == "no") {
            return 0;
        } else {
            gb.d->invalid();
        }
    }
    return 0;
}

