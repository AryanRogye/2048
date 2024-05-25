#ifndef Board_H
#define Board_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Board {

private:
    int board[4][4];
    int SIZE;
public:

    Board();

    void handleUp();
    void handleDown();
    void handleLeft();
    void handleRight();

    void generateRandom();

    void startGame();
    void displayBoard();
};

#endif