//#include <bits/stdc++.h>
#include "board.h"
#include <iostream>

// Methods in Tile
void Tile::printNum() const { 
    if (num < 10) std::cout << ' ' << num; 
    else std::cout << num;
}

void Tile::printNumber() const { std::cout << num; }

void Tile::printType() const { std::cout << type; }

void Tile::printVal() const { std::cout << val; }

bool Tile::occupy() const { return goose; }

int Tile::getNum() const { return num; }

std::string Tile::getType() const { return type; }

int Tile::getLength() const { return type.length(); }

int Tile::getVal() const { return val; }

bool Tile::getGoose() const { return goose; }

std::vector <int> Tile::getNeighbourVertex() const { return neighbourVertex; }

std::vector <int> Tile::getNeighbourEdge() const { return neighbourEdge; }

void Tile::setNum(int num) { this->num = num; }

void Tile::setType(std::string type) { this->type = type; }

void Tile::setVal(int val) { this->val = val; }

void Tile::setStatus(bool goose) { this->goose = goose; }

void Tile::setVertex(int num) {
    if (num == 0) {
        neighbourVertex.push_back(0);
        neighbourVertex.push_back(1);
        neighbourVertex.push_back(3);
        neighbourVertex.push_back(4);
        neighbourVertex.push_back(8);
        neighbourVertex.push_back(9);
    } else if (num == 1) {
        neighbourVertex.push_back(2);
        neighbourVertex.push_back(3);
        neighbourVertex.push_back(7);
        neighbourVertex.push_back(8);
        neighbourVertex.push_back(13);
        neighbourVertex.push_back(14);
    } else if (num == 2) {
        neighbourVertex.push_back(4);
        neighbourVertex.push_back(5);
        neighbourVertex.push_back(9);
        neighbourVertex.push_back(10);
        neighbourVertex.push_back(15);
        neighbourVertex.push_back(16);
    } else if (num == 3) {
        neighbourVertex.push_back(6);
        neighbourVertex.push_back(7);
        neighbourVertex.push_back(12);
        neighbourVertex.push_back(13);
        neighbourVertex.push_back(18);
        neighbourVertex.push_back(19);
    } else if (num == 4) {
        neighbourVertex.push_back(8);
        neighbourVertex.push_back(9);
        neighbourVertex.push_back(14);
        neighbourVertex.push_back(15);
        neighbourVertex.push_back(20);
        neighbourVertex.push_back(21);
    } else if (num == 5) {
        neighbourVertex.push_back(10);
        neighbourVertex.push_back(11);
        neighbourVertex.push_back(16);
        neighbourVertex.push_back(17);
        neighbourVertex.push_back(22);
        neighbourVertex.push_back(23);
    } else if (num == 6) {
        neighbourVertex.push_back(13);
        neighbourVertex.push_back(14);
        neighbourVertex.push_back(19);
        neighbourVertex.push_back(20);
        neighbourVertex.push_back(25);
        neighbourVertex.push_back(26);
    } else if (num == 7) {
        neighbourVertex.push_back(15);
        neighbourVertex.push_back(16);
        neighbourVertex.push_back(21);
        neighbourVertex.push_back(22);
        neighbourVertex.push_back(27);
        neighbourVertex.push_back(28);
    } else if (num == 8) {
        neighbourVertex.push_back(18);
        neighbourVertex.push_back(19);
        neighbourVertex.push_back(24);
        neighbourVertex.push_back(25);
        neighbourVertex.push_back(30);
        neighbourVertex.push_back(31);
    } else if (num == 9) {
        neighbourVertex.push_back(20);
        neighbourVertex.push_back(21);
        neighbourVertex.push_back(26);
        neighbourVertex.push_back(27);
        neighbourVertex.push_back(32);
        neighbourVertex.push_back(33);
    } else if (num == 10) {
        neighbourVertex.push_back(22);
        neighbourVertex.push_back(23);
        neighbourVertex.push_back(28);
        neighbourVertex.push_back(29);
        neighbourVertex.push_back(34);
        neighbourVertex.push_back(35);
    } else if (num == 11) {
        neighbourVertex.push_back(25);
        neighbourVertex.push_back(26);
        neighbourVertex.push_back(31);
        neighbourVertex.push_back(32);
        neighbourVertex.push_back(37);
        neighbourVertex.push_back(38);
    } else if (num == 12) {
        neighbourVertex.push_back(27);
        neighbourVertex.push_back(28);
        neighbourVertex.push_back(33);
        neighbourVertex.push_back(34);
        neighbourVertex.push_back(39);
        neighbourVertex.push_back(40);       
    } else if (num == 13) {
        neighbourVertex.push_back(30);
        neighbourVertex.push_back(31);
        neighbourVertex.push_back(36);
        neighbourVertex.push_back(37);
        neighbourVertex.push_back(42);
        neighbourVertex.push_back(43);
    } else if (num == 14) {
        neighbourVertex.push_back(32);
        neighbourVertex.push_back(33);
        neighbourVertex.push_back(38);
        neighbourVertex.push_back(39);
        neighbourVertex.push_back(44);
        neighbourVertex.push_back(45);
    } else if (num == 15) {
        neighbourVertex.push_back(34);
        neighbourVertex.push_back(35);
        neighbourVertex.push_back(40);
        neighbourVertex.push_back(41);
        neighbourVertex.push_back(46);
        neighbourVertex.push_back(47);
    } else if (num == 16) {
        neighbourVertex.push_back(37);
        neighbourVertex.push_back(38);
        neighbourVertex.push_back(43);
        neighbourVertex.push_back(44);
        neighbourVertex.push_back(48);
        neighbourVertex.push_back(49);
    } else if (num == 17) {
        neighbourVertex.push_back(39);
        neighbourVertex.push_back(40);
        neighbourVertex.push_back(45);
        neighbourVertex.push_back(46);
        neighbourVertex.push_back(50);
        neighbourVertex.push_back(51);
    } else {
        neighbourVertex.push_back(44);
        neighbourVertex.push_back(45);
        neighbourVertex.push_back(49);
        neighbourVertex.push_back(50);
        neighbourVertex.push_back(52);
        neighbourVertex.push_back(53);
    }
}

