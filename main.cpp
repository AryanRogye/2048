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

Board::Board() {
    this->SIZE = 4;

    for (int row = 0; row < this->SIZE; row++) {
        for (int col = 0; col < this->SIZE; col++) {
            this->board[row][col] = 0;
        }
    }
    generateRandom();
    generateRandom();
}

void Board::generateRandom() {

    int emptyCells = 0;

    //checks how many empty cells there are
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (this->board[row][col] == 0) {
                emptyCells++;
            }
        }
    }

    //if none then u lost
    if (emptyCells == 0) {
        return;
    }

    int randRow = rand() % 4;
    int randCol = rand() % 4;

    while (this -> board[randRow][randCol] != 0) {
        randRow = rand() % 4;
        randCol = rand() % 4;
    }

    this -> board[randRow][randCol] = 2;
}

void Board::displayBoard() {
    for(int row = 0; row < this -> SIZE; row++) {
        for(int col = 0; col < this -> SIZE; col++) {
            cout << this -> board[row][col] << " ";
        }
        cout << endl;
    }
}

void Board::startGame() {
    string input = "";
    while(input != "q") {
        displayBoard();
        cout << "Enter Your Next Move : ";
        cin >> input;
        if(input == "\033[A") {
            cout << "up" << endl;
            handleUp();
        }
        if(input == "\033[D") {
          cout << "left" << endl;
            handleLeft();
        }
        if(input == "\033[B") {
            cout << "down" << endl;
            handleDown();
        }
        if(input == "\033[C") {
            cout << "right" << endl;
            handleRight();
        }
    }
}

void Board::handleUp() {
    //start at col 1 then move everything up
    //if above is 0 then can move up if up matches with number than add
    bool moved = false;
    for(int row = 1; row < this -> SIZE; row++) {
        for(int col = 0; col < this -> SIZE; col++) {
            if(this -> board[row][col] == 0) {
                continue;
            }
            int currRow = row;
            while (currRow > 0) {
                if(this -> board[currRow-1][col] == this -> board[currRow][col]) {
                    moved = true;
                    this -> board[currRow-1][col] *= 2;
                    this -> board[currRow][col] = 0;
                    break;
                }
                else if(this -> board[currRow-1][col] == 0) {
                    moved = true;
                    this -> board[currRow-1][col] = this -> board[currRow][col];
                    this -> board[currRow][col] = 0;
                    currRow--;
                } else {
                    break;
                }
            }
        }
    }
    if(moved) generateRandom();
    else cout << "CANT MOVE TRY AGAIN" << endl;
}

void Board::handleDown() {
    bool moved = false;
    for(int row = this -> SIZE-2; row >= 0; row--) {
        for(int col = 0; col < this -> SIZE; col++) {
            if(this -> board[row][col] == 0) {
                continue;
            }
            int currRow = row;
            while (currRow < 3) {
                if(this -> board[currRow+1][col] == this -> board[currRow][col]) {
                    moved = true;
                    this -> board[currRow+1][col] *= 2;
                    this -> board[currRow][col] = 0;
                    break;
                }
                else if(this -> board[currRow+1][col] == 0) {
                    moved = true;
                    this -> board[currRow+1][col] = this -> board[currRow][col];
                    this -> board[currRow][col] = 0;
                    currRow++;
                } else {
                    break;
                }
            }
        }
    }
    if(moved) generateRandom();
    else cout << "CANT MOVE TRY AGAIN" << endl;
}

void Board::handleLeft() {
    bool moved = false;
    for(int row = 0; row < this -> SIZE; row++) {
        for(int col = 1; col < this -> SIZE; col++) {
            if(this -> board[row][col] == 0) {
                continue;
            }
            int currCol = col;
            while (currCol > 0) {
                if(this -> board[row][currCol-1] == this -> board[row][currCol]) {
                    moved = true;
                    this -> board[row][currCol-1] *= 2;
                    this -> board[row][currCol] = 0;
                    break;
                }
                else if(this -> board[row][currCol-1] == 0) {
                    moved = true;
                    this -> board[row][currCol-1] = this -> board[row][currCol];
                    this -> board[row][currCol] = 0;
                    currCol--;
                } else {
                    break;
                }
            }
        }
    }
    if(moved) generateRandom();
    else cout << "CANT MOVE TRY AGAIN" << endl;
}

void Board::handleRight() {
    bool moved = false;
    for(int row = 0; row < this -> SIZE; row++) {
        for(int col = this->SIZE-2; col >= 0; col--) {
            if(this -> board[row][col] == 0) {
                continue;
            }
            int currCol = col;
            while (currCol < 3) {
                if(this -> board[row][currCol+1] == this -> board[row][currCol]) {
                    moved = true;
                    this -> board[row][currCol+1] *= 2;
                    this -> board[row][currCol] = 0;
                    break;
                }
                else if(this -> board[row][currCol+1] == 0) {
                    moved = true;
                    this -> board[row][currCol+1] = this -> board[row][currCol];
                    this -> board[row][currCol] = 0;
                    currCol++;
                } else {
                    break;
                }
            }
        }
    }
    if(moved) generateRandom();
    else cout << "CANT MOVE TRY AGAIN" << endl;
}

int main() {
    srand(time(nullptr));
    Board b;
    b.startGame();
}