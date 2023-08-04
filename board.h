#ifndef BOARD
#define BOARD
//#include <bits/stdc++.h>
#include <string>
#include <vector>

class Tile {
    int num;             // 0-18
    std::string type;    // energy heat (E)
    int val;             // 2-12
    bool goose;
    std::vector <int> neighbourVertex;
    std::vector <int> neighbourEdge;

  public:
    void printNum() const; // This function is used for map print. It will print a ' ' if num is less than 10.
    void printNumber() const; // This function prints the num direcly.
    void printType() const;
    void printVal() const;
    bool occupy() const;
    int getNum() const;
    std::string getType() const;
    int getLength() const;
    int getVal() const;
    bool getGoose() const;
    std::vector <int> getNeighbourVertex() const;
    std::vector <int> getNeighbourEdge() const;
    void setNum(int num);
    void setType(std::string type);
    void setVal(int val);
    void setStatus(bool goose);
    void setVertex(int num);
    void setEdge(int num);
};

class Vertex {
    int num;
    bool occupy = false;
    std::string owner; // Can be either B (Blue), R (Red), O (Orange), Y (Yellow).
    std::string level; // Can be either B (Basement), H (House), T (Tower).
    std::vector <int> neighbourVertex;
    std::vector <int> neighbourEdge;

  public:
    void printNum() const;
    void printOwner() const;
    void printLevel() const;
    bool own() const;
    int getNum() const;
    std::string getOwner() const;
    std::string getLevel() const;
    std::vector <int> getNeighbourVertex() const;
    std::vector <int> getNeighbourEdge() const;
    void setNum(int num);
    void setStatus (bool occupy);
    void setOwner(std::string owner);
    void setLevel (std::string level);
    void setVertex(int num);
    void setEdge(int num);
    void build(std::string builder); // The string must be either B (Blue), R (Red), O (Orange), Y (Yellow).
    void improve();
};

class Edge {
    int num;
    bool occupy; 
    std::string owner; // Can be either B (Blue), R (Red), O (Orange), Y (Yellow).
    std::vector <int> neighbourVertex;
    std::vector <int> neighbourEdge;

  public:
    void printNum() const;
    void printOwner() const;
    bool own() const;
    int getNum() const;
    std::string getOwner() const;
    std::vector <int> getNeighbourVertex() const;
    std::vector <int> getNeighbourEdge() const;    
    void setNum(int num);
    void setStatus(bool occupy);
    void setOwner(std::string owner);
    void setVertex(int num);
    void setEdge(int num);
};

#endif