void Tile::setEdge(int num) {
        if (num == 0) {
        neighbourEdge.push_back(0);
        neighbourEdge.push_back(1);
        neighbourEdge.push_back(2);
        neighbourEdge.push_back(6);
        neighbourEdge.push_back(7);
        neighbourEdge.push_back(10);
    } else if (num == 1) {
        neighbourEdge.push_back(3);
        neighbourEdge.push_back(5);
        neighbourEdge.push_back(6);
        neighbourEdge.push_back(13);
        neighbourEdge.push_back(14);
        neighbourEdge.push_back(18);
    } else if (num == 2) {
        neighbourEdge.push_back(4);
        neighbourEdge.push_back(7);
        neighbourEdge.push_back(8);
        neighbourEdge.push_back(15);
        neighbourEdge.push_back(16);
        neighbourEdge.push_back(19);
    } else if (num == 3) {
        neighbourEdge.push_back(9);
        neighbourEdge.push_back(12);
        neighbourEdge.push_back(13);
        neighbourEdge.push_back(20);
        neighbourEdge.push_back(21);
        neighbourEdge.push_back(26);
    } else if (num == 4) {
        neighbourEdge.push_back(10);
        neighbourEdge.push_back(14);
        neighbourEdge.push_back(15);
        neighbourEdge.push_back(22);
        neighbourEdge.push_back(23);
        neighbourEdge.push_back(27);
    } else if (num == 5) {
        neighbourEdge.push_back(11);
        neighbourEdge.push_back(16);
        neighbourEdge.push_back(17);
        neighbourEdge.push_back(24);
        neighbourEdge.push_back(25);
        neighbourEdge.push_back(28);
    } else if (num == 6) {
        neighbourEdge.push_back(13);
        neighbourEdge.push_back(14);
        neighbourEdge.push_back(19);
        neighbourEdge.push_back(20);
        neighbourEdge.push_back(25);
        neighbourEdge.push_back(26);
    } else if (num == 7) {
        neighbourEdge.push_back(18);
        neighbourEdge.push_back(21);
        neighbourEdge.push_back(22);
        neighbourEdge.push_back(30);
        neighbourEdge.push_back(31);
        neighbourEdge.push_back(35);
    } else if (num == 8) {
        neighbourEdge.push_back(26);
        neighbourEdge.push_back(29);
        neighbourEdge.push_back(30);
        neighbourEdge.push_back(37);
        neighbourEdge.push_back(38);
        neighbourEdge.push_back(43);
    } else if (num == 9) {
        neighbourEdge.push_back(27);
        neighbourEdge.push_back(31);
        neighbourEdge.push_back(32);
        neighbourEdge.push_back(39);
        neighbourEdge.push_back(40);
        neighbourEdge.push_back(44);
    } else if (num == 10) {
        neighbourEdge.push_back(28);
        neighbourEdge.push_back(33);
        neighbourEdge.push_back(34);
        neighbourEdge.push_back(41);
        neighbourEdge.push_back(42);
        neighbourEdge.push_back(45);
    } else if (num == 11) {
        neighbourEdge.push_back(35);
        neighbourEdge.push_back(38);
        neighbourEdge.push_back(39);
        neighbourEdge.push_back(47);
        neighbourEdge.push_back(48);
        neighbourEdge.push_back(52);
    } else if (num == 12) {
        neighbourEdge.push_back(36);
        neighbourEdge.push_back(40);
        neighbourEdge.push_back(41);
        neighbourEdge.push_back(49);
        neighbourEdge.push_back(50);
        neighbourEdge.push_back(53);       
    } else if (num == 13) {
        neighbourEdge.push_back(43);
        neighbourEdge.push_back(46);
        neighbourEdge.push_back(47);
        neighbourEdge.push_back(54);
        neighbourEdge.push_back(55);
        neighbourEdge.push_back(60);
    } else if (num == 14) {
        neighbourEdge.push_back(44);
        neighbourEdge.push_back(48);
        neighbourEdge.push_back(49);
        neighbourEdge.push_back(56);
        neighbourEdge.push_back(57);
        neighbourEdge.push_back(61);
    } else if (num == 15) {
        neighbourEdge.push_back(45);
        neighbourEdge.push_back(50);
        neighbourEdge.push_back(51);
        neighbourEdge.push_back(58);
        neighbourEdge.push_back(59);
        neighbourEdge.push_back(62);
    } else if (num == 16) {
        neighbourEdge.push_back(52);
        neighbourEdge.push_back(55);
        neighbourEdge.push_back(56);
        neighbourEdge.push_back(63);
        neighbourEdge.push_back(64);
        neighbourEdge.push_back(67);
    } else if (num == 17) {
        neighbourEdge.push_back(53);
        neighbourEdge.push_back(57);
        neighbourEdge.push_back(58);
        neighbourEdge.push_back(65);
        neighbourEdge.push_back(66);
        neighbourEdge.push_back(68);
    } else {
        neighbourEdge.push_back(61);
        neighbourEdge.push_back(64);
        neighbourEdge.push_back(65);
        neighbourEdge.push_back(69);
        neighbourEdge.push_back(70);
        neighbourEdge.push_back(71);
    }
}

// Methods in Vertex
void Vertex::printNum() const { 
    if (num < 10) std::cout << ' ' << num; 
    else std::cout << num;
}

void Vertex::printOwner() const { std::cout << owner; }

void Vertex::printLevel() const { std::cout << level; }

bool Vertex::own() const { return occupy; }

int Vertex::getNum() const { return num; }

std::string Vertex::getOwner() const { return owner; }

std::string Vertex::getLevel() const { return level; }

std::vector <int> Vertex::getNeighbourVertex() const { return neighbourVertex; }

std::vector <int> Vertex::getNeighbourEdge() const { return neighbourEdge; }

void Vertex::setNum(int num) { this->num = num; }

