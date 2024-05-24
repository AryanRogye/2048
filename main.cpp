#include <iostream>

using namespace std;

class Board {

private:
    int board[4][4];

public:

    Board() {
        cout << "Constructor Made" << endl;
    }

};

int main() {
    Board b;
}