#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player {
    private:
        int id;
        int position;

    public:
        Player();
        Player(int); // Only accepts id as paremeter, initial position is always 1

        int getId();
        int getPosition();
        void setPosition(int);

        int throwDice();
};

#endif