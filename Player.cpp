#include "../header/Player.h"
#include <cstdlib> 
#include <ctime>
using namespace std;

Player::Player() {
    this->id = 0;
    this->position = 1;
}

Player::Player(int id) {
    this->id = id;
    this->position = 1;
}

int Player::getId() {
    return id;
}

int Player::getPosition() {
    return position;
}

void Player::setPosition(int position) {
    this->position = position;
}

int Player::throwDice() {
    // Dice is to be considered as a conventional six-sided dice
    srand(time(0));
    int value = rand() % 6 + 1;

    return value;
}