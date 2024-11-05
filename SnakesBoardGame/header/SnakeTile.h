#ifndef SNAKETILE_H
#define SNAKETILE_H

#include "Tile.h"
using namespace std;

class SnakeTile : public Tile {
    private:
        int penalty;

    public:
        SnakeTile();
        SnakeTile(int);

        int getPenalty() override;
        void setPenalty(int);
};

#endif