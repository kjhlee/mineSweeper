#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include "globals.h"

using namespace std;

class Game {
private:
    int numMoves;
    bool firstMove;
    bool gameOver;
public:
    Game();
    void playMinesweeper(Board& gameBoard, Board& fakeBoard);
    bool playMinesweeperUtil(Board& gameBoard, Board& fakeBoard, int row, int col);
    void makeMove(Board& myBoard, int& x, int& y);
    bool isGameOver();
    bool checkWin(Board& myBoard, Board& fakeBoard);
};


#endif