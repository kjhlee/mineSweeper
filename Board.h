#ifndef BOARD_H
#define BOARD_H

#include<vector>

using namespace std;

class Board{
    public:
        vector<vector<char>> board;
        Board(); 
        ~Board();
        void printBoard();
        void placeMines();

};


#endif