#ifndef Board_H
#define Board_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>

using namespace std;

class Board {

private:
    
    stack<int(*)[4]>boards;

    int board[4][4];
    int SIZE;
public:

    Board();
    ~Board();

    void storeBoard();
    void printAllPastBoards();
    void undoBoard();

    void handleUp();
    void handleDown();
    void handleLeft();
    void handleRight();

    void generateRandom();

    void startGame();
    void displayBoard();
};

#endif