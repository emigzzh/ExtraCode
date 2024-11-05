#include "../header/SnakeTile.h"
using namespace std;

SnakeTile::SnakeTile() : Tile('S') {
    this->penalty = -3;
}

SnakeTile::SnakeTile(int penalty) : Tile('S') {
    this->penalty = penalty;
}

int SnakeTile::getPenalty() {
    return penalty;
}

void SnakeTile::setPenalty(int penalty) {
    this->penalty = penalty;
}