#include "Battleship.h"
#include <iostream>

using namespace std;

const string DISPLAY[10] = {
        " 1 ", " 2 ", " 3 ", " 4 ", " 5 ",
        " 6 ", " 7 ", " 8 ", " 9 ", "10 "
};

int* gameBoard = new int[ROWS * COLS];

void createGameBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            *(gameBoard + i * COLS + j) = 0;
        }
    }
}

void displayGameBoard() {
    system("cls");
    int num;
    cout << "   1 2 3 4 5 6 7 8 9 10" << endl;
    for (int i = 0; i < ROWS; i++) {
        cout << DISPLAY[i];
        for (int j = 0; j < COLS; j++) {
            num = *(gameBoard + i * COLS + j);
            switch (num) {
                case 0:
                    cout << "* ";
                    break;
                case 1:
                    cout << "X ";
                    break;
                case 2:
                    cout << "M ";
                    break;
                case 3:
                    cout << "H ";
                    break;
                default:
                    break;
            }
        }
        cout << endl;
    }
}

void placeRandomShips() {
    for (int i = 0; i < sizeof(SHIP_LENGTHS)/sizeof(SHIP_LENGTHS[0]); i++) {
        int orientation = rand() % 2;
        int x, y, shipLength = SHIP_LENGTHS[i];

        if (orientation == 0) {
            x = rand() % 10;
            y = rand() % (10-SHIP_LENGTHS[i]);
        } else {
            x = rand() % (10-SHIP_LENGTHS[i]);
            y = rand() % 10;
        }
        for (int j = 0; j < shipLength; j++) {
            *(gameBoard + x * COLS + y) = 1;
            if (orientation == 0)
                y++;
            else if (orientation == 1)
                x++;
        }
    }
    if (!checkForShips()) {
        createGameBoard();
        placeRandomShips();
    }
}

bool checkForShips() {
    int tileCount = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (*(gameBoard + i * COLS + j) != 0)
                tileCount++;
        }
    }
    if (tileCount == 17)
        return true;
    return false;
}

void fire(int x, int y) {
    if (*(gameBoard + (x-1) * COLS + (y-1)) == 0)
        *(gameBoard + (x-1) * COLS + (y-1)) = 2;
    else
        *(gameBoard + (x-1) * COLS + (y-1)) = 3;
}

void startSingleplayerGame() {
    int inputX = 1, inputY = 1;
    createGameBoard();
    placeRandomShips();
    while (inputX != 0) {
        displayGameBoard();
        cout << "Enter X and Y coords: ";
        cin >> inputX >> inputY;
        fire(inputX, inputY);
    }
    mainMenu();
}