void Vertex::setStatus (bool occupy) { this->occupy = occupy; }

void Vertex::setOwner(std::string owner) { this->owner = owner; }

void Vertex::setLevel(std::string level) { this->level = level; }

void Vertex::setVertex(int num) {
    if (num == 0) {
        neighbourVertex.push_back(1);
        neighbourVertex.push_back(3);
    } else if (num == 1) {
        neighbourVertex.push_back(0);
        neighbourVertex.push_back(4);
    } else if (num == 2) {
        neighbourVertex.push_back(3);
        neighbourVertex.push_back(7);
    } else if (num == 3) {
        neighbourVertex.push_back(0);
        neighbourVertex.push_back(2);
        neighbourVertex.push_back(8);
    } else if (num == 4) {
        neighbourVertex.push_back(1);
        neighbourVertex.push_back(3);
        neighbourVertex.push_back(9);
    } else if (num == 5) {
        neighbourVertex.push_back(4);
        neighbourVertex.push_back(10);
    } else if (num == 6) {
        neighbourVertex.push_back(7);
        neighbourVertex.push_back(12);
    } else if (num == 7) {
        neighbourVertex.push_back(2);
        neighbourVertex.push_back(6);
        neighbourVertex.push_back(13);
    } else if (num == 8) {
        neighbourVertex.push_back(3);
        neighbourVertex.push_back(9);
        neighbourVertex.push_back(14);
    } else if (num == 9) {
        neighbourVertex.push_back(4);
        neighbourVertex.push_back(8);
        neighbourVertex.push_back(15);
    } else if (num == 10) {
        neighbourVertex.push_back(5);
        neighbourVertex.push_back(11);
        neighbourVertex.push_back(16);
    } else if (num == 11) {
        neighbourVertex.push_back(10);
        neighbourVertex.push_back(17);
    } else if (num == 12) {
        neighbourVertex.push_back(6);
        neighbourVertex.push_back(18);
    } else if (num == 13) {
        neighbourVertex.push_back(7);
        neighbourVertex.push_back(14);
        neighbourVertex.push_back(19);
    } else if (num == 14) {
        neighbourVertex.push_back(8);
        neighbourVertex.push_back(13);
        neighbourVertex.push_back(20);
    } else if (num == 15) {
        neighbourVertex.push_back(9);
        neighbourVertex.push_back(16);
        neighbourVertex.push_back(21);
    } else if (num == 16) {
        neighbourVertex.push_back(10);
        neighbourVertex.push_back(15);
        neighbourVertex.push_back(22);
    } else if (num == 17) {
        neighbourVertex.push_back(11);
        neighbourVertex.push_back(23);
    } else if (num == 18) {
        neighbourVertex.push_back(12);
        neighbourVertex.push_back(19);
        neighbourVertex.push_back(24);
    } else if (num == 19) {
        neighbourVertex.push_back(13);
        neighbourVertex.push_back(18);
        neighbourVertex.push_back(25);
    } else if (num == 20) {
        neighbourVertex.push_back(14);
        neighbourVertex.push_back(21);
        neighbourVertex.push_back(26);
    } else if (num == 21) {
        neighbourVertex.push_back(15);
        neighbourVertex.push_back(20);
        neighbourVertex.push_back(27);
    } else if (num == 22) {
        neighbourVertex.push_back(16);
        neighbourVertex.push_back(23);
        neighbourVertex.push_back(28);
    } else if (num == 23) {
        neighbourVertex.push_back(17);
        neighbourVertex.push_back(22);
        neighbourVertex.push_back(29);
    } else if (num == 24) {
        neighbourVertex.push_back(18);
        neighbourVertex.push_back(30);
    } else if (num == 25) {
        neighbourVertex.push_back(19);
        neighbourVertex.push_back(26);
        neighbourVertex.push_back(31);
    } else if (num == 26) {
        neighbourVertex.push_back(20);
        neighbourVertex.push_back(25);
        neighbourVertex.push_back(32);
    } else if (num == 27) {
        neighbourVertex.push_back(21);
        neighbourVertex.push_back(28);
        neighbourVertex.push_back(33);
    } else if (num == 28) {
        neighbourVertex.push_back(22);
        neighbourVertex.push_back(27);
        neighbourVertex.push_back(34);
    } else if (num == 29) {
        neighbourVertex.push_back(23);
        neighbourVertex.push_back(35);
    } else if (num == 30) {
        neighbourVertex.push_back(24);
        neighbourVertex.push_back(31);
        neighbourVertex.push_back(36);
    } else if (num == 31) {
        neighbourVertex.push_back(25);
        neighbourVertex.push_back(30);
        neighbourVertex.push_back(37);
    } else if (num == 32) {
        neighbourVertex.push_back(36);
        neighbourVertex.push_back(33);
        neighbourVertex.push_back(38);
    } else if (num == 33) {
        neighbourVertex.push_back(27);
        neighbourVertex.push_back(32);
        neighbourVertex.push_back(39);
    } else if (num == 34) {
        neighbourVertex.push_back(28);
        neighbourVertex.push_back(35);
        neighbourVertex.push_back(40);
    } else if (num == 35) {
        neighbourVertex.push_back(29);
        neighbourVertex.push_back(34);
        neighbourVertex.push_back(40);
    } else if (num == 36) {
        neighbourVertex.push_back(30);
        neighbourVertex.push_back(42);
    } else if (num == 37) {
        neighbourVertex.push_back(31);
        neighbourVertex.push_back(38);
        neighbourVertex.push_back(43);
    } else if (num == 38) {
        neighbourVertex.push_back(32);
        neighbourVertex.push_back(37);
        neighbourVertex.push_back(44);
    } else if (num == 39) {
        neighbourVertex.push_back(33);
        neighbourVertex.push_back(40);
        neighbourVertex.push_back(45);
    } else if (num == 40) {
        neighbourVertex.push_back(34);
        neighbourVertex.push_back(39);
        neighbourVertex.push_back(46);
    } else if (num == 41) {
        neighbourVertex.push_back(35);
        neighbourVertex.push_back(47);
    } else if (num == 42) {
        neighbourVertex.push_back(36);
        neighbourVertex.push_back(43);
    } else if (num == 43) {
        neighbourVertex.push_back(37);
        neighbourVertex.push_back(42);
        neighbourVertex.push_back(48);
    } else if (num == 44) {
        neighbourVertex.push_back(38);
        neighbourVertex.push_back(45);
        neighbourVertex.push_back(49);
    } else if (num == 45) {
        neighbourVertex.push_back(39);
        neighbourVertex.push_back(44);
        neighbourVertex.push_back(50);
    } else if (num == 46) {
        neighbourVertex.push_back(40);
        neighbourVertex.push_back(47);
        neighbourVertex.push_back(51);
    } else if (num == 47) {
        neighbourVertex.push_back(41);
        neighbourVertex.push_back(46);
    } else if (num == 48) {
        neighbourVertex.push_back(43);
        neighbourVertex.push_back(49);
    } else if (num == 49) {
        neighbourVertex.push_back(44);
        neighbourVertex.push_back(48);
        neighbourVertex.push_back(52);
    } else if (num == 50) {
        neighbourVertex.push_back(45);
        neighbourVertex.push_back(51);
        neighbourVertex.push_back(53);
    } else if (num == 51) {
        neighbourVertex.push_back(46);
        neighbourVertex.push_back(50);
    } else if (num == 52) {
        neighbourVertex.push_back(49);
        neighbourVertex.push_back(53);
    } else {
        neighbourVertex.push_back(50);
        neighbourVertex.push_back(52);
    }
}

