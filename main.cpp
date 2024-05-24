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

    void startGame();
    void displayBoard();
};

Board::Board() {
    this->SIZE = 4;
    /**
     * since random spawning is 2x need to get both rand locations
     */
    int randRow1 = rand() % 4;
    int randCol1 = rand() % 4;

    int randRow2 = rand() % 4;
    int randCol2 = rand() % 4;
    // if the 2nd locations is equal to the first then need to change again
    while (randRow2 == randRow1 && randCol1 == randCol2) {
        randRow2 = rand() % 4;
        randCol2 = rand() % 4;
    }

    cout << "rand row -- " << randRow1 << " rand col -- " << randCol1 << endl;
    cout << "rand row -- " << randRow2 << " rand col -- " << randCol2 << endl;

    for (int row = 0; row < this->SIZE; row++) {
        for (int col = 0; col < this->SIZE; col++) {
            if (row == randRow1 && col == randCol1) {
                this->board[row][col] = 2;
                continue;
            }
            if (row == randRow2 && col == randCol2) {
                this->board[row][col] = 2;
                continue;
            }
            this->board[row][col] = 0;
        }
    }
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

}

void Board::handleDown() {

}

void Board::handleLeft() {

}

void Board::handleRight() {

}

int main() {
    srand(time(nullptr));
    Board b;
    b.startGame();
}