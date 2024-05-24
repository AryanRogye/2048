#include <iostream>

using namespace std;

class Board {

private:
    int board[4][4];
    int SIZE;
public:

    Board() {
        this -> SIZE = 4;

        for(int row = 0; row < this -> SIZE; row++) {
            for(int col = 0; col < this -> SIZE; col++) {
                this -> board[row][col] = 0;
            }
        }
    }

    void displayBoard() {
        for(int row = 0; row < this -> SIZE; row++) {
            for(int col = 0; col < this -> SIZE; col++) {
                cout << this -> board[row][col] << " ";
            }
            cout << endl;
        }
    }

};

int main() {
    Board b;
    b.displayBoard();
}