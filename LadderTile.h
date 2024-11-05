#ifndef LADDERTILE_H
#define LADDERTILE_H

#include "Tile.h"
using namespace std;

class LadderTile : public Tile {
    private:
        int reward;

    public:
        LadderTile();
        LadderTile(int);

        int getReward() override;
        void setReward(int);
};

#endif