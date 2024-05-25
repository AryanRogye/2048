#include "Board.h"

Board::Board() {
    this->SIZE = 4;

    for (int row = 0; row < this->SIZE; row++) {
        for (int col = 0; col < this->SIZE; col++) {
            this->board[row][col] = 0;
        }
    }
    generateRandom();
    generateRandom();
    storeBoard();
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
        if(input == "u") {
            undoBoard();
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
    if(moved) {
        generateRandom();
        storeBoard();
    }
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
    }if(moved) {
        generateRandom();
        storeBoard();
    }if(moved) generateRandom();
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
    if(moved) {
        generateRandom();
        storeBoard();
    }
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
    if(moved) {
        generateRandom();
        storeBoard();
    }
    else cout << "CANT MOVE TRY AGAIN" << endl;
}

void Board::storeBoard() {
    int (*toAdd)[4] = new int[4][4]; // Allocate memory for a copy of the board

    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            toAdd[row][col] = board[row][col];
        }
    }
    boards.push(toAdd);
}

void Board::printAllPastBoards() {
    stack<int(*)[4]> tempStack = boards;

    while (!tempStack.empty()) {
        int (*tempBoard)[4] = tempStack.top();
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                cout << tempBoard[row][col] << " ";
            }
            cout << endl;
        }
        cout << endl;

        tempStack.pop();
    }
}

void Board::undoBoard() {
    if (!boards.empty()) {
        boards.pop();
        if (!boards.empty()) {
            int (*topBoard)[4] = boards.top();
            for(int i = 0; i < this -> SIZE; i++) {
                for(int j = 0; j < this -> SIZE; j++) {
                    this -> board[i][j] = topBoard[i][j];
                }
            }
        } else {
            cout << "CANT UNDO" << endl;
        }
    } else {
        cout << "CANT UNDO" << endl;
    }
}


Board::~Board() {
    while (!boards.empty()) {
        int (*toRemove)[4] = boards.top();
        delete[] toRemove;
        boards.pop();
    }
}