void Vertex::setEdge(int num) {
    if (num == 0) {
        neighbourEdge.push_back(0);
        neighbourEdge.push_back(1);
    } else if (num == 1) {
        neighbourEdge.push_back(0);
        neighbourEdge.push_back(2);
    } else if (num == 2) {
        neighbourEdge.push_back(3);
        neighbourEdge.push_back(5);
    } else if (num == 3) {
        neighbourEdge.push_back(1);
        neighbourEdge.push_back(3);
        neighbourEdge.push_back(6);
    } else if (num == 4) {
        neighbourEdge.push_back(2);
        neighbourEdge.push_back(4);
        neighbourEdge.push_back(7);
    } else if (num == 5) {
        neighbourEdge.push_back(4);
        neighbourEdge.push_back(8);
    } else if (num == 6) {
        neighbourEdge.push_back(9);
        neighbourEdge.push_back(12);
    } else if (num == 7) {
        neighbourEdge.push_back(5);
        neighbourEdge.push_back(9);
        neighbourEdge.push_back(13);
    } else if (num == 8) {
        neighbourEdge.push_back(6);
        neighbourEdge.push_back(10);
        neighbourEdge.push_back(14);
    } else if (num == 9) {
        neighbourEdge.push_back(7);
        neighbourEdge.push_back(10);
        neighbourEdge.push_back(15);
    } else if (num == 10) {
        neighbourEdge.push_back(8);
        neighbourEdge.push_back(11);
        neighbourEdge.push_back(16);
    } else if (num == 11) {
        neighbourEdge.push_back(11);
        neighbourEdge.push_back(17);
    } else if (num == 12) {
        neighbourEdge.push_back(12);
        neighbourEdge.push_back(20);
    } else if (num == 13) {
        neighbourEdge.push_back(13);
        neighbourEdge.push_back(18);
        neighbourEdge.push_back(21);
    } else if (num == 14) {
        neighbourEdge.push_back(14);
        neighbourEdge.push_back(18);
        neighbourEdge.push_back(22);
    } else if (num == 15) {
        neighbourEdge.push_back(15);
        neighbourEdge.push_back(19);
        neighbourEdge.push_back(23);
    } else if (num == 16) {
        neighbourEdge.push_back(16);
        neighbourEdge.push_back(19);
        neighbourEdge.push_back(24);
    } else if (num == 17) {
        neighbourEdge.push_back(17);
        neighbourEdge.push_back(25);
    } else if (num == 18) {
        neighbourEdge.push_back(20);
        neighbourEdge.push_back(26);
        neighbourEdge.push_back(29);
    } else if (num == 19) {
        neighbourEdge.push_back(21);
        neighbourEdge.push_back(26);
        neighbourEdge.push_back(30);
    } else if (num == 20) {
        neighbourEdge.push_back(22);
        neighbourEdge.push_back(27);
        neighbourEdge.push_back(31);
    } else if (num == 21) {
        neighbourEdge.push_back(23);
        neighbourEdge.push_back(27);
        neighbourEdge.push_back(32);
    } else if (num == 22) {
        neighbourEdge.push_back(24);
        neighbourEdge.push_back(28);
        neighbourEdge.push_back(33);
    } else if (num == 23) {
        neighbourEdge.push_back(25);
        neighbourEdge.push_back(28);
        neighbourEdge.push_back(34);
    } else if (num == 24) {
        neighbourEdge.push_back(29);
        neighbourEdge.push_back(37);
    } else if (num == 25) {
        neighbourEdge.push_back(30);
        neighbourEdge.push_back(35);
        neighbourEdge.push_back(38);
    } else if (num == 26) {
        neighbourEdge.push_back(31);
        neighbourEdge.push_back(35);
        neighbourEdge.push_back(39);
    } else if (num == 27) {
        neighbourEdge.push_back(32);
        neighbourEdge.push_back(36);
        neighbourEdge.push_back(40);
    } else if (num == 28) {
        neighbourEdge.push_back(33);
        neighbourEdge.push_back(36);
        neighbourEdge.push_back(41);
    } else if (num == 29) {
        neighbourEdge.push_back(34);
        neighbourEdge.push_back(42);
    } else if (num == 30) {
        neighbourEdge.push_back(37);
        neighbourEdge.push_back(43);
        neighbourEdge.push_back(46);
    } else if (num == 31) {
        neighbourEdge.push_back(38);
        neighbourEdge.push_back(43);
        neighbourEdge.push_back(47);
    } else if (num == 32) {
        neighbourEdge.push_back(39);
        neighbourEdge.push_back(44);
        neighbourEdge.push_back(48);
    } else if (num == 33) {
        neighbourEdge.push_back(40);
        neighbourEdge.push_back(44);
        neighbourEdge.push_back(49);
    } else if (num == 34) {
        neighbourEdge.push_back(41);
        neighbourEdge.push_back(45);
        neighbourEdge.push_back(50);
    } else if (num == 35) {
        neighbourEdge.push_back(42);
        neighbourEdge.push_back(45);
        neighbourEdge.push_back(51);
    } else if (num == 36) {
        neighbourEdge.push_back(46);
        neighbourEdge.push_back(54);
    } else if (num == 37) {
        neighbourEdge.push_back(47);
        neighbourEdge.push_back(52);
        neighbourEdge.push_back(55);
    } else if (num == 38) {
        neighbourEdge.push_back(48);
        neighbourEdge.push_back(52);
        neighbourEdge.push_back(56);
    } else if (num == 39) {
        neighbourEdge.push_back(49);
        neighbourEdge.push_back(53);
        neighbourEdge.push_back(57);
    } else if (num == 40) {
        neighbourEdge.push_back(50);
        neighbourEdge.push_back(53);
        neighbourEdge.push_back(58);
    } else if (num == 41) {
        neighbourEdge.push_back(51);
        neighbourEdge.push_back(59);
    } else if (num == 42) {
        neighbourEdge.push_back(54);
        neighbourEdge.push_back(60);
    } else if (num == 43) {
        neighbourEdge.push_back(55);
        neighbourEdge.push_back(60);
        neighbourEdge.push_back(63);
    } else if (num == 44) {
        neighbourEdge.push_back(56);
        neighbourEdge.push_back(61);
        neighbourEdge.push_back(64);
    } else if (num == 45) {
        neighbourEdge.push_back(57);
        neighbourEdge.push_back(61);
        neighbourEdge.push_back(65);
    } else if (num == 46) {
        neighbourEdge.push_back(58);
        neighbourEdge.push_back(62);
        neighbourEdge.push_back(66);
    } else if (num == 47) {
        neighbourEdge.push_back(59);
        neighbourEdge.push_back(62);
    } else if (num == 48) {
        neighbourEdge.push_back(63);
        neighbourEdge.push_back(67);
    } else if (num == 49) {
        neighbourEdge.push_back(64);
        neighbourEdge.push_back(67);
        neighbourEdge.push_back(69);
    } else if (num == 50) {
        neighbourEdge.push_back(65);
        neighbourEdge.push_back(68);
        neighbourEdge.push_back(70);
    } else if (num == 51) {
        neighbourEdge.push_back(66);
        neighbourEdge.push_back(68);
    } else if (num == 52) {
        neighbourEdge.push_back(69);
        neighbourEdge.push_back(71);
    } else {
        neighbourEdge.push_back(70);
        neighbourEdge.push_back(71);
    }
}

