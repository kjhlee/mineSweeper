#include "Board.h"
#include "globals.h"
#include <vector>
#include <iostream>
#include <utility> 
#include <algorithm>
using namespace std;



bool isValid(int row, int col){
    return (row >= 0) && (row < boardSize) && (col >= 0) && (col < boardSize);
}

Board::Board(){
    board.resize(boardSize, vector<char>(boardSize, '-'));
}
Board::~Board(){
    return;
}

void Board::printBoard(){
    cout << "    ";
    for (int i = 0; i < boardSize; ++i)
        // cout << i+1 << " ";
        cout << i << " ";
    cout << "\n\n";

    for (int i = 0; i < boardSize; ++i) {
        // cout << i + 1 << "   ";
        cout << i << "   ";
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

int Board::countAdjMines(int row, int col){
    int count = 0;
    int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    for(int pos = 0; pos < 8; pos++){
        int updateRow = row + dx[pos];
        int updateCol = col + dy[pos];
        if(isValid(updateRow, updateCol)){
            if(isMine(updateRow, updateCol)){
                count++;
            }
        }
    }
    return count;
}

void Board::replaceMines(int row, int col){
    board[row][col] = '-';
    
    for(int r = 0; r < board.size(); r++){
        for(int c = 0; c < board.size(); c++){
            if(board[r][c] == '-'){
                board[r][c] = '*';
                return;
            }
        }
    }
    return;
}
