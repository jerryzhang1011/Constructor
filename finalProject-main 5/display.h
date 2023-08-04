#ifndef DISPLAY
#define DISPLAY
#include "subject.h"
#include "board.h"
#include "abstractPlayer.h"
#include "abstractDisplay.h"
#include <fstream>
#include <string>

class Display: public AbstractDisplay {

  public:
    // order: "Blue", "Red", "Orange", "Yellow", 0, 1, 2, 3
    void trading(int curr, int other_player, int give, int get);

    void geeseLose(int colour, int *r);

    std::string input();
    // > \n, take input 

    int readInt();
    // > \n, take input

    void invalid();
    // Invalid command. \n

    void buildFail();
    // You cannot build here. \n

    void insufficient();
    // You do not have enough resources. \n

    void begin(int builder);
    // Builder <colour>, where do you want to build a basement? \n

    void end(int builder);
    // Builder <colour> is the winner. \n
    // Would you like play again? \n

    void loadedDice(); 
    // Input a roll between 2 and 12: \n

    void invalidRoll();
    // Invalid roll. \n

    void turn(int builder);
    // Builder <colour>’s turn. \n

    void gain(std::vector <AbstractPlayer*> p, std::vector <int> num, std::string type);
    // Builder <colour> gained: \n
    // <numResource> <resourceType> \n

    void noGain();
    // No builders gained resources. \n

    void geeseSteal(std::vector <AbstractPlayer*> p, std::vector <std::vector <std::pair <int, std::string>> > resourcesLost);
    // Builder <colour> loses <numResourcesLost> resources to the geese. They lose: \n
    // <numResource> <resourceName> \n

    void placeGeese();
    // Choose where to place the GEESE. \n

    void chooseSteal(int builder, std::vector <std::string> builders);
    // Builder <colour1> can choose to steal from [builders]. \n
    // Choose a builder to steal from.

    void steal(int builder, std::string stolen, std::string resource);
    // Builder <colour1> steals <resource> from builder <colour2>. \n

    void noSteal(int builder);
    // Builder <colour1> has no builders to steal from. \n

    void status(int builder, int numPoints, int* resources);
    // <colour> has <numPoints> building points, <numBrick> brick, <numEnergy> energy,
    // <numGlass> glass, <numHeat> heat, and <numWiFi> WiFi. \n

    void residence(int builder, std::vector <int> basement, std::vector <int> house, std::vector <int> tower);
    // <colour> has built: \n
    // <vertex> <buildingType> \n

    void trade(int builder, std::string colour, std::string give, std::string take); 
    // <colour1> offers <colour2> one <resource1> for one <resource2>. \n
    // Does <colour2> accept this offer? \n

    void save(int builder, std::vector <AbstractPlayer*> p, std::vector <Tile*> tiles, std::ofstream& oss); 
    // <curTurn> \n
    // <builder0Data> \n
    // <builder1Data> \n
    // <builder2Data> \n
    // <builder3Data> \n
    // <board> \n
    // <geese> \n

    void help(); 
    // Valid commands: \n
    // board \n
    // status \n
    // residences \n
    // build-road <edge#> \n
    // build-res <housing#> \n
    // improve <housing#> \n
    // trade <colour> <give> <take> \n
    // next \n
    // save <file> \n
    // help \n
    
    void board(std::vector <Tile*> tiles, std::vector <Vertex*> vertices, std::vector <Edge*> edges); 
    // prints the board.

    ~Display();
};

#endif
