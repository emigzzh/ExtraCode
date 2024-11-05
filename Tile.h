#ifndef TILE_H
#define TILE_H

using namespace std;

class Tile {
    private:
        char type;

    public:
        Tile();
        Tile(char);

        char getType();
        void setType(char);

        virtual int getPenalty();  // Penalización por defecto
        virtual int getReward();
};

#endif