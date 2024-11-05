# Actividad1

This project corresponds to the board game of snakes and ladders designed for exclusively 2 players. It is subdivided into 3 folders: header, resources and src. (1) Header contains the interface for client applications. (2) Resources contains input and output files in .csv extension. (3) Src contains the implementation of classes as .cpp.

## Header Folder

The project interface contains 5 header classes modeling different objects.

```cpp
- MyGame.h // Board game
- Player.h // Player
- Tile.h // Abstract Tile
- SnakeTile.h // Child of Tile
- LadderTile.h // Child of Tile
```

## ../src/Snakes.cpp

```Snake.cpp``` contains the ```main()```, which starts the game with the usage of the ```MyGame``` class.

```cpp
#include "../header/MyGame.h"

using namespace std;

int main() {
    MyGame g;
    g.start();
    return 0;
}
```

## ../src/MyGame.cpp

```MyGame.cpp``` creates a game every time the ```start()``` is invoked. Includes all headers from the ```header``` folder.

```cpp
#include "../header/MyGame.h"
#include "../header/Player.h"
#include "../header/Tile.h"
#include "../header/SnakeTile.h"
#include "../header/LadderTile.h"

// Creates random map every time a new game begins
void MyGame::createRandomMap();

// Calculates end position of a player after rolling a dice
void calcPriorEndPosition(Player& player, bool& flag, int diceResult);

// Calculates extra movement tiles according to the tile where the player landed
void substractPlaces(Player& player, bool& flag, Tile tileFallen);

// Initializes a new game
void MyGame::start();
```

## Authors

Emilio González A01286440