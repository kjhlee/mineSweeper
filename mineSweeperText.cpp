#include "globals.h"
#include "Board.h"
#include <iostream>
#include <istream>
using namespace std;


int boardSize = 0;
int numMines = 0;
void levelPick(){
    string levelChosen;
    cout << "Pick a level. 0 for easy, 1 for med, 2 for hard: ";
    cin >> levelChosen;

    if(stoi(levelChosen) == 0){
        boardSize = 9;
        numMines = 10;
    } else if(stoi(levelChosen) == 1){
        boardSize = 16;
        numMines = 40;
    } else {
        boardSize = 24;
        numMines = 99;
    }
    return;
    
}


int main() {
    levelPick();
    cout << boardSize << " " << numMines << endl;
    Board newBoard, fakeBoard;
    newBoard.printBoard();
    fakeBoard.placeMines();
    fakeBoard.printBoard();
    // string row;
    // string col;
    // cin >> row;
    // cin >> col;
    // fakeBoard.replaceMines(stoi(row), stoi(col));
    // fakeBoard.printBoard();


    return 0;
}