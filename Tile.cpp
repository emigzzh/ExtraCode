#include "../header/Tile.h"
using namespace std;

Tile::Tile() {
    this->type = 'N';
}

Tile::Tile(char type) {
    this->type = type;
}

char Tile::getType() {
    return type;
}

void Tile::setType(char type) {
    this->type = type;
}

int Tile::getPenalty() {
    return 0;
}

int Tile::getReward() {
    return 0;
}