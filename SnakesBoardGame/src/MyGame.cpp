#include "../header/MyGame.h"
#include "../header/Player.h"
#include "../header/Tile.h"
#include "../header/SnakeTile.h"
#include "../header/LadderTile.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>

using namespace std;

void MyGame::createRandomMap() {
    SnakeTile STile;
    LadderTile LTile;
    Tile NTile;

    for (int i = 0; i < 24; ++i) { map[i] = NTile; }
    for (int i = 24; i < 27; ++i) { map[i] = STile; }
    for (int i = 27; i < 30; ++i) { map[i] = LTile; }

    // Mezclar el arreglo para obtener una disposición aleatoria
    random_device rd;
    mt19937 g(rd());
    shuffle(map.begin(), map.end(), g);

    // Imprimir el arreglo para verificar la disposición aleatoria
    cout << "Random Map Created: ";
    for (int i = 0; i < 30; i++) { cout << map[i].getType() << "  "; }
    cout << endl;
}

void calcPriorEndPosition(Player& player, bool& flag, int diceResult) {
    int newPosition = min(player.getPosition() + diceResult, 30);
    player.setPosition(newPosition);

    flag = (newPosition < 30);
}

void substractPlaces(Player& player, bool& flag, Tile tileFallen) {
    int newPosition = clamp(player.getPosition() + tileFallen.getPenalty() + tileFallen.getReward(), 1, 30);
    player.setPosition(newPosition);

    flag = (newPosition < 30);     
}

void MyGame::start() {
    Player p1(1);
    Player p2(2);

    createRandomMap();
    seed = to_string(time(0));
    turn = 1;
    turnsLimit = 0;

    int endingCase = 1;
    bool continueGame = true;

    ostringstream ossOutputFile;
    string fileHeader = "../resources/SnakesGame_Seed";
    ossOutputFile << fileHeader << seed << ".csv";
    string gameLogFile = ossOutputFile.str();

    ofstream gameLog(gameLogFile);
    gameLog << "Press C to continue next turn or E to end the game:\n";
    gameLog << "Turn | Player | InitialPos | NumRolled | PlaceFallen | EndPos\n";

    ifstream inputFile;
    string line;

    int inputOption = 2; bool inputOptionChosen = false;
    cout << "Is the amount of turns ought to be determined by a file (1) or the players (2)? [Insert number]: ";
    while (!inputOptionChosen) {
        cin >> inputOption;
        if (inputOption == 1) {
            string inputFileName;
            cout << "Enter the name of the file as 'fileName.csv': " << endl;
            cin >> inputFileName;
            string directory = "../resources/";
            string inputFileNameAddress = directory.append(inputFileName);

            inputFile.open(inputFileNameAddress);
            if (inputFile.is_open()) {
                getline(inputFile, line); // Get rid of header
                inputOptionChosen = true;
            } else {
                cout << "Error: Could not open the file." << endl;
            }
            
        } else if (inputOption == 2) {
            cout << "Would you like the game to have a limit for the amount of turns?" << endl;
            cout << "(Enter the amount (should be >=2). If amount < 2, then no limit will be considered): ";
            cin >> turnsLimit;

            inputOptionChosen = true;

        } else {
            cout << "Select another option" << endl;
        }
    }

    if (turnsLimit < 2) { turnsLimit = 0; }

    while(continueGame) {
        ostringstream oss;
        string turnResult;

        if(turn%2 == 1) { // Player 1 turn
            int diceResult = p1.throwDice();
            int initialPosition = p1.getPosition();

            calcPriorEndPosition(p1, continueGame, diceResult);

            Tile tileFallen = map[p1.getPosition() - 1];

            substractPlaces(p1, continueGame, tileFallen);

            int endPosition = p1.getPosition();

            oss << turn << " " << p1.getId() << " " << initialPosition << " " << diceResult << " " << tileFallen.getType() << " " << endPosition;
            turnResult = oss.str();
        } else { // Player 2 turn
            int diceResult = p2.throwDice();
            int initialPosition = p2.getPosition();

            calcPriorEndPosition(p2, continueGame, diceResult);

            Tile tileFallen = map[p2.getPosition() - 1];

            substractPlaces(p2, continueGame, tileFallen);

            int endPosition = p2.getPosition();

            oss << turn << " " << p2.getId() << " " << initialPosition << " " << diceResult << " " << tileFallen.getType() << " " << endPosition;
            turnResult = oss.str();
        }

        cout << turnResult << endl;
        gameLog << turnResult.append("\n");

        if(!continueGame) { continue; }

        if(turn == turnsLimit && turnsLimit != 0) {
            endingCase = 2;
            continueGame = false;
            continue;
        }

        turn++;

        if(inputOption == 1) {
            getline(inputFile, line);
            stringstream ss(line);

            string option;
            getline(ss, option, '\n');

            if(option == "E") {
                cout << "Input file stated that the game will end..." << endl;
                endingCase = 3;
                continueGame = false;
            } else {
                cout << "Input file stated that the game will continue." << endl;
            }
        } else {
            string option; bool optionChosen = false;
            cout << "Press C to continue next turn, or E to end the game: ";
        
            while(!optionChosen) {
                cin >> option;

                if(option == "E") {
                    endingCase = 3;
                    optionChosen = true;
                    continueGame = false;
                } else if (option == "C") {
                    optionChosen = true;
                } else {
                    cout << "Invalid option, please press C to continue next turn or E to end the game" << endl;
                }
            }
        }
    }

    cout << "-- GAME OVER --" << endl;
    gameLog << "-- GAME OVER --\n";

    if (endingCase == 1) {
        if (turn%2 == 1) {
            cout << "Player 1 is the winner!!!" << endl;
            gameLog << "Player 1 is the winner!!!";
        } else {
            cout << "Player 2 is the winner!!!" << endl;
            gameLog << "Player 2 is the winner!!!";
        }
    } else if (endingCase == 2) {
        cout << "The maximum number of turns (" << turnsLimit << ") has been reached..." << endl;
        gameLog << "The maximum number of turns (" << to_string(turnsLimit) << ") has been reached...";
    } else {
        if(inputOption == 1) {
            cout << "Input file decided to end the game. Thanks for playing!!!" << endl;
            gameLog << "Input file decided to end the game. Thanks for playing!!!";
        } else {
            cout << "A player decided to end the game. Thanks for playing!!!" << endl;
            gameLog << "A player decided to end the game. Thanks for playing!!!";
        }
    }
}