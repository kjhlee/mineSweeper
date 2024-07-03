#include "Board.h"
#include "globals.h"
#include <vector>
#include <iostream>

using namespace std;
Board::Board(){
    board.resize(boardSize, vector<char>(boardSize, '-'));
}
Board::~Board(){
    return;
}

void Board::printBoard(){
    cout << "    ";
    for (int i = 0; i < boardSize; ++i)
        cout << i+1 << " ";
    cout << "\n\n";

    for (int i = 0; i < boardSize; ++i) {
        std::cout << i + 1 << "   ";
        for (int j = 0; j < boardSize; ++j)
            cout << board[i][j] << " ";
        cout << "\n";
    }
}

void Board::placeMines(){
    return; 
}

