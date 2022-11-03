#include "Battleship.h"
#include <iostream>

using namespace std;

const string DISPLAY[10] = {
        " 1 ", " 2 ", " 3 ", " 4 ", " 5 ",
        " 6 ", " 7 ", " 8 ", " 9 ", "10 "
};

int* playerOneBoard = new int[ROWS * COLS];
int* playerTwoBoard = new int[ROWS * COLS];

void createPlayerBoard(int *board) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            *(board + i * COLS + j) = 0;
        }
    }
}

void displayPlayerBoard(int *board, bool hidden) {
    system("cls");
    int num;
    cout << "   1 2 3 4 5 6 7 8 9 10" << endl;
    for (int i = 0; i < 10; i++) {
        cout << DISPLAY[i];
        for (int j = 0; j < 10; j++) {
            num = *(board + i * COLS + j);
            if (hidden) {
                switch (num) {
                    case 0:
                        cout << "* ";
                        break;
                    case 1:
                        cout << "* ";
                        break;
                    case 2:
                        cout << "* ";
                        break;
                    case 3:
                        cout << "* ";
                        break;
                    case 4:
                        cout << "* ";
                        break;
                    case 5:
                        cout << "* ";
                        break;
                    case 6:
                        cout << "M ";
                        break;
                    case 7:
                        cout << "H ";
                        break;
                    default:
                        break;
                }
            } else {
                switch (num) {
                    case 0:
                        cout << "* ";
                        break;
                    case 1:
                        cout << "1 ";
                        break;
                    case 2:
                        cout << "2 ";
                        break;
                    case 3:
                        cout << "3 ";
                        break;
                    case 4:
                        cout << "4 ";
                        break;
                    case 5:
                        cout << "5 ";
                        break;
                    case 6:
                        cout << "M ";
                        break;
                    case 7:
                        cout << "H ";
                        break;
                    default:
                        break;
                }
            }
        }
        cout << endl;
    }
}

void placePlayerShips(int *board) {
    system("cls");
    displayPlayerBoard(board, false);
    int input = 1;
    for (int i = 0; i < sizeof(SHIP_LENGTHS)/sizeof(SHIP_LENGTHS[0]); i++) {
        string orientation;
        int x, y, shipLength = SHIP_LENGTHS[i];
        cout << "Ship: " << i + 1 << " || Length: " << SHIP_LENGTHS[i] << endl;
        cout << "Enter orientation: ";
        cin >> orientation;
        cout << "Enter starting coordinates for ship: ";
        cin >> x >> y;
        for (int j = 0; j < shipLength; j++) {
            *(board + (x-1) * COLS + (y-1)) = i + 1;
            if (orientation == "h")
                y++;
            else if (orientation == "v")
                x++;
        }
        system("cls");
        displayPlayerBoard(board, false);
    }
    while (input != 0) {
        cout << "[0] Done" << endl;
        cin >> input;
    } input = 1;
    if (!checkForShips(board)) {
        while (input != 0) {
            cout << "Ships out of bounds." << endl;
            cout << "[0] Try again" << endl;
            cin >> input;
        } input = 1;
        createPlayerBoard(board);
        placePlayerShips(board);
    }
}

void startMultiplayerGame() {
    placePlayerShips(playerOneBoard);
}