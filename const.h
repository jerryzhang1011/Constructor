#ifndef CONST
#define CONST
#include <string>
class CONSTANTS{
    public: 
        static constexpr int ROADCOST[5] = {0,0,0,1,1};
        static constexpr int BASEMENTCOST[5] = {1,1,1,0,1};
        static constexpr int HOUSECOST[5] = {0,0,2,3,0};
        static constexpr int TOWERCOST[5] = {3,2,2,1,2};
        static constexpr int DECIMALPOWER[5] = {1,100,10000,1000000,100000000};
        static const int RESOURCE = 100;
        static const int RESOURCETYPE = -200;
        static const int ROADCOMMAND = 2;
        static const int BASEMENTCOMMAND = 3;
        static const int IMPROVECOMMAND = 4;
        static const int TRADECOMMAND = -5; 
        static int get_resource_code(std::string s) {
            if (s == "BRICK") {
                return 100;
            } else if (s == "ENERGY") {
                return 101;
            } else if (s == "GLASS") {
                return 102;
            } else if (s == "HEAT") {
                return 103;
            } else {
                return 104;
            }
        }
        static std::string get_resource_name(int s) {
            if (s == 0) {
                return "Brick";
            } else if (s == 1) {
                return "Energy";
            } else if (s == 2) {
                return "Glass";
            } else if (s == 3) {
                return "Heat";
            } else {
                return "WIFI";
            }
        }
    static int get_Player_code(std::string s) {
        if (s == "B") {
            return 0;
        } else if (s == "R") {
            return 1;
        } else if (s == "O") {
            return 2;
        } else if (s == "Y") {
            return 3;
        }
    }
    static std::string get_Player_string(int s) {
        if (s == 0) {
            return "Blue";
        } else if (s == 1) {
            return "Red";
        } else if (s == 2) {
            return "Orange";
        } else if (s == 3) {
            return "Yellow";
        }
        return "";

    }
};
#endif
