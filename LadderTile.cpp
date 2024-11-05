#include "../header/LadderTile.h"
using namespace std;

LadderTile::LadderTile() : Tile('L') {
    this->reward = 3;
}

LadderTile::LadderTile(int reward) : Tile('L') {
    this->reward = reward;
}

int LadderTile::getReward() {
    return reward;
}

void LadderTile::setReward(int reward) {
    this->reward = reward;
}