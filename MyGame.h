#ifndef MYGAME_H
#define MYGAME_H

#include "Tile.h"
#include <iostream>
#include <string>
#include <array>
using namespace std;

class MyGame {
    private:
        array<Tile, 30> map;
        int turn;
        int turnsLimit;
        string seed;

    public:
        void start();
        void createRandomMap();
};

#endif