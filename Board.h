#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include<vector>
#include<utility>

using namespace std;


class Board{
    public:
        vector<pair<int, int>> placedMines;
        vector<vector<char>> board;
        Board(); 
        ~Board();
        void printBoard();
        void placeMines();
        bool isMine(int row, int col);
        int countAdjMines(int row, int col);
        void replaceMines(int row, int col);
};


#endif