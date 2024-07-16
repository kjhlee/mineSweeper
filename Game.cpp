#include "Game.h"
#include "globals.h"
#include <iostream>

using namespace std;


bool isValidMove(int row, int col){
    return (row >= 0) && (row < boardSize) && (col >= 0) && (col < boardSize);
}

Game::Game(){
    firstMove = true;
    gameOver = false;
    numMoves = 0;
}

void Game::playMinesweeper(Board& gameBoard, Board& fakeBoard){
    fakeBoard.placeMines();
    while(!isGameOver()){
        // fakeBoard.printBoard();
        gameBoard.printBoard();
        int row, col;
        makeMove(gameBoard, row, col);
        if(playMinesweeperUtil(gameBoard, fakeBoard, row, col)){
            gameOver = true;
            cout << "Game over!" << endl;
            fakeBoard.printBoard();
        } else if(checkWin(gameBoard, fakeBoard)){
            gameOver = true;
            cout << "Congratulations! You won!" << endl;
        }
        // gameBoard.printBoard();
        // gameOver = true;
    }
    return;
}
bool Game::playMinesweeperUtil(Board& gameBoard, Board& fakeBoard, int row, int col){
    if(gameBoard.board[row][col] != '-'){
        return false;
    }
    if(fakeBoard.isMine(row, col)){
        if(firstMove){
            firstMove = false;
            fakeBoard.replaceMines(row, col);
            return playMinesweeperUtil(gameBoard, fakeBoard, row, col);
        } else {
            gameBoard.board[row][col] = '*';
            gameBoard.printBoard();
            return true;
        }
    }
    firstMove = false;

    int adjMines = fakeBoard.countAdjMines(row, col);
    if(!fakeBoard.isMine(row,col)){
        gameBoard.board[row][col] = adjMines + '0';
    }

    if(adjMines == 0){
        int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
        int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
        for(int pos = 0; pos < 8; pos++){
            int updateRow = row + dx[pos];
            int updateCol = col + dy[pos];
            if(isValidMove(updateRow, updateCol)){
                playMinesweeperUtil(gameBoard, fakeBoard, updateRow, updateCol);
            }
        }
    }
    return false;
}
void Game::makeMove(Board& myBoard, int& x, int& y){
    bool validMove = false;
    char moveType;
    while(!validMove){
        cout << "Enter a move type, 'P' to place mines and 'R' to reveal areas: " << endl;
        cin >> moveType;
        if(moveType == 'P'){
            int r;
            int c;
            cout << "Enter where you'd like to place the flag";
            cin >> r >> c;
            myBoard.board[r][c] = 'X';
            myBoard.printBoard();
        } else if(moveType == 'R'){
            cout<< "Enter a move (row, column): ";
            cin >> x >> y;
            if(isValidMove(x, y)){
                validMove = true;
            } else {
                cout << "Invalid move, please try again";
            }
        }
    }

    return;
}

bool Game::isGameOver(){
    return gameOver;
}

bool Game::checkWin(Board& myBoard, Board& fakeBoard){
    for(int row = 0; row < boardSize; row++){
        for(int col = 0; col < boardSize; col++){
            if(myBoard.board[row][col] == '-' && !fakeBoard.isMine(row, col)){
                return false;
            }
        }
    }
    return true;
}






