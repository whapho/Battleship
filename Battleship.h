#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <stdio.h>
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
bool fire(std::string coord, int *board, int mode);
void createGameLog();
std::string getFormattedTime();
void writePlayerBoards();
const int SHIP_LENGTHS[5] = {2,3,3,4,5};
const int ROWS = 10, COLS = 10;
const std::string DISPLAY[10] = {
        " 1 ", " 2 ", " 3 ", " 4 ", " 5 ",
        " 6 ", " 7 ", " 8 ", " 9 ", "10 "
};