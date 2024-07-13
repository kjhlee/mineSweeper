#include "Board.h"
#include "globals.h"
#include <vector>
#include <iostream>
#include <utility> 
#include <algorithm>
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
    srand(time(0));
    while(placedMines.size() < numMines){
        int row = rand() % boardSize;
        int col = rand() % boardSize;
        bool placed = false;
        for(auto mines : placedMines){
            if(row == mines.first && col == mines.second){
                placed = true;
                break;
            }
        }
        if(!placed){
            placedMines.push_back(make_pair(row, col));
            board[row][col] = '*';
        }
    }
    return; 
}

bool Board::isMine(int row, int col){
    pair<int, int> p = make_pair(row, col);
    auto it = find(placedMines.begin(), placedMines.end(), p);
    if(it == placedMines.end()){
        return false;
    }
    return true;
}