void Vertex::build (std::string builder) {
    occupy = true;
    owner = builder;
    level = "B";
    return;
}

void Vertex::improve () {
    if (level == "B") {
        level = "H";
    } else if (level == "H") {
        level = "T";
    } else {
        return;
    }
}

// Methods in Edge
void Edge::printNum() const { 
    if (num < 10) std::cout << ' ' << num; 
    else std::cout << num;
}

void Edge::printOwner() const { std::cout << owner; }

bool Edge::own() const { return occupy; }

int Edge::getNum() const { return num; }

std::string Edge::getOwner() const { return owner; }

std::vector <int> Edge::getNeighbourVertex() const { return neighbourVertex; }

std::vector <int> Edge::getNeighbourEdge() const { return neighbourEdge; }

void Edge::setNum(int num) { this->num = num; }

void Edge::setStatus (bool occupy) { this->occupy = occupy; }

void Edge::setOwner(std::string owner) { this->owner = owner; }

void Edge::setVertex(int num) {
    if (num == 0) {
        neighbourVertex.push_back(0);
        neighbourVertex.push_back(1);
    } else if (num == 1) {
        neighbourVertex.push_back(0);
        neighbourVertex.push_back(3);
    } else if (num == 2) {
        neighbourVertex.push_back(1);
        neighbourVertex.push_back(4);
    } else if (num == 3) {
        neighbourVertex.push_back(2);
        neighbourVertex.push_back(3);
    } else if (num == 4) {
        neighbourVertex.push_back(4);
        neighbourVertex.push_back(5);
    } else if (num == 5) {
        neighbourVertex.push_back(2);
        neighbourVertex.push_back(7);
    } else if (num == 6) {
        neighbourVertex.push_back(3);
        neighbourVertex.push_back(8);
    } else if (num == 7) {
        neighbourVertex.push_back(4);
        neighbourVertex.push_back(9);
    } else if (num == 8) {
        neighbourVertex.push_back(5);
        neighbourVertex.push_back(10);
    } else if (num == 9) {
        neighbourVertex.push_back(6);
        neighbourVertex.push_back(7);
    } else if (num == 10) {
        neighbourVertex.push_back(8);
        neighbourVertex.push_back(9);
    } else if (num == 11) {
        neighbourVertex.push_back(10);
        neighbourVertex.push_back(11);
    } else if (num == 12) {
        neighbourVertex.push_back(6);
        neighbourVertex.push_back(12);
    } else if (num == 13) {
        neighbourVertex.push_back(7);
        neighbourVertex.push_back(13);
    } else if (num == 14) {
        neighbourVertex.push_back(8);
        neighbourVertex.push_back(14);
    } else if (num == 15) {
        neighbourVertex.push_back(9);
        neighbourVertex.push_back(15);
    } else if (num == 16) {
        neighbourVertex.push_back(10);
        neighbourVertex.push_back(16);
    } else if (num == 17) {
        neighbourVertex.push_back(11);
        neighbourVertex.push_back(17);
    } else if (num == 18) {
        neighbourVertex.push_back(13);
        neighbourVertex.push_back(14);
    } else if (num == 19) {
        neighbourVertex.push_back(15);
        neighbourVertex.push_back(16);
    } else if (num == 20) {
        neighbourVertex.push_back(12);
        neighbourVertex.push_back(18);
    } else if (num == 21) {
        neighbourVertex.push_back(13);
        neighbourVertex.push_back(19);
    } else if (num == 22) {
        neighbourVertex.push_back(14);
        neighbourVertex.push_back(20);
    } else if (num == 23) {
        neighbourVertex.push_back(15);
        neighbourVertex.push_back(21);
    } else if (num == 24) {
        neighbourVertex.push_back(16);
        neighbourVertex.push_back(22);
    } else if (num == 25) {
        neighbourVertex.push_back(17);
        neighbourVertex.push_back(23);
    } else if (num == 26) {
        neighbourVertex.push_back(18);
        neighbourVertex.push_back(19);
    } else if (num == 27) {
        neighbourVertex.push_back(20);
        neighbourVertex.push_back(21);
    } else if (num == 28) {
        neighbourVertex.push_back(22);
        neighbourVertex.push_back(23);
    } else if (num == 29) {
        neighbourVertex.push_back(18);
        neighbourVertex.push_back(24);
    } else if (num == 30) {
        neighbourVertex.push_back(19);
        neighbourVertex.push_back(25);
    } else if (num == 31) {
        neighbourVertex.push_back(20);
        neighbourVertex.push_back(26);
    } else if (num == 32) {
        neighbourVertex.push_back(21);
        neighbourVertex.push_back(27);
    } else if (num == 33) {
        neighbourVertex.push_back(22);
        neighbourVertex.push_back(28);
    } else if (num == 34) {
        neighbourVertex.push_back(23);
        neighbourVertex.push_back(29);
    } else if (num == 35) {
        neighbourVertex.push_back(25);
        neighbourVertex.push_back(26);
    } else if (num == 36) {
        neighbourVertex.push_back(27);
        neighbourVertex.push_back(28);
    } else if (num == 37) {
        neighbourVertex.push_back(24);
        neighbourVertex.push_back(30);
    } else if (num == 38) {
        neighbourVertex.push_back(25);
        neighbourVertex.push_back(31);
    } else if (num == 39) {
        neighbourVertex.push_back(26);
        neighbourVertex.push_back(32);
    } else if (num == 40) {
        neighbourVertex.push_back(27);
        neighbourVertex.push_back(33);
    } else if (num == 41) {
        neighbourVertex.push_back(28);
        neighbourVertex.push_back(34);
    } else if (num == 42) {
        neighbourVertex.push_back(29);
        neighbourVertex.push_back(35);
    } else if (num == 43) {
        neighbourVertex.push_back(30);
        neighbourVertex.push_back(31);
    } else if (num == 44) {
        neighbourVertex.push_back(32);
        neighbourVertex.push_back(33);
    } else if (num == 45) {
        neighbourVertex.push_back(34);
        neighbourVertex.push_back(35);
    } else if (num == 46) {
        neighbourVertex.push_back(30);
        neighbourVertex.push_back(36);
    } else if (num == 47) {
        neighbourVertex.push_back(31);
        neighbourVertex.push_back(37);
    } else if (num == 48) {
        neighbourVertex.push_back(32);
        neighbourVertex.push_back(38);
    } else if (num == 49) {
        neighbourVertex.push_back(33);
        neighbourVertex.push_back(39);
    } else if (num == 50) {
        neighbourVertex.push_back(34);
        neighbourVertex.push_back(40);
    } else if (num == 51) {
        neighbourVertex.push_back(35);
        neighbourVertex.push_back(41);
    } else if (num == 52) {
        neighbourVertex.push_back(37);
        neighbourVertex.push_back(38);
    } else if (num == 53) {
        neighbourVertex.push_back(39);
        neighbourVertex.push_back(40);
    } else if (num == 54) {
        neighbourVertex.push_back(36);
        neighbourVertex.push_back(42);
    } else if (num == 55) {
        neighbourVertex.push_back(37);
        neighbourVertex.push_back(43);
    } else if (num == 56) {
        neighbourVertex.push_back(38);
        neighbourVertex.push_back(44);
    } else if (num == 57) {
        neighbourVertex.push_back(39);
        neighbourVertex.push_back(45);
    } else if (num == 58) {
        neighbourVertex.push_back(40);
        neighbourVertex.push_back(46);
    } else if (num == 59) {
        neighbourVertex.push_back(41);
        neighbourVertex.push_back(47);
    } else if (num == 60) {
        neighbourVertex.push_back(42);
        neighbourVertex.push_back(43);
    } else if (num == 61) {
        neighbourVertex.push_back(44);
        neighbourVertex.push_back(45);
    } else if (num == 62) {
        neighbourVertex.push_back(46);
        neighbourVertex.push_back(47);
    } else if (num == 63) {
        neighbourVertex.push_back(43);
        neighbourVertex.push_back(48);
    } else if (num == 64) {
        neighbourVertex.push_back(44);
        neighbourVertex.push_back(49);
    } else if (num == 65) {
        neighbourVertex.push_back(45);
        neighbourVertex.push_back(50);
    } else if (num == 66) {
        neighbourVertex.push_back(46);
        neighbourVertex.push_back(51);
    } else if (num == 67) {
        neighbourVertex.push_back(48);
        neighbourVertex.push_back(49);
    } else if (num == 68) {
        neighbourVertex.push_back(50);
        neighbourVertex.push_back(51);
    } else if (num == 69) {
        neighbourVertex.push_back(49);
        neighbourVertex.push_back(52);
    } else if (num == 70) {
        neighbourVertex.push_back(50);
        neighbourVertex.push_back(53);
    } else {
        neighbourVertex.push_back(52);
        neighbourVertex.push_back(53);
    }

}

