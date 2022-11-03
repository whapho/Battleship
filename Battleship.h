#pragma once
#include<string>
void mainMenu();
void showInstructions();
void newGame();
void startSingleplayerGame();
void createGameBoard();
void displayGameBoard();
void placeRandomShips();
bool checkForShips(int *board);
void showSingleplayerInstructions();
void showMultiplayerInstructions();
void startMultiplayerGame();
void createPlayerBoard(int *board);
void placePlayerShips(int *board);
void displayPlayerBoard(int *board, bool hidden);
bool gameOver(int *board, int mode);
void showStatMenu();
void showSingleplayerStats();
void showMultiplayerStats();
void aimbot(int *board);
void fire(std::string coord, int *board);
const int SHIP_LENGTHS[5] = {2,3,3,4,5};
const int ROWS = 10, COLS = 10;