void Edge::setEdge(int num) {
    if (num == 0) {
        neighbourEdge.push_back(1);
        neighbourEdge.push_back(2);
    } else if (num == 1) {
        neighbourEdge.push_back(0);
        neighbourEdge.push_back(3);
        neighbourEdge.push_back(6);
    } else if (num == 2) {
        neighbourEdge.push_back(0);
        neighbourEdge.push_back(4);
        neighbourEdge.push_back(7);
    } else if (num == 3) {
        neighbourEdge.push_back(1);
        neighbourEdge.push_back(5);
        neighbourEdge.push_back(6);
    } else if (num == 4) {
        neighbourEdge.push_back(2);
        neighbourEdge.push_back(7);
        neighbourEdge.push_back(8);
    } else if (num == 5) {
        neighbourEdge.push_back(3);
        neighbourEdge.push_back(9);
        neighbourEdge.push_back(13);
    } else if (num == 6) {
        neighbourEdge.push_back(1);
        neighbourEdge.push_back(3);
        neighbourEdge.push_back(10);
        neighbourEdge.push_back(14);
    } else if (num == 7) {
        neighbourEdge.push_back(2);
        neighbourEdge.push_back(4);
        neighbourEdge.push_back(10);
        neighbourEdge.push_back(15);
    } else if (num == 8) {
        neighbourEdge.push_back(4);
        neighbourEdge.push_back(11);
        neighbourEdge.push_back(16);
    } else if (num == 9) {
        neighbourEdge.push_back(5);
        neighbourEdge.push_back(12);
        neighbourEdge.push_back(13);
    } else if (num == 10) {
        neighbourEdge.push_back(6);
        neighbourEdge.push_back(7);
        neighbourEdge.push_back(14);
        neighbourEdge.push_back(15);
    } else if (num == 11) {
        neighbourEdge.push_back(8);
        neighbourEdge.push_back(16);
        neighbourEdge.push_back(17);
    } else if (num == 12) {
        neighbourEdge.push_back(9);
        neighbourEdge.push_back(20);
    } else if (num == 13) {
        neighbourEdge.push_back(5);
        neighbourEdge.push_back(9);
        neighbourEdge.push_back(18);
        neighbourEdge.push_back(21);
    } else if (num == 14) {
        neighbourEdge.push_back(6);
        neighbourEdge.push_back(10);
        neighbourEdge.push_back(18);
        neighbourEdge.push_back(22);
    } else if (num == 15) {
        neighbourEdge.push_back(7);
        neighbourEdge.push_back(10);
        neighbourEdge.push_back(19);
        neighbourEdge.push_back(23);
    } else if (num == 16) {
        neighbourEdge.push_back(8);
        neighbourEdge.push_back(11);
        neighbourEdge.push_back(19);
        neighbourEdge.push_back(24);
    } else if (num == 17) {
        neighbourEdge.push_back(11);
        neighbourEdge.push_back(25);
    } else if (num == 18) {
        neighbourEdge.push_back(13);
        neighbourEdge.push_back(14);
        neighbourEdge.push_back(21);
        neighbourEdge.push_back(22);
    } else if (num == 19) {
        neighbourEdge.push_back(15);
        neighbourEdge.push_back(16);
        neighbourEdge.push_back(23);
        neighbourEdge.push_back(24);
    } else if (num == 20) {
        neighbourEdge.push_back(12);
        neighbourEdge.push_back(26);
        neighbourEdge.push_back(29);
    } else if (num == 21) {
        neighbourEdge.push_back(13);
        neighbourEdge.push_back(18);
        neighbourEdge.push_back(26);
        neighbourEdge.push_back(30);
    } else if (num == 22) {
        neighbourEdge.push_back(14);
        neighbourEdge.push_back(18);
        neighbourEdge.push_back(27);
        neighbourEdge.push_back(31);
    } else if (num == 23) {
        neighbourEdge.push_back(15);
        neighbourEdge.push_back(19);
        neighbourEdge.push_back(27);
        neighbourEdge.push_back(32);
    } else if (num == 24) {
        neighbourEdge.push_back(16);
        neighbourEdge.push_back(19);
        neighbourEdge.push_back(28);
        neighbourEdge.push_back(33);
    } else if (num == 25) {
        neighbourEdge.push_back(17);
        neighbourEdge.push_back(28);
        neighbourEdge.push_back(34);
    } else if (num == 26) {
        neighbourEdge.push_back(20);
        neighbourEdge.push_back(21);
        neighbourEdge.push_back(29);
        neighbourEdge.push_back(30);
    } else if (num == 27) {
        neighbourEdge.push_back(22);
        neighbourEdge.push_back(23);
        neighbourEdge.push_back(31);
        neighbourEdge.push_back(32);
    } else if (num == 28) {
        neighbourEdge.push_back(24);
        neighbourEdge.push_back(25);
        neighbourEdge.push_back(33);
        neighbourEdge.push_back(34);
    } else if (num == 29) {
        neighbourEdge.push_back(20);
        neighbourEdge.push_back(26);
        neighbourEdge.push_back(37);
    } else if (num == 30) {
        neighbourEdge.push_back(21);
        neighbourEdge.push_back(26);
        neighbourEdge.push_back(35);
        neighbourEdge.push_back(38);
    } else if (num == 31) {
        neighbourEdge.push_back(22);
        neighbourEdge.push_back(27);
        neighbourEdge.push_back(35);
        neighbourEdge.push_back(39);
    } else if (num == 32) {
        neighbourEdge.push_back(23);
        neighbourEdge.push_back(27);
        neighbourEdge.push_back(36);
        neighbourEdge.push_back(40);
    } else if (num == 33) {
        neighbourEdge.push_back(24);
        neighbourEdge.push_back(28);
        neighbourEdge.push_back(36);
        neighbourEdge.push_back(41);
    } else if (num == 34) {
        neighbourEdge.push_back(25);
        neighbourEdge.push_back(28);
        neighbourEdge.push_back(42);
    } else if (num == 35) {
        neighbourEdge.push_back(30);
        neighbourEdge.push_back(31);
        neighbourEdge.push_back(38);
        neighbourEdge.push_back(39);
    } else if (num == 36) {
        neighbourEdge.push_back(32);
        neighbourEdge.push_back(33);
        neighbourEdge.push_back(40);
        neighbourEdge.push_back(41);
    } else if (num == 37) {
        neighbourEdge.push_back(29);
        neighbourEdge.push_back(43);
        neighbourEdge.push_back(46);
    } else if (num == 38) {
        neighbourEdge.push_back(30);
        neighbourEdge.push_back(35);
        neighbourEdge.push_back(43);
        neighbourEdge.push_back(47);
    } else if (num == 39) {
        neighbourEdge.push_back(31);
        neighbourEdge.push_back(35);
        neighbourEdge.push_back(44);
        neighbourEdge.push_back(48);
    } else if (num == 40) {
        neighbourEdge.push_back(32);
        neighbourEdge.push_back(36);
        neighbourEdge.push_back(44);
        neighbourEdge.push_back(49);
    } else if (num == 41) {
        neighbourEdge.push_back(33);
        neighbourEdge.push_back(36);
        neighbourEdge.push_back(45);
        neighbourEdge.push_back(50);
    } else if (num == 42) {
        neighbourEdge.push_back(34);
        neighbourEdge.push_back(45);
        neighbourEdge.push_back(51);
    } else if (num == 43) {
        neighbourEdge.push_back(37);
        neighbourEdge.push_back(38);
        neighbourEdge.push_back(46);
        neighbourEdge.push_back(47);
    } else if (num == 44) {
        neighbourEdge.push_back(39);
        neighbourEdge.push_back(40);
        neighbourEdge.push_back(48);
        neighbourEdge.push_back(49);
    } else if (num == 45) {
        neighbourEdge.push_back(41);
        neighbourEdge.push_back(42);
        neighbourEdge.push_back(50);
        neighbourEdge.push_back(51);
    } else if (num == 46) {
        neighbourEdge.push_back(37);
        neighbourEdge.push_back(43);
        neighbourEdge.push_back(54);
    } else if (num == 47) {
        neighbourEdge.push_back(38);
        neighbourEdge.push_back(43);
        neighbourEdge.push_back(52);
        neighbourEdge.push_back(55);
    } else if (num == 48) {
        neighbourEdge.push_back(39);
        neighbourEdge.push_back(44);
        neighbourEdge.push_back(52);
        neighbourEdge.push_back(56);
    } else if (num == 49) {
        neighbourEdge.push_back(40);
        neighbourEdge.push_back(44);
        neighbourEdge.push_back(53);
        neighbourEdge.push_back(57);
    } else if (num == 50) {
        neighbourEdge.push_back(41);
        neighbourEdge.push_back(45);
        neighbourEdge.push_back(53);
        neighbourEdge.push_back(58);
    } else if (num == 51) {
        neighbourEdge.push_back(42);
        neighbourEdge.push_back(45);
        neighbourEdge.push_back(59);
    } else if (num == 52) {
        neighbourEdge.push_back(47);
        neighbourEdge.push_back(48);
        neighbourEdge.push_back(55);
        neighbourEdge.push_back(56);
    } else if (num == 53) {
        neighbourEdge.push_back(49);
        neighbourEdge.push_back(50);
        neighbourEdge.push_back(57);
        neighbourEdge.push_back(58);
    } else if (num == 54) {
        neighbourEdge.push_back(46);
        neighbourEdge.push_back(60);
    } else if (num == 55) {
        neighbourEdge.push_back(47);
        neighbourEdge.push_back(52);
        neighbourEdge.push_back(60);
        neighbourEdge.push_back(63);
    } else if (num == 56) {
        neighbourEdge.push_back(48);
        neighbourEdge.push_back(52);
        neighbourEdge.push_back(61);
        neighbourEdge.push_back(64);
    } else if (num == 57) {
        neighbourEdge.push_back(49);
        neighbourEdge.push_back(53);
        neighbourEdge.push_back(61);
        neighbourEdge.push_back(65);
    } else if (num == 58) {
        neighbourEdge.push_back(50);
        neighbourEdge.push_back(53);
        neighbourEdge.push_back(62);
        neighbourEdge.push_back(66);
    } else if (num == 59) {
        neighbourEdge.push_back(51);
        neighbourEdge.push_back(62);
    } else if (num == 60) {
        neighbourEdge.push_back(54);
        neighbourEdge.push_back(55);
        neighbourEdge.push_back(63);
    } else if (num == 61) {
        neighbourEdge.push_back(56);
        neighbourEdge.push_back(57);
        neighbourEdge.push_back(64);
        neighbourEdge.push_back(65);
    } else if (num == 62) {
        neighbourEdge.push_back(58);
        neighbourEdge.push_back(59);
        neighbourEdge.push_back(66);
    } else if (num == 63) {
        neighbourEdge.push_back(55);
        neighbourEdge.push_back(60);
        neighbourEdge.push_back(67);
    } else if (num == 64) {
        neighbourEdge.push_back(56);
        neighbourEdge.push_back(61);
        neighbourEdge.push_back(67);
        neighbourEdge.push_back(69);
    } else if (num == 65) {
        neighbourEdge.push_back(57);
        neighbourEdge.push_back(61);
        neighbourEdge.push_back(68);
        neighbourEdge.push_back(70);
    } else if (num == 66) {
        neighbourEdge.push_back(58);
        neighbourEdge.push_back(62);
        neighbourEdge.push_back(68);
    } else if (num == 67) {
        neighbourEdge.push_back(63);
        neighbourEdge.push_back(64);
        neighbourEdge.push_back(69);
    } else if (num == 68) {
        neighbourEdge.push_back(65);
        neighbourEdge.push_back(66);
        neighbourEdge.push_back(70);
    } else if (num == 69) {
        neighbourEdge.push_back(64);
        neighbourEdge.push_back(67);
        neighbourEdge.push_back(71);
    } else if (num == 70) {
        neighbourEdge.push_back(65);
        neighbourEdge.push_back(68);
        neighbourEdge.push_back(71);
    } else {
        neighbourEdge.push_back(69);
        neighbourEdge.push_back(70);
    }
}
